/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 14:12:41 by gdanylov          #+#    #+#             */
/*   Updated: 2017/12/25 14:12:42 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/get_next_line.h"
# include <fcntl.h>

typedef struct		s_fil
{
	int				x;
	int				y;
	struct s_fil	*next;
}					t_fil;

typedef struct	s_s
{
	char		*t;
	char		*d;
	int			ret;
	char		*buf;
	char		*tmp;
	t_list		*buf2;
}				t_s;

int				get_next_line(const int fd, char **line);


typedef struct	s_info
{
	char		my;
	char 		other;
	int			width_map;
	int			height_map;
	char 		**map;
	int			width_fig;
	int			height_fig;
	char		**fig;
	int			start_x_x;
	int			start_x_y;
	int			start_o_x;
	int			start_o_y;
	int			position;
	int x_map;
	int y_map;
	int count;
	int i_fig;
	int j_fig;
	int a_my;
	int b_other;
	int save;
	int res_x;
	int res_y;
	int distance;

}				t_info;

// void check_other_func(t_info *s);
int				get_next_line(const int fd, char **line);
void check_other_func(t_info *s);
void check_start_position(t_info *s);
void check_position_in_map(t_info *s);
void check_figure(char *buff, t_info *s);
void	ft_check_name(char *str, t_info *s);
void check_size(char *buff, t_info *s);
void walk_in_map(t_info *s);


void		cl_st(t_info *s);

int 	other(char c, t_info *s);
int check_in_the_map(int x, int y, t_info *s);

// delete
void print_map_fig(char **map, int height, int width);

int my(char c, t_info *s);


#endif
