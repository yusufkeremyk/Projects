/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalbayra < yalbayra@student.42kocaeli.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 07:38:48 by yaktas            #+#    #+#             */
/*   Updated: 2023/05/23 21:57:39 by yalbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	render_player2(t_main *main, int i)
{
	int	j;

	j = 0;
	while (j < main->map->x)
	{
		if (main->map->map[i][j] == '1')
			mlx_put_image_to_window(
				main->mlx, main->win,
				main->sprite->wall, j * PIXEL, i * PIXEL);
		else if (main->map->map[i][j] == '0' || main->map->map[i][j] == 'P')
			mlx_put_image_to_window(
				main->mlx, main->win,
				main->sprite->tile, j * PIXEL, i * PIXEL);
		else if (main->map->map[i][j] == 'E')
			mlx_put_image_to_window(
				main->mlx, main->win,
				main->sprite->exit, j * PIXEL, i * PIXEL);
		else if (main->map->map[i][j] == 'C')
			mlx_put_image_to_window(
				main->mlx, main->win,
				main->sprite->coin, j * PIXEL, i * PIXEL);
		j++;
	}
}

int	render_player(t_main *main)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	x = main->player_x;
	y = main->player_y;
	while (i < main->map->y)
	{
		render_player2(main, i);
		i++;
	}
	mlx_put_image_to_window(
		main->mlx, main->win, main->sprite->player, x * PIXEL, y * PIXEL);
	return (0);
}

int	render(t_main *main)
{
	render_player(main);
	if (main->ccount == 0 && main->map->map
		[main->player_y][main->player_x] == 'E')
		key_hook(ESC, main);
	return (0);
}
