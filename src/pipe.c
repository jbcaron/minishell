/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:02:40 by jcaron            #+#    #+#             */
/*   Updated: 2023/03/12 20:01:57 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "browser.h"

static int	wait_all_child(pid_t last_child_pid)
{
	int		status;
	int		last_child_status;
	pid_t	last_wait_pid;

	last_child_status = 0;
	while (1)
	{
		last_wait_pid = waitpid(-1, &status, 0);
		if (last_wait_pid < 0)
			break ;
		else if (last_wait_pid == last_child_pid)
			last_child_status = get_real_status(status);
	}
	return (last_child_status);
}

static int	pipe_with_next_cmd(t_command *cmd, int fd_pipe[2]
	, int fd_last_pipe_out)
{
	int	pid;

	ft_pipe(fd_pipe, fd_last_pipe_out);
	pid = ft_fork();
	if (pid == 0)
	{
		close(fd_pipe[PIPE_OUT]);
		cmd->fd_in = fd_last_pipe_out;
		cmd->fd_out = fd_pipe[PIPE_IN];
		execute_command_child(cmd);
	}
	else
	{
		close(fd_pipe[PIPE_IN]);
		close_if(fd_last_pipe_out);
		fd_last_pipe_out = fd_pipe[PIPE_OUT];
	}
	return (fd_last_pipe_out);
}

int	execute_pipe(t_node_data *data)
{
	int		fd_pipe[2];
	pid_t	pid;
	int		fd_last_pipe_out;

	fd_last_pipe_out = STDIN_FILENO;
	while (data->next)
	{
		fd_last_pipe_out = pipe_with_next_cmd(&data->command, fd_pipe,
				fd_last_pipe_out);
		data = data->next;
	}
	pid = ft_fork();
	if (pid == 0)
	{
		data->command.fd_in = fd_last_pipe_out;
		execute_command_child(&data->command);
	}
	close_if(fd_last_pipe_out);
	return (wait_all_child(pid));
}
