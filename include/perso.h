/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perso.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 08:02:38 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/15 14:55:39 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERSO_H
# define PERSO_H

# include "libft.h"

int	ft_countchar(char *str, char c);
int ft_tabsize(char **tab);
void    free_tab(void   **tab);

#endif 