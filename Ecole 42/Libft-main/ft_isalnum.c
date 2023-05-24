/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalbayra < yalbayra@student.42kocaeli.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:47:08 by yalbayra          #+#    #+#             */
/*   Updated: 2023/05/23 21:47:08 by yalbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
//sayi ve harf kontrolu.
int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}
/*
int	main(void)
{
	char	c;

	c = '.';
	printf("%d", ft_isalnum(c));
}*/
