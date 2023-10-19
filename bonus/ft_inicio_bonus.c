/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inicio_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:47:03 by salustianos       #+#    #+#             */
/*   Updated: 2022/03/24 09:38:27 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	s->i.contador3 = 0;
	s->i.x_contador = 0;
	s->i.y_contador = 0;
	s->i.x2_contador = 0;
	s->i.y2_contador = 0;
}

void	ft_inicializar2(t_s *s, char *mapa)
{
	s->i.posicion_puerta = malloc(ft_puertas(s, mapa));
	s->i.posicion_enemigo = malloc(ft_enemigos(s, mapa));
	s->i.ancho_enemigo = malloc(ft_enemigos(s, mapa));
	s->i.alto_enemigo = malloc(ft_enemigos(s, mapa));
	s->i.ancho_puerta = malloc(ft_puertas(s, mapa));
	s->i.alto_puerta = malloc(ft_puertas(s, mapa));
	s->i.posicion_puerta[s->i.contador2] = 0;
	s->i.posicion_enemigo[s->i.contador3] = 0;
	s->i.ancho_enemigo[s->i.contador3] = 0;
	s->i.alto_enemigo[s->i.contador3] = 0;
	s->i.alto_puerta[s->i.contador2] = 0;
	s->i.ancho_puerta[s->i.contador2] = 0;
}

void	ft_personaje(t_s *s)
{
	char	*s2;

	s->i.personaje = mlx_xpm_file_to_image(&s->mlx,
			"xpm/4personaje1.xpm", &s->i.fat, &s->i.tall);
	mlx_put_image_to_window(s->mlx, s->mlx_win,
		s->i.personaje, s->i.long_p, s->i.tall_p);
	mlx_destroy_image(s->mlx, s->i.personaje);
	s->i.number2++;
	printf("%d\n", s->i.number2);
	s2 = ft_itoa(s->i.number2);
	s->i.suelo = mlx_xpm_file_to_image(&s->mlx,
			"xpm/2pared.xpm", &s->i.fat, &s->i.tall);
	mlx_put_image_to_window(s->mlx, s->mlx_win,
		s->i.suelo, 0, 0);
	mlx_destroy_image(s->mlx, s->i.suelo);
	mlx_string_put(s->mlx, s->mlx_win, 10, 10, 0xffffff, s2);
	free(s2);
}

void	ft_suelo(t_s *s)
{
	s->i.suelo = mlx_xpm_file_to_image(&s->mlx,
			"xpm/1suelo.xpm", &s->i.fat, &s->i.tall);
	mlx_put_image_to_window(s->mlx, s->mlx_win,
		s->i.suelo, s->i.long_p, s->i.tall_p);
	mlx_destroy_image(s->mlx, s->i.suelo);
}
