/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:52:36 by jcaron            #+#    #+#             */
/*   Updated: 2023/03/14 23:09:24 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	env_builtin(t_command cmd)
{
	char	**env;

	(void)cmd;
	env = g_mini.cpy_env;
	if (cmd.argv[1])
	{
		ft_putstr_fd("minishell: env: too many arguments\n", STDERR_FILENO);
		return (1);
	}
	while (*env)
	{
		ft_putstr_fd(*env, cmd.fd_out);
		ft_putstr_fd("\n", cmd.fd_out);
		env++;
	}
	return (0);
}
