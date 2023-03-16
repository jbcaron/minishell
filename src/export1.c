/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:56:42 by jcaron            #+#    #+#             */
/*   Updated: 2023/03/12 19:23:29 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static char	*get_variable_equal(char *arg)
{
	size_t	size;
	char	*variable;

	size = 0;
	if (!*arg)
		return (NULL);
	while (arg[size] && arg[size] != '=')
		size++;
	if (!arg[size])
		return (NULL);
	variable = ft_calloc(size + 2, sizeof(*variable));
	ft_memcpy(variable, arg, size + 1);
	return (variable);
}

static char	**add_to_env(char *arg, char **env)
{
	size_t	size;
	char	**new_env;

	ft_mem_bucket(0);
	size = 0;
	while (env[size])
		size++;
	new_env = ft_calloc(size + 2, sizeof(*new_env));
	new_env[size] = ft_strdup(arg);
	while (size--)
		new_env[size] = env[size];
	ft_free(env);
	ft_mem_bucket(1);
	return (new_env);
}

static void	replace_env(size_t env_index, char *new_elem)
{
	ft_mem_bucket(0);
	ft_free(g_mini.cpy_env[env_index]);
	g_mini.cpy_env[env_index] = ft_strdup(new_elem);
	ft_mem_bucket(1);
}

static void	export_arg(char **argv)
{
	size_t	i_env;
	char	*var;

	while (*argv)
	{
		while (*argv && !is_valid_var(*argv))
			argv++;
		if (!*argv)
			return ;
		var = get_variable_equal(*argv);
		i_env = 0;
		while (g_mini.cpy_env[i_env])
		{
			if (!ft_strncmp(g_mini.cpy_env[i_env], var, ft_strlen(var)))
			{
				replace_env(i_env, *argv);
				break ;
			}
			i_env++;
		}
		if (!g_mini.cpy_env[i_env])
			g_mini.cpy_env = add_to_env(*argv, g_mini.cpy_env);
		argv++;
	}
}

int	export_builtin(t_command cmd)
{
	g_mini.last_status = 0;
	cmd.argv++;
	if (!*cmd.argv)
		return (env_builtin(cmd));
	export_arg(cmd.argv);
	return (g_mini.last_status);
}
