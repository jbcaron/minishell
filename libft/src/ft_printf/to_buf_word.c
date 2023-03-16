/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_buf_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:42:47 by jcaron            #+#    #+#             */
/*   Updated: 2023/01/10 15:48:23 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_printf.h"
#include "ft_str.h"

ssize_t	char_to_buf(int c, t_buffer *buf)
{
	char	new_c;

	new_c = (char)c;
	return (fill_buf(buf, &new_c, 1));
}

ssize_t	str_to_buf(char *s, t_buffer *buf)
{
	if (!s)
	{
		return (fill_buf(buf, "(null)", 6));
	}
	return (fill_buf(buf, s, ft_strlen(s)));
}
