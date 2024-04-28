/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilsanc <guilsanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:29:42 by guilsanc          #+#    #+#             */
/*   Updated: 2024/02/28 20:25:47 by guilsanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	char	*pname;
	char	nl;

	argc = 0;
	pname = argv[0];
	while (argc < 1)
	{
		while (*pname)
		{
			write(1, pname, 1);
			pname++;
		}
		nl = 10;
		write(1, &nl, 1);
		argc++;
	}
	return (0);
}
