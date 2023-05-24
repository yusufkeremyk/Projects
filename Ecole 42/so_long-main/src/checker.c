/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalbayra < yalbayra@student.42kocaeli.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 23:33:01 by yaktas            #+#    #+#             */
/*   Updated: 2023/05/23 21:57:04 by yalbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	ber_checker(char *path)
{
	int	i;

	i = ft_strlen(path);
	if (!((path[i - 1] == 'r') && (path[i - 2] == 'e')
			&& (path[i - 3] == 'b') && (path[i - 4] == '.')))
	{
		write(1, "Map name is wrong!", 18);
		exit(0);
	}
}

int	map_check_right_left(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->map->y - 1)
	{
		if (main->map->map[i][0] != '1')
		{
			ft_error("Error\nMap checker: Left is wrong.", main);
			return (0);
		}
		else if (main->map->map[i][main->map->x - 1] != '1')
		{
			ft_error("Error\nMap checker: Right is wrong.", main);
			return (0);
		}
		i++;
	}
	return (1);
}

int	map_check_top_bottom(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->map->x)
	{
		if (main->map->map[0][i] != '1')
		{
			ft_error("Error\nMap checker: The top is wrong.", main);
			return (0);
		}
		else if (main->map->map[main->map->y - 1][i] != '1')
		{
			ft_error("Error\nMap checker: The bottom is wrong.", main);
			return (0);
		}
		i++;
	}
	return (1);
}

int	map_check(t_main *main)
{
	if (main->ecount <= 0)
		ft_error("Error\nExit not found.", main);
	else if (main->ecount > 1)
		ft_error("Error\nThere are multiple exits.", main);
	else if (main->ccount <= 0)
		ft_error("Error\nCollectible not found.", main);
	else if (main->pcount <= 0)
		ft_error("Error\nPlayer not found.", main);
	else if (main->pcount > 1)
		ft_error("Error\nThere are multiple player.", main);
	map_check_top_bottom(main);
	map_check_right_left(main);
	return (0);
}
