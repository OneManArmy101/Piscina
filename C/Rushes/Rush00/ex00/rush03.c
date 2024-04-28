/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorenil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:28:42 by fmorenil          #+#    #+#             */
/*   Updated: 2024/02/11 19:30:38 by fmorenil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	create_line(int i, int j, int x, int y)
{
	if (i == 0)
	{
		if (j == 0)
			ft_putchar('A');
		else if (j == x - 1)
			ft_putchar('C');
		else
			ft_putchar('B');
	}
	else if (i == y - 1)
	{
		if (j == 0)
			ft_putchar('A');
		else if (j == x - 1)
			ft_putchar('C');
		else
			ft_putchar('B');
	}
	else
	{
		if (j == 0 || j == x - 1)
			ft_putchar('B');
		else
			ft_putchar(' ');
	}
}

void	check_row(int x, int y, int i)
{
	int	j;

	j = 0;
	while (j < x)
	{
		create_line(i, j, x, y);
		j++;
	}
}

void	rush(int x, int y)
{
	int		i;
	char	*error;
	char	*limit;

	error = "No se pueden introducir datos negativos o con valor de 0 :(\n";
	limit = "242, 242 son las dimensiones máximas ;)\n";
	i = 0;
	if (x <= 0 || y <= 0)
	{
		write(1, error, 61);
	}
	else if (x > 242 || y > 242)
	{
		write(1, limit, 42);
	}
	else
	{
		while (i < y)
		{
			check_row(x, y, i);
			ft_putchar('\n');
			i++;
		}
	}
}
