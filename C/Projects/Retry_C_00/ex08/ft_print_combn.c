/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarti3 <almarti3@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:56:16 by almarti3          #+#    #+#             */
/*   Updated: 2024/02/15 14:30:08 by almarti3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	initialize_combination(int combination[], int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		combination[i] = i;
		i++;
	}
}

void	print_combination(int combination[], int n)
{
	char	digit;
	int		i;

	i = 0;
	while (i < n)
	{
		digit = combination[i] + '0';
		write(1, &digit, 1);
		i++;
	}
	if (combination[0] != 10 - n)
	{
		write(1, ", ", 2);
	}
}

void	update_combination(int combination[], int n, int *is_working)
{
	int		i;
	int		j;

	i = n - 1;
	while (i >= 0 && combination[i] == 9 - (n - 1 - i))
	{
		i--;
	}
	if (i < 0)
	{
		*is_working = 0;
	}
	else
	{
		combination[i]++;
		j = i + 1;
		while (j < n)
		{
			combination[j] = combination[j - 1] + 1;
			j++;
		}
	}
}

void	ft_print_combn(int n)
{
	int		combination[10];
	int		is_working;

	if (n <= 0 || n >= 10)
	{
		return ;
	}
	initialize_combination(combination, n);
	is_working = 1;
	while (is_working)
	{
		print_combination(combination, n);
		update_combination(combination, n, &is_working);
	}
}

/*
int	main(void)
{
	ft_print_combn(7);
	return (0);
}
*/
