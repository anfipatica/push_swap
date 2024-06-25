/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes_to_head.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 21:53:27 by anfi              #+#    #+#             */
/*   Updated: 2024/06/19 17:30:33 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * This function moves one node to it's stack head.
 */
void	move_node(t_node **head, int index, int median)
{
	if (index == 0)
		return ;
	if (index <= median)
	{
		while (index-- > 0)
			ra(head);
	}
	else
	{
		while (index++ < ((*head)->tail->index))
			rra(head);
		rra(head);
	}
}

/**
 * Once we have the best push cost node pair, we move them both the its stack
 * head. It will stop once both nodes have index 0.
 * It first tries to either rr or rrr since it is more cost efficient.
 * Then, it moves each node independently with ra, rra or rb, rrb with move_node.
 * And lastly, we push.
 */
void	move_nodes_to_head(t_node **head_main, t_node **head_target,
		int main_index, int target_index)
{
	int	main_median;
	int	target_median;

	main_median = (*head_main)->tail->index / 2 + 1;
	target_median = (*head_target)->tail->index / 2 + 1;
	while (main_index != 0 && target_index != 0)
	{
		if (main_index < main_median && target_index < target_median)
			rr(head_main, head_target, &main_index, &target_index);
		else if (main_index >= main_median && target_index >= target_median)
			rrr(head_main, head_target, &main_index, &target_index);
		else
			break ;
		if (main_index > (*head_main)->tail->index)
			main_index = 0;
		if (target_index > (*head_target)->tail->index)
			target_index = 0;
	}
	move_node(head_main, main_index, main_median);
	move_node(head_target, target_index, target_median);
	pb(head_main, head_target);
}
