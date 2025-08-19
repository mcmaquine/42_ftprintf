/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:40:15 by mmaquine          #+#    #+#             */
/*   Updated: 2025/08/19 17:20:05 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	char	*str1;
	char	*str2;
	char	*start;

	str1 = (char *)s1;
	str2 = (char *)s2;
	joined = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	if (!joined)
		return (NULL);
	start = joined;
	while (*str1)
		*joined++ = *str1++;
	while (*str2)
		*joined++ = *str2++;
	*joined = '\0';
	return (start);
}

/*
The function allocates memory for an array of nmemb elements of size bytes each
and returns a pointer to the allocated memory. The memory is set to zero. If
nmemb or size is 0, then ft_calloc() returns a unique pointer value that can
later be successfully passed to free().
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	unsigned char	*p;
	size_t			total_bytes;

	total_bytes = nmemb * size;
	if (!nmemb || !size)
		return (malloc(sizeof(void *)));
	if ((!nmemb && !size) || (nmemb != total_bytes / size))
		return (NULL);
	ptr = malloc(total_bytes);
	if (!ptr)
		return (NULL);
	p = ptr;
	while (total_bytes--)
		*p++ = '\0';
	return (ptr);
}

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c ^ 0x20);
	else
		return (c);
}
