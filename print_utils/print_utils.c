/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erabbath <erabbath@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 08:51:02 by erabbath          #+#    #+#             */
/*   Updated: 2023/07/12 07:35:44 by erabbath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

ssize_t	ft_write_count(int fd, void *buf, size_t nbyte, int *len)
{
	ssize_t	result;

	if (*len < 0)
		return (*len);
	result = write(fd, buf, nbyte);
	if (result < 0)
		*len = result;
	else
		*len += result;
	return (result);
}

static ssize_t	print_mult_chars(char *c_50x, size_t n, int *len)
{
	while (n > 50)
	{
		if (ft_write_count(1, c_50x, 50, len) < 0)
			return (-1);
		n -= 50;
	}
	if (!n)
		return (n);
	return (ft_write_count(1, c_50x, n, len));
}

ssize_t	print_spaces(size_t n, int *len)
{
	static char	*spaces = "                                                  ";

	return (print_mult_chars(spaces, n, len));
}

ssize_t	print_zeros(size_t n, int *len)
{
	static char	*zeros = "00000000000000000000000000000000000000000000000000";

	return (print_mult_chars(zeros, n, len));
}
