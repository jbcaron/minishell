/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:56:42 by jcaron            #+#    #+#             */
/*   Updated: 2023/03/11 20:43:07 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

char	*get_oldpwd(void)
{
	char	*oldpwd;
	char	buffer[2048];

	if (!getcwd(buffer, 2048))
		return (NULL);
	oldpwd = ft_strjoin("OLDPWD=", buffer);
	return (oldpwd);
}
