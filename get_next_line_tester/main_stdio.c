#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int    main(void)
{
    int        i;
    int        fd;
    int        r;
    char    *get_line;

    i = 0;
    fd = 0;
    while (i++ < 2)
    {
        r = get_next_line(fd, &get_line);
        printf("%d\n", r);
        if (r == -1)
        {
            break ;
        }
        //printf("%s\n", get_line);
        free(get_line);
    }
    close(fd);
    return (0);
}
