#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int    main(int argc, char **argv)
{
    int        fd;
    char    *line;
	int		ret;


    (void)argv;
	line = NULL;

	if (argc == 1)
	{
		while(1)
		{
			ret = get_next_line(42,&line);
			printf("%d\n", ret);
			if (printf("input:%s\n",line))
			{
				free(line);
				line = NULL;
				break ;
			}
		}
		return (0);
	}
	else if(argc > 1)
	{
		//fd = 42;
		fd = open(argv[1], O_RDONLY);
		while (1)
    	{
			ret = get_next_line(fd, &line);
			if (line != NULL)
			{
    			printf("%s\n", line);
				free(line);
				line = NULL;
			}
			printf("%d\n", ret);
			if (ret == 0)
				break ;
			if (ret == -1)
				break ;
		}
    	close(fd);
    }
    return (0);
}
