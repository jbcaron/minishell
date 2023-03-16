/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:41:26 by jcaron            #+#    #+#             */
/*   Updated: 2023/02/26 14:49:50 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TK_VECTOR_H
# define TK_VECTOR_H

# include <stddef.h>
# include "token.h"

typedef struct s_tk_vector
{
	t_token		*data;
	size_t		size;
	size_t		capacity;
}	t_tk_vector;

t_tk_vector	*tk_vector_init(size_t capacity);
t_token		tk_vector_pop_back(t_tk_vector *vec);
t_token		tk_vector_pop_front(t_tk_vector *vec);
t_token		tk_vector_get(t_tk_vector *vec, size_t index);
void		tk_vector_destroy(t_tk_vector **vec);
void		tk_vector_resize(t_tk_vector *vec, size_t new_capacity);
void		tk_vector_push_back(t_tk_vector *vec, t_token token);
void		tk_vector_push_front(t_tk_vector *vec, t_token token);
void		tk_vector_set(t_tk_vector *vec, size_t index, t_token token);
void		tk_vector_insert(t_tk_vector *vec, size_t index, t_token token);
void		tk_vector_delete(t_tk_vector *vec, size_t index);

#endif
