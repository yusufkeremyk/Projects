/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalbayra < yalbayra@student.42kocaeli.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:12:27 by yaktas            #+#    #+#             */
/*   Updated: 2023/05/23 21:57:38 by yalbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

t_main	*main_init(char *path)
{
	t_main	*main;

	main = (t_main *) malloc(sizeof(t_main));
	main->map = (t_map *)malloc(sizeof(t_map));
	main->sprite = (t_sprite *)malloc(sizeof(t_sprite));
	main->mcount = 0;
	main->read_count = 0;
	main->map->map = map_init(path, main);
	main->mlx = mlx_init();
	main->win = mlx_new_window(
			main->mlx, main->map->x * PIXEL, main->map->y * PIXEL, "so_long");
	return (main);
}

int	main(int ac, char **av)
{
	t_main	*main;
	int		flag;

	flag = 0;
	if (ac == 2)
	{
		ber_checker(av[1]);
		main = main_init(av[1]);
		map_check(main);
		virtual_map(main, 0, 0, flag);
		draw_map(main);
		mlx_hook(main->win, 2, 1L << 0, key_hook, main);
		mlx_loop_hook(main->mlx, render, main);
		mlx_hook(main->win, 17, 0, ft_x_button, main);
		mlx_loop(main->mlx);
	}
	write(1, "Wrong Argument", 14);
	return (0);
}
