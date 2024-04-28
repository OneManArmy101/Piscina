/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarti3 <almarti3@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:25:56 by almarti3          #+#    #+#             */
/*   Updated: 2024/02/15 14:19:17 by almarti3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write_numbers(int i, int j, char nums[])
{
	if (i == 98 && j == 99)
	{
		write(1, nums, 5);
	}
	else
	{
		write(1, nums, 7);
	}
}

void	ft_generate_numbers(int i, int j, char nums[])
{
	nums[0] = '0' + i / 10;
	nums[1] = '0' + i % 10;
	nums[2] = ' ';
	nums[3] = '0' + j / 10;
	nums[4] = '0' + j % 10;
	nums[5] = ',';
	nums[6] = ' ';
}

void	ft_print_comb2(void)
{
	int		i;
	int		j;
	char	nums[7];

	i = 0;
	while (i < 100)
	{
		j = i + 1;
		while (j < 100)
		{
			ft_generate_numbers(i, j, nums);
			ft_write_numbers(i, j, nums);
			j++;
		}
		i++;
	}
}

/*
int	main(void)
{
	ft_print_comb2();
}
*/
