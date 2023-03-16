/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:19:59 by jcaron            #+#    #+#             */
/*   Updated: 2023/03/12 14:47:52 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "stdio.h"
#include "libft.h"

static const char	*g_keyword_value[KEYWORDS_NUMBER] = {
	"&&",
	"||",
	">>",
	"<<",
	"|",
	">",
	"<",
	";"
};

t_token_type	token_type(char *str)
{
	t_uint	i;

	i = 0;
	while (i < KEYWORDS_NUMBER)
	{
		if (!ft_strncmp(g_keyword_value[i], str, ft_strlen(g_keyword_value[i])))
			return (i);
		i++;
	}
	return (STRING);
}

t_token	token(char *str)
{
	t_token	ledittoken;

	ledittoken.type = NULL_TOKEN;
	ledittoken.str = NULL;
	if (!str)
		return (ledittoken);
	ledittoken.type = token_type(str);
	if (ledittoken.type != STRING)
		ledittoken.str = ft_strdup(g_keyword_value[ledittoken.type]);
	else
	{
		ledittoken.str = ft_strdup(str);
	}
	return (ledittoken);
}

int	operator_priority(t_token_type	type)
{
	if (type == SEMICOLON)
		return (-1);
	if (type == AND)
		return (0);
	if (type == OR)
		return (1);
	if (type == PIPE)
		return (3);
	if (type == INPUT_REDIRECTION || type == OUTPUT_REDIRECTION
		|| type == APPEND_OPERATOR)
		return (2);
	if (type == HERE_DOC)
		return (4);
	return (5);
}

void	delete_token(t_token token)
{
	ft_free(token.str);
}
