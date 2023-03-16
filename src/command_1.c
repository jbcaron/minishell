/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 10:59:16 by nomoulin          #+#    #+#             */
/*   Updated: 2023/03/15 18:56:26 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "tk_vector.h"
#include "libft.h"
#include "node.h"

void	append_redirection(t_redirection **list, t_redirection *new)
{
	if (!*list)
		*list = new;
	else if ((*list)->next)
		append_redirection(&(*list)->next, new);
	else
		(*list)->next = new;
}

t_redirection	*get_redirections(t_tk_vector *vector, t_uint command_index)
{
	t_redirection	*redirect;
	t_redirection	*redirections;
	t_uint			start;
	t_uint			end;

	redirections = NULL;
	start = command_start(vector, command_index);
	end = command_end(vector, command_index);
	while (start < end)
	{
		if (is_redirection(tk_vector_get(vector, start))
			|| tk_vector_get(vector, start).type == HERE_DOC)
		{
			redirect = redirection(vector, start);
			if (redirect->ptn_de_heredoc_a_la_con_error)
				return (redirect);
			append_redirection(&redirections, redirect);
		}
		start++;
	}
	return (redirections);
}
