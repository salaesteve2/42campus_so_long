/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:44:14 by salustianos       #+#    #+#             */
/*   Updated: 2022/03/17 17:01:18 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_suelo_mapa(t_s *s)
{
	s->i.suelo = mlx_xpm_file_to_image(&s->mlx,
			"xpm/1suelo.xpm", &s->i.fat, &s->i.tall);
	mlx_put_image_to_window(s->mlx, s->mlx_win,
		s->i.suelo, s->i.ancho, s->i.alto);
	mlx_destroy_image(s->mlx, s->i.suelo);
}

void	ft_obstaculo_mapa(t_s *s)
{
	s->i.obstaculo = mlx_xpm_file_to_image(&s->mlx,
			"xpm/2pared.xpm", &s->i.fat, &s->i.tall);
	mlx_put_image_to_window(s->mlx, s->mlx_win,
		s->i.obstaculo, s->i.ancho, s->i.alto);
	mlx_destroy_image(s->mlx, s->i.obstaculo);
	s->i.ancho += 50;
}

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
	s->i.ancho += 50;
	s->i.contador2++;
}
