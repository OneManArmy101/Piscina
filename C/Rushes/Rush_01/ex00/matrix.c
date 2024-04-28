#include <unistd.h>
#include "matrix.h"

void ft_write_matrix();
int matrix[4][4] = {0};
int * val_matrix[4][4];

int array1[3];
int array2[3];
int array3[3];
int array4[3];
int array5[3];
int array6[3];
int array7[3];
int array8[3];
int array9[3];
int array10[3];
int array11[3];
int array12[3];
int array13[3];
int array14[3];
int array15[3];
int array16[3];

void ft_change_number(int x, int y, int target_val)
{
    matrix[x][y] = target_val;
}

//line_type { 0 = row; 1 = column }     direction { 1 = positive; -1 = negative }
void ft_change_line(int x, int y, int line_type, int direction) 
{
    int i;
    int neg_i;
    
    if(direction == 1)
    {
        i = 0;
        while(i < 4)
        {
            if(line_type == 0)
            {
                ft_change_number(x, i, i + 1);
            }
            else if(line_type == 1)
            {
                ft_change_number(i, x, i + 1);
            }
            i++;
        }
    }
    else if(direction == -1)
    {
        i = 4;
        neg_i = 1;
        while(i > 0)
        {
            if(line_type == 0)
            {
                ft_change_number(x, i - 1, neg_i);
            }
            else if(line_type == 1)
            {
                ft_change_number(i - 1, y, neg_i);
            }
            i--;
            neg_i++;
        }
    }
}

void ft_write_matrix()
{
    int i;
    int j;
    char digit;

    i = 0;

    while(i < 4)
    {
        j = 0;
        while(j < 4)
        {
            digit = '0' + matrix[i][j];
            write(1, &digit, 1);
            write(1, " ", 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
}

void ft_assign_ptr_matrix()
{
    val_matrix[0][0] = array1;
    val_matrix[0][1] = array2;
    val_matrix[0][2] = array3;
    val_matrix[0][3] = array4;
    val_matrix[1][0] = array5;
    val_matrix[1][1] = array6;
    val_matrix[1][2] = array7;
    val_matrix[1][3] = array8;
    val_matrix[2][0] = array9;
    val_matrix[2][1] = array10;
    val_matrix[2][2] = array11;
    val_matrix[2][3] = array12;
    val_matrix[3][0] = array13;
    val_matrix[3][1] = array14;
    val_matrix[3][2] = array15;
    val_matrix[3][3] = array16;
}