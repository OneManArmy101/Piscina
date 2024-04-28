#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char code_numbers[41][20];
char code_values[41][20];
char *ft_strstr_target(char *str, char *to_find);
void read_dict(char * name, int ** ptr);
char *ft_strcat(char *dest, char *src);
char *ft_strcpy(char *dest, char *src);
void initialize_values();
void create_number_txt(int nb);
int ft_atoi(const char *str);
char *ft_strstr_target(char *str, char *to_find)
{
    int i;
    int j;
    int counter;
    char * target_val;

    i = 0;
    j = 0;
    counter = 0;
    target_val = malloc(20);
    while (str[i] != '\0')
    {
        if (str[i] == to_find[counter])
            counter++;
        else if (to_find[counter] == '\0')
        {
            while(str[i] != '\n')
            {
                target_val[j] = str[i];
                j++;
                i++;
            }
            //esta línea es sólo para evitar errores
            target_val[j] = '\0';
            return target_val;
        }
        i++;
    }
    free(target_val);
    return NULL;
}
void read_dict(char * name, int ** ptr)
{
    int dict;
    int is_read;
    char error[6] = {"Error"};
    char * word_to_find;
    int i;
    dict = open(name, O_RDONLY);
    //Si no se leyó correctamente
    if (dict == -1)
    {
        write(1, error, 6);
        return;
    }
    *ptr = malloc(2000);
    int ret = 500;
    ret = read(dict, *ptr, 500);
    int size = ret;
    while (ret == 500)
    {
        ret = read(dict, *ptr, 500);
        size += ret;
    }
    is_read = read(dict, *ptr, 500);
    printf("%d\n", is_read);
    is_read = read(dict, *ptr, 500);
    printf("%d\n", is_read);
    if (is_read == -1)
    {
        free(ptr);
        return;
    }
    i = 0;
    while(i < 41)
    {
        word_to_find = ft_strstr_target((char*)ptr, code_numbers[i]);
        if (word_to_find != NULL)
        {
            ft_strcpy(code_values[i], word_to_find);
        }
        i++;
    }
}
void initialize_values()
{
    int i;
    int counter;
    i = 0;
    while(i < 41)
    {
        ft_strcpy(code_numbers[i], "");
        ft_strcpy(code_values[i], "");
        i++;
    }
    i = 1;
    counter = 1;
    while (i <= 20)
    {
        code_numbers[i][0] = counter + ':';
        i++;
        counter++;
    }
    while(i <= 29)
    {
        code_numbers[i][0] = counter + ':';
        i++;
        counter += 10;
    }
    while(i < 42)
    {
        code_numbers[i][0] = counter + ':';
        i++;
        counter *= 1000;
    }
}
int main(int argc, char *argv[])
{
    int nb;
    int *ptr;
    char *name = {"numbers.dict"};
    if (argc != 2)
    {
        return (1);
    }
    nb = ft_atoi(argv[1]);
    if (nb < 0)
    {
        return (1);
    }
    initialize_values();
    read_dict(name, &ptr);
    create_number_txt(nb);
    free(ptr);
    return (0);
}
void create_number_txt(int nb) //Aquí antes estaba *ptr, pero lo he quitado ya que con las flags
                                //da error
{
    int nb_holder;
    char txt_nb[80]; //Aquí va lo que obtengamos
    int cont;
    cont = 0;
    ft_strcpy(txt_nb, "");
    if (nb == 0) {
        ft_strcat(txt_nb, code_values[0]);
        return;
    }
    while (nb > 0) {
        nb_holder = nb % 1000;
        nb /= 1000;
        if (nb_holder > 0) {
            ft_strcat(txt_nb, code_values[nb_holder / 100]);
            if (nb_holder >= 100) {
                ft_strcat(txt_nb, " ");
                ft_strcat(txt_nb, code_values[28]); // cien
                if (nb_holder % 100 != 0)
                {
                    ft_strcat(txt_nb, " and ");
                }
                nb_holder %= 100;
            }
            if (nb_holder >= 20)
            {
                ft_strcat(txt_nb, " ");
                ft_strcat(txt_nb, code_values[20 + nb_holder / 10 - 2]); // de decena en decena
                nb_holder %= 10;
            }
            if (nb_holder > 0)
            {
                ft_strcat(txt_nb, " ");
                ft_strcat(txt_nb, code_values[nb_holder]);
            }
            if (cont > 0)
            {
                ft_strcat(txt_nb, " ");
                ft_strcat(txt_nb, code_values[cont + 28]); // aumentando 3 ceros a la vez
            }
        }
        cont++;
    }
    write(1, txt_nb, 20);
}
char *ft_strcpy(char *dest, char *src)
{
    int i;
    i = 0;
    while(src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
int ft_atoi(const char *str)
{
    int res;
    int negative;
    negative = 1;
    res = 0;
    while (*str && (*str == ' ' || *str == '\n' || *str == '\t' ||
            *str == '\v' || *str == '\f' || *str == '\r'))
        ++str;
    if (*str == '-')
        negative = -1;
    if (*str == '-' || *str == '+')
        ++str;
    while (*str && *str >= '0' && *str <= '9')
    {
        res = res * 10 + (*str - 48);
        ++str;
    }
    return (res * negative);
}
char *ft_strcat(char *dest, char *src)
{
    int i;
    int j;
    i = 0;
    j = 0;
    while(dest[i] != '\0')
    {
        i++;
    }
    while(src[j] != '\0')
    {
        dest[i + j] = src[j];
        j++;
    }
    return (dest);
}