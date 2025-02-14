/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:09:34 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/26 19:09:35 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	save_i;
	char	*str;

	i = 0;
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	save_i = i;
	i = 0;
	while (s2[i] != '\0')
	{
		str[save_i + i] = s2[i];
		i++;
	}
	str[i + save_i] = '\0';
	return (str);
}
