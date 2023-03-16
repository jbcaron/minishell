/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:01:46 by jcaron            #+#    #+#             */
/*   Updated: 2023/03/14 22:25:03 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "browser.h"

void	ft_pipe(int fd_pipe[2], int last_fd_pipe_open)
{
	if (pipe(fd_pipe) < 0)
	{
		perror("FATAL ERROR: pipe");
		close_if(last_fd_pipe_open);
		rl_clear_history();
		ft_free_all();
		kill(0, SIGKILL);
		exit(1);
	}
}

pid_t	ft_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("FATAL ERROR: fork");
		rl_clear_history();
		ft_free_all();
		kill(0, SIGKILL);
		exit(1);
	}
	if (pid == 0)
		g_mini.is_child = true;
	return (pid);
}

int	close_if(int fd)
{
	if (fd > 2)
		close(fd);
	return (1);
}

int	get_real_status(int status)
{
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		if (WCOREDUMP(status))
			ft_putstr_fd("Aborted: (core dumped)\n", STDERR_FILENO);
		status = WTERMSIG(status) + 128;
	}
	return (status);
}

char	*ft_readline(char *prompt)
{
	char	*line;
	char	*line_ft_malloc;

	line = NULL;
	line = readline(prompt);
	if (!line)
		return (NULL);
	line_ft_malloc = ft_strdup(line);
	free(line);
	return (line_ft_malloc);
}
