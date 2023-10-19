/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:44:14 by salustianos       #+#    #+#             */
/*   Updated: 2022/03/24 09:28:23 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
