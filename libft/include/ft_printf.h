/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:29:26 by jcaron            #+#    #+#             */
/*   Updated: 2023/01/10 16:02:04 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

# define BUF_SIZE 32

typedef struct s_buffer
{
	size_t	id;
	size_t	print_count;
	char	data[BUF_SIZE];
}	t_buffer;

int		ft_printf(const char *format, ...);

ssize_t	put_to_hex(unsigned long n, const char *hex_base, t_buffer *buf);
ssize_t	put_to_dec(long n, t_buffer *buf);

ssize_t	char_to_buf(int c, t_buffer *buf);
ssize_t	str_to_buf(char *s, t_buffer *buf);
ssize_t	dec_to_buf(int n, t_buffer *buf);
ssize_t	udec_to_buf(unsigned int n, t_buffer *buf);
ssize_t	low_hex_to_buf(unsigned int n, t_buffer *buf);
ssize_t	up_hex_to_buf(unsigned int n, t_buffer *buf);
ssize_t	ptr_to_buf(void *p, t_buffer *buf);

void	init_buf(t_buffer *buf);
ssize_t	fill_buf(t_buffer *buf, const char *str, size_t len);
ssize_t	empty_buf(t_buffer *buf);

#endif
