/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:05:30 by jcaron            #+#    #+#             */
/*   Updated: 2023/03/14 22:53:19 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static size_t	strlen_equal(char *str)
{
	size_t	size;

	size = 0;
	if (!str)
		return (size);
	while (str[size] && str[size] != '=')
		size++;
	return (size);
}

static bool	is_same_var(char *var_env, char *argv)
{
	if (strlen_equal(var_env) == ft_strlen(argv))
	{
		if (!ft_strncmp(var_env, argv, ft_strlen(argv)))
			return (true);
	}
	return (false);
}

int	unset_builtin(t_command cmd)
{
	size_t	i_env;

	cmd.argv++;
	while (*cmd.argv)
	{
		i_env = 0;
		while (g_mini.cpy_env[i_env])
		{
			if (is_same_var(g_mini.cpy_env[i_env], *cmd.argv))
			{
				ft_free(g_mini.cpy_env[i_env]);
				while (g_mini.cpy_env[i_env])
				{
					g_mini.cpy_env[i_env] = g_mini.cpy_env[i_env + 1];
					i_env++;
				}
				break ;
			}
			i_env++;
		}
		cmd.argv++;
	}
	return (0);
}
