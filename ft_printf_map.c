/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salustianosalamanca <salustianosalamanc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:14:24 by salustianos       #+#    #+#             */
/*   Updated: 2022/03/21 11:45:04 by salustianos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit_hook(t_s *s)
{
	free(s->i.copia);
	mlx_destroy_window(s->mlx, s->mlx_win);
	exit(-1);
}

void	ft_salto_mapa(t_s *s)
{
	s->i.ancho = 0;
	s->i.alto += 50;
}

int	ft_puertas(t_s *s, char *mapa)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	s->i.vacio = 0;
	while (mapa[x])
	{
		if (mapa[x] == 'E')
		{
			y++;
		}
		x++;
	}
	return (y);
}

void	ft_map(t_s *s, char *mapa)
{
	s->i.posicion_puerta = malloc(ft_puertas(s, mapa));
	while (mapa[s->i.contador])
	{
		s->i.copia[s->i.contador] = mapa[s->i.contador];
		if (mapa[s->i.contador] != '\n')
			ft_suelo_mapa(s);
		if (mapa[s->i.contador] == '1')
			ft_obstaculo_mapa(s);
		else if (mapa[s->i.contador] == 'P')
			ft_personaje_mapa(s, s->i.contador);
		else if (mapa[s->i.contador] == 'C')
			ft_moneda_mapa(s);
		else if (mapa[s->i.contador] == 'E')
			ft_puerta_mapa(s, s->i.contador);
		else if (mapa[s->i.contador] != '\n')
		{
			ft_suelo_mapa(s);
			s->i.ancho += 50;
		}
		if (mapa[s->i.contador] == '\n')
			ft_salto_mapa(s);
		s->i.contador++;
	}
	s->i.copia[s->i.contador] = '\0';
	s->i.posicion_puerta[s->i.contador2] = 0;
}

void	ft_printf_map(char *mapa)
{
	t_s	s;
	int	x;

	x = ft_strlen(mapa);
	mapa[x - 1] = '\0';
	ft_inicializar(&s, mapa);
	ft_map(&s, mapa);
	free(mapa);
	mlx_key_hook(s.mlx_win, key_hook, &s);
	mlx_hook(s.mlx_win, 17, 1L << 17, ft_exit_hook, &s);
	mlx_loop(s.mlx);
	free(s.mlx);
	free(s.mlx_win);
}
