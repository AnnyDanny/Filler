#include <stdio.h>
#include <locale.h>
#include "filler.h"
#include "libft/get_next_line.h"
#include "libft/includes/libft.h"

char my;
char other;

void	ft_check_name_s(char *str)
{
	if (ft_strstr(str, "gdanylov.filler") && ft_atoi(&str[10]) == 1)
	{
		my = 'O';
		other = 'X';
	}
	else if (ft_strstr(str, "gdanylov.filler") && ft_atoi(&str[10]) == 2)
	{
		my = 'X';
		other = 'O';
	}
}


int main(void)
{
	// ft_printf("hello\n");
	setlocale (LC_ALL, "");
	char *buff;
	
	// while (get_next_line(0, &buff) > 0)
	// {
	// 	if (ft_strstr(buff, "gdanylov.filler"))
	// 	{
	// 		if (ft_strstr(buff, "p1"))
	// 		{
	// 			my = 'O';
	// 			other = 'X';
	// 		}
	// 		else
	// 		{
	// 			my = 'X';
	// 			other = 'O';
	// 		}
	// 		break;
	// 	}
	// }
	// ft_printf("hello\n");
	while (get_next_line(0, &buff) > 0)
	{
		if (!ft_strncmp(buff, "$$$ exec ", 9))
		{
			ft_check_name_s(buff);
		}
		// ft_printf("hello2\n");
		if (!ft_strncmp(buff, "Plateau ", 8))
		{
			// ft_printf("hell3\n");
			system("clear");

			while (get_next_line(0, &buff) > 0)
			{
				if (!ft_strncmp(buff, "Piece ", 6))
					break;
				// ft_printf("hello\n");
				int i = 0;
				while (buff[i])
				{
					if (buff[i] == my || buff[i] == my + 32)
						printf("%C", L'🐧');
					else if (buff[i] == '.')
						printf("%C", L'💓');
					else if (buff[i] == other || buff[i] == other + 32)
						printf("%C", L'🐸');
					else
						printf("%c", buff[i]);
					i++;
				}
				printf("\n");
			}
			usleep(10000);
		}
		// ft_printf("%s\n", buff);
	}
	return (0);
}