/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 11:00:17 by nomoulin          #+#    #+#             */
/*   Updated: 2023/03/12 16:16:13 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include "token.h"
# include "memory.h"
# include "tk_vector.h"
# include <stdbool.h>

typedef struct s_redirection
{
	struct s_redirection	*next;
	t_token_type			type;
	bool					ptn_de_heredoc_a_la_con_error;
	char					*heredoc_string;
	char					*redirection_file;
}	t_redirection;

typedef struct s_command
{
	t_redirection		*redirections;
	bool				is_null;
	bool				errorc;
	char				*name;
	char				**argv;
	char				**env;
	int					argc;
	int					fd_in;
	int					fd_out;
}	t_command;

t_redirection	*redirection(t_tk_vector *vector, t_uint index);
t_command		command(t_tk_vector *vector, t_uint command_index);
t_uint			arg_count(t_tk_vector *vector, t_uint command_index);
t_uint			command_start(t_tk_vector *vector, t_uint command_index);
t_uint			command_end(t_tk_vector *vector, t_uint command_index);
char			*get_heredoc(char *delimitor);
char			*eval_variable_in_heredoc(char *str);
char			**get_args(t_tk_vector *vector, t_uint command_index);
void			append_redirection(t_redirection **list, t_redirection *new);
t_redirection	*get_redirections(t_tk_vector *vector, t_uint command_index);

#endif
