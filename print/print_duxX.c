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

void	print_d(va_list args, t_specifier *specifier, int *len)
{
	int		value;
	size_t	digit_count;
	size_t	char_count;

	value = va_arg(args, int);
	digit_count = count_digits(value, 10, specifier->precision);
	char_count = digit_count;
	if (specifier->precision > (ssize_t)digit_count)
		char_count = specifier->precision;
	if (value < 0 || (value >= 0 && specifier->sign != SIGN_DEFAULT))
		char_count++;
	if (specifier->padding == PADDING_ZERO)
		print_sign(value, specifier->sign, len);
	print_left_padding(char_count, specifier->padding, specifier, len);
	if (specifier->padding == PADDING_SPACE)
		print_sign(value, specifier->sign, len);
	print_precision_padding(digit_count, specifier, len);
	print_digits(value, digit_count, len);
	print_right_padding(char_count, specifier->padding, specifier, len);
}

void	print_u(va_list args, t_specifier *specifier, int *len)
{
	unsigned int	value;
	size_t			digit_count;
	size_t			char_count;

	value = va_arg(args, unsigned int);
	digit_count = ucount_digits(value, 10, specifier->precision);
	char_count = digit_count;
	if (specifier->precision > (ssize_t)digit_count)
		char_count = specifier->precision;
	print_left_padding(char_count, specifier->padding, specifier, len);
	print_precision_padding(digit_count, specifier, len);
	uprint_digits(value, digit_count, len);
	print_right_padding(char_count, specifier->padding, specifier, len);
}

void	print_x(va_list args, t_specifier *spec, int *len)
{
	unsigned int	value;
	size_t			digit_count;
	size_t			char_count;

	value = va_arg(args, unsigned int);
	digit_count = ucount_digits(value, 16, spec->precision);
	char_count = digit_count;
	if (spec->precision > (ssize_t)digit_count)
		char_count = spec->precision;
	if (value != 0 && spec->is_alternative)
		char_count += 2;
	if (value != 0 && spec->is_alternative && spec->padding == PADDING_ZERO)
		print_hex_prefix(spec->conversion == CONVERT_HEX_UPPER, len);
	print_left_padding(char_count, spec->padding, spec, len);
	if (value != 0 && spec->is_alternative && spec->padding == PADDING_SPACE)
		print_hex_prefix(spec->conversion == CONVERT_HEX_UPPER, len);
	print_precision_padding(digit_count, spec, len);
	uprint_hex_digits(value, digit_count,
		spec->conversion == CONVERT_HEX_UPPER, len);
	print_right_padding(char_count, spec->padding, spec, len);
}
