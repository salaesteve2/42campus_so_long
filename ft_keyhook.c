/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:48:27 by salustianos       #+#    #+#             */
/*   Updated: 2022/03/17 12:52:08 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(t_s *s, int x)
{
	free(s->i.copia);
	mlx_destroy_window(s->mlx, s->mlx_win);
	if (x == 1)
		printf("Ganaste");
	exit(-1);
}

int	key_hook(int keycode, t_s *s)
{
	int	a;

	a = ft_puertas(s, s->i.copia) - 1;
	if (keycode == 13
		&& s->i.copia[s->i.posicion_pers - s->i.ancho_total] != '1')
		ft_arriba(s);
	if (keycode == 1
		&& s->i.copia[s->i.posicion_pers + s->i.ancho_total] != '1')
		ft_abajo(s);
	if (keycode == 2 && s->i.copia[s->i.posicion_pers + 1] != '1')
		ft_derecha(s);
	if (keycode == 0 && s->i.copia[s->i.posicion_pers - 1] != '1')
		ft_izquierda(s);
	if (keycode == 53)
		ft_exit(s, 0);
	if (s->i.monedas == 0)
		s->i.puerta = 1;
	while (a >= 0)
	{
		if (s->i.posicion_pers == s->i.posicion_puerta[a] && s->i.puerta == 1)
			ft_exit(s, 1);
		a--;
	}
	return (0);
}
