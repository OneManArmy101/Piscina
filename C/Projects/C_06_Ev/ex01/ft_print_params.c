/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilsanc <guilsanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:34:21 by guilsanc          #+#    #+#             */
/*   Updated: 2024/02/28 20:27:51 by guilsanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	main(int argc, char *argv[])
{
	int	nl;
	int	i;

	nl = 10;
	i = 1;
	while (i < argc)
	{
		ft_putchar(argv[i]);
		write(1, &nl, 1);
		i++;
	}
	return (0);
}
