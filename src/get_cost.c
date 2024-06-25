/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:20:29 by anfi              #+#    #+#             */
/*   Updated: 2024/06/19 17:27:02 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * This function calculates the cost of moving a node to its stack head.
 * If it is above the median of the stack, it's cost is it's index.
 * Else, the cost is the tail index - its index, as a negative nº to show
 * it needs reverse rotate.
 */
int	return_cost(int index, int total)
{
	if (index <= (total / 2) || (index == 1 && total == 1))
		return (index);
	else
		return (((total - index) + 1) * -1);
}

/**
 * decrease_cost will check if the following movements can be made:
 * - rr, ra, rb.
 */
void	decrease_cost(int *cost_a, int *cost_b, int *total_cost)
{
	if (*cost_a > 0 && *cost_b > 0)
	{
		(*total_cost)++;
		(*cost_a)--;
		(*cost_b)--;
	}
	else if (*cost_a > 0)
	{
		(*total_cost)++;
		(*cost_a)--;
	}
	else if (*cost_b > 0)
	{
		(*total_cost)++;
		(*cost_b)--;
	}
}

/**
 * increase_cost will check if the following movements can be made:
 * - rrr, rra, rrb.
 */
void	increase_cost(int *cost_a, int *cost_b, int *total_cost)
{
	if (*cost_a < 0 && *cost_b < 0)
	{
		(*total_cost)++;
		(*cost_a)++;
		(*cost_b)++;
	}
	else if (*cost_a < 0)
	{
		(*total_cost)++;
		(*cost_a)++;
	}
	else if (*cost_b < 0)
	{
		(*total_cost)++;
		(*cost_b)++;
	}
}

/**
 * This function calculates the push_cost of paired nodes.
 * - return_cost() will return the cost of r (positive) or rr (negative) the node
 * 	to the head.
 * - decrease_cost() and increase_cost will check based on cost_a & cost_b which
 * 	movement can be made. The objective is to have both cost to 0.
 * - total_cost holds the real movements needed to move both nodes to head.
 */
int	get_cost(t_node *current_node)
{
	int	main_tail_index;
	int	target_tail_index;
	int	cost_a;
	int	cost_b;
	int	total_cost;

	main_tail_index = current_node->tail->index;
	target_tail_index = current_node->target->tail->index;
	cost_a = return_cost(current_node->index, main_tail_index);
	cost_b = return_cost(current_node->target->index, target_tail_index);
	total_cost = 0;
	while (cost_a || cost_b)
	{
		decrease_cost(&cost_a, &cost_b, &total_cost);
		increase_cost(&cost_a, &cost_b, &total_cost);
	}
	return (total_cost);
}
