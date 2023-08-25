/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils_digits.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erabbath <erabbath@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 08:51:02 by erabbath          #+#    #+#             */
/*   Updated: 2023/07/12 07:35:44 by erabbath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	count_digits(long long value, int base, int precision)
{
	size_t	i;

	if (value == 0 && precision != 0)
		return (1);
	i = 0;
	while (value)
	{
		i++;
		value /= base;
	}
	return (i);
}

size_t	ucount_digits(unsigned long long value, int base, int precision)
{
	size_t	i;

	if (value == 0 && precision != 0)
		return (1);
	i = 0;
	while (value)
	{
		i++;
		value /= base;
	}
	return (i);
}

ssize_t	print_digits(long long value, size_t digit_count, int *len)
{
	size_t	i;
	char	buffer[19];

	if (digit_count == 0)
		return (0);
	if (value > 0)
		value = -value;
	i = digit_count;
	while (i--)
	{
		buffer[i] = "0123456789"[-(value % 10)];
		value /= 10;
	}
	return (write_count(1, buffer, digit_count, len));
}

ssize_t	uprint_digits(unsigned long long value, size_t digit_count, int *len)
{
	size_t	i;
	char	buffer[20];

	if (digit_count == 0)
		return (0);
	i = digit_count;
	while (i--)
	{
		buffer[i] = "0123456789"[value % 10];
		value /= 10;
	}
	return (write_count(1, buffer, digit_count, len));
}

ssize_t	uprint_hex_digits(unsigned long long value, size_t digit_count,
		int is_upper, int *len)
{
	size_t	i;
	char	buffer[20];
	char	*digits;

	if (is_upper)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	if (digit_count == 0)
		return (0);
	i = digit_count;
	while (i--)
	{
		buffer[i] = digits[value % 16];
		value /= 16;
	}
	return (write_count(1, buffer, digit_count, len));
}
