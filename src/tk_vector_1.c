/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_vector_1.c                                      :+:      :+:    :+:   */
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

void	tk_vector_push_front(t_tk_vector *vec, t_token token)
{
	if (vec->size == vec->capacity)
		tk_vector_resize(vec, vec->capacity * 2);
	ft_memmove(&vec->data[1], vec->data, sizeof(*vec->data) * vec->size);
	vec->size++;
	vec->data[0] = token;
}

t_token	tk_vector_pop_front(t_tk_vector *vec)
{
	t_token	first_token;

	if (vec->size == 0)
		return (g_no_token);
	first_token = vec->data[0];
	vec->size--;
	ft_memmove(vec->data, &vec->data[1], sizeof(*vec->data) * vec->size);
	return (first_token);
}

t_token	tk_vector_get(t_tk_vector *vec, size_t index)
{
	if (index >= vec->size)
		return (g_no_token);
	return (vec->data[index]);
}

void	tk_vector_set(t_tk_vector *vec, size_t index, t_token token)
{
	if (index >= vec->size)
		return ;
	vec->data[index] = token;
}

void	tk_vector_insert(t_tk_vector *vec, size_t index, t_token token)
{
	if (index >= vec->size)
		return ;
	if (vec->size == vec->capacity)
		tk_vector_resize(vec, vec->capacity * 2);
	ft_memmove(&vec->data[index + 1], &vec->data[index], \
		sizeof(*vec->data) * (vec->size - index));
	vec->size++;
	vec->data[index] = token;
}
