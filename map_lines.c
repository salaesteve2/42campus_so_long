/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:49:28 by salustianos       #+#    #+#             */
/*   Updated: 2022/03/17 09:48:43 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
