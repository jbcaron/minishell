/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:56:22 by jcaron            #+#    #+#             */
/*   Updated: 2023/03/13 23:02:21 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include <signal.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"
# include "browser.h"
# include "builtin.h"
# include "lexer.h"

char	*eval_variable_in_str(char *str);

bool	quotes_ok(char *entry);

bool	tokens_ok(t_tk_vector *tokens);

void	handle_sigint(int sig);
void	handle_sigquit(int sig);

void	init_var(char **env);

#endif
