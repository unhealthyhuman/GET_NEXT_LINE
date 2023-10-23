/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:16:09 by ischmutz          #+#    #+#             */
/*   Updated: 2023/10/20 10:19:44 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 3

#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd);

#endif