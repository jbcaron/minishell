/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:16:46 by jcaron            #+#    #+#             */
/*   Updated: 2023/03/12 14:42:15 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STR_IS_H
# define FT_STR_IS_H

# include <stdbool.h>

# define STR_MIN_INT "2147483648"
# define STR_MAX_INT "2147483647"

# define STR_MIN_LONG "9223372036854775808"
# define STR_MAX_LONG "9223372036854775807"

bool	ft_str_is_digit(const char *str);
bool	ft_str_is_int(const char *str);

#endif
