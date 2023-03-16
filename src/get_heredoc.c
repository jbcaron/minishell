/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_herdoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:22:46 by jcaron            #+#    #+#             */
/*   Updated: 2023/03/14 23:25:06 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>
#include "libft.h"
#include "command.h"
#include "browser.h"
#include "main.h"

static bool	receive_sigint(bool status, bool push)
{
	static bool	glob = false;

	if (push)
		glob = status;
	return (glob);
}

static void	handle_heredoc_sigint(int sig)
{
	(void)sig;
	close(STDIN_FILENO);
	receive_sigint(true, true);
	g_mini.last_status = 130;
}

static void	*sigint_stop(int dup_stdin)
{
	dup2(dup_stdin, STDIN_FILENO);
	close_if(dup_stdin);
	signal(SIGINT, &handle_sigint);
	ft_putstr_fd("\n", STDOUT_FILENO);
	return (NULL);
}

static void	warning_if_eof(char *line)
{
	if (!line)
	{
		ft_putstr_fd(
			"minishell: warning: here-document delimited by end-of-file\n",
			STDERR_FILENO);
	}
}

char	*get_heredoc(char *delimitor)
{
	char		*line;
	t_dyn_str	*dyn_str;
	int			dup_stdin;

	receive_sigint(false, true);
	signal(SIGINT, &handle_heredoc_sigint);
	dup_stdin = dup(STDIN_FILENO);
	dyn_str = ds_create(1);
	line = ft_readline("> ");
	if (receive_sigint(false, false))
		return (sigint_stop(dup_stdin));
	warning_if_eof(line);
	while (line && ft_strcmp(line, delimitor))
	{
		ds_append_str(dyn_str, line);
		ds_append_char(dyn_str, '\n');
		line = ft_readline("> ");
		if (receive_sigint(false, false))
			return (sigint_stop(dup_stdin));
		warning_if_eof(line);
	}
	signal(SIGINT, &handle_sigint);
	close_if(dup_stdin);
	return (eval_variable_in_heredoc(dyn_str->str));
}
