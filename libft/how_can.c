#include "filler.h"
// #include "get_next_line.h"

void		clear_struct(t_info *s)
{
	s->my = '\0';
	s->other = '\0';
	s->width = 0;
	s->height = 0;
	s->map = NULL;
	s->width_fig = 0;
	s->height_fig = 0;
	s->fig = NULL;
	s->start_x_x = 0;
	s->start_x_y = 0;
	s->start_o_x = 0;
	s->start_o_y = 0;
	s->position = 0;
}

int	check_position_in_map(t_info *s)
{
	// printf("\nok\n");
	if (s->my == 'O')
	{
		if (s->start_o_y < s->start_x_y)
			s->position = 2;
		else if (s->start_o_y > s->start_x_y)
			s->position = 1;
	}
	if (s->my == 'X')
	{
		// printf("\nok1\n");
		if (s->start_x_y < s->start_o_y)
			s->position = 2;
		else if (s->start_x_y > s->start_o_y)
			s->position = 1;
	}
	// printf("position:%d\n", s->position);
	if (s->position == 1)
		return (1);
	else
		return (2);
	return (0);
}

// void walk_in_map(t_info *s)
// {
// 	int a;
// 	int b;
// 	int c;
// 	int d;

// 	while (b < y - j)
// 	{
// 		a = 0;
// 		while (a < x - i)
// 		{
// 			c = 0;
// 			if (op == 0 && my == 1)
// 				coords(a,b);
// 			op = 0;
// 			my = 0;
// 			a++;
// 			while (d < i)
// 			{
// 				if (map[a][b] == my && piece[d] == '*')
// 					my++;
// 				if (map[a][b] == 'op' && piece[c][d] == '*')
// 					++op;
// 				++d;
// 			}
// 			++c;
// 		}
// 		b++;
// 	}
// }

void ft_check_name(char *str, t_info *s)
{
	// printf(">>%c\n", str[10]);
	if (ft_strstr(str, "gdanylov.filler") && ft_atoi(&str[10]) == 1)
	{
		printf("str:%s\n", str);
		s->my = 'O';
		s->other = 'X';
	}
	else if (ft_strstr(str, "gdanylov.filler") && ft_atoi(&str[10]) == 2)
	{
		s->my = 'X';
		s->other = 'O';
	}
}

void 	check_start_position(t_info *s)
{
	int y;
	int x;

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
	// printf("x_x:%d\n", s->start_x_x);
	// printf("x_y:%d\n", s->start_x_y);
	// printf("o_x:%d\n", s->start_o_x);
	// printf("o_y:%d\n", s->start_o_y);
}

void check_size(char *buff, t_info *s)
{
	int i;

	i = 0;
	// printf("\nokcheck\n");
	s->height = ft_atoi(&buff[8]);
	s->width = ft_atoi(&buff[11]);
	printf("width = %d\n", s->width);
	printf("height = %d\n", s->height);
	s->map = (char**)malloc(sizeof(char*) * s->height + 1);
	// get_next_line(0, &buff);
	while (i < s->height)
	{
		// printf("\nokwhile\n");
		get_next_line(0, &buff);
		s->map[i] = ft_strdup(buff + 4);
		i++;
	}
	check_start_position(s);
	check_position_in_map(s);
	s->map[i] = NULL;
	i = 0;
	printf("\nmap>>>\n");
	while (s->map[i])
	{
		printf("%s\n", s->map[i]);
		i++;
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
	printf("height_fig = %d\n", s->height_fig);
	printf("width_fig = %d\n", s->width_fig);
	i = 0;
	s->fig = (char**)malloc(sizeof(char*) * s->height_fig + 1);
	// get_next_line(0, &buff);
	while (i < s->height_fig)
	{
		get_next_line(0, &buff);
		s->fig[i] = ft_strdup(buff);
		i++;
	}
	s->fig[i] = NULL;
	write(1, "#\n", 2);
	i = 0;
	printf("\nfig>>>>>\n");
	while (s->fig[i])
	{
		printf("%s\n", s->fig[i]);
		i++;
	}
	check_start_position(s);
	// check_position_in_map(s);
	// walk_in_map(s);
}

int main(void)
{
	printf("\nok1\n");
	t_info s;
	int fd;
	// int i;
	char *buff;
	clear_struct(&s);
	// s = ft_memalloc(sizeof(t_info));
	fd = open("vika", O_RDONLY);
	while (get_next_line(fd, &buff))
	{
		if (!ft_strncmp(buff, "$$$ exec ", 9))
		{
			printf("buff1:%s\n", buff);
			printf("\nok2\n");
			ft_check_name(buff, &s);
		}
		if (!ft_strncmp(buff, "Plateau ", 8))
		{
			printf("buff2:%s\n", buff);
			printf("\nok3\n");
			check_size(buff, &s);
		}
		printf("buff3:%s\n", buff);
		if (!ft_strncmp(buff, "Piece ", 6))
		{
			printf("\nok4\n");
			check_figure(buff, &s);
		}
		// printf("buff4:%s\n", buff);
		// break;
		// printf("%s\n", buff);
	}
	// get_next_line(0, &buff);
	// printf("\nbuff2:%s\n", buff);
	return (0);
}