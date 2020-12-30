#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int    main(int argc, char **argv)
{
    int        fd;
    int        fd2;
    char    *line;
	int		ret;
	int		ret2;

    (void)argv;
	line = NULL;
	ret = -1;
	ret2 = -1;
	if (argc == 1)
	{
		while(1)
		{
			get_next_line(0,&line);
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
		fd = open(argv[1], O_RDONLY);
    	fd2 = open(argv[2], O_RDONLY);
		while (1)
    	{
			if (ret != 0)
			{
				ret = get_next_line(fd, &line);
				if (line != NULL)
				{
    				printf("%s\n", line);
					free(line);
					line = NULL;
				}
				printf("%d\n", ret);
			}
			if (ret2 != 0)
			{
				ret2 = get_next_line(fd2, &line);
				//printf("%d\n", ret2);
				if (line != NULL)
				{

    				printf("%s\n", line);
    				free(line);
					line = NULL;
					printf("%d\n", ret2);
				}
			}
			if (fd2 == -1)
				if (ret == 0)
					break ;
			if (ret == 0 && ret2 == 0)
				break ;
		}
    	close(fd);
    	close(fd2);
	}
    return (0);
}
