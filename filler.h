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

# include "libft/includes/libft.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>


# define BUFF_SIZE 5

typedef struct	s_struct
{
	char		*t;
	char		*d;
	int			ret;
	char		*buf;
	char		*tmp;
	t_list		*buf2;
}				t_struct;

int				get_next_line(const int fd, char **line);


typedef struct	s_info
{
	char		my;
	char 		other;
	int			width;
	int			height;
	char 		**map;
	int			width_fig;
	int			height_fig;
	char		**fig;
	int			start_x_x;
	int			start_x_y;
	int			start_o_x;
	int			start_o_y;
	int			position;

}				t_info;

int				get_next_line(const int fd, char **line);

#endif
