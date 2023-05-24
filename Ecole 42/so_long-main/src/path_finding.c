/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalbayra < yalbayra@student.42kocaeli.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:43:00 by yaktas            #+#    #+#             */
/*   Updated: 2023/05/23 21:57:40 by yalbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

static void	path_finding(int **v_map, t_main *main, int y, int x)
{
	if (main->map->map[y][x] == 'E' || main->map->map[y][x] == 'C')
		main->read_count++;
	if (main->map->map[y - 1][x] != '1' && v_map[y - 1][x] < 1)
	{
		v_map[y - 1][x] = v_map[y][x] + 1;
		path_finding(v_map, main, y - 1, x);
	}
	if (main->map->map[y][x + 1] != '1' && v_map[y][x + 1] < 1)
	{
		v_map[y][x + 1] = v_map[y][x] + 1;
		path_finding(v_map, main, y, x + 1);
	}
	if (main->map->map[y + 1][x] != '1' && v_map[y + 1][x] < 1)
	{
		v_map[y + 1][x] = v_map[y][x] + 1;
		path_finding(v_map, main, y + 1, x);
	}
	if (main->map->map[y][x - 1] != '1' && v_map[y][x - 1] < 1)
	{
		v_map[y][x - 1] = v_map[y][x] + 1;
		path_finding(v_map, main, y, x - 1);
	}
}

static void	print_virtual_map(t_main *main, int **v_map, int y, int x)
{
	while (y < main->map->y)
	{
		x = 0;
		write(1, "\n", 1);
		while (x < main->map->x)
		{
			if (v_map[y][x] == 0)
				ft_putstr_fd("\033[1;42m00-\033[0;39m", 1);
			else if (v_map[y][x] > 0 && v_map[y][x] < 10)
			{
				ft_putstr_fd("0", 1);
				ft_putstr_fd(ft_strjoin(ft_itoa(v_map[y][x]), "-"), 1);
			}
			else
			{
				ft_putstr_fd(ft_strjoin(ft_itoa(v_map[y][x]), "-"), 1);
			}
			x++;
		}
		y++;
	}
	ft_putstr_fd("\n\n", 1);
}

void	virtual_map(t_main *main, int y, int x, int flag)
{
	int	**v_map;

	v_map = (int **)malloc(sizeof(int *) * main->map->y);
	while (y < main->map->y)
	{
		v_map[y] = (int *)malloc(sizeof(int) * main->map->x);
		x = 0;
		while (x < main->map->x)
		{
			v_map[y][x] = 0;
			x++;
		}
		y++;
	}
	v_map[main->player_y][main->player_x] = 1;
	path_finding(v_map, main, main->player_y, main->player_x);
	if (!(main->read_count == main->ccount + 1))
		ft_error("Error\nCollecttables is not accessible!", main);
	if (flag == 1)
		print_virtual_map(main, v_map, 0, 0);
	virtual_map_free(v_map, main);
}
