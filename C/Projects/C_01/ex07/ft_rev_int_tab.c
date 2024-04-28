/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarti3 <almarti3@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:47:03 by almarti3          #+#    #+#             */
/*   Updated: 2024/02/19 12:47:30 by almarti3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	holder;

	i = 0;
	while (i < size / 2)
	{
		holder = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i -1] = holder;
		i++;
	}
}

/*
	i = 0;
	char ch;
	while(i < size)
	{
		ch = '0' + tab[i];
		write(1, &ch, 1);
		i++;
	}
	*/

/*
int main(void)
{
    int nb[3];

	nb[0] = 8;
	nb[1] = 1;
	nb[2] = 6;
    ft_rev_int_tab(nb, 3);
	return (0);
}
*/
