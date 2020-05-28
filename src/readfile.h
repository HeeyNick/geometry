
#include <stdio.h>
typedef struct{
    char name[100];
    int x;
    int y;
    int r;
}figure;
void skip_char(size_t* i, char* line, size_t symb);
int parse_coord(size_t* i, int* coord, char* line);
int scan_string(char* line, size_t number, figure* circle);
size_t read_file(char* str, figure* circle);



