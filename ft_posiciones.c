/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_posiciones.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:42:35 by salustianos       #+#    #+#             */
/*   Updated: 2022/03/17 16:58:11 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_control_puertas(t_s *s)
{
	while (s->i.puertas >= 0)
	{
		if (s->i.posicion_pers
			== s->i.posicion_puerta[s->i.puertas])
		{
			s->i.exit = mlx_xpm_file_to_image(&s->mlx,
					"xpm/3puerta.xpm", &s->i.fat, &s->i.tall);
			mlx_put_image_to_window(s->mlx, s->mlx_win,
				s->i.exit, s->i.long_p, s->i.tall_p);
			mlx_destroy_image(s->mlx, s->i.exit);
		}
		s->i.puertas--;
	}
}

void	ft_arriba(t_s *s)
{
	s->i.puertas = ft_puertas(s, s->i.copia) - 1;
	if (s->i.monedas != 0
		&& s->i.copia[s->i.posicion_pers - s->i.ancho_total] == 'C')
	{
		s->i.monedas--;
		s->i.copia[s->i.posicion_pers - s->i.ancho_total] = '0';
	}
	ft_suelo(s);
	ft_control_puertas(s);
	s->i.tall_p -= 50;
	if (s->i.copia[s->i.posicion_pers - s->i.ancho_total] != 'E')
		ft_suelo(s);
	ft_personaje(s);
	s->i.posicion_pers -= s->i.ancho_total;
}

void	ft_abajo(t_s *s)
{
	s->i.puertas = ft_puertas(s, s->i.copia) - 1;
	if (s->i.monedas != 0
		&& s->i.copia[s->i.posicion_pers + s->i.ancho_total] == 'C')
	{
		s->i.monedas--;
		s->i.copia[s->i.posicion_pers + s->i.ancho_total] = '0';
	}
	ft_suelo(s);
	ft_control_puertas(s);
	s->i.tall_p += 50;
	if (s->i.copia[s->i.posicion_pers + s->i.ancho_total] != 'E')
		ft_suelo(s);
	ft_personaje(s);
	s->i.posicion_pers += s->i.ancho_total;
}

void	ft_derecha(t_s *s)
{
	s->i.puertas = ft_puertas(s, s->i.copia) - 1;
	if (s->i.monedas != 0
		&& s->i.copia[s->i.posicion_pers + 1] == 'C')
	{
		s->i.monedas--;
		s->i.copia[s->i.posicion_pers + 1] = '0';
	}
	ft_suelo(s);
	ft_control_puertas(s);
	s->i.long_p += 50;
	if (s->i.copia[s->i.posicion_pers + 1] != 'E')
		ft_suelo(s);
	ft_personaje(s);
	s->i.posicion_pers++;
}

void	ft_izquierda(t_s *s)
{
	s->i.puertas = ft_puertas(s, s->i.copia) - 1;
	if (s->i.monedas != 0
		&& s->i.copia[s->i.posicion_pers - 1] == 'C')
	{
		s->i.monedas--;
		s->i.copia[s->i.posicion_pers - 1] = '0';
	}
	ft_suelo(s);
	ft_control_puertas(s);
	s->i.long_p -= 50;
	if (s->i.copia[s->i.posicion_pers - 1] != 'E')
		ft_suelo(s);
	ft_personaje(s);
	s->i.posicion_pers--;
}
