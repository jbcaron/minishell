/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 00:21:16 by jcaron            #+#    #+#             */
/*   Updated: 2023/03/11 01:05:52 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "verification.h"

bool	operators_ok(t_tk_vector *tokens)
{
	t_uint	i;

	i = 0;
	while (tk_vector_get(tokens, i).type != NULL_TOKEN)
	{
		if (is_operator(tk_vector_get(tokens, i)))
			if (!is_operator_suite(tk_vector_get(tokens, i + 1)))
				return (false);
		i++;
	}
	return (true && !is_operator(tk_vector_get(tokens, 0)));
}

bool	quotes_ok(char *entry)
{
	t_uint	i;

	i = 0;
	while (entry[i])
	{
		if (entry[i] == '\'' || entry[i] == '"')
			if (!second_matched(entry, &i, entry[i]))
				return (false);
		i++;
	}
	return (true);
}

bool	tokens_ok(t_tk_vector *tokens)
{
	return (operators_ok(tokens) && redirections_ok(tokens)
		&& heredocs_ok(tokens));
}
