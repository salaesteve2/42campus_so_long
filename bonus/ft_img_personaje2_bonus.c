/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_personaje2_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:31:04 by sasalama          #+#    #+#             */
/*   Updated: 2022/03/24 12:32:05 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_img_personaje_suelo(t_s *s, int a)
{
	if (a == 0)
	{
		s->i.suelo = mlx_xpm_file_to_image(&s->mlx, "xpm/1suelo.xpm",
				&s->i.fat, &s->i.tall);
		mlx_put_image_to_window(s->mlx, s->mlx_win,
			s->i.suelo, s->i.long_p, s->i.tall_p);
		mlx_destroy_image(s->mlx, s->i.suelo);
	}
}

void	ft_img_personaje_puerta(t_s *s, int x, int a)
{
	while (x >= 0)
	{
		if (s->i.posicion_pers == s->i.posicion_puerta[x])
		{
			s->i.suelo = mlx_xpm_file_to_image(&s->mlx, "xpm/1suelo.xpm",
					&s->i.fat, &s->i.tall);
			mlx_put_image_to_window(s->mlx, s->mlx_win, s->i.suelo,
				s->i.ancho_puerta[x], s->i.alto_puerta[x]);
			mlx_destroy_image(s->mlx, s->i.suelo);
			s->i.exit = mlx_xpm_file_to_image(&s->mlx, "xpm/3puerta.xpm",
					&s->i.fat, &s->i.tall);
			mlx_put_image_to_window(s->mlx, s->mlx_win, s->i.exit,
				s->i.ancho_puerta[x], s->i.alto_puerta[x]);
			mlx_destroy_image(s->mlx, s->i.exit);
			a = 1;
			break ;
		}
		x--;
	}
}
