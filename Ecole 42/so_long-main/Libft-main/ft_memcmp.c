/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalbayra < yalbayra@student.42kocaeli.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:48:59 by yalbayra          #+#    #+#             */
/*   Updated: 2023/05/23 21:48:59 by yalbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//bellekte belirlenen iki stringi n kadar karsilastirir.
//fark varsa farki dondurur.
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*st1;
	unsigned char	*st2;

	if (n == 0)
		return (0);
	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	i = 0;
	while (i < n - 1)
	{
		if (st1[i] != st2[i])
			return (st1[i] - st2[i]);
	i++;
	}
	return (st1[i] - st2[i]);
}

/*int	main(void)
{
	char	a[] = "bilgisayar";
	char	b[] = "bilgiler";
	printf("%d\n", ft_memcmp(a, b, 6));
}*/