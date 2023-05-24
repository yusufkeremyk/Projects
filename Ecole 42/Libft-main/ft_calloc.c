/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalbayra < yalbayra@student.42kocaeli.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:46:57 by yalbayra          #+#    #+#             */
/*   Updated: 2023/05/23 21:46:57 by yalbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
//bellekte bos bir alan acar.
void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*mem;

	mem = malloc(size * nmemb);
	if (!mem)
		return (0);
	ft_bzero(mem, (size * nmemb));
	return (mem);
}
