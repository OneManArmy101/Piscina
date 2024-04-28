#include <stdio.h>

int ft_find_next_prime(int nb)
{
    while (ft_is_prime(nb) == 0)
    {
        nb++;
    }
    return (nb);
}

int ft_is_prime(int nb)
{
    int i;

    i = 3;
    if(nb <= 1)
        return (0);
    if(nb % 2 == 0 && nb != 2)
        return (0);
    while (i * i <= nb)
    {
        if (nb % i == 0)
            return (0);
        i += 2;
    }
    return (1);
}

int main()
{
    printf("%i", ft_is_prime(19));
    return (0);
}