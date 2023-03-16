/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:03:29 by jcaron            #+#    #+#             */
/*   Updated: 2023/03/11 20:43:17 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"
# include "command.h"
# include "browser.h"

int		echo_builtin(t_command cmd);

int		cd_builtin(t_command cmd);
char	*get_oldpwd(void);

int		pwd_builtin(t_command cmd);

int		env_builtin(t_command cmd);

int		export_builtin(t_command cmd);
bool	is_valid_var(char *str);
int		export_bis(char *arg);
int		export_new_pwd(void);

int		unset_builtin(t_command cmd);

int		exit_builtin(t_command cmd);

#endif
