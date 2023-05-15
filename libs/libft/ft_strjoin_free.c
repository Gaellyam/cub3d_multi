/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galamy <galamy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 11:01:41 by galamy            #+#    #+#             */
/*   Updated: 2023/01/09 16:34:35 by galamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	a;
	char	*res;
	int		i;
	int		j;

	if (!s1)
		s1 = ft_calloc(sizeof(char), 1);
	if (!s1 || !s2)
		return (NULL);
	j = 0;
	i = -1;
	a = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(a + 1 * sizeof(char));
	if (!res)
		return (NULL);
	if (s1)
		while (s1[++i])
			res[i] = s1[i];
	while (s2[j])
		res[i++] = s2[j++];
	res[a] = '\0';
	free(s1);
	return (res);
}
