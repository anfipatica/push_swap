/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_method.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 20:49:00 by anfi              #+#    #+#             */
/*   Updated: 2024/05/30 16:42:02 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * This functions decides how to proceed with the sorting.
 * If there is only twwo or three numbers it calls their respective function.
 * Else, it starts the turk_algorithm.
*/
void	order_list(t_node **head_a, t_node **head_b)
{
	if ((*head_a)->tail->index == 1)
		ft_order_two(head_a);
	else if ((*head_a)->tail->index == 2)
		ft_order_three(head_a);
	else
	{
		turk_algorithm(head_a, head_b);
	}
}

/**
 * ft_order_three() orders three numbers.
*/
void	ft_order_three(t_node **head)
{
	if ((*head)->tail->index > 2)
		return ;
	if ((*head)->value > (*head)->next->value
		&& (*head)->value > (*head)->next->next->value)
		ra(head);
	else if ((*head)->next->value > (*head)->value
		&& (*head)->next->value > (*head)->next->next->value)
		rra(head);
	if ((*head)->value > (*head)->next->value)
		sa(head, 3);
}

/**
 * ft_order_two() orders two numbers.
*/
void	ft_order_two(t_node **head)
{
	if ((*head)->value > (*head)->next->value)
		sa(head, 2);
}
