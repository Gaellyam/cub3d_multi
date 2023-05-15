/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galamy <galamy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:07:38 by galamy            #+#    #+#             */
/*   Updated: 2022/01/04 14:09:29 by galamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int n)
{
	int				c;
	unsigned int	nbr;

	if (n == 0)
		return (1);
	c = 0;
	nbr = n;
	if (n < 0)
	{
		c++;
		nbr = -n;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	char	*s;
	long	nb;
	int		sizen;

	nb = n;
	if (nb == 0)
		return (ft_strdup("0"));
	sizen = ft_nbrlen(nb);
	s = (char *)malloc(sizeof(char) * (sizen + 1));
	if (!s)
		return (NULL);
	s[sizen--] = '\0';
	if (nb < 0)
	{
		s[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		s[sizen] = (nb % 10) + '0';
		nb /= 10;
		sizen--;
	}
	return (s);
}
