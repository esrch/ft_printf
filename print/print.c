/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erabbath <erabbath@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 08:51:02 by erabbath          #+#    #+#             */
/*   Updated: 2023/07/12 07:35:44 by erabbath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

ssize_t	print_special(t_specifier *specifier, va_list args, int *len)
{
	if (specifier->conversion == CONVERT_PERCENT)
		return (write_count(1, "%", 1, len));
	if (specifier->conversion == CONVERT_CHAR)
		return (print_c(args, specifier, len));
	if (specifier->conversion == CONVERT_STRING)
		return (print_s(args, specifier, len));
	if (specifier->conversion == CONVERT_INT)
		return (print_d(args, specifier, len));
	if (specifier->conversion == CONVERT_UNSIGNED_INT)
		return (print_u(args, specifier, len));
	if (specifier->conversion == CONVERT_HEX_LOWER
		|| specifier->conversion == CONVERT_HEX_UPPER)
		return (print_x(args, specifier, len));
	if (specifier->conversion == CONVERT_POINTER)
		return (print_p(args, specifier, len));
	return (write_count(1, "?", 1, len));
}
