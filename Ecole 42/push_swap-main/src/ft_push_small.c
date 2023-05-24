/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:07:56 by yaktas            #+#    #+#             */
/*   Updated: 2022/10/18 16:50:34 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_push_small_a(t_list **stack_a, t_list **stack_b, int flag)
{
	t_list	*head;

	head = *stack_a;
	while (head->next != NULL)
	{
		if (head->index == 0 && flag == 0)
		{
			pb(stack_a, stack_b);
			break ;
		}
		if (head->index == 1 && flag == 1)
		{
			pb(stack_a, stack_b);
			break ;
		}
		ra(stack_a);
		head = *stack_a;
	}
}
