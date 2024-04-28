#include "values.h"

int		x_size;
int		y_size;
char	empty_char;
char    obstacle_char;
char	square_char;
char 	*ptr_file;
int 	row_size;
int     max_size;

void	analyze_file()
{
	int i;
	int char_checker;

	x_size = 0;
	i = 3;

	char_checker = initialize_visual_chars();
	if (char_checker == -1)
		return;

	if (empty_char == '\0' || obstacle_char == '\0' || square_char == '\0')
	{
		write_map_error();
		return;
	}

	while (ptr_file[i] != '\0')
	{
		if (ptr_file[i] == '\n')
		{
 			row_size++;
		}
		if(ptr_file[i] != empty_char && ptr_file[i] != square_char
				&& ptr_file[i] != obstacle_char && ptr_file[i] != '\n')
		{
			write_map_error();
			return;
		}
		i++;
	}
	if(i == 0)
		return;
}

char	check_val_char(char value)
{
	if (value < 33 && value > 126)
		return '\0';
	if (value != empty_char && value != square_char && value != obstacle_char)
		return value;
	else
	{
		write_map_error();
		return '\0';
	}
}

int	initialize_visual_chars()
{
    char ch;
	if (ptr_file[0] == '\n')
		return (-1);
	ch = check_val_char(ptr_file[0]);
    y_size = ch - '0';
	x_size = 3 * y_size;
    max_size = y_size;
	if (ptr_file[1] == '\n')
		return (-1);
	empty_char = check_val_char(ptr_file[1]);
	if (ptr_file[2] == '\n')
		return (-1);
	obstacle_char = check_val_char(ptr_file[2]);
	if (ptr_file[3] == '\n')
		return (-1);
	square_char = check_val_char(ptr_file[3]);
	return (1);
}
