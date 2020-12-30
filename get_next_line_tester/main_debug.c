#include "get_next_line.h"
#include <stdio.h>

int    main(void)
{
    int        fd;
	char    *line;
	int		ret;

	fd = open("test1.txt", O_RDONLY);
	//while (1)
    //{
		ret = get_next_line(fd, &line);
    	printf("%s\n", line);
		printf("%d\n", ret);
		free(line);
		line = NULL;
	//	if (ret == 0)
	//		break ;
	//}
	close(fd);
    return (0);
}
