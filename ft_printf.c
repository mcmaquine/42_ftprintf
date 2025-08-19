/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:29:33 by mmaquine          #+#    #+#             */
/*   Updated: 2025/08/18 17:30:05 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

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

int	main()
{
	ft_printf("String", 1, 2, 3, 4, 5, 6, 7);
}
