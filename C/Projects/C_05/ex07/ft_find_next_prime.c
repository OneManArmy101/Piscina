#include <stdio.h>

int ft_find_next_prime(int nb)
{
    int i;
    int j;
    int has_found;

    i = nb + 1;
    has_found = 0;
    while(has_found == 0)
    {
        j = 2;
        while(j < i)
        {
            if(i % j == 0)
            {
                break;
            }
            j++;
        }
        if(j == i)
            has_found = 1;
        else
            i++;
    }
    return (i);
}

int main()
{
    printf("%i", ft_find_next_prime(24));
    return (0);
}