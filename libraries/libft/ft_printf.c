#include "libft.h"

int	calc_digits(size_t nbr, size_t base_len)
{
	int	digits;

	digits = 0;
	while (nbr >= base_len)
	{
		nbr /= base_len;
		digits++;
	}
	return (++digits);
}

int	print_string(va_list arg)
{
	char	*string;
	int		printed;

	string = va_arg(arg, char *);
	if (!string)
		string = "(null)";
	printed = ft_strlen(string);
	write(1, string, printed);
	return (printed);
}

int	print_decimal(va_list arg)
{
	long	decimal;
	int		printed;
	short	negative;

	decimal = va_arg(arg, int);
	negative = 0;
	if (decimal < 0)
	{
		decimal = -decimal;
		negative++;
	}
	printed = calc_digits(decimal, 10);
	if (negative)
	{
		printed++;
		write(1, "-", 1);
	}
	ft_putnbr(decimal);
	return (printed);
}

static int	dispatcher(char spec, va_list args)
{
	if (spec == 's')
		return (print_string(args));
	if (spec == 'd')
		return (print_decimal(args));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	int		printed;
	va_list	args;

	printed = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			printed += dispatcher(*str, args);
		}	
		else
		{
			write(1, str, 1);
			printed++;
		}
		str++;
	}
	va_end(args);
	return (printed);
}
