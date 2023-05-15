/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galamy <galamy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:58:37 by galamy            #+#    #+#             */
/*   Updated: 2022/01/04 15:58:41 by galamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **alst, void (*del)(void *))
{
	t_list	*tmp;

	if (alst == 0 || del == 0)
		return ;
	while (*alst)
	{
		tmp = (*alst)->next;
		ft_lstdelone(*alst, del);
		*alst = tmp;
	}
	*alst = 0;
}
