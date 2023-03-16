/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 11:01:47 by nomoulin          #+#    #+#             */
/*   Updated: 2023/03/12 16:11:15 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"
#include <stdbool.h>

t_token	next_token(char *str)
{
	static t_uint	i = 0;
	t_token			next_token_;
	t_uint			len;

	len = (t_uint)ft_strlen(str);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (i >= len)
	{
		next_token_.type = NULL_TOKEN;
		next_token_.str = NULL;
		i = 0;
	}
	else
		next_token_ = first_token(str, &i);
	return (next_token_);
}

t_tk_vector	*tokens(char *str)
{
	t_tk_vector	*tokens_vector;
	t_token		current_token;

	tokens_vector = tk_vector_init(1);
	while (true)
	{
		current_token = next_token(str);
		append_token(tokens_vector, current_token);
		if (current_token.type == NULL_TOKEN)
			return (tokens_vector);
	}
}
