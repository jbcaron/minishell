/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:56:42 by jcaron            #+#    #+#             */
/*   Updated: 2023/03/11 20:42:49 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static int	print_error_path(char *path)
{
	ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
	perror(path);
	return (1);
}

static int	cd_home(char **env)
{
	while (*env && ft_strncmp(*env, "HOME=", 5))
		env++;
	if (!*env)
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", STDERR_FILENO);
		return (1);
	}
	if (chdir(*env + 5) < 0)
		return (print_error_path(*env + 5));
	return (0);
}

static int	cd_absolute(char **argv)
{
	if (chdir(argv[1]) < 0)
		return (print_error_path(argv[1]));
	return (0);
}

static int	cd_relative(char **argv)
{
	char	*path;
	char	*tmp;
	char	buffer[2048];

	if (!getcwd(buffer, 2048))
	{
		ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
		perror(argv[1]);
		return (1);
	}
	tmp = ft_strjoin(buffer, "/");
	path = ft_strjoin(tmp, argv[1]);
	ft_free(tmp);
	if (chdir(path) < 0)
	{
		print_error_path(argv[1]);
		ft_free(path);
		return (1);
	}
	ft_free(path);
	return (0);
}

int	cd_builtin(t_command cmd)
{
	int		status;
	char	*oldpwd;

	oldpwd = get_oldpwd();
	if (!cmd.argv[1])
		status = cd_home(g_mini.cpy_env);
	else if (cmd.argv[1] && cmd.argv[2])
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", STDERR_FILENO);
		return (1);
	}
	else if (cmd.argv[1][0] == '/')
		status = cd_absolute(cmd.argv);
	else
		status = cd_relative(cmd.argv);
	if (status == 0 && oldpwd)
		export_bis(oldpwd);
	export_new_pwd();
	return (status);
}
