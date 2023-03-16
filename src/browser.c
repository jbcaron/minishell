/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browser.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 23:35:09 by jcaron            #+#    #+#             */
/*   Updated: 2023/03/12 20:29:37 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "browser.h"

int	browse(t_node *root)
{
	int	status;

	status = 0;
	if (!root)
		return (1);
	else if (root->data.type == COMMAND_)
	{
		if (root->data.next)
			status = execute_pipe(&root->data);
		else
			status = execute_simple_command(&root->data.command);
	}
	else if (root->data.type == OPERATOR)
	{
		if (root->data.operator == AND)
			status = execute_and(root);
		else if (root->data.operator == OR)
			status = execute_or(root);
	}
	g_mini.last_status = status;
	return (status);
}
