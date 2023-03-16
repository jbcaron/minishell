/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 10:58:07 by nomoulin          #+#    #+#             */
/*   Updated: 2023/03/12 18:26:57 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
# define NODE_H

# include "token.h"
# include "command.h"
# include "tk_vector.h"
# include <stdbool.h>

typedef enum e_node_type
{
	OPERATOR,
	COMMAND_,
	NULL_NODE,
}	t_node_type;

typedef struct s_node_data
{
	struct s_node_data	*next;
	t_token_type		operator;
	t_node_type			type;
	t_command			command;
	bool				berror;
	int					priority;
}	t_node_data;

typedef struct s_node
{
	struct s_node	*left;
	struct s_node	*right;
	t_node_data		data;
}	t_node;

t_node_data	node_data(t_tk_vector	*tokens, t_uint index);
t_node_data	*nodes_datas(t_tk_vector *vector);
t_node_data	*pipeline(t_node_data *commands);
t_node		*node(t_node_data *raw_nodes);
t_uint		nodes_number(t_tk_vector *vector);
t_uint		node_data_array_len(t_node_data *array);
t_uint		operators_number(t_node_data *nodes);
bool		is_pipeline(t_node_data *nodes);
t_node_data	next_node(t_tk_vector *vector);
void		append(t_node_data *list, t_node_data *command);
t_uint		lowest_priority_index(t_node_data *nodes);
t_node_data	*left_part(t_node_data *array, t_uint pivot);
t_node_data	*right_part(t_node_data *array, t_uint pivot);
void		creuse(t_node_data *raw_nodes, t_node *this, t_node_type *ret);

#endif