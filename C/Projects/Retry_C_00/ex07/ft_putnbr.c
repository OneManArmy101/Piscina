/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarti3 <almarti3@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:55:08 by almarti3          #+#    #+#             */
/*   Updated: 2024/02/15 14:30:26 by almarti3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	cont_digitos(int nb)
{
	int		cont;

	cont = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		nb = -nb;
	while (nb != 0)
	{
		nb /= 10;
		cont++;
	}
	return (cont);
}

void	ft_putnbr(int nb)
{
	int		nb_t;
	int		nb_rest;
	int		cont;
	char	c[10];

	nb_t = nb;
	cont = cont_digitos(nb);
	while (cont > 0)
	{
		nb_rest = nb_t % 10;
		nb_t /= 10;
		if (nb > 0)
			c[cont - 1] = '0' + nb_rest;
		else
			c[cont - 1] = '0' - nb_rest;
		cont--;
	}
	if (nb < 0)
		write(1, "-", 1);
	write(1, c, cont_digitos(nb));
}

/*
int	main(void)
{
	ft_putnbr(0);
	return (0);
}
*/
