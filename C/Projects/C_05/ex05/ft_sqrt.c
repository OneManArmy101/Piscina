#include <stdio.h>
int ft_sqrt(int nb)
{
    int sqrt;
    if (nb < 0 || nb > 2147395600)
        return (0);
    sqrt = 1;
    while (sqrt <= nb / sqrt)
    {
        if (sqrt * sqrt == nb)
        {
            return (sqrt);
        }
        sqrt++;
    }
    return (0);
}
/*int main()
{
    int number = 16; // Example number to find the square root of
    int sqrt = ft_sqrt(number);
    printf("The square root of %d is %d\n", number, sqrt);
    return 0;
}*/