/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:04:27 by jcaron            #+#    #+#             */
/*   Updated: 2023/01/10 15:24:53 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include "ft_printf.h"

static int	is_arg(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' \
			|| c == 'u' || c == 'x' || c == 'X');
}

static ssize_t	ft_arg(char c, va_list args, t_buffer *buf)
{
	if (c == 'c')
		return (char_to_buf(va_arg(args, int), buf));
	if (c == 's')
		return (str_to_buf(va_arg(args, char *), buf));
	if (c == 'p')
		return (ptr_to_buf(va_arg(args, void *), buf));
	if (c == 'd')
		return (dec_to_buf(va_arg(args, int), buf));
	if (c == 'i')
		return (dec_to_buf(va_arg(args, int), buf));
	if (c == 'u')
		return (udec_to_buf(va_arg(args, unsigned int), buf));
	if (c == 'x')
		return (low_hex_to_buf(va_arg(args, unsigned int), buf));
	if (c == 'X')
		return (up_hex_to_buf(va_arg(args, unsigned int), buf));
	return (-1);
}

static ssize_t	print_format(const char *str, va_list args, t_buffer *buf)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && is_arg(str[i + 1]))
		{
			if (ft_arg(str[i + 1], args, buf) < 0)
				return (-1);
			i += 2;
		}
		else if (str[i] == '%' && str[i + 1] == '%')
		{
			if (fill_buf(buf, &str[i], 1) < 0)
				return (-1);
			i += 2;
		}
		else if (str[i] == '%')
			return (-1);
		else
			if (fill_buf(buf, &str[i++], 1) < 0)
				return (-1);
	}
	return ((int)buf->print_count);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	t_buffer		buf;

	init_buf(&buf);
	va_start(args, format);
	if (print_format(format, args, &buf) < 0)
	{
		va_end(args);
		return (-1);
	}
	if (empty_buf(&buf) < 0)
	{
		va_end(args);
		return (-1);
	}
	va_end(args);
	return ((int)buf.print_count);
}
