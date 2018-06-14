/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 15:55:38 by gdanylov          #+#    #+#             */
/*   Updated: 2018/06/07 15:55:40 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
// #include "get_next_line.h"

int fd;

void		ft_add_end(t_fil **head, t_fil *node)
{
	t_fil 	*tmp;

	if (!head || !node)
		return ;
	tmp = (*head);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = node;
}

t_fil *listnew(int x, int y)
{
	t_fil *coord;

	if (!(coord = (t_fil*)malloc(sizeof(t_fil))))
		return (0);
	coord->x = x;
	coord->y = y;
	coord->next = NULL;
	return (coord);
} 
// fd = open("vika", O_RDWR, O_APPEND);

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
}

// void check_symb_in_map(t_info *s, char c)
// {
// 	if (c == s->my || c == s->my + 32)
// 		s->a_my++;
// 	if (c == s->other || c == s->other + 32)
// 		s->b_other++;
// }

// int check_in_map(t_info *s)
// {
// 	s->save = s->y_map;
// 	while (s->i_fig < s->height_fig && s->x_map < s->height_map && s->count >= 0)
// 	{
// 		s->y_map = s->save;
// 		while (s->j_fig < s->width_fig && s->y_map < s->width_map && s->count >= 0)
// 		{
// 			if (s->fig[s->i_fig][s->j_fig] == '*')
// 			{
// 				check_symb_in_map(s, '*');
// 				s->count--;
// 			}
// 			s->j_fig++;
// 			s->y_map++;
// 		}
// 		s->i_fig++;
// 		s->x_map++;
// 		if (s->count == 0 && s->a_my == 1 && s->b_other == 0)
// 			return (1);
// 	}
// 	return (0);
// }

// void walk_in_map(t_info *s)
// {
// 	while (s->map[s->x_map])
// 	{
// 		s->y_map = 0;
// 		while (s->map[s->x_map][s->y_map])
// 		{
// 			if (check_in_map(s) == 1)
// 				write(1, "0 0\n", 5);
// 			s->y_map++;
// 		}
// 		s->x_map++;
// 	}
// }

int 	vrag(char c, t_info *s)
{
	if (c == s->other || c == s->other + 32)
		return (1);
	return(0);
}

int my(char c, t_info *s)
{
	if (c == s->my || c == s->my + 32)
		return (1);
	return (0);
}

int check_in_the_map(t_info *s)
{
	 int a = 0;

	 while (s->y_map < s->height_map && s->j_fig < s->height_fig) //i < s->height_fig
	 {
	 	while (s->x_map < s->width_map && s->i_fig < s->width_fig)
	 	{
	 		if (s->fig[s->j_fig][s->i_fig] == '*')
	 		{
	 			if (vrag(s->map[s->y_map + s->j_fig][s->x_map + s->i_fig], s))
	 				return (0);
	 			if (my(s->map[s->y_map + s->j_fig][s->x_map + s->i_fig], s))
	 				a++;
	 			if (a > 1)
	 				return(0);
	 		}
	 		s->x_map++;
	 	}
	 	s->y_map++;
	 }
	 if (a == 1)
	 	return(1);
	 return (0);
}


 void walk_in_the_map(t_info *s)
{
	write(fd, "\nok2\n", 5);
	t_fil		*head;
	t_fil		*new;

	head = NULL;
	while (s->map[s->x_map])
	{
		s->y_map = 0;
		while (s->map[s->x_map][s->y_map])
		{
			if (check_in_the_map(s) == 1)
			{
				if (head == NULL)
					head = listnew(s->x_map, s->y_map);
				else
				{
					new = listnew(s->x_map, s->y_map);
					ft_add_end(&head, new);
				}
			}

			s->y_map++;
		}
		s->x_map++;
	}
}

void check_position_in_map(t_info *s)
{
	write(fd, "\nok4\n", 5);
	if (s->my == 'O')
	{
		if (s->start_o_y < s->start_x_y)
			s->position = 2;
		else if (s->start_o_y > s->start_x_y)
			s->position = 1;
	}
	if (s->my == 'X')
	{
		if (s->start_x_y < s->start_o_y)
			s->position = 2;
		else if (s->start_x_y > s->start_o_y)
			s->position = 1;
	}

}

void check_start_position(t_info *s)
{
	write(fd, "\nok3\n", 5);
	int x;
	int y;

	y = 0;
	while (s->map[y])
	{
		x = 0;
		while (s->map[y][x])
		{
			if (s->map[y][x] == 'X' || s->map[y][x] == 'X' + 32)
			{
				s->start_x_x = x;
				s->start_x_y = y;
			}
			else if (s->map[y][x] == 'O' || s->map[y][x] == 'O' + 32)
			{
				s->start_o_x = x;
				s->start_o_y = y;
			}
			x++;
		}
		y++;
	}
}

void check_size_plateau(char *buff, t_info *s, int fd)
{
	int i;

	i = 0;
	s->height_map = ft_atoi(&buff[8]);
	s->width_map = ft_atoi(&buff[11]);
	s->map = (char**)malloc(sizeof(char*) * (s->height_map + 1));
	// write(fd, "\n", 1);
	ft_putnbr_fd(s->height_map, fd);
	// write(fd, "\n", 1);
	ft_putnbr_fd(s->width_map, fd);
	// write(fd, "\n", 1);
	while (i < s->height_map)
	{
		// write(fd, "\nOKOKOK\n", 8);
		get_next_line(0, &buff);
		s->map[i] = ft_strdup(buff + 4);
		// ft_strdel(&buff);
		i++;
	}
	i = 0;
	while (i < s->height_map)
	{
		// write(fd, "\nok3\n", 5);
		ft_putendl_fd(s->map[i], fd);
		i++;
	}
	check_start_position(s);
	check_position_in_map(s);
}

void	ft_check_name(char *str, t_info *s)
{
	if (ft_strstr(str, "gdanylov.filler") && ft_atoi(&str[10]) == 1)
	{
		write(fd, "\nok6\n", 5);
		s->my = 'O';
		s->other = 'X';
	}
	else if (ft_strstr(str, "gdanylov.filler") && ft_atoi(&str[10]) == 2)
	{
		write(fd, "\nok7\n", 5);
		s->my = 'X';
		s->other = 'O';
	}
}

void check_figure(char *buff, t_info *s, int fd)
{
	int i;

	i = 0;
	while (!ft_isdigit(buff[i]))
		i++;
	s->height_fig = ft_atoi(&buff[i]);
	s->width_fig = ft_atoi(ft_strrchr(buff, ' ') + 1);
	i = 0;
	s->fig = (char**)malloc(sizeof(char*) * (s->height_fig + 1));
	while (i < s->height_fig)
	{
		get_next_line(0, &buff);
		s->fig[i] = ft_strdup(buff);
		i++;
	}
	i = 0;
	write(fd, "\nbefore\n", 9);
	while (i < s->height_fig)
	{
		// get_next_line(fd, &buff);
		ft_putendl_fd(s->fig[i], fd);
		i++;
		write(fd, "\nin\n", 4);
	}
	write(fd, "\nafter\n", 7);
	walk_in_the_map(s);
	write(fd, "\nafter1\n", 8);
}

// void check_other_func(t_info *s)
// {
	// check_start_position(s);
	// check_position_in_map(s);
	// walk_in_map(s);
// }

int main(void)
{
	t_info s;
	int fd;
	
	clear_struct(&s);
	char *buff;
	// fd = open("vika3", O_RDWR, O_APPEND);
	fd = open("vika3", O_RDWR, O_APPEND);
	write(fd, "i am here\n", 10);
	// write(1, "\nok\n", 4);
	while (get_next_line(0, &buff))
	{
		if (!ft_strncmp(buff, "$$$ exec ", 9))
		{
			write(fd, "i am here1\n", 11);
			ft_check_name(buff, &s);
		}
		if (!strncmp(buff, "Plateau ", 8))
		{
			write(fd, "i am here2\n", 11);
			check_size_plateau(buff, &s, fd);
		}
		if (!ft_strncmp(buff, "Piece ", 6))
		{
			write(fd, "i am here3\n", 11);
			check_figure(buff, &s, fd);
		}
	}
	write(fd, "\nok9\n", 5);
	// check_start_position(&s);
	// check_position_in_map(&s);
	// walk_in_the_map(&s);
	return (0);
}