/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_to.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:42:36 by jcaron            #+#    #+#             */
/*   Updated: 2023/01/10 15:31:48 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_printf.h"
#include "ft_str.h"

ssize_t	put_to_hex(unsigned long n, const char *hex_base, t_buffer *buf)
{
	unsigned int	i;
	char			str[16];

	if (ft_strlen(hex_base) != 16)
		return (-1);
	if (n == 0)
		return (fill_buf(buf, "0", 1));
	i = 15;
	while (n)
	{
		str[i] = hex_base[n & 0xf];
		n >>= 4 ;
		i--;
	}
		i++;
	return (fill_buf(buf, &str[i], 16 - i));
}

ssize_t	put_to_dec(long n, t_buffer *buf)
{
	unsigned int	i;
	int				is_neg;
	char			str[20];

	is_neg = 0;
	if (n == 0)
		return (fill_buf(buf, "0", 1));
	if (n < 0)
	{
		is_neg = 1;
		n *= -1;
	}
	i = 19;
	while (n)
	{
		str[i--] = n % 10 + '0';
		n /= 10;
	}
	if (is_neg)
		str[i--] = '-';
	i++;
	return (fill_buf(buf, &str[i], 20 - i));
}
