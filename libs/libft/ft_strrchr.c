/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galamy <galamy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:27:38 by galamy            #+#    #+#             */
/*   Updated: 2022/05/12 12:34:34 by galamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*res;

	res = 0;
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			res = (char *)s;
		s++;
	}
	if (res)
		return (res);
	else if (c == '\0')
		return ((char *)s);
	else
		return (NULL);
}
