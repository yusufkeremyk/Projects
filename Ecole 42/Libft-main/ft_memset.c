/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalbayra < yalbayra@student.42kocaeli.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:49:13 by yalbayra          #+#    #+#             */
/*   Updated: 2023/05/23 21:49:13 by yalbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//s dizisini n kadar c ile doldurur. 
void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	char			*j;

	i = 0;
	j = (char *)s;
	while (i < n)
	{
		j[i] = c;
		i++;
	}
	s = j;
	return (s);
}

/* int	main(void)
{
	char a[] = "yunusemre";
	char b = 'z';

	printf("%s", ft_memset(a, b , 5));
} */