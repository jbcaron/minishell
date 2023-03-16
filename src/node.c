/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 11:03:02 by nomoulin          #+#    #+#             */
/*   Updated: 2023/03/15 18:58:28 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"
#include "libft.h"
#include "token.h"
#include "lexer.h"

static void	else_(t_node_data *data, t_token *tok)
{
	data->operator = tok->type;
	data->type = OPERATOR;
	data->priority = operator_priority(tok->type);
}

t_node_data	node_data(t_tk_vector	*tokens, t_uint index)
{
	t_node_data	data;
	t_token		tok;

	tok = tk_vector_get(tokens, index);
	data.berror = false;
	if (tok.type == COMMAND || tok.type == NULL_COMMAND)
	{
		data.command = command(tokens, index);
		if (data.command.errorc)
		{
			data.berror = true;
			return (data);
		}
		data.type = COMMAND_;
		data.operator = NOT_AN_OPERATOR;
		data.priority = 100;
	}
	else if (tok.type == NULL_TOKEN)
		data.type = NULL_NODE;
	else
		else_(&data, &tok);
	data.next = NULL;
	return (data);
}

t_node_data	next_node(t_tk_vector *vector)
{
	static t_uint	i = 0;
	t_node_data		ret;

	while (tk_vector_get(vector, i).type != COMMAND
		&& !is_operator(tk_vector_get(vector, i))
		&& tk_vector_get(vector, i).type != NULL_TOKEN
		&& tk_vector_get(vector, i).type != NULL_COMMAND)
		i++;
	ret = node_data(vector, i++);
	if (ret.berror || ret.type == NULL_NODE)
		i = 0;
	return (ret);
}

t_node_data	*nodes_datas(t_tk_vector *vector)
{
	t_node_data	data;
	t_node_data	*datas;
	t_uint		size;
	t_uint		i;

	i = 0;
	size = nodes_number(vector);
	datas = ft_malloc((size + 1) * sizeof(t_node_data));
	datas[size].type = NULL_NODE;
	while (true)
	{
		data = next_node(vector);
		datas[i] = data;
		i++;
		if (data.berror)
			return (NULL);
		if (data.type == NULL_NODE)
			return (datas);
	}
}

t_uint	operators_number(t_node_data *nodes)
{
	t_uint	i;
	t_uint	n;

	i = 0;
	n = 0;
	while (nodes[i].type != NULL_NODE)
	{
		if (nodes[i].type == OPERATOR && nodes[i].operator != PIPE)
			n++;
		i++;
	}
	return (n);
}
