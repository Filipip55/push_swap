/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icoman <icoman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 12:52:50 by filip             #+#    #+#             */
/*   Updated: 2026/04/01 22:17:37 by icoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_formatters(va_list args, const char *str, int i)
{
	int	c;

	if (str[i] == 'c')
	{
		c = va_arg(args, int);
		return (write(1, &c, 1));
	}
	if (str[i] == 's')
		return (put_str(va_arg(args, char *)));
	if (str[i] == 'p')
		return (put_ptr((unsigned long long)va_arg(args, void *)));
	if (str[i] == 'd' || str[i] == 'i')
		return (put_nbr(va_arg(args, int)));
	if (str[i] == 'u')
		return (put_nbr(va_arg(args, unsigned int)));
	if (str[i] == 'x')
		return (put_hex(va_arg(args, unsigned int), 'x'));
	if (str[i] == 'X')
		return (put_hex(va_arg(args, unsigned int), 'X'));
	if (str[i] == '%')
		return (write(1, "%", 1));
	return (0);
}

void	check_flag(int print_word_counter)
{
	static int	words_printed;

	if (print_word_counter)
		put_nbr(words_printed);
	else
		words_printed++;
}

int	ft_printf(const char *str, int print_word_counter, ...)
{
	va_list		args;
	int			i;
	int			char_count;

	if (str == NULL)
		return (-1);
	i = 0;
	char_count = 0;
	va_start(args, print_word_counter);
	while (i < (int)ft_strlen(str))
	{
		if (str[i] == '%')
		{
			i++;
			char_count += check_formatters(args, str, i);
			i++;
		}
		else
			char_count += write(1, &str[i++], 1);
	}
	va_end(args);
	check_flag(print_word_counter);
	return (char_count);
}
