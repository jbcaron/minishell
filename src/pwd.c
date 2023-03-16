/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:23:56 by jcaron            #+#    #+#             */
/*   Updated: 2023/03/11 16:49:42 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	pwd_builtin(t_command cmd)
{
	char	buffer[2048];

	(void)cmd;
	if (!getcwd(buffer, 2048))
	{
		ft_putstr_fd("minishell: pwd:", STDERR_FILENO);
		perror("");
		return (1);
	}
	ft_putstr_fd(buffer, cmd.fd_out);
	ft_putstr_fd("\n", cmd.fd_out);
	return (0);
}
