/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:53:49 by jcaron            #+#    #+#             */
/*   Updated: 2023/03/11 20:33:37 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "browser.h"

static int	execute_in_redirection(t_redirection *redir)
{
	int	fd;

	fd = -1;
	if (redir->type == INPUT_REDIRECTION)
		fd = get_fd_input_redirection(redir);
	else if (redir->type == HERE_DOC)
		fd = get_fd_here_doc(redir);
	return (fd);
}

static int	execute_out_redirection(t_redirection *redir)
{
	int	fd;

	fd = -1;
	if (redir->type == OUTPUT_REDIRECTION)
		fd = get_fd_output_redirection(redir);
	else if (redir->type == APPEND_OPERATOR)
		fd = get_fd_append_redirection(redir);
	return (fd);
}

int	execute_redirection(t_command *cmd)
{
	t_redirection	*redir;

	redir = cmd->redirections;
	while (redir)
	{
		if (redir->type == INPUT_REDIRECTION || redir->type == HERE_DOC)
		{
			close_if(cmd->fd_in);
			cmd->fd_in = execute_in_redirection(redir);
			if (cmd->fd_in < 0)
				return (close_if(cmd->fd_out));
		}
		else if (redir->type == OUTPUT_REDIRECTION
			|| redir->type == APPEND_OPERATOR)
		{
			close_if(cmd->fd_out);
			cmd->fd_out = execute_out_redirection(redir);
			if (cmd->fd_out < 0)
				return (close_if(cmd->fd_in));
		}
		redir = redir->next;
	}
	return (0);
}
