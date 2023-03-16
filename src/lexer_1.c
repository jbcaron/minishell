/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_1.c                                          :+:      :+:    :+:   */
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

static void	if__(t_token *previous_token, t_token *token,
			int *command_before_token)
{
	if (is_redirection(*previous_token))
		token->type = FILE_ID;
	else if (previous_token->type == HERE_DOC)
		token->type = HEREDOC_END;
	else if (*command_before_token)
		token->type = ARG;
	else
	{
		token->type = COMMAND;
		*command_before_token = 1;
	}
}

void	append_token(t_tk_vector *vector, t_token token)
{
	t_token		previous_token;
	t_token		null;
	static int	command_before_token = 0;
	static int	redirections_befrore_token = 0;

	previous_token = tk_vector_get(vector, vector->size - 1);
	if (token.type == STRING)
		if__(&previous_token, &token, &command_before_token);
	else if (is_operator(token) || token.type == NULL_TOKEN)
	{
		if (redirections_befrore_token && !command_before_token)
		{
			null.type = NULL_COMMAND;
			null.str = ft_strdup("");
			tk_vector_push_back(vector, null);
		}
		command_before_token = 0;
		redirections_befrore_token = 0;
	}
	else if (is_redirection(token) || token.type == HERE_DOC)
		redirections_befrore_token = 1;
	tk_vector_push_back(vector, token);
}

static void	if_(t_uint *i, t_dyn_str *token_value, char *str, t_token *token_)
{
	token_value = ds_create(1);
	while (str[*i] && token_type(&str[*i]) == STRING && !is_ws(str[*i]))
	{
		if (str[*i] == '\'')
			ds_append_str(token_value, squoted(str, i));
		else if (str[*i] == '"')
			ds_append_str(token_value, dquoted(str, i));
		else
		{
			ds_append_char(token_value, str[*i]);
			(*i)++;
		}
	}
	token_->str = token_value->str;
	token_->type = STRING;
}

t_token	first_token(char *str, t_uint *i)
{
	t_dyn_str	*token_value;
	t_token		token_;

	token_value = NULL;
	if (str[*i] && token_type(&str[*i]) == STRING)
	{
		if_(i, token_value, str, &token_);
	}
	else
	{
		token_ = token(&str[*i]);
		(*i) += ft_strlen(token_.str);
	}
	return (token_);
}
