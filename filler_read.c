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

t_fil *listnew(int x, int y)
{
	t_fil *coord;

	if (!(coord = (t_fil*)malloc(sizeof(t_fil))))
		return (NULL);
	coord->x = x;
	coord->y = y;
	coord->next = NULL;
	return (coord);
}

void		ft_add_end(t_fil **head, t_fil 	*node)
{
	t_fil 	*tmp;
	

	
	if (!head || !node)
		return ;
	tmp = (*head);
	node->next = NULL;
	if (*head == NULL)
	{
		*head = node;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = node;
}

void		free_arr(t_info *s)
{
	int 	i;

	i = 0;
	while(i < s->height_map)
	{
		ft_strdel(&(s->map[i]));
		i++;
	}
	free(s->map);
	while(i < s->height_fig)
	{
		ft_strdel(&(s->fig[i]));
		i++;
	}
	free(s->fig);
	s->fig = NULL;
	s->map = NULL;
}


// fd = open("vika", O_RDWR, O_APPEND);




int check_in_the_map(t_info *s)
{
	 int a = 0;

	s->j_fig = 0;
	write(fd, "ok7\n", 4);
	if (!(s->x_map + s->height_fig < s->height_map &&\
	s->y_map + s->width_fig < s->width_map))
	{
		// write(fd, "ok8\n", 4);
		return (0);
	}
	 while (s->j_fig < s->height_fig) //i < s->height_fig
	 {
	 	s->i_fig = 0;
	 	while (s->i_fig < s->width_fig)
	 	{
	 		if (s->fig[s->j_fig][s->i_fig] == '*')
	 		{
	 			if (vrag(s->map[s->x_map + s->j_fig][s->y_map + s->i_fig], s))
	 				return (0);
	 			if (my(s->map[s->x_map + s->j_fig][s->y_map + s->i_fig], s))
	 				a++;
	 			if (a > 1)
	 				return(0);
	 		}
	 		s->i_fig++;
	 	}
	 	s->j_fig++;
	 }
	 if (a == 1)
	 	return(1);
	 return (0);
}

void distance(t_info *s, t_fil *head)
{
	int res;
	int x;
	int y;


	res = 0;
	x = (s->x_map - head->x) < 0 ? (-1) * (s->x_map - head->x) : (s->x_map - head->x);
	y = (s->x_map - head->x) < 0 ? (-1) * (s->x_map - head->x) : (s->x_map - head->x);
	res = x + y;
	if (s->distance == -1)
	{
		s->res_x = head->x;
		s->res_y = head->y;
		s->distance = res;
	}
	else if (res < s->distance)
	{
		s->distance = res;
		s->res_x = head->x;
		s->res_y = head->y;
	}
}

int print_list(t_fil *head)
{
	int i;

	i = 0;
	while (head)
	{
		write(fd, "list1\n", 6);
		ft_putnbr_fd(head->x, fd);
		write(fd, " ", 1);
		ft_putnbr_fd(head->y, fd);
		write(fd, "\n", 1);
		head = head->next;
		i++;
	}
	return (i);
}

void return_coord(t_info *s, t_fil *head)
{
	
	t_fil *tmp;

	tmp = head;
	s->x_map = 0;
	while (s->x_map < s->height_map)
	{
		s->y_map = 0;
		while (s->y_map < s->width_map)
		{
			if (vrag(s->map[s->x_map][s->y_map], s) == 1)
			{
				head = tmp;
				distance(s, head);
				head = head->next;
			}
			s->y_map++;
		}
		s->x_map++;
	}
	
	ft_putnbr_fd(s->res_x, 1);
	write(1, " ", 1);
	ft_putnbr_fd(s->res_y, 1);
	write(1, "\n", 1);
	write(fd, "\nfinal\n", 7);
	ft_putnbr_fd(s->res_x, fd);
	write(fd, "\n", 1);
	ft_putnbr_fd(s->res_y, fd);
	write(fd, "\n", 1);
	free_arr(s);
	clear_struct(s);
}




 void walk_in_the_map(t_info *s)
{
	write(fd, "\nok2\n", 5);
	t_fil		*head;
	t_fil		*new;

	head = NULL;
	new = NULL;
	s->x_map = 0;
	while (s->x_map < s->height_map)
	{
		// write(fd, "\nok3\n", 5);
		s->y_map = 0;
		while (s->y_map < s->width_map)
		{
			// write(fd, "\nok4\n", 5);		
			if (check_in_the_map(s) == 1)
			{
				write(fd, "\nok5\n", 5);
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
	print_list(head);
	return_coord(s, new);
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
	while (i < s->height_map)
	{
		get_next_line(0, &buff);
		s->map[i] = ft_strdup(buff + 4);
		//ft_putendl_fd(s->map[i], fd);
		ft_strdel(&buff);
		i++;
	}
	check_start_position(s);
	check_position_in_map(s);
	get_next_line(0, &buff);
	if (!ft_strncmp(buff, "Piece ", 6))
	{
		write(fd, "i am here3\n", 11);
		check_figure(buff, s);
	}
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
		//ft_putendl_fd(s->fig[i], fd);
		ft_strdel(&buff);
		i++;
	}
	s->fig[i] = NULL;
	//write(fd, "\nbefore\n", 8);
	walk_in_the_map(s);
}

int main(void)
{
	t_info s;
	
	
	clear_struct(&s);
	char *buff;


	// write(fd, "\nok\n", 4);
	fd = open("vika3", O_RDWR | O_APPEND);
	//write(fd, "i am here\n", 10);
	 
	while (get_next_line(0, &buff) > 0)
	{
		if (!ft_strncmp(buff, "$$$ exec ", 9))
		{
			//write(fd, "i am here1\n", 11);
			ft_check_name(buff, &s);
		}
		else if (!strncmp(buff, "Plateau ", 8))
		{
			//write(fd, "i am here2\n", 11);
			check_size_plateau(buff, &s);
		}
		// clear_struct(&s);
		//ft_strdel(&buff);
		// if (!ft_strncmp(buff, "Piece ", 6))
		// {
		// 	//write(fd, "i am here3\n", 11);
		// 	check_figure(buff, &s);
		// }
	}
	// clear_struct(&s);
	//write(fd, "\nok9\n", 5);
	// check_start_position(&s);
	// check_position_in_map(&s);
	// walk_in_the_map(&s);
	return (0);
}