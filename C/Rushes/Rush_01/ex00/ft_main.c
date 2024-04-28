#include <stdio.h>
#include <unistd.h>
#include "matrix.h"
void ft_change_line(int x, int y, int line_type, int direction);
void ft_obtain_parameters(char *input_parameters, int *parameters);
void ft_write_matrix();
void ft_check_fours(int * parameters);
void ft_check_number(int * parameters, int val_to_check, int val_to_add);
void ft_change_number(int x, int y, int target_val);
void ft_check_one_sym(int * parameters);
void check_nb_rep(int val_to_check);
void check_all_axis();

int four_x[4];
int four_y[4];

int main(int argc, char* argv[])
{
    char *error01;
    int parameters[16];
    error01 = "Introduzca un solo parámetro\n";
    if(argc != 2)
    {
        write(1, error01, 29);
        return 1;
    }
    ft_obtain_parameters(argv[1], parameters);

    ft_check_fours(parameters);
    ft_check_number(parameters, 1, 4);
    ft_check_one_sym(parameters);
    check_nb_rep(4);
    check_all_axis();
    ft_write_matrix();
    return 0;
}
void ft_obtain_parameters(char *input_parameters, int *parameters) {
    int i = 0;
    int j = 0;
    char *error02;
    error02 = "Sólo puede poner valores entre 1 y 4\n";
    while(input_parameters[i] != '\0' && j < 16)
    {
        if(input_parameters[i] != ' ')
        {
            if(input_parameters[i] >= '1' && input_parameters[i] <= '4')
            {
                parameters[j] = input_parameters[i] - '0';
                j++;
            }
            else
            {
                write(1, error02, 38);
                return;
            }
        }
        i++;
    }
}

void ft_check_fours(int * parameters)
{
    int i;

    i = 0;
    while(i < 16)
    {
        if(parameters[i] == 4)
        {
            if(i < 4)
            {
                ft_change_line(i, 0, 1, 1);
            }
            else if(i < 8)
            {
                ft_change_line(i - 4, 3, 1, -1);
            }
            else if(i < 12)
            {
                ft_change_line(i - 8, 0, 0, 1);
            }
            else
            {
                ft_change_line(i - 12, 3, 0, -1);
            }
        }
        i++;
    }
}

void ft_check_number(int * parameters, int val_to_check, int val_to_add)
{
    int i;

    i = 0;
    while(i < 16)
    {
        if(parameters[i] == val_to_check)
        {
            if(i < 4)
            {
                ft_change_number(0, i, val_to_add);
            }
            else if(i < 8)
            {
                ft_change_number(3, i - 4, val_to_add);

            }
            else if(i < 12)
            {
                ft_change_number(i - 8, 0, val_to_add);
            }
            else
            {
                ft_change_number(i - 12, 3, val_to_add);
            }
        }
        i++;
    }
}

void ft_check_one_sym(int * parameters)
{
    if((parameters[0] == parameters[8]) || parameters[3] == parameters[12])
    {
        if((parameters[11] == parameters[4]) || parameters[15] == parameters[7])
        {
            if(parameters[9] == 3)
            {
                ft_change_number(1, 2, 4);
            }
            else if(parameters[10] == 3)
            {
                ft_change_number(2, 1, 4);
            }
            else if(parameters[13])
            {
                ft_change_number(1, 1, 4);
            }
            else if(parameters[14])
            {
                ft_change_number(2, 2, 4);
            }
        }
    }
}

void check_nb_rep(int val_to_check)
{
    int i;
    int j;
    int row_checks[4] = {0};
    int col_checks[4] = {0};
    int result[2] = {-1};

    i = 0;
    while(i < 4)
    {
        j = 0;
        while(j < 4)
        {
            if(matrix[i][j] == val_to_check)
            {
                row_checks[i] = 1;
                col_checks[j] = 1;
                if(val_to_check == 4 && four_x[i] == -1)
                {
                    four_x[j] = i;
                    four_y[j] = j;
                }
            }
            j++;
        }
        i++;
    }
    i = 0;
    while(i < 4)
    {
        if(row_checks[i] == 0)
        {
            result[0] = i;
            break;
        }
        i++;
    }
    i = 0;
    while(i < 4)
    {
        if(col_checks[i] == 0)
        {
            result[1] = i;
            break;
        }
        i++;
    }
    if((result[0] != -1) && (result[1] != -1))
    {
        matrix[result[0]][result[1]] = 4;
    }
}

void check_four_relatives()
{
    int i;
    i = 0;
    while(i < 4)
    {
        check_all_axis();
        i++;
    }
}

//UNFINISHED
void check_all_axis()
{

    int dist;
    int curr_dist;
   
    // if(four_x[0] == 2)
    // {
    //     if(four_y[0] == 2)
    //     {               
    //         val_matrix[four_x[0]][four_y[0]][0] = 1;
    //         val_matrix[four_x[0]][four_y[0]][1] = 2;
    //         val_matrix[four_x[0]][four_y[1]][1] = 2;
    //         val_matrix[four_x[0]][four_y[1]][1] = 3;
    //     }
    //     else if(four_y[0] == 3)
    //     {
    //         val_matrix[four_x[0]][four_y[0]][0] = 2;
    //         val_matrix[four_x[0]][four_y[0]][1] = 1;
    //         val_matrix[four_x[0]][four_y[1]][0] = 2;
    //         val_matrix[four_x[0]][four_y[1]][1] = 1;
    //         val_matrix[four_x[0]][four_y[1]][2] = 3;
    //     }
    // }
    // else if(four_x[0] == 3)
    // {
    //     if(four_y[10] == 2)
    //     {               
    //         val_matrix[four_x[0]][four_y[0]][0] = 2;
    //         val_matrix[four_x[0]][four_y[0]][1] = 3;
    //         val_matrix[four_x[0]][four_y[1]][0] = 1;
    //         val_matrix[four_x[0]][four_y[1]][1] = 2;
    //     }
    //     else if(four_y[0] == 3)
    //     {
    //         val_matrix[four_x[0]][four_y[0]][0] = 2;
    //         val_matrix[four_x[0]][four_y[0]][1] = 3;
    //         val_matrix[four_x[0]][four_y[0]][2] = 1;
    //         val_matrix[four_x[0]][four_y[1]][1] = 1;
    //         val_matrix[four_x[0]][four_y[1]][2] = 3;
    //         val_matrix[four_x[0]][four_y[2]][0] = 1;
    //         val_matrix[four_x[0]][four_y[2]][1] = 2;
    //     }
    // }
}

