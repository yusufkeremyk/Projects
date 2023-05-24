/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalbayra < yalbayra@student.42kocaeli.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 03:44:26 by yaktas            #+#    #+#             */
/*   Updated: 2023/05/23 21:57:41 by yalbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	ft_up(t_main *main)
{
	main->player_y--;
	main->mcount++;
	ft_putstr_fd("\033[1;42m\rMove:", 1);
	ft_putnbr_fd(main->mcount, 1);
	if (main->map->map[main->player_y][main->player_x] == 'C')
	{
		main->map->map[main->player_y][main->player_x] = '0';
		main->ccount--;
	}
}

void	ft_left(t_main *main)
{
	main->player_x--;
	main->mcount++;
	ft_putstr_fd("\033[1;42m\rMove:", 1);
	ft_putnbr_fd(main->mcount, 1);
	if (main->map->map[main->player_y][main->player_x] == 'C')
	{
		main->map->map[main->player_y][main->player_x] = '0';
		main->ccount--;
	}
}

void	ft_down(t_main *main)
{
	main->player_y++;
	main->mcount++;
	ft_putstr_fd("\033[1;42m\rMove:", 1);
	ft_putnbr_fd(main->mcount, 1);
	if (main->map->map[main->player_y][main->player_x] == 'C')
	{
		main->map->map[main->player_y][main->player_x] = '0';
		main->ccount--;
	}
}

void	ft_right(t_main *main)
{
	main->player_x++;
	main->mcount++;
	ft_putstr_fd("\033[1;42m\rMove:", 1);
	ft_putnbr_fd(main->mcount, 1);
	if (main->map->map[main->player_y][main->player_x] == 'C')
	{
		main->map->map[main->player_y][main->player_x] = '0';
		main->ccount--;
	}
}

int	key_hook(int keycode, t_main *main)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(main->mlx, main->win);
		exit(0);
	}
	else if (keycode == W && main->map->map
		[main->player_y - 1][main->player_x] != '1')
		ft_up(main);
	else if (keycode == A && main->map->map
		[main->player_y][main->player_x - 1] != '1')
		ft_left(main);
	else if (keycode == S && main->map->map
		[main->player_y + 1][main->player_x] != '1')
		ft_down(main);
	else if (keycode == D && main->map->map
		[main->player_y][main->player_x + 1] != '1')
		ft_right(main);
	return (0);
}
