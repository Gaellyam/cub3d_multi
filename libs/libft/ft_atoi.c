/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galamy <galamy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:45:50 by galamy            #+#    #+#             */
/*   Updated: 2023/05/23 12:29:49 by galamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long int	c;
	long int	nb;

	c = 1;
	nb = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
		c = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if ((nb > 922337203685477580 || (nb == 922337203685477580
					&& (*str - '0') > 7)) && c == 1)
			return (-1);
		else if ((nb > 922337203685477580 || (nb == 922337203685477580
					&& (*str - '0') > 8)) && c == -1)
			return (0);
		nb = nb * 10 + (*str - 48);
		str++;
	}
	nb *= c;
	return (nb);
}

int	ft_atoi2(const char *str)
{
	long int	nb;

	nb = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + (*str - 48);
		str++;
	}
	if (nb > 255)
		return (-1);
	return (nb);
}
