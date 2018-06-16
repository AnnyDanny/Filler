/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 18:58:42 by gdanylov          #+#    #+#             */
/*   Updated: 2018/02/21 18:58:42 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "includes/libft.h"

# define PLUS 0
# define MINUS 1
# define HASH 2
# define SPACE 3
# define ZERO 4
# define H 5
# define L 6
# define HH 7
# define LL 8
# define Z 9
# define J 10

typedef struct		s_struct
{
	char			sp;
	int				flags[11];
	long long int	width;
	long long int	p;
	char			*str1;
	int				l1;
	int				i;
	int				l2;
	wchar_t			*s2;
}					t_struct;

typedef struct		s_arg
{
	char			*f;
	int				i;
}					t_arg;

int					ft_printf(char *format, ...);
void				check_flags1(int *i, char *format, t_struct *s);
void				check_flags2(int *i, char *format, t_struct *s);
void				check_flags3(int *i, char *format, t_struct *s);
void				check_flags4(int *i, char *format, t_struct *s);
void				check_flags5(int *i, char *format, t_struct *s);
int					print_nulls(t_struct *s, int count);
int					print_spaces(t_struct *s, int count);
int					check_space(t_struct *s);
void				check_flags(int *i, char *format, t_struct *s);
long long			check_flags_d(long long d, t_struct *s);
int					check_plus_minus(long long d, int count, t_struct *s);
long long			check_all_d_i_bd(t_struct *s, va_list arg, int count);
int					print_space(t_struct *s, int d, int count);
int					print_nulls_d(t_struct *s, int len, int count, int d);
int					print_spaces_d(t_struct *s, int len, int count, int d);
int					print_spaces_c(t_struct *s, int count);
int					check_flags_c(t_struct *s);
int					print_nulls_c(t_struct *s, int count);
int					print_spaces_s(t_struct *s, int count, int len);
int					print_nulls_s(t_struct *s, int count, int len);
int					print_nulls_null(t_struct *s, int count);
int					print_type_s(t_struct *s, va_list arg, int count);
int					print_type_c(t_struct *s, va_list arg, int count);
int					pr_sp_u_s(t_struct *s, int len, int count, char c);
size_t				num_bytes(wchar_t *str);
int					check_prec_bs(unsigned int c);
void				no_minus(t_struct *s, int *count);
void				yes_minus(t_struct *s, int *count);
int					pr_t_u_s(t_struct *s, va_list arg, int count);
int					ft_3_byte(unsigned int c);
int					ft_2_byte(unsigned int c);
int					ft_4_byte(unsigned int c);
int					print_type_uni_c(unsigned int c, int count);
unsigned long long	check_flags_u(unsigned long long u, t_struct *s);
int					print_spaces_o(t_struct *s, int len, int count);
int					print_nulls_o(t_struct *s, int len, int count);
int					check_null_o(unsigned long long nbr);
unsigned long long	check_flags_o(unsigned long long o, t_struct *s);
int					ft_hex_len(unsigned long long x, int y);
void				hexa(unsigned long long nbr, int len, char *res);
int					check_hash_x(unsigned long long x, t_struct *s, int count);
int					check_hash(unsigned long long x, t_struct *s, int count);
int					print_spaces_x(t_struct *s, int len, int count);
int					print_nulls_x(t_struct *s, int len, int count, int x);
unsigned long long	check_flags_x(unsigned long long x, t_struct *s);
int					s_p(t_struct *s, int len, int count, unsigned long long p);
int					p_z(t_struct *s, int len, int count, unsigned long long p);
int					print_hexa_x_p(unsigned long long nbr);
int					print_hexa_p(t_struct *s, va_list arg, int count);
int					print_type_x(t_struct *s, va_list arg, int count);
int					print_hexa_uni_x(unsigned long long int nbr);
int					print_type_uni_x(t_struct *s, va_list arg, int count);
void				clear_struct(t_struct *s);
int					ft_strlen_int(int num);
int					check_types(t_struct *s, va_list arg, int count);
int					ch_f(char *format, t_struct *s, va_list arg, int count);
int					check_plus_minus(long long d, int count, t_struct *s);
int					print_type_o(t_struct *s, va_list arg, int count);
int					print_type_u(t_struct *s, va_list arg, int count);
void				check_width_prec(int i, char *format, t_struct *s);
int					print_spaces_uni_s(t_struct *s, int len, int count, char c);
int					print_type_uni_s(t_struct *s, va_list arg, int count);

#endif
