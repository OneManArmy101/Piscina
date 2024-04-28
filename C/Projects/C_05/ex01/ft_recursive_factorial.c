/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarti3 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:44:26 by almarti3          #+#    #+#             */
/*   Updated: 2024/02/29 21:44:28 by almarti3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
	{
		return (0);
	}
	if (nb == 0)
	{
		return (1);
	}
	return (nb * ft_recursive_factorial(nb - 1));
}
/*int main()
{
	int numero = 5; // Puedes cambiar este valor para proba
	con diferentes números
	int resultado = ft_recursive_factorial(numero);
	printf("El factorial de %d es: %d\n", numero, resultado);
	return 0;
}*/
