/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:29:24 by jcaron            #+#    #+#             */
/*   Updated: 2023/03/14 23:05:02 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static bool	argument_is_n(char *argv)
{
	if (!argv)
		return (false);
	if (argv[0] == '-' && argv[1] == 'n')
	{
		argv++;
		while (*argv == 'n')
			argv++;
		if (!*argv)
			return (true);
	}
	return (false);
}

int	echo_builtin(t_command cmd)
{
	bool	ret_line;

	ret_line = true;
	cmd.argv++;
	while (*cmd.argv && argument_is_n(*cmd.argv))
	{
		ret_line = false;
		cmd.argv++;
	}
	while (*cmd.argv)
	{
		ft_putstr_fd(*cmd.argv, cmd.fd_out);
		cmd.argv++;
		if (*cmd.argv)
			ft_putstr_fd(" ", cmd.fd_out);
	}
	if (ret_line)
		ft_putstr_fd("\n", cmd.fd_out);
	return (0);
}
