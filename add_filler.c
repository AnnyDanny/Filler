/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_filler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 15:55:38 by gdanylov          #+#    #+#             */
/*   Updated: 2018/06/07 15:55:40 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"


// void check_symb_in_map(t_info *s)
// {
// 	if (c == s->my || c == s->my + 32)
// 		s->a_my++;
// 	if (c == s->other || c == s->other + 32)
// 		s->b_other++;
// }

// int check_in_map(t_info *s)
// {
// 	char c;

// 	s->save = s->y_map;
// 	while (s->i_fig < s->height_fig && s->x_map < s->height_map && count >= 0)
// 	{
// 		s->y_map = s->save;
// 		while (s->j_fig < s->width_fig && s->y_map < s->width_map && count >= 0)
// 		{
// 			if (s->fig[s->i_fig][s->j_fig] == '*')
// 			{
// 				check_symb_in_map(s);
// 				count--;
// 			}
// 			s->j_fig++;
// 			s->y_map++;
// 		}
// 		s->i_fig++;
// 		s->x_map++;
// 		if (count = 0 && s->a_my == 1 && s->b_other == 0)
// 			return (1);
// 	}
// }

// void walk_in_map(t_info *s)
// {
// 	while (s->map[s->x_map])
// 	{
// 		s->y_map = 0;
// 		while (s->map[s->x_map][s->y_map])
// 		{
// 			if (check_in_map(s) == 1)
// 		}
// 	}
// }
