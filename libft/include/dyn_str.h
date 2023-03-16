/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dyn_str.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:07:57 by jcaron            #+#    #+#             */
/*   Updated: 2023/01/15 17:38:45 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DYN_STR_H
# define DYN_STR_H

# include <stddef.h>

typedef struct s_dyn_str
{
	size_t	len;
	size_t	capacity;
	char	*str;
}			t_dyn_str;

t_dyn_str	*ds_create(size_t capacity);
void		ds_destroy(t_dyn_str *ds);
size_t		ds_append_char(t_dyn_str *ds, char c);
size_t		ds_append_str(t_dyn_str *ds, char *str);

#endif
