/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:17:53 by nsiefert          #+#    #+#             */
/*   Updated: 2024/05/04 12:24:07 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_fd.h"

int	ft_fd_printchar(int c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

static int	ft_fd_formats(int fd, va_list args, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_fd_printchar(fd, va_arg(args, int));
	else if (format == 's')
		print_length += ft_fd_printstr(fd, va_arg(args, char *));
	else if (format == 'p')
		print_length += ft_fd_print_ptr(fd, va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		print_length += ft_fd_printnbr(fd, va_arg(args, int));
	else if (format == 'u')
		print_length += ft_fd_print_unsigned(fd, va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_length += ft_fd_print_hex(fd, va_arg(args, unsigned int), format);
	else if (format == '%')
		print_length += ft_fd_printpercent();
	return (print_length);
}

int	ft_printf_fd(int fd, const char *str, ...)
{
	int		i;
	va_list	args;
	int		print_length;

	i = 0;
	print_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_length += ft_fd_formats(fd, args, str[i + 1]);
			i++;
		}
		else
			print_length += ft_fd_printchar(fd, str[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}
