#include "filler.h"


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


int 	vrag(char c, t_info *s)
{
	// write(fd, "ok11\n", 6);
	if (c == s->other || c == s->other + 32)
		return (1);
	return(0);
}

int my(char c, t_info *s)
{
	// write(fd, "ok10\n", 6);
	if (c == s->my || c == s->my + 32)
		return (1);
	return (0);
}

void check_position_in_map(t_info *s)
{
	//write(fd, "\nok4\n", 5);
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
	//write(fd, "\nok3\n", 5);
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

void	ft_check_name(char *str, t_info *s)
{
	if (ft_strstr(str, "gdanylov.filler") && ft_atoi(&str[10]) == 1)
	{
		//write(fd, "\nok6\n", 5);
		s->my = 'O';
		s->other = 'X';
	}
	else if (ft_strstr(str, "gdanylov.filler") && ft_atoi(&str[10]) == 2)
	{
		//write(fd, "\nok7\n", 5);
		s->my = 'X';
		s->other = 'O';
	}
}

