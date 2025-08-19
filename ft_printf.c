/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:29:33 by mmaquine          #+#    #+#             */
/*   Updated: 2025/08/19 17:23:16 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*
Convert a number n to hex representation, if caps is 0 the representaion is
lower, upper otherwise.*/
static void	ft_tohex(size_t n, char *num, int *pos)
{
	if (n >= 16)
	{
		ft_tohex(n / 16, num, pos);
		ft_tohex(n % 16, num, pos);
	}
	if (n < 16)
	{
		num[*pos] = "0123456789abcdef"[n];
		(*pos)++;
	}
}

char	*ft_ptohex(size_t n, int (*f)(int))
{
	char	num[17];
	char	*hexstr;
	int		i;

	i = 0;
	ft_tohex(n, num, &i);
	num[i] = '\0';
	hexstr = ft_strjoin("0x", num);
	if (!hexstr)
		return (NULL);
	i += 2;
	while (--i > -1)
	{
		if (f)
			hexstr[i] = f(num[i]);
		else
			hexstr[i] = num[i];
	}
	return (hexstr);
}
/*
Upon succesful return, these functions return the number of bytes printed
excluding the null byte used to end output to strings)
 */
int	ft_printf(const	char *format, ...)
{
	va_list	ptr;

	va_start(ptr, format);
	while(*format)
	{
		int num = va_arg(ptr, int);

		printf("%d\n", num);
		format++;
	}
	va_end(ptr);
	return (0);
}
