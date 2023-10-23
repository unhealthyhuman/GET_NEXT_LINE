/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:15:31 by ischmutz          #+#    #+#             */
/*   Updated: 2023/10/23 19:03:32 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	liberator(char *imprisoned_ptr)
{
	free(imprisoned_ptr);
	imprisoned_ptr = NULL;
}

static char	*readme(char *cookedstr, int fd)
{
	int		bytes_read;
	char	*tinybuffer;

	tinybuffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (tinybuffer == NULL)
		return (NULL);
	while (!ft_strchr(cookedstr, '\n') && bytes_read == 0)
	{
		bytes_read = read(fd, tinybuffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		cookedstr = ft_strjoin(cookedstr, tinybuffer);
		if (cookedstr == NULL)
			return (NULL);
	}
	liberator(tinybuffer);
	return (cookedstr);
}

char	*get_next_line(int fd)
{
	char		*rawstr;
	static char	*cookedstr;
	int			len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	cookedstr = read(cookedstr, fd);
	len = linlen(cookedstr);
	rawstr = ft_substr(cookedstr, cookedstr[0], linlen(cookedstr));
	cookedstr = ft_substr(cookedstr, cookedstr[len], (ft_strlen(cookedstr) - linlen(cookedstr)));
	return (rawstr);
}
