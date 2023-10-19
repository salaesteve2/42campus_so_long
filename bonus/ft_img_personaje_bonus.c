/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_personaje_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:28:20 by salustianos       #+#    #+#             */
/*   Updated: 2022/03/24 12:31:52 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	inicializar_bool(t_s *s, int x)
{
	if (x == 1)
	{
		s->i.y2_contador = 1;
		s->i.x2_contador = 0;
	}
	if (x == 0)
	{
		s->i.y2_contador = 0;
		s->i.x2_contador = 0;
	}
}

void	ft_img_personaje2(t_s *s, int x, int a)
{
	ft_img_personaje_puerta(s, x, a);
	ft_img_personaje_suelo(s, a);
	s->i.personaje = mlx_xpm_file_to_image(&s->mlx, "xpm/10personaje2.xpm",
			&s->i.fat, &s->i.tall);
	mlx_put_image_to_window(s->mlx, s->mlx_win,
		s->i.personaje, s->i.long_p, s->i.tall_p);
	mlx_destroy_image(s->mlx, s->i.personaje);
	inicializar_bool(s, 1);
}

void	ft_img_personaje3(t_s *s, int x, int a)
{
	ft_img_personaje_puerta(s, x, a);
	ft_img_personaje_suelo(s, a);
	s->i.personaje = mlx_xpm_file_to_image(&s->mlx, "xpm/4personaje1.xpm",
			&s->i.fat, &s->i.tall);
	mlx_put_image_to_window(s->mlx, s->mlx_win, s->i.personaje,
		s->i.long_p, s->i.tall_p);
	mlx_destroy_image(s->mlx, s->i.personaje);
	inicializar_bool(s, 0);
}

void	ft_img_personaje(t_s *s)
{
	int	x;
	int	a;

	x = s->i.contador2 - 1;
	a = 0;
	if (s->i.x2_contador == 15000 && s->i.y2_contador == 0)
		ft_img_personaje2(s, x, a);
	if (s->i.x2_contador == 15000 && s->i.y2_contador == 1)
		ft_img_personaje3(s, x, a);
	s->i.x2_contador++;
}
