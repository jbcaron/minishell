/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 10:59:16 by nomoulin          #+#    #+#             */
/*   Updated: 2023/03/15 18:56:45 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "tk_vector.h"
#include "libft.h"
#include "node.h"

t_uint	arg_count(t_tk_vector *vector, t_uint command_index)
{
	t_uint	count;
	t_uint	i;

	i = command_index;
	count = 0;
	while (!is_operator(tk_vector_get(vector, i)) && \
		tk_vector_get(vector, i).type != NULL_TOKEN)
	{
		if (tk_vector_get(vector, i).type == ARG)
			count++;
		i++;
	}
	return (count);
}

char	**get_args(t_tk_vector *vector, t_uint command_index)
{
	t_uint	j;
	t_uint	i;
	t_uint	ac;
	char	**av;

	ac = arg_count(vector, command_index);
	av = ft_malloc((ac + 2) * sizeof(char *));
	av[0] = ft_strdup(tk_vector_get(vector, command_index).str);
	av[ac + 1] = NULL;
	i = command_index;
	j = 1;
	while (!is_operator(tk_vector_get(vector, i)) && \
		tk_vector_get(vector, i).type != NULL_TOKEN)
	{
		if (tk_vector_get(vector, i).type == ARG)
		{
			av[j] = ft_strdup(tk_vector_get(vector, i).str);
			j++;
		}
		i++;
	}
	return (av);
}

t_uint	command_start(t_tk_vector *vector, t_uint command_index)
{
	t_uint	i;

	i = command_index;
	while (!is_operator(tk_vector_get(vector, i)) && i)
		i--;
	return (i);
}

t_uint	command_end(t_tk_vector *vector, t_uint command_index)
{
	t_uint	i;

	i = command_index;
	while (!is_operator(tk_vector_get(vector, i)) && \
		tk_vector_get(vector, i).type != NULL_TOKEN)
		i++;
	return (i);
}

t_redirection	*redirection(t_tk_vector *vector, t_uint index)
{
	t_redirection	*redirection;
	t_token			redirect;
	char			*redirection_arg;
	char			*saloperie_de_heredoc;

	redirection = ft_malloc(sizeof(t_redirection));
	redirection->next = NULL;
	redirect = tk_vector_get(vector, index);
	redirection_arg = ft_strdup(tk_vector_get(vector, index + 1).str);
	redirection->type = redirect.type;
	redirection->ptn_de_heredoc_a_la_con_error = false;
	if (redirection->type == HERE_DOC)
	{
		saloperie_de_heredoc = get_heredoc(redirection_arg);
		if (!saloperie_de_heredoc)
		{
			redirection->ptn_de_heredoc_a_la_con_error = true;
			return (redirection);
		}
		redirection->heredoc_string = saloperie_de_heredoc;
	}
	else
		redirection->redirection_file = redirection_arg;
	return (redirection);
}
