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

void	print_special(t_specifier *specifier, va_list args, int *len)
{
	if (specifier->conversion == CONVERT_PERCENT)
		ft_write_count(1, "%", 1, len);
	else if (specifier->conversion == CONVERT_CHAR)
		print_c(args, specifier, len);
	else if (specifier->conversion == CONVERT_STRING)
		print_s(args, specifier, len);
	else if (specifier->conversion == CONVERT_INT)
		print_d(args, specifier, len);
	else if (specifier->conversion == CONVERT_UNSIGNED_INT)
		print_u(args, specifier, len);
	else if (specifier->conversion == CONVERT_HEX_LOWER
		|| specifier->conversion == CONVERT_HEX_UPPER)
		print_x(args, specifier, len);
	else if (specifier->conversion == CONVERT_POINTER)
		print_p(args, specifier, len);
}
