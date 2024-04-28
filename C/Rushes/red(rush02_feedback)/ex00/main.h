extern char code_numbers[41][20];
extern char code_values[41][20];

struct list
{
    int             key;
    char            *value;
    struct list     *next;
    struct list     *prev;
}