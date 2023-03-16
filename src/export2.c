/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:56:42 by jcaron            #+#    #+#             */
/*   Updated: 2023/03/12 19:22:10 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static bool	print_error_invlid_identifier(char *arg)
{
	ft_putstr_fd("minishell: export: '", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
	g_mini.last_status = 1;
	return (false);
}

bool	is_valid_var(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (false);
	if (!(ft_isalpha(str[i]) || str[i] == '_'))
		return (print_error_invlid_identifier(str));
	while (str[i] && str[i] != '=')
	{
		if (!(ft_isalnum(str[i]) || str[i] == '_'))
			return (print_error_invlid_identifier(str));
		i++;
	}
	if (str[i] != '=')
		return (false);
	return (true);
}

int	export_bis(char *arg)
{
	t_command	cmd;
	char		*argv[3];

	argv[0] = "export";
	argv[1] = arg;
	argv[2] = NULL;
	cmd.argv = argv;
	return (export_builtin(cmd));
}

int	export_new_pwd(void)
{
	char	*new_pwd;
	char	buffer[2048];

	if (!getcwd(buffer, 2048))
	{
		perror("minishell: cd:");
		return (1);
	}
	new_pwd = ft_strjoin("PWD=", buffer);
	export_bis(new_pwd);
	ft_free(new_pwd);
	return (0);
}
