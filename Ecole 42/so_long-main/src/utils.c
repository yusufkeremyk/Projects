/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalbayra < yalbayra@student.42kocaeli.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 14:40:09 by yaktas            #+#    #+#             */
/*   Updated: 2023/05/23 21:57:37 by yalbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	ft_free(t_main *main)
{
	free(main->map);
	free(main->sprite);
}

void	ft_error(char *errormsg, t_main *main)
{
	int	i;

	i = 0;
	while (errormsg[i])
	{
		write(1, &errormsg[i], 1);
		i++;
	}
	write(1, "\n", 1);
	ft_free(main);
	exit(0);
}

int	ft_x_button(t_main *main)
{
	mlx_destroy_image(main->mlx, main->win);
	exit(0);
	return (0);
}

void	virtual_map_free(int **v_map, t_main *main)
{
	int	i;

	i = 0;
	while (i < main->map->y)
	{
		free(v_map[i]);
		i++;
	}
	free(v_map);
}

void	player_xy(t_main *main, int x, int y)
{
	main->pcount++;
	main->player_x = x;
	main->player_y = y;
}
