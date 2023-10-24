/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:15:31 by ischmutz          #+#    #+#             */
/*   Updated: 2023/10/24 18:13:39 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void	liberator(char *imprisoned_ptr)
{
	free(imprisoned_ptr);
	imprisoned_ptr = NULL;
}

static char	*readme(char *rawstr, int fd)
{
	int		bytes_read;
	char	*tinybuffer;

	tinybuffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (tinybuffer == NULL)
		return (NULL);
	while (!ft_strchr(tinybuffer, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, tinybuffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(tinybuffer), free(rawstr), NULL);
		/*if (bytes_read < 0)
			return (NULL);*/
		//printf("Buffer: %s\n", tinybuffer);
		if (bytes_read > 0)
			rawstr = ft_strjoin(rawstr, tinybuffer);
		if (rawstr == NULL)
			return (NULL);
		//printf("Line: %s\n", rawstr);
	}
	//printf("%s", tinybuffer);
	free(tinybuffer);
	return (rawstr);
}

char	*get_next_line(int fd)
{
	char		*cookeds;
	static char	*rawstr;
	size_t			len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rawstr = readme(rawstr, fd);
	len = linlen(rawstr);
	cookeds = ft_substr(rawstr, 0, len);
	//printf("%s | ", cookeds);
	if ((ft_strlen(rawstr) - linlen(rawstr)) > 0)
		rawstr = ft_substr(rawstr, len, ((ft_strlen(rawstr) + 1) - len));
	printf("%s", rawstr);
	return (cookeds);
}


// #include "get_next_line.h"
// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	*temp;
// 	int		fd;
// 	int		i;
// 	char	*line1;
// 	char	*line2;
// 	char	*line3;
// 	char	*line4;


// 	printf("Test1");
// 	fd = open("normalfile.txt", O_RDONLY);

// 	printf("Test1");
// 	line1 = get_next_line(fd);
// 	line2 = get_next_line(fd);
// 	line3 = get_next_line(fd);
// 	line4 = get_next_line(fd);

// 	printf("Line 1: %s", line1);
// 	printf("Line 2: %s", line2);
// 	printf("Line 3: %s", line3);
// 	printf("Line 4: %s", line4);

// 	// i = 0;
// 	// while (1)
// 	// {
// 	// 	temp = get_next_line(fd);
// 	// 	if (!temp)
// 	// 		break ;
// 	// 	printf("%s", temp);
// 	// 	free(temp);
// 	// 	i++;
// 	// }
// 	close(fd);
// 	return (0);
// }
