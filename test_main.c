#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    int fd;

    fd = open("testtext.txt", O_RDONLY);
    //get_next_line(fd);
    printf("%s", get_next_line(fd));
    return (0);

}