/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:15:31 by ischmutz          #+#    #+#             */
/*   Updated: 2023/10/23 09:48:20 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*get_next_line(int fd)
{
	
}
