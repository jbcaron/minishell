/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:03:49 by jcaron            #+#    #+#             */
/*   Updated: 2023/03/14 23:48:19 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "browser.h"

static int	print_error_cmd_not_found(char *cmd)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	return (127);
}

static char	*get_path_cmd(char *cmd, char **env)
{
	char	*path;
	char	*tmp;
	size_t	i;

	path = NULL;
	if (*cmd && ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	while (*env && ft_strncmp(*env, "PATH", 4))
		env++;
	if (!*env)
		return (NULL);
	env = ft_split(*env + 5, ':');
	i = 0;
	while (*cmd && env[i])
	{
		tmp = ft_strjoin(env[i], "/");
		path = ft_strjoin(tmp, cmd);
		ft_free(tmp);
		if (!access(path, F_OK))
			break ;
		ft_free(path);
		path = NULL;
		i++;
	}
	return (path);
}

static int	ft_exec_in_child(t_command *cmd, char *path)
{
	int	dup_fd_in;
	int	dup_fd_out;

	dup_fd_in = dup2(cmd->fd_in, STDIN_FILENO);
	close_if(cmd->fd_in);
	dup_fd_out = dup2(cmd->fd_out, STDOUT_FILENO);
	close_if(cmd->fd_out);
	if (dup_fd_in < 0 || dup_fd_out < 0)
		perror("minishell: dup2");
	else
	{
		execve(path, cmd->argv, g_mini.cpy_env);
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		perror(cmd->argv[0]);
	}
	close_if(dup_fd_in);
	close_if(dup_fd_out);
	rl_clear_history();
	ft_free_all();
	exit(127);
}

int	execute_simple_command(t_command *cmd)
{
	pid_t		pid;
	int			status;
	char		*path;

	if (cmd->is_null)
		return (execute_null_command(cmd));
	if (execute_redirection(cmd))
		return (1);
	if (is_builtin(cmd->name))
		return (execute_builtin(cmd));
	path = get_path_cmd(cmd->name, g_mini.cpy_env);
	if (!path)
		return (print_error_cmd_not_found(cmd->name));
	pid = ft_fork();
	if (pid == 0)
		ft_exec_in_child(cmd, path);
	close_if(cmd->fd_in);
	close_if(cmd->fd_out);
	waitpid(pid, &status, 0);
	return (get_real_status(status));
}

int	execute_command_child(t_command *cmd)
{
	char	*path;
	int		status;

	status = 0;
	if (cmd->is_null)
		status = execute_null_command(cmd);
	else if (execute_redirection(cmd))
		status = 1;
	else if (is_builtin(cmd->name))
		status = execute_builtin(cmd);
	else
	{
		path = get_path_cmd(cmd->name, g_mini.cpy_env);
		if (!path)
			status = print_error_cmd_not_found(cmd->name);
		else
			ft_exec_in_child(cmd, path);
	}
	close_if(cmd->fd_in);
	close_if(cmd->fd_out);
	rl_clear_history();
	ft_free_all();
	exit(status);
}
