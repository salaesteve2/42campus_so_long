/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salustianosalamanca <salustianosalamanc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:14:58 by salustianos       #+#    #+#             */
/*   Updated: 2022/03/21 11:46:07 by salustianos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(void)
{
	printf("Error\nMapa no valido");
	return (0);
}

int	main(int argc, char *argv[])
{
	char	*text;
	int		fd;
	int		x;
	char	*map_completo;

	if (argc == 2)
	{
		x = 0;
		text = argv[1];
		fd = open(text, O_RDWR);
		if (fd == -1)
			return (ft_error());
		x = ft_lines(fd, x);
		fd = open(text, O_RDWR);
		map_completo = ft_proces(fd, x);
		close(fd);
		if (!map_completo || ft_caracters(map_completo) == -1)
			return (ft_error());
		ft_printf_map(map_completo);
		free(map_completo);
	}
	else
		printf("Error\nNumero de argumentos");
	return (0);
}
