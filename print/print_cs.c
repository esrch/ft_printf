/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erabbath <erabbath@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 08:51:02 by erabbath          #+#    #+#             */
/*   Updated: 2023/07/12 07:35:44 by erabbath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

ssize_t	print_c(va_list args, t_specifier *specifier, int *len)
{
	unsigned char	c;

	c = va_arg(args, int);
	if (print_left_padding(1, PADDING_SPACE, specifier, len) < 0)
		return (-1);
	if (write_count(1, &c, 1, len) < 0)
		return (-1);
	if (print_right_padding(1, PADDING_SPACE, specifier, len) < 0)
		return (-1);
	return (0);
}

ssize_t	print_s(va_list args, t_specifier *specifier, int *len)
{
	char	*str;
	size_t	char_count;

	str = va_arg(args, char *);
	if (specifier->precision >= 0)
		char_count = ft_strlen_max(str, specifier->precision);
	else
		char_count = ft_strlen(str);
	if (print_left_padding(char_count, PADDING_SPACE, specifier, len) < 0)
		return (-1);
	if (char_count > 0)
		if (write_count(1, str, char_count, len) < 0)
			return (-1);
	if (print_right_padding(char_count, PADDING_SPACE, specifier, len) < 0)
		return (-1);
	return (0);
}
