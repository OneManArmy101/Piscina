/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarti3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:43:35 by almarti3          #+#    #+#             */
/*   Updated: 2024/02/29 21:43:38 by almarti3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	ft_iterative_factorial(int nb)
{
	int	factorial;
	int	i;

	if (nb < 0)
	{
		return (0);
	}
	factorial = 1;
	i = 1;
	while (i <= nb)
	{
		factorial *= i;
		i++;
	}
	return (factorial);
}
/*
int main(void)
{
    int num = 5;  // Puedes cambiar este valor para probar con diferentes números
    int result = ft_iterative_factorial(num);
    printf("El factorial de %d es %d\n", num, result);
    return 0;
}
*/
