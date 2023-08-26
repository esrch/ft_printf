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

void	print_c(va_list args, t_specifier *specifier, int *len)
{
	unsigned char	c;

	c = va_arg(args, int);
	print_left_padding(1, PADDING_SPACE, specifier, len);
	ft_write_count(1, &c, 1, len);
	print_right_padding(1, PADDING_SPACE, specifier, len);
}

static size_t	count_chars_s(char *str, t_specifier *specifier)
{
	if (str == NULL && specifier->precision >= 0 && specifier->precision < 6)
		return (0);
	else if (str == NULL)
		return (6);
	else if (specifier->precision >= 0)
		return (ft_strlen_max(str, specifier->precision));
	return (ft_strlen(str));
}

void	print_s(va_list args, t_specifier *specifier, int *len)
{
	char	*str;
	size_t	char_count;

	str = va_arg(args, char *);
	char_count = count_chars_s(str, specifier);
	print_left_padding(char_count, PADDING_SPACE, specifier, len);
	if (str == NULL && (specifier->precision < 0 || specifier->precision >= 6))
		ft_write_count(1, "(null)", 6, len);
	else if (char_count > 0)
		ft_write_count(1, str, char_count, len);
	print_right_padding(char_count, PADDING_SPACE, specifier, len);
}
