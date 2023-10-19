/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:15:54 by ischmutz          #+#    #+#             */
/*   Updated: 2023/10/19 15:40:51 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	if (buffer != NULL)
	{
		ft_memset(buffer, 0, bytesize);
	}
	return (buffer);
}

char	*read(fd)
{
	int		bytes_read;
	char	*tinybuffer;

	tinybuffer = ft_calloc(3 + 1 * sizeof(char)); //*********
	if (tinybuffer == NULL)
		return (NULL);
	bytes_read = read(fd, tinybuffer, 3);
	if (bytes_read <= 0)
		return (NULL);
	return (tinybuffer);
}