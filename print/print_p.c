/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_duxXp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erabbath <erabbath@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 08:51:02 by erabbath          #+#    #+#             */
/*   Updated: 2023/07/12 07:35:44 by erabbath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static size_t	count_chars(unsigned long value, size_t digit_count,
	t_specifier *specifier)
{
	size_t	char_count;

	if (value == 0)
		return (5);
	char_count = digit_count + 2;
	if (specifier->precision > (ssize_t)digit_count)
		char_count = specifier->precision + 2;
	if (specifier->sign != SIGN_DEFAULT)
		char_count++;
	return (char_count);
}

static ssize_t	print_prefixes(t_specifier *spec, int *len)
{
	if (print_sign(1, spec->sign, len) < 0)
		return (-1);
	if (print_hex_prefix(spec->conversion == CONVERT_HEX_UPPER, len) < 0)
		return (-1);
	return (0);
}

static ssize_t	print_value(unsigned long value, size_t digit_count,
	t_specifier *spec, int *len)
{
	if (value == 0 && ft_write_count(1, "(nil)", 5, len) < 0)
		return (-1);
	if (value != 0 && uprint_hex_digits(value, digit_count,
			spec->conversion == CONVERT_HEX_UPPER, len) < 0)
		return (-1);
	return (0);
}

ssize_t	print_p(va_list args, t_specifier *spec, int *len)
{
	unsigned long	value;
	size_t			digit_count;
	size_t			char_count;

	value = va_arg(args, unsigned long);
	digit_count = ucount_digits(value, 16, spec->precision);
	char_count = count_chars(value, digit_count, spec);
	if (value != 0 && spec->padding == PADDING_ZERO)
	{
		if (print_prefixes(spec, len) < 0)
			return (-1);
	}
	if (print_left_padding(char_count, spec->padding, spec, len) < 0)
		return (-1);
	if (value != 0 && spec->padding == PADDING_SPACE)
	{
		if (print_prefixes(spec, len) < 0)
			return (-1);
	}
	if (value != 0 && print_precision_padding(digit_count, spec, len) < 0)
		return (-1);
	if (print_value(value, digit_count, spec, len) < 0)
		return (-1);
	return (print_right_padding(char_count, spec->padding, spec, len));
}
