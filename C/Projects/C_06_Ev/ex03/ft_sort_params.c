/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilsanc <guilsanc@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 21:13:27 by guilsanc          #+#    #+#             */
/*   Updated: 2024/02/28 20:59:33 by guilsanc         ###   ########.fr       */
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

void	ft_print_params(int argc, char *argv[])
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
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return ((unsigned char)(*s1) - (unsigned char)(*s2));
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	**argv_cp;
	char	*aux_str;

	argv_cp = argv;
	i = 1;
	while (i != argc)
	{
		j = i + 1;
		while (j != argc)
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
			{
				aux_str = argv[i];
				argv[i] = argv[j];
				argv[j] = aux_str;
			}
			j++;
		}
		i++;
	}
	ft_print_params(argc, argv_cp);
	return (0);
}
