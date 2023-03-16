/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 10:58:07 by nomoulin          #+#    #+#             */
/*   Updated: 2023/03/12 16:09:50 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "tk_vector.h"
# include "token.h"
# include <stdbool.h>

t_tk_vector	*tokens(char *str);
t_token		next_token(char *str);
t_token		first_token(char *str, t_uint *i);
void		append_token(t_tk_vector *vector, t_token token);
bool		is_ws(char chr);
char		*squoted(char *str, t_uint *i);
char		*dquoted(char *str, t_uint *i);

#endif
