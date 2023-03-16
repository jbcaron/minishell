/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:33:58 by jcaron            #+#    #+#             */
/*   Updated: 2023/03/14 00:16:31 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	handle_sigint(int sig)
{
	(void)sig;
	printf("\n");
	if (g_mini.in_exec)
		return ;
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	handle_sigquit(int sig)
{
	(void)sig;
}

static char	**copy_env(char **env)
{
	char	**new_env;
	size_t	size;

	size = 0;
	while (env[size])
		size++;
	new_env = ft_calloc(size + 1, sizeof(*new_env));
	while (size--)
		new_env[size] = ft_strdup(env[size]);
	return (new_env);
}

void	init_var(char **env)
{
	g_mini.cpy_env = copy_env(env);
	g_mini.last_status = 0;
	g_mini.is_child = false;
	g_mini.in_exec = false;
	export_bis("TERM=xterm-256color");
}
