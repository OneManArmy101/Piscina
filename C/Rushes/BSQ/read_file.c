#include "values.h"

char * ptr_file;

char *ft_read_file(char * file_name)
{
    int map_val;
    int is_read;
    int file_size;
    int index;
    char buffer;

    ptr_file = NULL;
    file_size = 0;
    index = 0;
    map_val = open(file_name, O_RDONLY);
    if (map_val == -1)
        return NULL;

    while((is_read = read(map_val, &buffer, 1)) > 0)
    {
        file_size++;
    }
    if(is_read == -1)
    {
        close(map_val);
        return NULL;
    }
    ptr_file = malloc(file_size + 1);

    if(ptr_file == NULL)
    {
        close(map_val);
        return NULL;
    }

    close(map_val);
    map_val = open(file_name, O_RDONLY);

    while((is_read = read(map_val, &buffer, 1)) > 0)
    {
        ptr_file[index++] = buffer;
    }

    if(is_read == -1)
    {
        free(ptr_file);
        close(map_val);
        return NULL;
    }

    ptr_file[file_size] = '\0';

    close(map_val);
    return ptr_file;    
}