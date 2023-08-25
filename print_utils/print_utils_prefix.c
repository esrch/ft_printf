/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erabbath <erabbath@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 08:51:02 by erabbath          #+#    #+#             */
/*   Updated: 2023/07/12 07:35:44 by erabbath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

ssize_t	print_sign(int sign, t_sign sign_char, int *len)
{
	if (sign < 0)
		return (write_count(1, "-", 1, len));
	if (sign >= 0 && sign_char == SIGN_PLUS)
		return (write_count(1, "+", 1, len));
	if (sign >= 0 && sign_char == SIGN_SPACE)
		return (write_count(1, " ", 1, len));
	return (0);
}

ssize_t	print_hex_prefix(int is_upper, int *len)
{
	if (is_upper)
		return (write_count(1, "0X", 2, len));
	return (write_count(1, "0x", 2, len));
}
