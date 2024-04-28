#include <unistd.h>
#include <stddef.h>
#include <fcntl.h>
#include <stdlib.h>

int initialize_visual_chars();
void initialize_matrix();
void analyze_file();
void write_map_error();
void write_map(char ** matrix);
char *ft_read_file(char * file_name);
void asign_square(char ** matrix, int start_x, int start_y);

extern int x_size;
extern int y_size;
extern int max_size;
extern char * ptr_file;

extern char empty_char;
extern char obstacle_char;
extern char square_char;

