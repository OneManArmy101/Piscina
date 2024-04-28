#include "values.h"
int x_size;
int y_size;
int max_size;
char empty_char;
char square_char;

void calculate_square(char ** matrix)
{
    int x_val;
    int y_val;
    int x_sqr_ctr;
    int y_sqr_ctr;
    int break_while;
    int found_square;

    y_val = 0;
    break_while = 0;
    found_square = 0;
    while(max_size > 1)
    {
        if(x_val + max_size > x_size || y_val + max_size > y_size)
            continue;
        while(y_val < y_size)
        {
            x_val = 0;
            while(x_val < x_size)
            {
                y_sqr_ctr = 0;
                while(y_sqr_ctr < max_size)
                {
                    x_sqr_ctr = 0;
                    while(x_sqr_ctr < max_size)
                    {
                        if(matrix[x_val][y_val] != empty_char)
                        {
                            x_sqr_ctr++;
                            break_while = 1;
                            found_square = 0;
                            max_size--;
                            break;
                        }
                        else
                            found_square++;
                        x_sqr_ctr++;
                    }
                    if(break_while == 1)
                    {
                        break_while = 0;
                        x_sqr_ctr = 0;
                        break;
                    }
                    y_sqr_ctr++;
                }
                if(found_square == max_size * max_size)
                {
                    asign_square(matrix, x_val, y_val);
                    max_size = 0;
                    break;
                }
                x_val++;
            }
            if(found_square == max_size * max_size)
                break;
            y_val++;
        }
        x_val = 0;
        y_val = 0;
        x_sqr_ctr = 0;
        y_sqr_ctr = 0;
    }
    if(max_size == 1)
        write(1, &square_char, 1);
}

void initialize_matrix()
{
    int i;
    
    char **matrix;
    matrix = malloc(y_size);

    if (matrix == NULL)
        return;
    i = 0;
    while (i < y_size)
    {
        matrix[i] = malloc(x_size);
        if (matrix[i] == NULL)
            return;
        int j = 0;
        while (j < x_size)
        {
            matrix[i][j] = ptr_file[(i * x_size) + j];
            j++;
        }
        i++;
    }
    calculate_square(matrix);
}

void asign_square(char ** matrix, int start_x, int start_y)
{
    int x_ctr;
    int y_ctr;

    x_ctr = 0;
    y_ctr = 0;
    while(y_ctr < max_size + start_y)
    {
        x_ctr = start_x;
        while(x_ctr < max_size + start_x)
        {
            matrix[x_ctr][y_ctr] = square_char;
            x_ctr++;
        }
        y_ctr++;
    }
    write_map(matrix);
}