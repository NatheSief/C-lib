/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:54:24 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/25 21:16:26 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perso.h"

//  Free a 2 dimensions tab of pointers
void    free_tab(void   **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
