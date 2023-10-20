/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:15:54 by ischmutz          #+#    #+#             */
/*   Updated: 2023/10/20 17:13:48 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*result;
	char	*s_;

	i = 0;
	result = NULL;
	s_ = (char *) s;
	while (s_[i] != '\0')
	{
		if (s_[i] != '\n')
			i++;
		else
		{
			result = s_ + i;
			break ;
		}
	}
	return (result);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	i = 0;
	if (start >= ft_strlen(s) || len == 0)
	{
		subs = ft_calloc(1, 1);
		return (subs);
	}
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	subs = ft_calloc(len + 1, sizeof(char));
	if (subs == NULL)
		return (NULL);
	while (i < len && s[start] != '\0')
	{
		subs[i] = s[i + start];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}

char	*read(fd)
{
	int		bytes_read;
	char	*tinybuffer;

	tinybuffer = malloc(BUFFER_SIZE + 1 * sizeof(char)); //*********
	if (tinybuffer == NULL)
		return (NULL);
	bytes_read = read(fd, tinybuffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (NULL);
	return (tinybuffer);
}