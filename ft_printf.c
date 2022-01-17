#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int ft_len_n(long long d, int base)
{
	int i = 1;
	if (d < 0)
		d = -d;
	while (d >= base)
	{
		i++;
		d /= base;
	}
	return (i);
}

void ft_putnbr(long long d, int base, char *a)
{
	if (d >= base)
		ft_putnbr(d/base, base, a);
	write(1, &a[d%base], 1);
}

int ft_strlen(char *a)
{
	int i =0;
	if (!a)
		return (6);
	while (a[i] != '\0')
	{
		i++;
	}
	return (i);
}

int ft_find(va_list arg, char *a, int *len)
{
	int width = 0;
	int toc = -1;
	int i = 0;
	long long d;

	while (a[i] >= '0' && a[i] <= '9')
	{
		width = width * 10 + (a[i] - '0');
		i++;
	}
	if (a[i] == '.')
	{
		i++;
		toc = 0;
		while (a[i] >= '0' && a[i] <= '9')
		{
			toc = toc * 10 + (a[i] - '0');
			i++;
		}
	}

	int count_zero = 0;
	int count_pr = 0;
	int j =0;

	if (a[i] == 'd')
	{
		i++;
		d = va_arg(arg, int);
		if (toc < ft_len_n(d, 10) && toc != 0)
			toc = -1;
		else
			count_zero = toc - ft_len_n(d, 10);
		count_pr = width - count_zero - ft_len_n(d, 10);
		if (count_pr < 0)
			count_pr = 0;
		if (d < 0)
			count_pr--;

		j = 0;
		while  (j < count_pr)
		{
			write(1, " ",1);
			j++;
			*len += 1;
		}
		if (d == 0 && toc == 0)
			return (i);
		if (d < 0)
		{
			write(1, "-", 1);
			*len += 1;
			d = -d;
		}
		j = 0;
		while (j < count_zero)
		{
			write(1, "0",1);
			j++;
			*len += 1;
		}
		ft_putnbr(d, 10, "0123456789");
		*len += ft_len_n(d, 10);
	}

		if (a[i] == 'x')
	{
		i++;
		d = va_arg(arg, long long);
		if (toc > ft_len_n(d, 10))
		{
			count_zero = toc - ft_len_n(d, 16);
		}
		else
		{
			if (toc != 0)
				toc = -1;
		}
		count_pr = width - count_zero - ft_len_n(d, 16);
		if (d < 0)
			count_pr--;

		j = 0;
		while  (j < count_pr)
		{
			write(1, " ",1);
			j++;
			*len += 1;
		}
		if (d == 0 && toc == 0)
			return (i);
		j = 0;
		while (j < count_zero)
		{
			write(1, "0", 1);
			j++;
			*len += 1;
		}
		ft_putnbr(d, 16, "0123456789abcdef");
		*len += ft_len_n(d, 16);
	}

char *s;
	if (a[i] == 's')
	{
		i++;
		s = va_arg(arg, char *);
		if (s == NULL)
		{
			s = malloc(6);
			s = "(null)";
		}
		if (toc == -1)
			count_pr = width - ft_strlen(s);
		else
		{
			if (toc > ft_strlen(s))
			{
				count_pr = width - ft_strlen(s);
			}
			else
			{
				count_pr = width - toc;
			}
		}
		j = 0;
		while (j < count_pr)
		{
			write(1, " ",1);
			j++;
			*len += 1;
		}
		j = 0;
		while ((s[j] != '\0' && toc == -1) || (j < toc && toc > 0 && s[j] != '\0'))
		{
			write(1, &s[j], 1);
			*len += 1;
			j++;
		}
	}
	return (i);
}

int ft_printf(char *a, ...)
{
	va_list arg;
	int i = 0;
	int len = 0;

	va_start(arg, a);
	while (a[i] != '\0')
	{
		if (a[i] != '%')
		{
			write(1, &a[i], 1);
			len++;
		}
		else
		{
			i += ft_find(arg, &a[i+1], &len);
		}
		
		i++;
	}
	va_end(arg);
	return (len);
}