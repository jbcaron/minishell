/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:03:49 by jcaron            #+#    #+#             */
/*   Updated: 2023/03/11 20:29:01 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "browser.h"

int	execute_null_command(t_command *cmd)
{
	if (execute_redirection(cmd) < 0)
		return (1);
	close_if(cmd->fd_in);
	close_if(cmd->fd_out);
	return (0);
}
