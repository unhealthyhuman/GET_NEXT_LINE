/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:15:31 by ischmutz          #+#    #+#             */
/*   Updated: 2023/10/27 19:15:55 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void	liberator(char *imprisoned_ptr)
{
	free(imprisoned_ptr);
	imprisoned_ptr = NULL;
}

void	*ft_memset(void *s, int c, size_t size)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *) s;
	while (i < size)
	{
		str[i] = c;
		i++;
	}
	return (s);
}

/*
void	*ft_calloc(size_t num, size_t size)
{
	void	*buffer;
	size_t	bytesize;

	if (size == 0 || num == 0)
		return (malloc(0));
	bytesize = num * size;
	if (bytesize / num != size || bytesize > 2147483647)
		return (NULL);
	buffer = malloc(bytesize);
	if (buffer == NULL)
		return (NULL);
	ft_memset(buffer, '\0', bytesize);
	return (buffer);
}
*/

void	*ft_calloc(size_t num, size_t size)
{
	return (malloc(num * size));
}

/* void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	alloc;
	char	*blob;
	size_t	idx;

	alloc = nmemb * size;
	if (alloc != 0 && alloc / nmemb != size)
		return (NULL);
	blob = malloc(alloc);
	if (blob == NULL)
		return (NULL);
	idx = 0;
	while (idx < alloc)
		blob[idx++] = 0;
	return (blob);
} */

static char	*readme(char **rawstr, int fd) //char *eof
{
	int		bytes_read;
	char	*tinybuffer;
	int		progress;
	//int		loop;

	progress = 0;
	tinybuffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (tinybuffer == NULL)
	{
		free(*rawstr);
		return (NULL);
	}
	bytes_read = 1;
	while (!ft_strchr(tinybuffer, '\n') && (bytes_read > 0))
	{
		bytes_read = read(fd, tinybuffer, BUFFER_SIZE);
		tinybuffer[bytes_read] = '\0';
		if (bytes_read == -1)
			return (free(tinybuffer), liberator(*rawstr), NULL);
		if (bytes_read == 0)
			break ;
		// printf("Buffer: %s\n", tinybuffer);
		*rawstr = ft_strjoin(*rawstr, tinybuffer, bytes_read, &progress);
		if (*rawstr == NULL)
			return (NULL);
		printf("%s\n", *rawstr);
	}
	//printf("%s", tinybuffer);
	free(tinybuffer);
	return (*rawstr);
}

char	*get_next_line(int fd)
{
	char		*cookeds;
	char		*tmp;
	static char	*rawstr = NULL;
	size_t		len;
	/* char		eof;

	eof = 0; */
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// rawstr = ft_calloc(BUFFER_SIZE, sizeof(char));
	// if (rawstr == NULL)
	// 	return (NULL);
	rawstr = readme(&rawstr, fd); //&eof
	if (rawstr == NULL)
		return (NULL);
	len = linlen(rawstr);
	cookeds = ft_substr(rawstr, 0, len);
	//printf("%s | ", cookeds);
	if (cookeds == NULL)
	{
		free(rawstr);
		return (NULL);
	}
	//printf("%s | ", cookeds);
	//printf("\n%lu\n", (ft_strlen(rawstr) - linlen(rawstr)));
	if (((ft_strlen(rawstr) + 1) - len) > 0)
	{
		//printf("HELOOOOOOOO %lu %lu\n", ft_strlen(rawstr), linlen(rawstr));
		tmp = ft_substr(rawstr, len, ((ft_strlen(rawstr) + 1) - len));
		if (tmp == NULL)
		{
			liberator(rawstr);
			free(cookeds);
			return (NULL);
		}
		liberator(rawstr);
		rawstr = tmp;
	}
	else
		liberator(rawstr);
/* 	if (eof == 1)
	{
		free(tmp);
		cookeds = NULL;
	} */
	//free(tmp);
	return (cookeds);
}

//static variables remember their value, therefore u need to set them to NULL after freeing them

// #include "get_next_line.h"
// #include <fcntl.h>
// #include <stdio.h>

// ft_substr(rawstr, len, ((ft_strlen(rawstr) + 1) - len))

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
