/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 21:53:27 by anfi              #+#    #+#             */
/*   Updated: 2024/06/19 17:35:37 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * At this point stack_a is *almost* ordered. I mean, it is technically ordered
 * but desordered at the same time since the smallest and the biggest nº collide.
 * We need to either ra or rra until the head holds the smallest nº, and done.
 */
void	ft_order_min_int(t_node **head)
{
	int	n;
	int	median;

	n = ft_is_ordered(*head);
	median = (*head)->tail->index / 2 + 1;
	while (n != 0)
	{
		if (n < median)
			ra(head);
		else
			rra(head);
		n = ft_is_ordered(*head);
		ft_lstsize(*head);
		if (n == 0)
			return ;
	}
}

/**
 * The turk_algorithm itself! How does it work?
 * 
 * 1. We push each node from stack A to stack B until there's only 3 nodes left
 * 	in stack A.
 * 2. We first pb three nodes, unless doing so would left less than 3 nodes
 * 	inside stack_1.
 * 3. The push is done pairing each node inside stack A with the next smaller nº
 * 	of stack_b, or the biggest number of the stack B if no smaller nº is found.
 * 4. We push the node with the cheapest move cost, which implies both paired
 * 	nodes being on its respective stack head, and the push itself.
 * 5. Once there's only three nodes left on stack_a, we order those three nº
 * 	And start pushing back each node from stack_b.
 * 6. The process of 'pa' is the same BUT this time we pair each node of stack_b
 * with the next bigger number, or the smallest number if no bigger nº found.
 * 7. Once this is done, the nº are ordered but the head might not be the
 * 	smallest number, so we 'ra' or 'rra' until it is and then it is done.
 */
void	turk_algorithm(t_node **head_a, t_node **head_b)
{
	t_node	*cheapest_node;

	pb(head_a, head_b);
	if ((*head_a)->tail->index > 2 && ft_is_ordered(*head_a) != 0)
		pb(head_a, head_b);
	while ((*head_a)->tail->index > 2 && ft_is_ordered(*head_a) != 0)
	{
		cheapest_node = pair_nodes(*head_a, *head_b);
		move_nodes_to_head(head_a, head_b, cheapest_node->index,
			cheapest_node->target->index);
	}
	ft_order_three(head_a);
	while ((*head_b))
	{
		cheapest_node = pair_nodes(*head_b, *head_a);
		move_nodes_to_head(head_b, head_a, cheapest_node->index,
			cheapest_node->target->index);
	}
	ft_order_min_int(head_a);
}
