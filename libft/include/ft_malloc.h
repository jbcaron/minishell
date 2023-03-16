/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:12:55 by jcaron            #+#    #+#             */
/*   Updated: 2023/03/12 18:01:52 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <stddef.h>
# include <stdbool.h>
# include <signal.h>

typedef struct s_malloc_node
{
	int						bucket;
	size_t					size;
	struct s_malloc_node	*prev;
	struct s_malloc_node	*next;
}			t_malloc_node;

t_malloc_node	*get_last_node(t_malloc_node *node, bool push);
void			ft_malloc_node_add(t_malloc_node *node, size_t size);
void			ft_malloc_node_del(t_malloc_node *node);
void			*ft_malloc(size_t size);
void			ft_free(void *data);
int				ft_mem_bucket(int ac_bucket);
void			ft_free_bucket(int bucket);
void			*ft_realloc(void *old_data, size_t size);
void			ft_free_all(void);
size_t			ft_tot_alloc(void);

#endif
