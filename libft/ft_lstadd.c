/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 17:46:10 by gdanylov          #+#    #+#             */
/*   Updated: 2017/11/24 17:46:10 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (alst != NULL && new != NULL)
	{
		new->next = *alst;
		*alst = new;
	}
}


// void		ft_add_end(t_fil **head, t_fil *node)
// {
// 	t_fil 	*tmp;

// 	if (!head || !node)
// 		return ;
// 	tmp = (*head);
// 	while (tmp->next != NULL)
// 		tmp = tmp->next;
// 	tmp->next = node;
// }