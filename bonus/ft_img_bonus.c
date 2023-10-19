/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:34:52 by sasalama          #+#    #+#             */
/*   Updated: 2022/03/24 09:46:14 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_img_puerta(t_s *s)
{
	int	a;

	a = s->i.contador2 - 1;
	while (a >= 0)
	{
		s->i.suelo = mlx_xpm_file_to_image(&s->mlx, "xpm/1suelo.xpm",
				&s->i.fat, &s->i.tall);
		mlx_put_image_to_window(s->mlx, s->mlx_win, s->i.suelo,
			s->i.ancho_puerta[a], s->i.alto_puerta[a]);
		mlx_destroy_image(s->mlx, s->i.suelo);
		s->i.exit = mlx_xpm_file_to_image(&s->mlx, "xpm/11puerta2.xpm",
				&s->i.fat, &s->i.tall);
		mlx_put_image_to_window(s->mlx, s->mlx_win, s->i.exit,
			s->i.ancho_puerta[a], s->i.alto_puerta[a]);
		mlx_destroy_image(s->mlx, s->i.exit);
		a--;
	}
}

int	ft_img(t_s *s)
{
	ft_img_enemigos(s);
	ft_img_personaje(s);
	if (s->i.puerta == 1)
	{
		ft_img_puerta(s);
	}
	return (0);
}
