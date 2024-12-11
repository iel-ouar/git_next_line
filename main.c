#include "get_next_line_bonus.h"

int main(void)
{
    // FILE *file;
    // int fd;
    // char *line;

    // // Create the test file with some sample content
    // file = fopen("testfile.txt", "w");
    // if (file == NULL)
    // {
    //     perror("Error creating file");
    //     return (1);
    // }

    // fprintf(file, "Line 1: Hello, world!\n");
    // fprintf(file, "Line 2: This is a test.\n");
    // fprintf(file, "Line 3: Testing `get_next_line`.\n");
    // fprintf(file, "Line 4: File reading and printing.\n");
    // fprintf(file, "Line 5: End of file.\n");

    // fclose(file);

    // // Open the file to read
    // fd = open("testfile.txt", O_RDONLY);
    // if (fd < 0)
    // {
    //     perror("Error opening file");
    //     return (1);
    // }

    // // Read and print each line until EOF
    // while ((line = get_next_line(fd)) != NULL)
    // {
    //     printf("%s", line);
    //     free(line);
    // }

    // close(fd);
    // return (0);

    int fd;
    fd = open("test", O_RDONLY);
    int fd2;
    fd2 = open("test1", O_RDONLY);
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd2));
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd2));
    close(fd);
    close(fd2);
    
}
