/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:47:57 by jcaron            #+#    #+#             */
/*   Updated: 2023/03/12 20:29:50 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "browser.h"

int	execute_and(t_node *node)
{
	int			status;

	status = browse(node->left);
	if (!status)
		status = browse(node->right);
	return (status);
}

int	execute_or(t_node *node)
{
	int			status;

	status = browse(node->left);
	if (status)
		status = browse(node->right);
	return (status);
}
