/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_buf_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:42:47 by jcaron            #+#    #+#             */
/*   Updated: 2023/01/10 16:34:22 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_printf.h"

ssize_t	dec_to_buf(int n, t_buffer *buf)
{
	return (put_to_dec(n, buf));
}

ssize_t	udec_to_buf(unsigned int n, t_buffer *buf)
{
	return (put_to_dec(n, buf));
}

ssize_t	low_hex_to_buf(unsigned int n, t_buffer *buf)
{
	return (put_to_hex(n, "0123456789abcdef", buf));
}

ssize_t	up_hex_to_buf(unsigned int n, t_buffer *buf)
{
	return (put_to_hex(n, "0123456789ABCDEF", buf));
}
