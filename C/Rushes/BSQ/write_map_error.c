#include "values.h"
void write_map_error()
{
    char map_error_char[10];
    
    map_error_char[0] = 'm';
    map_error_char[1] = 'a';
    map_error_char[2] = 'p';
    map_error_char[3] = ' ';
    map_error_char[4] = 'e';
    map_error_char[5] = 'r';
    map_error_char[6] = 'r';
    map_error_char[7] = 'o';
    map_error_char[8] = 'r';
    map_error_char[9] = '\n';

    write(1, map_error_char, 10);
}