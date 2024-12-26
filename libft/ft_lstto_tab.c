/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstto_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 16:32:38 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/26 17:23:59 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_lstto_tab(t_list **head)
{
	char	**tab;
	int		i;
	int		size;
	t_list	*tmp;

	if (!head)
		return (NULL);
	tmp = *head;
	if (!tmp)
		return (NULL);
	size = ft_lstlen(head);
	tab = malloc(sizeof(char *) * size);
	if (!tab)
		return (NULL);
	i = -1;
	while (++i < size && tmp)
	{
		tab[i] = ft_strdup((char *)tmp->content);
		if (!tab[i])
			return (free_tab((void **)tab), NULL);
		tmp = tmp->next;
	}
	tab[i] = NULL;
	return (tab);
}
