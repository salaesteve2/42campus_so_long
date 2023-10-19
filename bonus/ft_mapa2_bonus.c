/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapa2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 09:27:52 by sasalama          #+#    #+#             */
/*   Updated: 2022/03/24 09:28:54 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_personaje_mapa(t_s *s, int x)
{
	s->i.long_p = s->i.ancho;
	s->i.tall_p = s->i.alto;
	s->i.posicion_pers = x;
	s->i.personaje = mlx_xpm_file_to_image(&s->mlx,
			"xpm/4personaje1.xpm", &s->i.fat, &s->i.tall);
	mlx_put_image_to_window(s->mlx, s->mlx_win,
		s->i.personaje, s->i.ancho, s->i.alto);
	mlx_destroy_image(s->mlx, s->i.personaje);
	s->i.ancho += 50;
}

void	ft_moneda_mapa(t_s *s)
{
	s->i.moneda = mlx_xpm_file_to_image(&s->mlx,
			"xpm/5moneda.xpm", &s->i.fat, &s->i.tall);
	mlx_put_image_to_window(s->mlx, s->mlx_win,
		s->i.moneda, s->i.ancho, s->i.alto);
	mlx_destroy_image(s->mlx, s->i.moneda);
	s->i.ancho += 50;
	s->i.monedas++;
}

void	ft_puerta_mapa(t_s *s, int x)
{
	s->i.posicion_puerta[s->i.contador2] = x;
	s->i.exit = mlx_xpm_file_to_image(&s->mlx,
			"xpm/3puerta.xpm", &s->i.fat, &s->i.tall);
	mlx_put_image_to_window(s->mlx, s->mlx_win,
		s->i.exit, s->i.ancho, s->i.alto);
	mlx_destroy_image(s->mlx, s->i.exit);
	s->i.puerta = 0;
	s->i.ancho_puerta[s->i.contador2] = s->i.ancho;
	s->i.alto_puerta[s->i.contador2] = s->i.alto;
	s->i.ancho += 50;
	s->i.contador2++;
}

void	ft_enemigo_mapa(t_s *s, int x)
{
	s->i.posicion_enemigo[s->i.contador3] = x;
	s->i.bad = mlx_xpm_file_to_image(&s->mlx,
			"xpm/6enemigo1.xpm", &s->i.fat, &s->i.tall);
	mlx_put_image_to_window(s->mlx, s->mlx_win,
		s->i.bad, s->i.ancho, s->i.alto);
	s->i.ancho_enemigo[s->i.contador3] = s->i.ancho;
	s->i.alto_enemigo[s->i.contador3] = s->i.alto;
	mlx_destroy_image(s->mlx, s->i.bad);
	s->i.enemigo = 0;
	s->i.ancho += 50;
	s->i.contador3++;
}
