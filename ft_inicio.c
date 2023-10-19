/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inicio.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salustianosalamanca <salustianosalamanc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:47:03 by salustianos       #+#    #+#             */
/*   Updated: 2022/03/21 11:04:42 by salustianos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_inicializar(t_s *s, char *mapa)
{
	s->i.monedas = 0;
	s->i.ancho = 0;
	s->i.alto = 0;
	s->i.ancho_total = ft_ancho(mapa) + 1;
	s->i.alto_total = ft_alto(mapa) + 1;
	s->mlx = mlx_init();
	s->mlx_win = mlx_new_window(s->mlx, (s->i.ancho_total - 1) * 50,
			(s->i.alto_total - 1) * 50, "Welcome to Hell!");
	s->i.copia = malloc(ft_strlen(mapa));
	s->i.number2 = 0;
	s->i.contador = 0;
	s->i.contador2 = 0;
}

void	ft_personaje(t_s *s)
{
	s->i.personaje = mlx_xpm_file_to_image(&s->mlx,
			"xpm/4personaje1.xpm", &s->i.fat, &s->i.tall);
	mlx_put_image_to_window(s->mlx, s->mlx_win,
		s->i.personaje, s->i.long_p, s->i.tall_p);
	mlx_destroy_image(s->mlx, s->i.personaje);
	s->i.number2++;
	printf("%d\n", s->i.number2);
}

void	ft_suelo(t_s *s)
{
	s->i.suelo = mlx_xpm_file_to_image(&s->mlx,
			"xpm/1suelo.xpm", &s->i.fat, &s->i.tall);
	mlx_put_image_to_window(s->mlx, s->mlx_win,
		s->i.suelo, s->i.long_p, s->i.tall_p);
	mlx_destroy_image(s->mlx, s->i.suelo);
}
