/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_lines_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:49:28 by salustianos       #+#    #+#             */
/*   Updated: 2022/03/17 15:42:28 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_lines(int fd, int x)
{
	char	*map;

	x++;
	map = get_next_line(fd, 35);
	free(map);
	while (map != 0)
	{
		map = get_next_line(fd, 35);
		free(map);
		x++;
	}
	x--;
	return (x);
}
