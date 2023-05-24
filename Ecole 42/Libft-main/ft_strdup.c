/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalbayra < yalbayra@student.42kocaeli.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:49:51 by yalbayra          #+#    #+#             */
/*   Updated: 2023/05/23 21:51:28 by yalbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//malloc ile yer acip icine str yaziyor.
char	*ft_strdup(const char *str)
{
	char	*m;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(str);
	m = (char *)malloc(j + 1);
	if (!m)
		return (0);
	while (str[i])
	{
		m[i] = str[i];
		i++;
	}
	m[i] = '\0';
	return (m);
}

/* int	main(void)
{
	char a[] = "emre";
	printf("%s", ft_strdup(a));
} */