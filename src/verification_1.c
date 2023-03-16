/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 00:21:16 by jcaron            #+#    #+#             */
/*   Updated: 2023/03/13 23:07:06 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "verification.h"

t_uint	occurences(char *str, char chr)
{
	t_uint	count;
	t_uint	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == chr)
			count++;
		i++;
	}
	return (count);
}

bool	second_matched(char *str, t_uint *i, char chr)
{
	(*i)++;
	while (str[*i] != chr)
	{
		if (!str[*i])
			return (false);
		(*i)++;
	}
	return (true);
}

bool	is_operator_suite(t_token token)
{
	return (token.type == COMMAND || token.type == NULL_COMMAND
		|| is_redirection(token) || token.type == HERE_DOC);
}

bool	redirections_ok(t_tk_vector *tokens)
{
	t_uint	i;

	i = 0;
	while (tk_vector_get(tokens, i).type != NULL_TOKEN)
	{
		if (is_redirection(tk_vector_get(tokens, i)))
			if (tk_vector_get(tokens, i + 1).type != FILE_ID)
				return (false);
		i++;
	}
	return (true);
}

bool	heredocs_ok(t_tk_vector *tokens)
{
	t_uint	i;

	i = 0;
	while (tk_vector_get(tokens, i).type != NULL_TOKEN)
	{
		if (tk_vector_get(tokens, i).type == HERE_DOC)
			if (tk_vector_get(tokens, i + 1).type != HEREDOC_END)
				return (false);
		i++;
	}
	return (true);
}
