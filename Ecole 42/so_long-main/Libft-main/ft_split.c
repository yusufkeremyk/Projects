/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalbayra < yalbayra@student.42kocaeli.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:49:39 by yalbayra          #+#    #+#             */
/*   Updated: 2023/05/23 21:49:39 by yalbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//dizi icinde gonderilen kelimeleri ayirir
//farkli bir pointere atar.
unsigned int	str_word_count(const char *s, char d)
{
	unsigned int	i;

	i = 0;
	while (*s)
	{
		if (*s == d)
			s++;
		else
		{
			while (*s != d && *s)
				s++;
			i++;
		}
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char			**m;
	unsigned int	j;
	unsigned int	a;

	if (!s)
		return (NULL);
	m = (char **) ft_calloc(str_word_count(s, c) + 1, sizeof(char *));
	if (!m)
		return (NULL);
	a = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			j = 0;
			while (*s != c && *s && ++j)
				s++;
			m[++a - 1] = (char *) ft_calloc(j + 1, sizeof(char));
			ft_strlcpy(m[a - 1], s - j, j + 1);
		}
	}
	return (m);
}

/* int	main(void)
{
	    char **a;
        a = ft_split("merhaba.selamlar.oye", '.');
        printf("%s\n",a[0]);
        printf("%s\n",a[1]);
        printf("%s",a[2]);
} */
