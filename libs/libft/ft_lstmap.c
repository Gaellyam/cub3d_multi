/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galamy <galamy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:59:27 by galamy            #+#    #+#             */
/*   Updated: 2022/01/12 16:19:32 by galamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_head;
	t_list	*tmp;
	t_list	*curr;

	if (!lst)
		return (NULL);
	new_head = ft_lstnew(f(lst->content));
	if (!new_head)
		return (NULL);
	curr = new_head;
	tmp = lst->next;
	while (tmp)
	{
		curr->next = ft_lstnew(f(tmp->content));
		if (curr->next == NULL)
		{
			ft_lstclear(&new_head, del);
			return (NULL);
		}
		curr = curr->next;
		tmp = tmp->next;
	}
	return (new_head);
}
