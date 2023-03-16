/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browser.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:38:36 by jcaron            #+#    #+#             */
/*   Updated: 2023/03/12 20:33:01 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BROWSER_H
# define BROWSER_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include <errno.h>
# include "libft.h"
# include "node.h"
# include "command.h"
# include "builtin.h"

# define PIPE_IN 1
# define PIPE_OUT 0

typedef struct s_glob
{
	char	**cpy_env;
	int		last_status;
	bool	is_child;
	bool	in_exec;
}	t_glob;

extern t_glob	g_mini;

void	ft_pipe(int fd_pipe[2], int last_fd_pipe_open);
pid_t	ft_fork(void);
int		close_if(int fd);
int		get_real_status(int status);
char	*ft_readline(char *prompt);

bool	is_builtin(char *cmd);

int		execute_and(t_node *node);
int		execute_or(t_node *node);

int		execute_pipe(t_node_data *data);

int		execute_redirection(t_command *cmd);
int		get_fd_input_redirection(t_redirection *redir);
int		get_fd_append_redirection(t_redirection *redir);
int		get_fd_here_doc(t_redirection *redir);
int		get_fd_output_redirection(t_redirection *redir);

int		execute_null_command(t_command *cmd);
int		execute_simple_command(t_command *cmd);
int		execute_command_child(t_command *cmd);

int		execute_builtin(t_command *cmd);

int		browse(t_node *root);

#endif
