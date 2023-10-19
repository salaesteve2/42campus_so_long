/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_enemigos_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:27:23 by salustianos       #+#    #+#             */
/*   Updated: 2022/03/24 09:45:24 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_img_enemigos2(t_s *s, int a)
{
	s->i.x_contador = 0;
	while (a >= 0)
	{
		s->i.suelo = mlx_xpm_file_to_image(&s->mlx, "xpm/1suelo.xpm",
				&s->i.fat, &s->i.tall);
		mlx_put_image_to_window(s->mlx, s->mlx_win, s->i.suelo,
			s->i.ancho_enemigo[a], s->i.alto_enemigo[a]);
		mlx_destroy_image(s->mlx, s->i.suelo);
		s->i.bad = mlx_xpm_file_to_image(&s->mlx, "xpm/7enemigo2.xpm",
				&s->i.fat, &s->i.tall);
		mlx_put_image_to_window(s->mlx, s->mlx_win, s->i.bad,
			s->i.ancho_enemigo[a], s->i.alto_enemigo[a]);
		mlx_destroy_image(s->mlx, s->i.bad);
		a--;
	}
s->i.y_contador = 1;
}

void	ft_img_enemigos3(t_s *s, int a)
{
	s->i.x_contador = 0;
	while (a >= 0)
	{
		s->i.suelo = mlx_xpm_file_to_image(&s->mlx, "xpm/1suelo.xpm",
				&s->i.fat, &s->i.tall);
		mlx_put_image_to_window(s->mlx, s->mlx_win, s->i.suelo,
			s->i.ancho_enemigo[a], s->i.alto_enemigo[a]);
		mlx_destroy_image(s->mlx, s->i.suelo);
		s->i.bad = mlx_xpm_file_to_image(&s->mlx, "xpm/8enemigo3.xpm",
				&s->i.fat, &s->i.tall);
		mlx_put_image_to_window(s->mlx, s->mlx_win, s->i.bad,
			s->i.ancho_enemigo[a], s->i.alto_enemigo[a]);
		mlx_destroy_image(s->mlx, s->i.bad);
		a--;
	}
	s->i.y_contador = 2;
}

void	ft_img_enemigos4(t_s *s, int a)
{
	s->i.x_contador = 0;
	while (a >= 0)
	{
		s->i.suelo = mlx_xpm_file_to_image(&s->mlx, "xpm/1suelo.xpm",
				&s->i.fat, &s->i.tall);
		mlx_put_image_to_window(s->mlx, s->mlx_win, s->i.suelo,
			s->i.ancho_enemigo[a], s->i.alto_enemigo[a]);
		mlx_destroy_image(s->mlx, s->i.suelo);
		s->i.bad = mlx_xpm_file_to_image(&s->mlx, "xpm/6enemigo1.xpm",
				&s->i.fat, &s->i.tall);
		mlx_put_image_to_window(s->mlx, s->mlx_win, s->i.bad,
			s->i.ancho_enemigo[a], s->i.alto_enemigo[a]);
		mlx_destroy_image(s->mlx, s->i.bad);
		a--;
	}
	s->i.y_contador = 0;
}

void	ft_img_enemigos(t_s *s)
{
	int	a;

	a = s->i.contador3 - 1;
	if (s->i.x_contador == 15000 && s->i.y_contador == 0)
		ft_img_enemigos2(s, a);
	if (s->i.x_contador == 15000 && s->i.y_contador == 1)
		ft_img_enemigos3(s, a);
	if (s->i.x_contador == 15000 && s->i.y_contador == 2)
		ft_img_enemigos4(s, a);
	s->i.x_contador++;
}
