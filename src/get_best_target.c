/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_best_target.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 20:46:47 by anfi              #+#    #+#             */
/*   Updated: 2024/06/19 17:17:28 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * This function pairs each node from stack_b with the next bigger nº inside
 * stack_a. If no bigger nº is found, that node is paired with the smallest nº
 * inside stack_a.
 */
void	biggest_target(t_node *one, t_node *two)
{
	t_node	*aux;

	aux = two;
	one->target = NULL;
	while (two)
	{
		if ((one->value < two->value)
			&& (!one->target || one->target->value > two->value))
		{
			one->target = two;
		}
		two = two->next;
	}
	if (!one->target)
	{
		two = aux;
		while (two)
		{
			if (!one->target || one->target->value > two->value)
				one->target = two;
			two = two->next;
		}
	}
}

/**
 * This function pairs each node from stack_a with the next smaller nº inside
 * stack_b. If no smaller nº is found, that node is paired with the biggest nº
 * inside stack_b.
 */
void	smallest_target(t_node *one, t_node *two)
{
	t_node	*aux;

	aux = two;
	one->target = NULL;
	while (two)
	{
		if ((one->value > two->value)
			&& (!one->target || one->target->value < two->value))
		{
			one->target = two;
		}
		two = two->next;
	}
	if (!one->target)
	{
		two = aux;
		while (two)
		{
			if (!one->target || one->target->value < two->value)
				one->target = two;
			two = two->next;
		}
	}
}

/**
 * This function will return the node which holds the cheapest push cost.
 * If we find one push cost that is 2 or less, we automatically choose that pair.
 * Else, we keep calculating the cost of each node and then return the cheapest.
 */
t_node	*pair_nodes(t_node *node_one, t_node*node_two)
{
	t_node	*best_cost_node;

	best_cost_node = NULL;
	while (node_one)
	{
		if (node_one->stack == 'a')
			smallest_target(node_one, node_two);
		else
			biggest_target(node_one, node_two);
		node_one->push_cost = get_cost(node_one);
		if (node_one->push_cost <= 1)
		{
			return (node_one);
		}
		if (!best_cost_node
			|| (best_cost_node->push_cost > node_one->push_cost))
		{
			best_cost_node = node_one;
		}
		node_one = node_one->next;
	}
	return (best_cost_node);
}
