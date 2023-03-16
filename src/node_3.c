/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:45:41 by nomoulin          #+#    #+#             */
/*   Updated: 2023/03/15 19:00:50 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"
#include "command.h"
#include "token.h"
#include "libft.h"

bool	is_pipeline(t_node_data *nodes)
{
	t_uint	i;

	i = 0;
	while (nodes[i].type != NULL_NODE)
	{
		if (nodes[i].type == OPERATOR && nodes[i].operator == PIPE)
			return (true);
		i++;
	}
	return (false);
}

static void	else_(t_command *command)
{
	command->argc = 0;
	command->argv = NULL;
	command->name = ft_strdup("");
	command->is_null = true;
}

t_command	command(t_tk_vector *vector, t_uint command_index)
{
	t_command		command;
	t_redirection	*redirections;
	t_token			token;

	token = tk_vector_get(vector, command_index);
	redirections = get_redirections(vector, command_index);
	command.errorc = false;
	if (redirections && redirections->ptn_de_heredoc_a_la_con_error)
	{
		command.errorc = true;
		return (command);
	}
	command.redirections = redirections;
	if (token.type != NULL_COMMAND)
	{
		command.argc = (int)arg_count(vector, command_index);
		command.argv = get_args(vector, command_index);
		command.name = ft_strdup(token.str);
		command.is_null = false;
	}
	else
		else_(&command);
	command.fd_in = 0;
	command.fd_out = 1;
	return (command);
}
