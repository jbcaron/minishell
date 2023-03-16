/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:05:30 by jcaron            #+#    #+#             */
/*   Updated: 2023/03/14 23:09:14 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft.h"
#include "builtin.h"

// NE PAS AFFICHER EXIT SI DANS UN FORK
int	exit_builtin(t_command cmd)
{
	if (!g_mini.is_child)
		ft_putstr_fd("exit\n", STDERR_FILENO);
	if (cmd.argv[1])
	{
		if (ft_str_is_long(cmd.argv[1]))
		{
			if (cmd.argv[2])
			{
				ft_putstr_fd("minishell: exit: too many arguments\n",
					STDERR_FILENO);
				return (1);
			}
			g_mini.last_status = ft_atol(cmd.argv[1]) % 256;
		}
		else
		{
			ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
			ft_putstr_fd(cmd.argv[1], STDERR_FILENO);
			ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
			g_mini.last_status = 2;
		}
	}
	rl_clear_history();
	ft_free_all();
	exit(g_mini.last_status);
}
