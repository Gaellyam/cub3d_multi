/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galamy <galamy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:10:28 by galamy            #+#    #+#             */
/*   Updated: 2023/05/15 22:52:32 by galamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkset(char c, char const *set)
{
	size_t	i;

	if (!c || !set)
		return (0);
	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*copy;
	size_t	i;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	start = (char *)s1;
	end = (char *)s1 + ft_strlen(s1);
	while (checkset(*start, set))
		start++;
	if (start < end)
		end--;
	while (checkset(*end, set))
		end--;
	len = end - start + 1;
	copy = (char *)malloc(sizeof(char) * len + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (len-- > 0)
		copy[i++] = *start++;
	copy[i] = '\0';
	return (copy);
}
