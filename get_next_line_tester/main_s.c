#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int    main(int argc, char **argv)
{
    int        i;
    int        fd;
    int        r;
    char    *get_line;

    (void)argc;
    i = 0;
    fd = open(argv[1], O_RDONLY);
    while (i++ < 5)
    {
        r = get_next_line(fd, &get_line);
        printf("%d\n", r);
        if (r == -1)
        {
            break ;
        }
        printf("%s\n", get_line);
        free(get_line);
    }
    close(fd);
    return (0);
}
