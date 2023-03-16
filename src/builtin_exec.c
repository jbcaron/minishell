/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:47:04 by jcaron            #+#    #+#             */
/*   Updated: 2023/03/14 23:22:03 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "browser.h"

/**
static const char	*g_builtin_cmd[8] = {
	"echo",
	"cd",
	"pwd",
	"export",
	"unset",
	"env",
	"exit",
	NULL
};

static int	(*g_builtin_function[7])(t_command) = {
	&echo_builtin,
	&cd_builtin,
	&pwd_builtin,
	&export_builtin,
	&unset_builtin,
	&env_builtin,
	&exit_builtin
};
**/

bool	is_builtin(char *cmd)
{
	if (!ft_strcmp(cmd, "echo"))
		return (true);
	else if (!ft_strcmp(cmd, "echo"))
		return (true);
	else if (!ft_strcmp(cmd, "cd"))
		return (true);
	else if (!ft_strcmp(cmd, "pwd"))
		return (true);
	else if (!ft_strcmp(cmd, "export"))
		return (true);
	else if (!ft_strcmp(cmd, "echo"))
		return (true);
	else if (!ft_strcmp(cmd, "unset"))
		return (true);
	else if (!ft_strcmp(cmd, "env"))
		return (true);
	else if (!ft_strcmp(cmd, "exit"))
		return (true);
	else
		return (false);
}

static int	get_builtin_i(char *cmd)
{
	if (!ft_strcmp(cmd, "echo"))
		return (0);
	else if (!ft_strcmp(cmd, "cd"))
		return (1);
	else if (!ft_strcmp(cmd, "pwd"))
		return (2);
	else if (!ft_strcmp(cmd, "export"))
		return (3);
	else if (!ft_strcmp(cmd, "unset"))
		return (4);
	else if (!ft_strcmp(cmd, "env"))
		return (5);
	else if (!ft_strcmp(cmd, "exit"))
		return (6);
	else
		return (-1);
}

static int	exec_builtin_i(t_command *cmd, int i)
{
	if (i == 0)
		return (echo_builtin(*cmd));
	else if (i == 1)
		return (cd_builtin(*cmd));
	else if (i == 2)
		return (pwd_builtin(*cmd));
	else if (i == 3)
		return (export_builtin(*cmd));
	else if (i == 4)
		return (unset_builtin(*cmd));
	else if (i == 5)
		return (env_builtin(*cmd));
	else if (i == 6)
		return (exit_builtin(*cmd));
	return (0);
}

int	execute_builtin(t_command *cmd)
{
	int	status;

	status = exec_builtin_i(cmd, get_builtin_i(cmd->argv[0]));
	close_if(cmd->fd_in);
	close_if(cmd->fd_out);
	return (status);
}
