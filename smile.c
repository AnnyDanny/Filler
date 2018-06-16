#include <stdio.h>
#include <locale.h>
#include "filler.h"
#include "libft/get_next_line.h"
#include "libft/includes/libft.h"



int main(void)
{
	// ft_printf("hello\n");
	setlocale (LC_ALL, "");
	char *buff;

	// ft_printf("hello\n");
	while (get_next_line(0, &buff) > 0)
	{
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
					if (buff[i] == 'o' || buff[i] == 'O')
						printf("%C", L'😃');
					else if (buff[i] == '.')
						printf("%C", L'💓');
					else if (buff[i] == 'x' || buff[i] == 'X')
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