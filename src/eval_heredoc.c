/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:49:39 by jcaron            #+#    #+#             */
/*   Updated: 2023/03/13 23:08:44 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "browser.h"

static char	*get_variable_value(char *var, char **env)
{
	size_t	i_env;

	i_env = 0;
	while (g_mini.cpy_env[i_env])
	{
		if (!ft_strncmp(env[i_env], var, ft_strlen(var)))
			return (ft_strdup(env[i_env] + ft_strlen(var)));
		i_env++;
	}
	return (ft_calloc(1, sizeof(char)));
	return (0);
}

static char	*get_variable_name_equal(char *str)
{
	size_t	size;
	char	*variable;

	size = 0;
	while (ft_isalnum(str[size]) || str[size] == '_')
		size++;
	variable = ft_calloc(size + 2, sizeof(*variable));
	ft_memcpy(variable, str, size);
	variable[size] = '=';
	return (variable);
}

static char	*ft_itoa(int nb)
{
	char	str[12];
	int		i;
	bool	is_neg;

	is_neg = false;
	i = 11;
	str[i] = '\0';
	str[i - 1] = '0';
	if (nb == 0)
		return (ft_strdup(&str[i - 1]));
	if (nb < 0)
	{
		is_neg = true;
		nb *= -1;
	}
	while (nb)
	{
		str[--i] = nb % 10 + '0';
		nb /= 10;
	}
	if (is_neg)
		str[--i] = '-';
	return (ft_strdup(&str[i]));
}

static char	*eval_dollar(char *str, t_dyn_str *dyn_str)
{
	char		*var_name;
	char		*var_value;

	if (*(str + 1) == '\0' || *(str + 1) == '"' || *(str + 1) == ' '
		|| *(str + 1) == '\t')
		ds_append_char(dyn_str, *str);
	else
	{
		str++;
		if (*str == '?')
			ds_append_str(dyn_str, ft_itoa(g_mini.last_status));
		else if (ft_isalpha(*str) || *str == '_')
		{
			var_name = get_variable_name_equal(str);
			str += ft_strlen(var_name) - 2;
			var_value = get_variable_value(var_name, g_mini.cpy_env);
			ft_free(var_name);
			ds_append_str(dyn_str, var_value);
			ft_free(var_value);
		}
	}
	return (str);
}

char	*eval_variable_in_heredoc(char *str)
{
	t_dyn_str	*dyn_str;

	dyn_str = ds_create(1);
	while (*str)
	{
		if (*str == '$')
			str = eval_dollar(str, dyn_str);
		else
			ds_append_char(dyn_str, *str);
		str++;
	}
	return (dyn_str->str);
}
