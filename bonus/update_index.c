/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 21:17:52 by anfi              #+#    #+#             */
/*   Updated: 2024/03/13 21:43:59 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	update_index(t_node **head)
{
	int	i;

	if (!(*head))
		return ;
	i = -1;
	while ((*head)->next != NULL)
	{
		(*head)->index = ++i;
		*head = (*head)->next;
	}
	(*head)->index = ++i;
	while ((*head)->index > 0)
		*head = (*head)->prev;
}

void	update_tail(t_node **current_node)
{
	t_node	*aux;

	aux = *current_node;
	while (aux)
	{
		aux->tail = (*current_node)->tail;
		aux = aux->next;
	}
}
