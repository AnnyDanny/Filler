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
#include <stdio.h>


int fd;

// t_fil *listnew(int x, int y)
// {
// 	t_fil *coord;

// 	if (!(coord = (t_fil*)malloc(sizeof(t_fil))))
// 		return (NULL);
// 	coord->x = x;
// 	coord->y = y;
// 	coord->next = NULL;
// 	return (coord);
// }

// void		ft_add_end(t_fil **head, t_fil 	*node)
// {
// 	t_fil 	*tmp;
		
// 	if (!head || !node)
// 		return ;
// 	tmp = (*head);
// 	node->next = NULL;
// 	if (*head == NULL)
// 	{
// 		*head = node;
// 		return ;
// 	}
// 	while (tmp->next != NULL)
// 		tmp = tmp->next;
// 	tmp->next = node;
// }

// void		free_arr(t_info *s)
// {
// 	int 	i;

// 	i = 0;
// 	while(i < s->height_map)
// 	{
// 		ft_strdel(&(s->map[i]));
// 		i++;
// 	}
// 	free(s->map);
// 	while(i < s->height_fig)
// 	{
// 		ft_strdel(&(s->fig[i]));
// 		i++;
// 	}
// 	free(s->fig);
// 	s->fig = NULL;
// 	s->map = NULL;
// }


// void distance(t_info *s, t_fil *head)
// {
// 	int res;
// 	int x;
// 	int y;


// 	res = 0;
// 	x = (s->x_map - head->x) < 0 ? (-1) * (s->x_map - head->x) : (s->x_map - head->x);
// 	y = (s->x_map - head->x) < 0 ? (-1) * (s->x_map - head->x) : (s->x_map - head->x);
// 	res = x + y;
// 	if (s->distance == -1)
// 	{
// 		s->res_x = head->x;
// 		s->res_y = head->y;
// 		s->distance = res;
// 	}
// 	else if (res < s->distance)
// 	{
// 		s->distance = res;
// 		s->res_x = head->x;
// 		s->res_y = head->y;
// 	}
// }

// int print_list(t_fil *head)
// {
// 	int i;

// 	i = 0;
// 	while (head)
// 	{
// 		ft_putnbr_fd(head->x, fd);
// 		write(fd, " ", 1);
// 		ft_putnbr_fd(head->y, fd);
// 		write(fd, "\n", 1);
// 		head = head->next;
// 		i++;
// 	}
// 	return (i);
// }

// void return_coord(t_info *s, t_fil *head)
// {
	
// 	t_fil *tmp;

// 	tmp = head;
// 	s->x_map = 0;
// 	while (s->x_map < s->height_map)
// 	{
// 		s->y_map = 0;
// 		while (s->y_map < s->width_map)
// 		{
// 			if (vrag(s->map[s->x_map][s->y_map], s) == 1)
// 			{
// 				head = tmp;
// 				distance(s, head);
// 				head = head->next;
// 			}
// 			s->y_map++;
// 		}
// 		s->x_map++;
// 	}
	
	// ft_putnbr_fd(s->res_x, 1);
	// write(1, " ", 1);
	// ft_putnbr_fd(s->res_y, 1);
	// write(1, "\n", 1);
	// ft_putnbr_fd(s->res_x, fd);
	// write(fd, "\n", 1);
	// ft_putnbr_fd(s->res_y, fd);
	// write(fd, "\n", 1);
	// free_arr(s);
	// clear_struct(s);
// }

// int check_in_the_map(t_info *s)
// {
// 	int a = 0;
// 	int x = s->x_map;

// 	s->j_fig = 0;

// 	if (!(s->x_map + s->height_fig < s->height_map &&\
// 	s->y_map + s->width_fig < s->width_map))
// 		return (0);
// 	 while (s->j_fig < s->height_fig)
// 	 {
//  		int y = s->y_map;
// 	 	s->i_fig = 0;
// 	 	while (s->i_fig < s->width_fig)
// 	 	{
// 	 		if (s->fig[s->j_fig][s->i_fig] == '*')
// 	 		{
// 	 			if (other(s->map[x][y], s))
// 	 				return (0);
// 	 			if (my(s->map[x][y], s))
// 	 				a++;
// 	 			// if (a > 1)
// 	 			// 	return(0);
// 	 		}
// 	 		y++;
// 	 		s->i_fig++;
// 	 	}
// 	 	x++;
// 	 	s->j_fig++;
// 	 }
// 	if (a == 1)
// 		return(1);
// 	return (0);
// }
//  void walk_in_the_map(t_info *s)
// {
// 	s->x_map = 0;
// 	while (s->x_map < s->height_map)
// 	{
// 		s->y_map = 0;
// 		while (s->y_map < s->width_map)
// 		{
// 			if (check_in_the_map(s) == 1)
// 			{
// 				ft_printf("%d", s->x_map - 1);
// 				write(1, " ", 1);
// 				ft_printf("%d", s->y_map);
// 				write(1, "\n", 1);
// 				return ;
// 				ft_putnbr_fd(s->x_map, fd);
// 				write(fd, " ", 1);
// 				ft_putnbr_fd(s->y_map, fd);
// 				write(fd, "\n", 1);
// 			}
// 			s->y_map++;
// 		}
// 		s->x_map++;
// 	}
// }

