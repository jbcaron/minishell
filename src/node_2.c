/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 11:03:02 by nomoulin          #+#    #+#             */
/*   Updated: 2023/03/15 18:49:57 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"
#include "libft.h"
#include "token.h"
#include "lexer.h"

t_uint	lowest_priority_index(t_node_data *nodes)
{
	int		lowest_priority;
	t_uint	lowest_priority_index;
	t_uint	i;

	lowest_priority = 100;
	lowest_priority_index = 0;
	i = 0;
	while (nodes[i].type != NULL_NODE)
	{
		if (nodes[i].type == OPERATOR && nodes[i].operator != PIPE)
		{
			if (nodes[i].priority <= lowest_priority)
			{
				lowest_priority = nodes[i].priority;
				lowest_priority_index = i;
			}
		}
		i++;
	}
	return (lowest_priority_index);
}

t_node_data	*left_part(t_node_data *array, t_uint pivot)
{
	array[pivot].type = NULL_NODE;
	return (array);
}

t_node_data	*right_part(t_node_data *array, t_uint pivot)
{
	array[pivot].type = NULL_NODE;
	return (&array[pivot + 1]);
}

void	creuse(t_node_data *raw_nodes, t_node *this, t_node_type *ret)
{
	t_uint		highest_operator_index;

	highest_operator_index = lowest_priority_index(raw_nodes);
	this->data = raw_nodes[highest_operator_index];
	*ret = this->data.type;
	this->left = node(left_part(raw_nodes, highest_operator_index));
	this->right = node(right_part(raw_nodes, highest_operator_index));
	this->data.type = *ret;
}

t_node	*node(t_node_data *raw_nodes)
{
	t_node_type	ret;
	t_node		*this;

	if (!raw_nodes)
		return (NULL);
	this = ft_malloc(sizeof(t_node));
	if (node_data_array_len(raw_nodes) > 1 && operators_number(raw_nodes))
	{
		creuse(raw_nodes, this, &ret);
	}
	else if (is_pipeline(raw_nodes))
	{
		this->data = *pipeline(raw_nodes);
		this->left = NULL;
		this->right = NULL;
	}
	else
	{
		this->data = raw_nodes[0];
		this->left = NULL;
		this->right = NULL;
	}
	return (this);
}
