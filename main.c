#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*temp;
	int		fd;
	char	*line1;
	char	*line2;
	char	*line3;
	char	*line4;
	char	*line;
	int i = 0;

	fd = open("gg.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL) 
	{
		printf("Line >> %s", line);
		free(line);
		line = get_next_line(fd);
	}
	// line1 = get_next_line(fd);

	// line2 = get_next_line(fd);
	// line3 = get_next_line(fd);
	// line4 = get_next_line(fd);

	// printf("Line 1: %s", line1);
	// printf("Line 2: %s", line2);
	// printf("Line 3: %s", line3);
	// printf("Line 4: %s", line4);

	// // i = 0;
	// // while (1)
	// // {
	// // 	temp = get_next_line(fd);
	// // 	if (!temp)
	// // 		break ;
	// // 	printf("%s", temp);
	// // 	free(temp);
	// // 	i++;
	// // }
	// free(line1);
	// free(line2);
	// free(line3);
	// free(line4);
	close(fd);
}