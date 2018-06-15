/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat.c.                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 15:55:38 by gdanylov          #+#    #+#             */
/*   Updated: 2018/06/07 15:55:40 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

void		clear_struct(t_info *s)
{
	s->my = '\0';
	s->other = '\0';
	s->width_map = 0;
	s->height_map = 0;
	s->map = NULL;
	s->width_fig = 0;
	s->height_fig = 0;
	s->fig = NULL;
	s->start_x_x = 0;
	s->start_x_y = 0;
	s->start_o_x = 0;
	s->start_o_y = 0;
	s->position = 0;
	s->x_map = 0;
	s->y_map = 0;
	s->count = 0;
	s->i_fig = 0;
	s->j_fig = 0;
	s->a_my = 0;
	s->b_other = 0;
	s->save = 0;
	s->res_x = 0;
	s->res_y = 0;
	s->distance = -1;
}


void ft_check_name(char *str, t_info *s)
{
	if (ft_strstr(str, "gdanylov.filler") && ft_atoi(&str[10]) == 1)
	{
		s->my = 'O';
		s->other = 'X';
	}
	else if (ft_strstr(str, "gdanylov.filler") && ft_atoi(&str[10]) == 2)
	{
		s->my = 'X';
		s->other = 'O';
	}
	printf("\ns->my>>>%c\n", s->my);
	printf("\ns->other>>>%c\n", s->other);
}

int main(void)
{
	t_info *s = NULL;
	int fd;

	clear_struct(s);
	char *buff;
	// s = NULL;

	printf("\nok\n");
	// fd = open("vika3", O_RDWR | O_APPEND);
	fd = open("tat", O_RDONLY);
	while (get_next_line(fd, &buff))
	{
		if (!ft_strncmp(buff, "$$$ exec ", 9))
		{
			ft_check_name(buff, s);
		}
	}
	return (0);
}