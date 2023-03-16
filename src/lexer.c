/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 11:01:47 by nomoulin          #+#    #+#             */
/*   Updated: 2023/03/11 11:11:18 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"
#include <stdbool.h>

char	*dquoted(char *str, t_uint *i)
{
	t_dyn_str	*acc;

	acc = ds_create(1);
	acc->str[0] = 0;
	(*i)++;
	while (str[*i] != '"')
	{
		ds_append_char(acc, str[*i]);
		(*i)++;
	}
	(*i)++;
	return (acc->str);
}

char	*squoted(char *str, t_uint *i)
{
	t_dyn_str	*acc;

	acc = ds_create(1);
	acc->str[0] = 0;
	(*i)++;
	while (str[*i] != '\'')
	{
		ds_append_char(acc, str[*i]);
		(*i)++;
	}
	(*i)++;
	return (acc->str);
}

int	is_operator(t_token token)
{
	return (token.type == SEMICOLON || token.type == OR || token.type == AND
		|| token.type == PIPE);
}

int	is_redirection(t_token token)
{
	return (token.type == APPEND_OPERATOR || token.type == OUTPUT_REDIRECTION
		|| token.type == INPUT_REDIRECTION);
}

bool	is_ws(char chr)
{
	return (chr == ' ' || chr == '\t');
}
