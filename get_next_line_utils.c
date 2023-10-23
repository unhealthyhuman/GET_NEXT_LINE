/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:15:54 by ischmutz          #+#    #+#             */
/*   Updated: 2023/10/23 10:30:17 by ischmutz         ###   ########.fr       */
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

char	*ft_strdup(char *src)
{
	char	*dupli;
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	dupli = (char *) malloc (i + 1);
	if (!dupli)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dupli[i] = src[i];
		i++;
	}
	dupli[i] = '\0';
	return (dupli);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	i = 0;
	if (start >= ft_strlen(s) || len == 0)
	{
		subs = malloc(1 * sizeof(char));
		return (subs);
	}
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	subs = malloc(len + 1 * sizeof(char));
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	size_t		i;
	size_t		e;
	
	i = 0;
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0' && ft_strlen(s1 + 1) > i + 1)
	{
		str[i] = s1[i];
		i++;
	}
	e = 0;
	while (s2[e] != '\0' && ft_strlen(s2 + 1) > e + 1)
	{
		str[i] = s2[e];
		i++;
		e++;
	}
	return (str);
}