// int other(char c, t_info *s)
// {
// 	if (c == s->other || c == s->other + 32)
// 		return (1);
// 	return (0);
// }

// int my(char c, t_info *s)
// {
// 	if (c == s->my || c == s->my + 32)
// 		return (1);
// 	return (0);
// }

// int check_coord_in_map(int y, int x)
// {
// 	if (y == 0)
// 		return (1);
// 	if (x == 0)
// 		return (2);
// 	return (0);
// }

int check_in_the_map(int x, int y, t_info *s)
{
	int i = 0;
	int a;
	int count;

	a = x;
	count = 0;
	while (i < s->height_fig)
	{
		int j = 0;
		x = a;
		while (j < s->width_fig)
		{
			if (s->fig[i][j] == '*')
			{
				if (s->map[y][x] == s->other || s->map[y][x] == s->other + 32)
					return (0);
				if (s->map[y][x] == s->my || s->map[y][x] == s->my + 32)
				{
					// s->map[y][x] = s->tmp[y][x];
					count++;
				}
				// if (check_coord_in_map(y, x) == 1)
					// y = s->height_map - 1;
				// if (check_coord_in_map(y, x) == 2)
					// x = s->width_map - 1;
				if (count > 1)
					return (0);
			}
			j++;
			x++;
		}
		i++;
		y++;
	}
	if (count == 1)
	{
		// s->check_coord++;
		return (1);
	}
	return (0);
}

int count_coord_one(s, int y, int x)
{
	int weight;
	int i;
	int j;

	i = 0;
	weight = 0;
	while (i < s->height_fig)
	{
		j = 0;
		while (j < s->width_fig)
		{
			if (s->fig[i][j] == '*')
				weight += s->tmp[y][x];
			j++;
		}
		i++;
	}
	return (weight);
}

int count_coord_second(s, int y, int x)
{
	int weight;
	int i;
	int j;

	i = 0;
	weight = 0;
	while (i < s->height_fig)
	{
		j = 0;
		while (j < s->width_fig)
		{
			if (s->fig[i][j] == '*')
				weight += s->tmp[s->coord_y][s->coord_x];
			j++;
		}
		i++;
	}
	return (weight);
}

int check_best_coord(t_info *s, int y, int x)
{
	int a;
	int b;

	a = 0;
	b = 0;
	if (s->check_coord == 1)
	{
		a = count_coord_one(s, int y, int x);
		b = count_coord_second(s);
	}
	else
	{
		s->coord_y = y;
		s->coord_x = x;
		s->check_coord = 1;
	}
		
}

void walk_in_the_map(t_info *s)
{
	int y = 0;
	s->check_coord = 0;

	while (y <= s->height_map - s->height_fig)
	{
		int x = 0;
		while (x <= s->width_map - s->width_fig)
		{
			if (check_in_the_map(x, y, s) == 1)
			{
				check_best_coord(s, y, x);
				// ft_printf("%d %d\n", y, x);
				// return ;
			}
			x++;
		}
		y++;
	}
	ft_printf("%d %d\n", 0, 0);
}


void check_figure(char *buff, t_info *s)
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
		ft_strdel(&buff);
		i++;
	}
	s->fig[i] = NULL;
	// print_map_fig(s->fig, s->height_fig, s->width_fig);
	// print_map_fig(s->map, s->height_map, s->width_map);
	// i = 0;
	// printf("\nfig>>>\n");
	// while (i < s->height_fig)
	// {
	// 	printf("\n%s\n", s->fig[i]);
	// 	i++;
	// }
	// printf("\ns->height_fig>>>%d\n", s->height_fig);
	// printf("\ns->width_fig>>>%d\n", s->width_fig);
	// printf("\ns->height_map>>>%d\n", s->height_map);
	// printf("\ns->width_map>>>%d\n", s->width_map);
	walk_in_the_map(s);
}

