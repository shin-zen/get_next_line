#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"


int main(int argc, char **argv)
{
	int	i;
	int j;
	int fd;
	int fd2;
	char	*line;

	i = 1;
	j = 1;
	if (argc <= 1)
		return (0);
	fd = open(argv[1], O_RDONLY);
    fd2 = 0;
	while (i > 0 || j > 0)
	{
		i = get_next_line(fd, &line);
		printf("ret = [%d]\n", i);
		if (i == -1)
			break ;
		printf("%s\n", line);
		free(line);
		line = NULL;
		j = get_next_line(fd2, &line);
		printf("ret = [%d]\n", j);
		if (j == -1)
			break ;
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	close(fd);
	close(fd2);
	//system("leaks ./a.out");
	return (0);
}
