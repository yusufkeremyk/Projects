/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalbayra < yalbayra@student.42kocaeli.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 00:57:50 by yaktas            #+#    #+#             */
/*   Updated: 2023/05/23 21:57:43 by yalbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	convert(t_main *main)
{
	int	x;
	int	y;

	main->sprite->wall = mlx_xpm_file_to_image(
			main->mlx, "./img/1wall.xpm", &x, &y);
	main->sprite->player = mlx_xpm_file_to_image(
			main->mlx, "./img/Prat_right.xpm", &x, &y);
	main->sprite->coin = mlx_xpm_file_to_image(
			main->mlx, "./img/Cfindux.xpm", &x, &y);
	main->sprite->tile = mlx_xpm_file_to_image(
			main->mlx, "./img/0grass.xpm", &x, &y);
	main->sprite->exit = mlx_xpm_file_to_image(
			main->mlx, "./img/Edoor.xpm", &x, &y);
}

int	draw_map3(t_main *main, int i, int j)
{
	if (main->map->map[i][j] == 'E')
		mlx_put_image_to_window(
			main->mlx, main->win, main->sprite->exit, j * PIXEL, i * PIXEL);
	else if (main->map->map[i][j] == 'C')
	{
		mlx_put_image_to_window(
			main->mlx, main->win, main->sprite->tile, j * PIXEL, i * PIXEL);
		mlx_put_image_to_window(
			main->mlx, main->win, main->sprite->coin, j * PIXEL, i * PIXEL);
	}
	else
		ft_error("Error\nWrong Character.", main);
	return (j);
}

int	draw_map2(t_main *main, int i, int j)
{
	if (main->map->map[i][j] == '1')
		mlx_put_image_to_window(
			main->mlx, main->win, main->sprite->wall, j * PIXEL, i * PIXEL);
	else if (main->map->map[i][j] == '0')
		mlx_put_image_to_window(
			main->mlx, main->win, main->sprite->tile, j * PIXEL, i * PIXEL);
	else if (main->map->map[i][j] == 'P')
	{
		mlx_put_image_to_window(
			main->mlx, main->win, main->sprite->player, j * PIXEL, i * PIXEL);
		main->player_y = i;
		main->player_x = j;
	}
	else
		j = draw_map3(main, i, j);
	j++;
	return (j);
}

void	draw_map(t_main *main)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	convert(main);
	while (i < (main->map->y))
	{
		while (j < (main->map->x))
		{
			j = draw_map2(main, i, j);
		}
		i++;
		j = 0;
	}
}
