#include "get_next_line.h"
// #include "get_next_line_bonus.h"

int main ()
{
    int fd;
    fd = open("test",O_RDONLY);
    // int n = 20;
    // char *line;
    // while (n >= 0)
    // {
    //     line = get_next_line(fd);
    //     printf("[%s]",line);
    //     free(line);
    //     n--;
    // }
    printf("%s",get_next_line(fd));
    close (fd);
}