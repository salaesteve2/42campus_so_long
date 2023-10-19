/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:58:16 by salustianos       #+#    #+#             */
/*   Updated: 2022/03/17 15:31:18 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	s2;

	i = 0;
	s2 = (unsigned char)c;
	while (*(s + i) && s2 != *(s + i))
		i++;
	if (*(s + i) == s2)
		return ((char *)(s + i));
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		x;
	int		y;
	int		z;
	char	*s;

	x = ft_strlen(s1);
	y = ft_strlen(s2);
	s = malloc(x + y + 1);
	if (s == 0)
		return (0);
	z = 0;
	while (s1[z])
	{
		s[z] = (char)s1[z];
		z++;
	}
	y = 0;
	while (s2[y])
		s[x++] = (char)s2[y++];
	s[x] = '\0';
	return (s);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			i++;
		}
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	x;
	size_t	y;
	char	*s1;

	x = 0;
	y = 0;
	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_calloc(1, sizeof(char)));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	s1 = malloc(len + 1);
	if (!s1)
		return (0);
	while (s[x])
	{
		if (x >= start && y < len)
			s1[y++] = s[x];
		x++;
	}
	s1[y] = '\0';
	return (s1);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	x;
	char	*s;

	x = 0;
	s = malloc(sizeof(char) * count * size);
	if (s == 0)
		return (0);
	while (x < sizeof(char) * count * size)
	{
		s[x] = '\0';
		x++;
	}
	return (s);
}
