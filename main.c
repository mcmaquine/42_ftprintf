/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:48:46 by mmaquine          #+#    #+#             */
/*   Updated: 2025/08/21 17:14:50 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	unsigned int i;
	int	sizeft, sizep;
	char	*str = NULL;

	i = 90238756;
	sizeft = ft_printf("%p %p, %x, %X, %%, %s", (void *)16, &i, -1, i, str);
	printf("\n");
	sizep = printf("%p %p, %x, %X, %%, %s", (void *)16, &i, -1, i, str);
	printf("\n\nSize of ft_printf: %d\nSize of printf: %d\n", sizeft, sizep);
	ft_putnbr(10);
}
