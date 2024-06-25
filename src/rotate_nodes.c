/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 22:01:55 by anfi              #+#    #+#             */
/*   Updated: 2024/03/11 20:25:12 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **head)
{
	t_node	*aux_tail;

	(*head)->prev = (*head)->tail;
	(*head)->tail->next = *head;
	aux_tail = (*head)->tail;
	*head = (*head)->next;
	(*head)->tail = aux_tail;
	(*head)->prev->next = NULL;
	(*head)->prev = NULL;
	(*head)->tail = (*head)->tail->next;
	if ((*head)->stack == 'a')
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
	update_index(head);
	update_tail(head);
}

void	rra(t_node **head)
{
	t_node	*aux_tail;

	(*head)->tail->next = *head;
	(*head)->prev = (*head)->tail;
	(*head)->tail->prev->next = NULL;
	(*head)->tail = (*head)->tail->prev;
	aux_tail = (*head)->tail;
	*head = (*head)->prev;
	(*head)->tail = aux_tail;
	if ((*head)->stack == 'a')
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
	update_tail(head);
	update_index(head);
}

void	rr(t_node **head_one, t_node **head_two, int *index_one, int *index_two)
{
	t_node	*tail_one;

	(*head_one)->prev = (*head_one)->tail;
	(*head_one)->tail->next = *head_one;
	tail_one = (*head_one)->tail;
	*head_one = (*head_one)->next;
	(*head_one)->tail = tail_one;
	(*head_one)->prev->next = NULL;
	(*head_one)->prev = NULL;
	(*head_one)->tail = (*head_one)->tail->next;
	(*head_two)->prev = (*head_two)->tail;
	(*head_two)->tail->next = *head_two;
	tail_one = (*head_two)->tail;
	*head_two = (*head_two)->next;
	(*head_two)->tail = tail_one;
	(*head_two)->prev->next = NULL;
	(*head_two)->prev = NULL;
	(*head_two)->tail = (*head_two)->tail->next;
	write(1, "rr\n", 3);
	update_tail(head_one);
	update_tail(head_two);
	update_index(head_one);
	update_index(head_two);
	(*index_one)--;
	(*index_two)--;
}

void	rrr(t_node **head_one, t_node **head_two,
		int *index_one, int *index_two)
{
	t_node	*tail_one;
	t_node	*tail_two;

	(*head_one)->tail->next = *head_one;
	(*head_one)->prev = (*head_one)->tail;
	(*head_one)->tail->prev->next = NULL;
	(*head_one)->tail = (*head_one)->tail->prev;
	tail_one = (*head_one)->tail;
	*head_one = (*head_one)->prev;
	(*head_one)->tail = tail_one;
	(*head_two)->tail->next = *head_two;
	(*head_two)->prev = (*head_two)->tail;
	(*head_two)->tail->prev->next = NULL;
	(*head_two)->tail = (*head_two)->tail->prev;
	tail_two = (*head_two)->tail;
	*head_two = (*head_two)->prev;
	(*head_two)->tail = tail_two;
	update_index(head_one);
	update_tail(head_one);
	update_index(head_two);
	update_tail(head_two);
	write(1, "rrr\n", 4);
	(*index_one)++;
	(*index_two)++;
}
