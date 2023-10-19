/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:34:58 by sasalama          #+#    #+#             */
/*   Updated: 2022/03/24 12:31:46 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../mlx/mlx.h"

typedef struct s_list
{
	char	*map;
	int		x;
	int		result;
	int		anchura;
	char	*map_completo;
	char	*swap;
}	t_list;

typedef struct s_data
{
	void	*suelo;
	void	*obstaculo;
	void	*personaje;
	void	*moneda;
	void	*exit;
	void	*bad;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		tall;
	int		fat;
	int		ancho;
	int		alto;
	int		long_p;
	int		tall_p;
	int		posicion_pers;
	int		*posicion_puerta;
	int		*posicion_enemigo;
	int		number2;
	char	*copia;
	int		ancho_total;
	int		alto_total;
	int		monedas;
	int		puerta;
	int		contador;
	int		puertas;
	int		contador2;
	int		contador3;
	int		vacio;
	int		enemigo;
	int		*ancho_enemigo;
	int		*alto_enemigo;
	int		x_contador;
	int		y_contador;
	int		x2_contador;
	int		y2_contador;
	int		*ancho_puerta;
	int		*alto_puerta;
}				t_data;

typedef struct s_s
{
	void	*mlx;
	void	*mlx_win;
	t_data	i;
}				t_s;

char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);
char	*get_next_line(int fd, int BUFFER_SIZE);
int		ft_lines(int fd, int x);
char	*ft_proces_bonus(int fd, int lines);
int		ft_proces2(char *map, int line, int maxlines, int anchura_inicial);
int		ft_anchura(char *map);
int		ft_caracters(char *map);
void	ft_printf_map(char *mapa);
int		ft_ancho(char *mapa);
int		ft_alto(char *mapa);
int		ft_obstaculos(char *mapa);
void	ft_puerta_mapa(t_s *s, int x);
void	ft_moneda_mapa(t_s *s);
void	ft_personaje_mapa(t_s *s, int x);
void	ft_obstaculo_mapa(t_s *s);
void	ft_suelo_mapa(t_s *s);
void	ft_inicializar(t_s *s, char *mapa);
int		key_hook(int keycode, t_s *s);
void	ft_arriba(t_s *s);
void	ft_abajo(t_s *s);
void	ft_derecha(t_s *s);
void	ft_izquierda(t_s *s);
int		ft_puertas(t_s *s, char *mapa);
void	ft_personaje(t_s *s);
void	ft_suelo(t_s *s);
void	ft_enemigo_mapa(t_s *s, int x);
int		ft_img(t_s *s);
char	*ft_itoa(int n);
void	ft_img_enemigos(t_s *s);
void	ft_img_personaje(t_s *s);
int		ft_exit_hook(t_s *s);
void	ft_inicializar2(t_s *s, char *mapa);
int		ft_enemigos(t_s *s, char *mapa);
void	ft_img_personaje_puerta(t_s *s, int x, int a);
void	ft_img_personaje_suelo(t_s *s, int a);

#endif