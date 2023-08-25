/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils_padding.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erabbath <erabbath@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 08:51:02 by erabbath          #+#    #+#             */
/*   Updated: 2023/07/12 07:35:44 by erabbath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static ssize_t	print_padding(size_t char_count, t_padding padding,
		t_specifier *specifier, int *len)
{
	if (specifier->min_width <= (int) char_count)
		return (0);
	if (padding == PADDING_ZERO)
		return (print_zeros(specifier->min_width - char_count, len));
	return (print_spaces(specifier->min_width - char_count, len));
}

ssize_t	print_left_padding(size_t char_count, t_padding padding,
		t_specifier *specifier, int *len)
{
	if (specifier->alignment != ALIGN_RIGHT)
		return (0);
	return (print_padding(char_count, padding, specifier, len));
}

ssize_t	print_right_padding(size_t char_count, t_padding padding,
		t_specifier *specifier, int *len)
{
	if (specifier->alignment != ALIGN_LEFT)
		return (0);
	return (print_padding(char_count, padding, specifier, len));
}

ssize_t	print_precision_padding(size_t digit_count, t_specifier *specifier,
		int *len)
{
	if (specifier->precision <= (ssize_t)digit_count)
		return (0);
	return (print_zeros((size_t)specifier->precision - digit_count, len));
}
