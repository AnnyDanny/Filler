/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 17:45:12 by gdanylov          #+#    #+#             */
/*   Updated: 2017/11/24 17:45:13 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*vika;
	void		*newcontent;
	size_t		newcontent_size;

	if (!(vika = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		vika->content = NULL;
		vika->content_size = 0;
	}
	else
	{
		newcontent = ft_memalloc(content_size);
		if (!newcontent)
		{
			free(vika);
			return (NULL);
		}
		vika->content = ft_memcpy(newcontent, content, content_size);
		newcontent_size = content_size;
		vika->content_size = newcontent_size;
	}
	vika->next = NULL;
	return (vika);
}


// t_fil *listnew(int x, int y)
// {
// 	t_fil *coord;
// 	int new_x;
// 	int new_y;

// 	if (!(coord = (t_fil*)malloc(sizeof(t_fil))))
// 		return (0);
// 	coord->x = x;
// 	coord->y = y;
// 	coord->next = NULL;
// 	return (coord);
// } 
