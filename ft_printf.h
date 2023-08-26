/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erabbath <erabbath@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 08:51:02 by erabbath          #+#    #+#             */
/*   Updated: 2023/07/12 07:35:44 by erabbath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_conversion
{
	CONVERT_CHAR,
	CONVERT_STRING,
	CONVERT_POINTER,
	CONVERT_INT,
	CONVERT_UNSIGNED_INT,
	CONVERT_HEX_LOWER,
	CONVERT_HEX_UPPER,
	CONVERT_PERCENT,
	CONVERT_INVALID
}					t_conversion;

typedef enum e_alignment
{
	ALIGN_RIGHT,
	ALIGN_LEFT
}					t_alignment;

typedef enum e_sign
{
	SIGN_DEFAULT,
	SIGN_PLUS,
	SIGN_SPACE
}					t_sign;

typedef enum e_padding
{
	PADDING_SPACE,
	PADDING_ZERO
}					t_padding;

typedef struct s_specifier
{
	t_conversion	conversion;
	t_alignment		alignment;
	t_sign			sign;
	int				is_alternative;
	t_padding		padding;
	int				min_width;
	int				precision;
	size_t			format_len;
}					t_specifier;

int					ft_printf(const char *format, ...);

// Utils
size_t				ft_strlen(char *str);
size_t				ft_strlen_max(char *str, size_t max);

// Parse
void				parse_specifier(char *format, va_list args,
						t_specifier *specifier);

// Print
void				print_special(t_specifier *specifier, va_list args,
						int *len);
void				print_c(va_list args, t_specifier *specifier, int *len);
void				print_s(va_list args, t_specifier *specifier, int *len);
void				print_d(va_list args, t_specifier *specifier, int *len);
void				print_u(va_list args, t_specifier *specifier, int *len);
void				print_x(va_list args, t_specifier *specifier, int *len);
void				print_p(va_list args, t_specifier *specifier, int *len);

// Print utils
void				ft_write_count(int fd, void *buf, size_t nbyte, int *len);
void				print_spaces(size_t n, int *len);
void				print_zeros(size_t n, int *len);
void				print_sign(int sign, t_sign sign_char, int *len);
void				print_hex_prefix(int is_upper, int *len);
void				print_left_padding(size_t char_count, t_padding padding,
						t_specifier *specifier, int *len);
void				print_right_padding(size_t char_count, t_padding padding,
						t_specifier *specifier, int *len);
void				print_precision_padding(size_t digit_count,
						t_specifier *specifier, int *len);
size_t				count_digits(long long value, int base, int precision);
size_t				ucount_digits(unsigned long long value, int base,
						int precision);
void				print_digits(long long value, size_t digit_count, int *len);
void				uprint_digits(unsigned long long value, size_t digit_count,
						int *len);
void				uprint_hex_digits(unsigned long long value,
						size_t digit_count, int is_upper, int *len);

#endif
