/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 11:03:02 by nomoulin          #+#    #+#             */
/*   Updated: 2023/03/12 16:22:03 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"
#include "libft.h"
#include "token.h"
#include "lexer.h"

void	append(t_node_data *list, t_node_data *command)
{
	while (list->next)
		list = list->next;
	list->next = command;
	command->next = NULL;
}

t_node_data	*pipeline(t_node_data *commands)
{
	t_node_data	*pipeline;
	t_uint		i;

	i = 0;
	pipeline = &commands[0];
	while (commands[i].type != NULL_NODE)
	{
		if (commands[i].type == COMMAND_)
			append(pipeline, &commands[i]);
		i++;
	}
	return (pipeline);
}

t_uint	node_data_array_len(t_node_data *array)
{
	t_uint	i;

	i = 0;
	while (array[i].type != NULL_NODE)
		i++;
	return (i);
}

t_uint	nodes_number(t_tk_vector *vector)
{
	t_token	tok;
	t_uint	n;
	t_uint	i;

	n = 0;
	i = 0;
	while (true)
	{
		tok = tk_vector_get(vector, i);
		if (is_operator(tok) || tok.type == NULL_COMMAND || tok.type == COMMAND)
			n++;
		else if (tok.type == NULL_TOKEN)
			return (n);
		i++;
	}
}
