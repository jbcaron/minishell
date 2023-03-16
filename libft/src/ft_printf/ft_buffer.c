/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:51:12 by jcaron            #+#    #+#             */
/*   Updated: 2023/01/10 15:30:29 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include "ft_printf.h"

void	init_buf(t_buffer *buf)
{
	buf->id = 0;
	buf->print_count = 0;
}

/*
** add a string in a buffer, if the buffer is full he buffer is printed
** and the lengh is return or -1 if an error occurs
*/

ssize_t	fill_buf(t_buffer *buf, const char *str, size_t len)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (i < len)
	{
		buf->data[buf->id] = str[i];
		i++;
		buf->id++;
		if (buf->id >= BUF_SIZE)
		{
			if (empty_buf(buf) < 0)
				return (-1);
		}
	}
	return ((ssize_t)len);
}

ssize_t	empty_buf(t_buffer *buf)
{
	ssize_t	ret;

	if (buf->id == 0)
		return (0);
	ret = write(1, buf->data, buf->id);
	if (ret < 0)
		return (-1);
	buf->print_count += (size_t)ret;
	buf->id = 0;
	return (ret);
}
