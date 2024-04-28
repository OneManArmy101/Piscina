#include "values.h"

int max_size;
int x_size;
int y_size;
char square_char;

void write_map(char ** matrix)
{
    int x_ctr;
    int y_ctr;
    char holder;
    y_ctr = 0;
    write(1, &matrix[0][0], 1);
    while(y_ctr < y_size)
    {
        x_ctr = 0;
        while(x_ctr < x_size)
        {
            holder = matrix[y_ctr][x_ctr];
            write(1, &holder, 1);
            x_ctr++;
        }
        write(1, "\n", 1);
        y_ctr++;
    }
}
