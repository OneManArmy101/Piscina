/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarti3 <almarti3@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:41:02 by almarti3          #+#    #+#             */
/*   Updated: 2024/02/19 12:41:29 by almarti3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	holder;

	holder = *a;
	*a = *b;
	*b = holder;
}

/*
int main()
{
    int first_nb;
    int sec_nb;
    int *a = &first_nb;
    int *b = &sec_nb;

    first_nb = 7;
    sec_nb = 3;
    ft_swap(a, b);
    return (0);
}
*/
