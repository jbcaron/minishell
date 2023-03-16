/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 00:21:16 by jcaron            #+#    #+#             */
/*   Updated: 2023/03/13 23:02:27 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERIFICATION_H
# define VERIFICATION_H

# include "libft.h"
# include "lexer.h"
# include "token.h"

t_uint	occurences(char *str, char chr);
bool	second_matched(char *str, t_uint *i, char chr);
bool	is_operator_suite(t_token token);
bool	redirections_ok(t_tk_vector *tokens);
bool	heredocs_ok(t_tk_vector *tokens);
bool	operators_ok(t_tk_vector *tokens);
bool	quotes_ok(char *entry);
bool	tokens_ok(t_tk_vector *tokens);

#endif
