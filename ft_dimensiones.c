/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dimensiones.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:13:41 by salustianos       #+#    #+#             */
/*   Updated: 2022/03/17 12:53:55 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_ancho(char *mapa)
{
	int	x;

	x = 0;
	while (mapa[x])
	{
		if (mapa[x] == '\n')
		{
			x--;
			break ;
		}
		x++;
	}
	x++;
	return (x);
}

int	ft_alto(char *mapa)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (mapa[x])
	{
		if (mapa[x] == '\n')
		{
			y++;
		}
		x++;
	}
	y++;
	return (y);
}

int	ft_obstaculos(char *mapa)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (mapa[x])
	{
		if (mapa[x] == '1')
		{
			y++;
		}
		x++;
	}
	return (y);
}
