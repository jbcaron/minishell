/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_buf_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:42:47 by jcaron            #+#    #+#             */
/*   Updated: 2023/01/10 16:34:35 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_printf.h"

ssize_t	ptr_to_buf(void *p, t_buffer *buf)
{
	if (!p)
		return (fill_buf(buf, "(nil)", 5));
	if (fill_buf(buf, "0x", 2) < 0)
		return (-1);
	return (put_to_hex((size_t)p, "0123456789abcdef", buf));
}
