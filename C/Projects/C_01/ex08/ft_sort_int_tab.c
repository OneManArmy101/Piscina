/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarti3 <almarti3@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:47:51 by almarti3          #+#    #+#             */
/*   Updated: 2024/02/19 12:48:30 by almarti3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

int	ft_change_order(int *tab, int i, int counter)
{
	int	holder;

	if (tab[i] > tab[i + 1])
	{
		holder = tab[i];
		tab[i] = tab[i + 1];
		tab[i + 1] = holder;
	}
	else
	{
		counter++;
	}
	return (counter);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	in_order;
	int	counter;

	in_order = 0;
	i = 0;
	counter = 0;
	while (in_order == 0)
	{
		i = 0;
		counter = 0;
		while (i < size)
		{
			counter = ft_change_order(tab, i, counter);
			i++;
		}
		if (counter == size)
		{
			in_order = 1;
		}
	}
	char ch;
	i = 0;
	while (i < size)
	{
		ch = '0' + tab[i];
		write(1, &ch, 1);
		i++;
	}
}

/*
	char ch;
	i = 0;
	while (i < size)
	{
		ch = '0' + tab[i];
		write(1, &ch, 1);
		i++;
	}
*/


int main()
{
	int nb[5] = { 3, 7, 2, 5, 1 };
	ft_sort_int_tab(nb, 5);
	return (0);
}

