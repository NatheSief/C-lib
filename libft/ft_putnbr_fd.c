/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:09:04 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/26 19:09:05 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_sign(int n, char *str, size_t *i, int fd)
{
	size_t		modulus;
	short int	maiboyerlpb;

	maiboyerlpb = 0;
	modulus = 1000000000;
	if (n < 0)
	{
		n = -n;
		str[(*i)] = '-';
		(*i)++;
	}
	while (modulus != 0)
	{
		if (n / modulus != 0 || maiboyerlpb != 0)
		{
			str[(*i)++] = (n / modulus) + 48;
			maiboyerlpb++;
		}
		n %= modulus;
		modulus /= 10;
	}
	ft_putstr_fd(str, fd);
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	size_t		i;
	char		str[13];

	i = 0;
	ft_bzero(str, 13);
	if (n == 0)
		ft_putstr_fd("0", fd);
	else if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
		ft_check_sign(n, str, &i, fd);
}
