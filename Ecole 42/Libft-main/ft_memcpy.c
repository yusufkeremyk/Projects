/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalbayra < yalbayra@student.42kocaeli.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:49:03 by yalbayra          #+#    #+#             */
/*   Updated: 2023/05/23 21:49:03 by yalbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//srcden deste n kadar kopyalar.
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dest;
	char	*srce;
	size_t	i;

	i = 0;
	dest = (char *)dst;
	srce = (char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		dest[i] = srce[i];
		i++;
	}
	return (dst);
}

/* int main()
{
	char	a[] = "bilgisayar";
	char	b[] = "emre";

	printf("%s", ft_memcpy(a, b, 3));

} */
