/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarti3 <almarti3@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:42:46 by almarti3          #+#    #+#             */
/*   Updated: 2024/02/19 12:43:14 by almarti3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	holder;

	holder = *a;
	*a = holder / *b;
	*b = holder % *b;
}

/*
int main()
{
	int val_a;
	int val_b;

	val_a = 7;
	val_b = 3;
	ft_ultimate_div_mod(&val_a, &val_b);
}
*/
