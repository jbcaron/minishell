/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:33:58 by jcaron            #+#    #+#             */
/*   Updated: 2023/03/14 23:23:17 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_glob	g_mini;

static t_node	*get_tree(char *str)
{
	char		*str_eval;
	t_tk_vector	*token_lst;

	if (!quotes_ok(str))
		return (NULL);
	str_eval = eval_variable_in_str(str);
	token_lst = tokens(str_eval);
	if (!tokens_ok(token_lst))
		return (NULL);
	return (node(nodes_datas(token_lst)));
}

static void	parse_exec(char *line)
{
	t_node		*root;
	char		*ft_mem_line;

	ft_mem_bucket(1);
	ft_mem_line = ft_strdup(line);
	free(line);
	if (!*ft_mem_line)
		return ;
	root = get_tree(ft_mem_line);
	if (root)
	{
		g_mini.in_exec = true;
		signal(SIGQUIT, &handle_sigquit);
		g_mini.last_status = browse(root);
		signal(SIGQUIT, SIG_IGN);
		g_mini.in_exec = false;
	}
	else if (g_mini.last_status != 130)
	{
		ft_putstr_fd("minishell: syntax error\n", STDERR_FILENO);
		g_mini.last_status = 2;
	}
	ft_free_bucket(1);
}

/**
 * memory analyse
 * 
 * printf("memory allocated with 'ft_malloc' before free bucket : 
 * 		%ld bytes\n", ft_tot_alloc());
 * printf("memory allocated with 'ft_malloc' after free bucket :
 * 		%ld bytes\n", ft_tot_alloc());
**/

static int	error_arg(char *prgm_name)
{
	if (!prgm_name)
		prgm_name = "minishell";
	ft_putstr_fd(prgm_name, STDERR_FILENO);
	ft_putstr_fd(": requiered no arguments\nUsage: ", STDERR_FILENO);
	ft_putstr_fd(prgm_name, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	return (2);
}

int	main(int argc, char **argv, char **env)
{
	char		*line;

	signal(SIGINT, &handle_sigint);
	signal(SIGQUIT, SIG_IGN);
	if (argc != 1)
		return (error_arg(argv[0]));
	init_var(env);
	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
			break ;
		else
		{
			add_history(line);
			parse_exec(line);
		}
	}
	rl_clear_history();
	ft_free_all();
	ft_putstr_fd("exit\n", STDERR_FILENO);
	return (g_mini.last_status);
}
