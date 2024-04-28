/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilsanc <guilsanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:40:16 by guilsanc          #+#    #+#             */
/*   Updated: 2024/02/28 20:34:18 by guilsanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char *str)
{
	int	nl;

	nl = 10;
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, &nl, 1);
}

int	main(int argc, char **argv)
{
	int		i;

	i = argc - 1;
	while (i != 0)
	{
		ft_putchar(argv[i]);
		i--;
	}
	return (0);
}
