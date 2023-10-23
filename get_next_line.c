/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:15:31 by ischmutz          #+#    #+#             */
/*   Updated: 2023/10/23 18:21:37 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	liberator(char *imprisoned_ptr)
{
	free(imprisoned_ptr);
	imprisoned_ptr = NULL;
}

char	*read(fd)
{
	int		bytes_read;
	char	*tinybuffer;
	char	*buffingbuf;

	tinybuffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (tinybuffer == NULL)
		return (NULL);
	while (!ft_strchr(buffingbuf, '\n') && bytes_read == 0)
	{
		bytes_read = read(fd, tinybuffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		buffingbuf = ft_strjoin(buffingbuf, *tinybuffer);
		if (buffingbuf == NULL)
			return (NULL);
	}
	liberator(tinybuffer);
	return (buffingbuf);
}

char	*cutme(char *rawstr)
{
	long long	pos_n;
	long long	len;
	char		*cookedstr;

	pos_n = ft_strchr(rawstr, '\n');
	len = ft_strlen(rawstr);
	cookedstr = ft_substr(rawstr, rawstr[0], linlen(rawstr));
	
}

char	*get_next_line(int fd)
{
	char	*mammothbuffer;
	
	if (fd <= 0 || BUFFER_SIZE = 0)
		return (NULL);
	mammothbuffer = malloc(sizeof(char));
}
