#include <stdio.h>

void	ft_putchar(char ch);

/* chars = {
	
 * arribaIzquierda, 
 * arribaDerecha,

 * vertical, 
 * horizontal, 
 
 * abajoIzquierda, 
 * abajoDerecha}*/

char	*ft_get_chars(int rush)
{
	char	*rush_chars;

	rush_chars = NULL;

	if (rush == 0)
	{
		rush_chars = "oo|-oo";
	}
	else if (rush == 1)
	{
		rush_chars = "/\\**\\/";
	}
	else if (rush == 2)
	{
		rush_chars = "AABBCC";
	}
	else if (rush == 3)
	{
		rush_chars = "ACBBAC";
	}
	else if (rush == 4)
	{
		rush_chars = "ACBBCA";
	}
	return (rush_chars);
}

void	ft_check_bottom(int curr_val[], int size[], int current_rush)
{
	if (curr_val[1] == size[1]&& size[1] > 1)
	{
		if (curr_val[0] == 1)
		{
			ft_putchar(ft_get_chars(current_rush)[4]);
		}
		else if (curr_val[0] == size[0])
		{
			ft_putchar(ft_get_chars(current_rush)[5]);
		}
		else
		{
			ft_putchar(ft_get_chars(current_rush)[3]);
		}
	}
}

void	ft_check_middle(int curr_val[], int size[], int current_rush)
{
	if (curr_val[1] > 1 && curr_val[1] < size[1])
	{
		if (curr_val[0] == 1 || curr_val[0] == size[0])
		{
			ft_putchar(ft_get_chars(current_rush)[2]);
		}
		else
		{
			ft_putchar(' ');
		}
	}
	ft_check_bottom(curr_val, size, current_rush);
}

void	ft_check_top(int curr_val[], int size[], int current_rush)
{
	if (curr_val[1] == 1)
	{
		if (curr_val[0] == 1)
		{
			ft_putchar(ft_get_chars(current_rush)[0]);
		}
		else if (curr_val[0] == size[0])
		{
			ft_putchar(ft_get_chars(current_rush)[1]);
		}
		else
		{
			ft_putchar(ft_get_chars(current_rush)[3]);
		}
	}
	ft_check_middle(curr_val, size, current_rush);
}

void	rush(int horizontal_size, int vertical_size, int current_rush)
{
	int counters[2];
	int curr_val[2];
	int size[2];

	if (horizontal_size < 1 || vertical_size < 1 || current_rush < 0)
		return ;
	if (horizontal_size > 50 || vertical_size > 50 || current_rush > 4)
		return ;
	counters[0] = 1;
	counters[1] = 1;
	size[0] = horizontal_size;
	size[1] = vertical_size;
	while (counters[1] <= vertical_size)
	{
		while (counters[0] <= horizontal_size)
		{
			curr_val[0] = counters[0];
			curr_val[1] = counters[1];
			ft_check_top(curr_val, size, current_rush);
			counters[0]++;
		}
		counters[1]++;
		counters[0] = 1;
		ft_putchar('\n');
	}
}








