/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_vector_2.c                                      :+:      :+:    :+:   */
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

void	tk_vector_delete(t_tk_vector *vec, size_t index)
{
	if (index >= vec->size)
		return ;
	ft_memmove(&vec->data[index], &vec->data[index + 1], \
		sizeof(*vec->data) * (vec->size - index - 1));
	vec->size--;
}
