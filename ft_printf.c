#include <stdarg.h>

int	ft_printf_core(char *format, va_list args)
{
	int			count;
	int			len;
	t_specifier	specifier;

	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			len = print_special_format(format, &specifier, args);
			if (len < 0)
				return (-1);
			count += len;
			format += specifier.format_len;
		}
		else
		{
			len = write(1, format, 1);
			if (len < 0)
				return (-1);
			count++;
			format++;
		}
	}
	return (count);
}

int	ft_printf(char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = ft_printf_core(format, args);
	va_end(args);
	return (count);
}
