/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:53:49 by jcaron            #+#    #+#             */
/*   Updated: 2023/03/12 18:03:36 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "browser.h"

int	get_fd_input_redirection(t_redirection *redir)
{
	int		file_fd;

	file_fd = open(redir->redirection_file, O_RDONLY);
	if (file_fd < 0)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		perror(redir->redirection_file);
		return (-1);
	}
	return (file_fd);
}

int	get_fd_append_redirection(t_redirection *redir)
{
	int		file_fd;

	file_fd = open(redir->redirection_file, O_WRONLY | O_CREAT
			| O_APPEND, 0666);
	if (file_fd < 0)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		perror(redir->redirection_file);
		return (-1);
	}
	return (file_fd);
}

int	get_fd_here_doc(t_redirection *redir)
{
	int		fd_pipe[2];

	ft_pipe(fd_pipe, 0);
	ft_putstr_fd(redir->heredoc_string, fd_pipe[PIPE_IN]);
	close_if(fd_pipe[PIPE_IN]);
	return (fd_pipe[PIPE_OUT]);
}

int	get_fd_output_redirection(t_redirection *redir)
{
	int		file_fd;

	file_fd = open(redir->redirection_file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (file_fd < 0)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		perror(redir->redirection_file);
		return (-1);
	}
	return (file_fd);
}
