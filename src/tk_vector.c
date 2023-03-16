/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:08:19 by jcaron            #+#    #+#             */
/*   Updated: 2023/03/11 11:14:03 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "tk_vector.h"
#include "token.h"
#include "libft.h"

static const t_token	g_no_token = {NULL_TOKEN, NULL};

t_tk_vector	*tk_vector_init(size_t capacity)
{
	t_tk_vector	*vec;

	vec = ft_malloc(sizeof(*vec));
	vec->data = ft_malloc(sizeof(*vec->data) * capacity);
	vec->size = 0;
	vec->capacity = capacity;
	return (vec);
}

void	tk_vector_destroy(t_tk_vector **vec)
{
	ft_free((*vec)->data);
	ft_free(*vec);
	*vec = NULL;
}

void	tk_vector_resize(t_tk_vector *vec, size_t new_capacity)
{
	vec->data = ft_realloc(vec->data, sizeof(*vec->data) * new_capacity);
	vec->capacity = new_capacity;
}

void	tk_vector_push_back(t_tk_vector *vec, t_token token)
{
	if (vec->size == vec->capacity)
		tk_vector_resize(vec, vec->capacity * 2);
	vec->data[vec->size] = token;
	vec->size++;
}

t_token	tk_vector_pop_back(t_tk_vector *vec)
{
	if (vec->size == 0)
		return (g_no_token);
	vec->size--;
	return (vec->data[vec->size]);
}
