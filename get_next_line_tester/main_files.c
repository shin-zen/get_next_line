#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int    main(int argc, char **argv)
{
    int        fd;
    char    *line;
	int		i;
	int 	ret;

    (void)argv;
	line = NULL;
	i = 1;
	if(argc > 1)
	{
		while ((fd = open(argv[i], O_RDONLY)) != -1)
    	{
			ret = get_next_line(fd, &line);
			if (line != NULL)
			{
    			printf("%s\n", line);
				free(line);
				line = NULL;
			}
			printf("ret:[%d]\n", ret);
			printf("fd == [%d]\n", fd);
			i++;
		}
    	close(fd);
	}
    return (0);
}
