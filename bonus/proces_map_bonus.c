/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proces_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:49:33 by salustianos       #+#    #+#             */
/*   Updated: 2022/03/24 09:24:01 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

typedef struct s_char
{
	int	x;
	int	p;
	int	e;
	int	c;
	int	o;
	int	l;
}	t_char;

int	ft_caracters(char *map)
{
	t_char	carac;

	carac.x = 0;
	carac.p = 0;
	carac.e = 0;
	carac.c = 0;
	carac.o = 0;
	carac.l = 0;
	while (map[carac.x])
	{
		if (map[carac.x] == 'P')
			carac.p++;
		if (map[carac.x] == 'E')
			carac.e++;
		if (map[carac.x] == 'C')
			carac.c++;
		if (map[carac.x] == '1')
			carac.o++;
		if (map[carac.x] == 'L')
			carac.l++;
		carac.x++;
	}
	if (carac.p != 1 || carac.e < 1 || carac.c < 1 || carac.l < 1)
		return (-1);
	return (0);
}

int	ft_anchura(char *map)
{
	int	x;

	x = 0;
	while (map[x])
	{
		if (map[x] == '\n')
			break ;
		x++;
	}
	return (x);
}

int	ft_proces2(char *map, int line, int maxlines, int anchura_inicial)
{
	int	x;

	x = 0;
	if (line == 1 || line == maxlines)
	{
		while (map[x])
		{
			if (map[x] == '\n')
				break ;
			if (map[x] != '1')
				return (-1);
			x++;
		}
	}
	else if (line < maxlines && line > 1)
	{
		while (map[x++] && x < anchura_inicial - 1)
		{
			if (map[x] != '0' && map[x] != 'C' && map[x] != 'P'
				&& map[x] != 'E' && map[x] != '1' && map[x] != 'L')
				return (-1);
		}
	}
	return (ft_anchura(map));
}

static char	*ft_controlerror(t_list mapa, int lines, int fd)
{
	while (mapa.map != 0)
	{
		mapa.swap = mapa.map_completo;
		mapa.map_completo = ft_strjoin(mapa.map_completo, mapa.map);
		free(mapa.swap);
		mapa.swap = mapa.map;
		if (mapa.map[0] != '1')
		{
			free(mapa.map_completo);
			free(mapa.map);
			return (0);
		}
		mapa.result = ft_proces2(mapa.map, mapa.x, lines, mapa.anchura);
		free(mapa.swap);
		if (mapa.result == -1 || mapa.anchura != mapa.result)
		{
			free(mapa.map_completo);
			return (0);
		}
		mapa.map = get_next_line(fd, 35);
		mapa.x++;
	}
	return (mapa.map_completo);
}

char	*ft_proces_bonus(int fd, int lines)
{
	t_list	mapa;
	int		a;

	mapa.x = 0;
	mapa.map_completo = malloc(35 + 1);
	if (!mapa.map_completo)
		return (0);
	mapa.map = get_next_line(fd, 35);
	mapa.anchura = ft_proces2(mapa.map, mapa.x, lines, mapa.anchura);
	if (mapa.anchura == lines)
	{
		free(mapa.map_completo);
		return (0);
	}
	mapa.x++;
	mapa.map_completo = ft_controlerror(mapa, lines, fd);
	a = ft_strlen(mapa.map_completo);
	if (!mapa.map_completo || mapa.map_completo[a - 1] != '\n')
	{
		free(mapa.map_completo);
		return (0);
	}
	return (mapa.map_completo);
}
