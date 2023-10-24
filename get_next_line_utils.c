/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:15:54 by ischmutz          #+#    #+#             */
/*   Updated: 2023/10/24 18:00:17 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != 0)
	{
		i++;
	}
	return (i);
}

size_t	linlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\n' && s[i])
	{
		i++;
	}
	return (i + 1);
}

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

/* char	*ft_strdup(char *src)
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
} */

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

// #include <stdio.h>

char	*ft_strjoin(char *s1, char *s2)
{
	char		*str;
	size_t		i;
	size_t		e;
	
	i = 0;
	if (s1 == NULL)
	{
		s1 = (char *)malloc(sizeof(char));
		if (s1 == NULL)
			return (free(s1), free(s2), NULL);
		s1[0] = '\0';
	}
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0' && ft_strlen(s1) > i)
	{
		str[i] = s1[i];
		i++;
	}
	e = 0;
	while (s2[e] != '\0' && ft_strlen(s2) > e)
	{
		str[i] = s2[e];
		i++;
		e++;
	}
	str[i] = '\0';
	return (str);
}

/*int	main(void)
{
	char	*fuck;
	char	*you;
	char	*conjoinedtwins;

	fuck = "goodbye";
	you = "zulu";
	conjoinedtwins = ft_strjoin(fuck, you);
	printf("%s", conjoinedtwins);
	
} */