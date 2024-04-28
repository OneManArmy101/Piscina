#include "values.h"

int main(int argc, char* argv[])
{
    int arg_counter;
    char *ptr;

    arg_counter = 1;
    
    while(arg_counter < argc)
    {
        ptr = ft_read_file(argv[arg_counter]);
        analyze_file();
        initialize_matrix();
        arg_counter++;
    }
    return 0;
}