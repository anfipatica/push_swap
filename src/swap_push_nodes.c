/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push_nodes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:17:04 by anfi              #+#    #+#             */
/*   Updated: 2024/05/30 16:50:40 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * sa() swaps the position of the first and second node.
 * It is only called when ordering two or three numbers.
*/
void	sa(t_node **head, int i)
{
	if (i == 3)
	{
		(*head)->next = (*head)->next->next;
		(*head)->next->prev->next = (*head);
		(*head)->prev = (*head)->next->prev;
		(*head)->next->prev = (*head);
		(*head)->prev->prev = NULL;
		(*head) = (*head)->prev;
		(*head)->prev = NULL;
		(*head)->tail = (*head)->next->next;
	}
	else if (i == 2)
	{
		(*head)->next->next = (*head);
		(*head)->prev = (*head)->next;
		(*head)->next = NULL;
		(*head)->prev->prev = NULL;
		(*head) = (*head)->prev;
		(*head)->tail = (*head)->next;
	}
	write(1, "sa\n", 3);
	update_index(head);
}

/**
 * A function that writes which stack was the target of the pushing.
*/
void	write_pb(char c)
{
	write(1, "p", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

/**
 * pb_empty_stack() makes the push to an empty stack.
*/
void	pb_empty_stack(t_node **head_a, t_node **head_b)
{
	t_node	*aux_tail_a;

	*head_b = *head_a;
	aux_tail_a = (*head_a)->tail;
	*head_a = (*head_a)->next;
	(*head_a)->tail = aux_tail_a;
	(*head_a)->prev = NULL;
	(*head_b)->next = NULL;
	(*head_b)->tail = *head_b;
}

/**
 * pb_last_node() makes the last push from stack_b.
*/
void	pb_last_node(t_node **head_b, t_node **head_a)
{
	t_node	*aux_tail;

	(*head_a)->prev = *head_b;
	(*head_b)->next = *head_a;
	aux_tail = (*head_a)->tail;
	*head_a = *head_b;
	*head_b = NULL;
	(*head_a)->tail = aux_tail;
}

/**
 * pb() pushes the head of one stack into the head of the other stack.
 * -> head_one = the head node that will be pushed;
 * -> head_two = the head of the stack that will receive the node;
*/
void	pb(t_node **head_one, t_node **head_two)
{
	t_node	*aux_tail_two;

	if (!(*head_two))
		pb_empty_stack(head_one, head_two);
	else if (!(*head_one)->next)
		pb_last_node(head_one, head_two);
	else
	{
		(*head_two)->prev = *head_one;
		(*head_one)->next->prev = NULL;
		(*head_one)->next->tail = (*head_one)->tail;
		*head_one = (*head_one)->next;
		(*head_two)->prev->next = *head_two;
		aux_tail_two = (*head_two)->tail;
		*head_two = (*head_two)->prev;
		(*head_two)->tail = aux_tail_two;
	}
	if ((*head_two)->stack == 'a')
		(*head_two)->stack = 'b';
	else
		(*head_two)->stack = 'a';
	update_tail(head_two);
	write_pb((*head_two)->stack);
	update_index(head_one);
	update_index(head_two);
}