void make_digits(t_info *s, int d)
{
	int i;
	int j;

	i = 0;
	while (i < s->height_map)
	{
		j = 0;
		while (j < s->width_map)
		{
			if (s->tmp[i][j] == -1)
			{
				if (j + 1 < s->width_map && s->tmp[i][j + 1] == d - 1)
					s->tmp[i][j] = d;
				if (j != 0 && s->tmp[i][j - 1] == d - 1)
					s->tmp[i][j] = d;
				if (i + 1 < s->height_map && s->tmp[i + 1][j] == d - 1)
					s->tmp[i][j] = d;
				if (i != 0 && s->tmp[i - 1][j] == d - 1)
					s->tmp[i][j] = d;
			}
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while (i < s->height_map)
	{
		j = 0;
		while (j < s->width_map)
		{
			dprintf(fd, "%3d", s->tmp[i][j]);
			j++;
		}
		i++;
		write(fd, "\n", 1);
	}
	write(fd, "\n", 1);
}


int check_minus_one(t_info *s)
{
	int i;
	int j;

	i = 0;
	while (i < s->height_map)
	{
		j = 0;
		while (j < s->width_map)
		{
			if (s->tmp[i][j] == -1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void fill_distance(t_info *s)
{
	int d;

	d = 1;
	while (check_minus_one(s) == 1)
	{
		make_digits(s, d);
		d++;
	}
}

void fill_tmp(t_info *s)
{
	int i;
	int j;

	i = 0;
	while (i < s->height_map)
	{
		j = 0;
		while (j < s->width_map)
		{
			if (s->tmp[i][j] == '.')
				s->tmp[i][j] = -1;
			if (s->tmp[i][j] == s->my || s->tmp[i][j] == s->my + 32)
				s->tmp[i][j] = -2;
			if (s->tmp[i][j] == s->other || s->tmp[i][j] == s->other + 32)
				s->tmp[i][j] = 0;
			j++;
		}
		i++;
	}
	// i = 0;
	// j = 0;
	// while (i < s->height_map)
	// {
	// 	j = 0;
	// 	while (j < s->width_map)
	// 	{
	// 		dprintf(fd, "%d", s->map[i][j]);
	// 		j++;
	// 	}
	// 	i++;
	// 	write(fd, "\n", 1);
	// }
}

void check_size_plateau(char *buff, t_info *s)
{
	int i;

	i = 0;
	s->height_map = ft_atoi(&buff[8]);
	s->width_map = ft_atoi(&buff[11]);
	get_next_line(0, &buff);
	ft_strdel(&buff);
	s->map = (char**)malloc(sizeof(char*) * (s->height_map + 1));
	s->tmp = (char**)malloc(sizeof(char*) * (s->height_map + 1));
	while (i < s->height_map)
	{
		get_next_line(0, &buff);
		s->map[i] = ft_strdup(buff + 4);
		s->tmp[i] = ft_strdup(buff + 4);
		ft_strdel(&buff);
		i++;
	}
	fill_tmp(s);
	fill_distance(s);
	// get_next_line(0, &buff);
	// if (!ft_strncmp(buff, "Piece ", 6))
	// {
	// 	check_figure(buff, s);
	// }
	// ft_putnbr_fd(s->height_map, fd);
	// ft_putnbr_fd(s->width_map, fd);
	// i = 0;
	// ft_printf("\nmap>>>\n");
	// while (i < s->height_map)
	// {
	// 	ft_printf("\n%s\n", s->map[i]);
	// 	i++;
	// }
	// check_start_position(s);
	// check_position_in_map(s);
}


int main(void)
{
	t_info s;
	
	cl_st(&s);
	char *buff;

	// fd = open("tat", O_RDONLY);
	fd = open("vika3", O_RDWR | O_APPEND);
	while (get_next_line(0, &buff) > 0)
	{
		if (!ft_strncmp(buff, "$$$ exec ", 9))
		{
			// write(fd, "\nif1\n", 5);
			ft_check_name(buff, &s);
		}
		if (!ft_strncmp(buff, "Plateau ", 8))
		{
			// write(fd, "\nif2\n", 5);
			check_size_plateau(buff, &s);
		}
		if (!ft_strncmp(buff, "Piece ", 6))
		{
			// write(fd, "\nif3\n", 5);
			check_figure(buff, &s);
		}
	}
	return (0);
}