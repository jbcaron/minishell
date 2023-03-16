/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 10:58:07 by nomoulin          #+#    #+#             */
/*   Updated: 2023/02/26 14:46:53 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# define KEYWORDS_NUMBER 8

typedef enum e_token_type
{
	AND,
	OR,
	APPEND_OPERATOR,
	HERE_DOC,
	PIPE,
	OUTPUT_REDIRECTION,
	INPUT_REDIRECTION,
	SEMICOLON,
	STRING,
	COMMAND,
	ARG,
	FILE_ID,
	HEREDOC_END,
	NULL_COMMAND,
	NULL_TOKEN,
	NOT_AN_OPERATOR
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*str;
}	t_token;

typedef unsigned int	t_uint;

t_token_type	token_type(char *str);
t_token			token(char *str);
void			delete_token(t_token token);
int				operator_priority(t_token_type	type);
int				is_redirection(t_token token);
int				is_operator(t_token token);

void			print_token(t_token token);

#endif
