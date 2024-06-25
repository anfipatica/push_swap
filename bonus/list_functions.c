/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 21:17:52 by anfi              #+#    #+#             */
/*   Updated: 2024/05/30 15:15:00 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_lstsize(t_node *lst)
{
	t_node	*aux;
	int		i;

	if (lst == NULL)
		return (0);
	aux = lst;
	i = 0;
	while (aux->next != NULL)
	{
		aux = aux->next;
		i++;
	}
	return (++i);
}

t_node	*ft_new_node(int value, int index)
{
	t_node	*new_node;

	new_node = ft_calloc(1, sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = index;
	new_node->push_cost = 0;
	new_node->stack = 'a';
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->target = NULL;
	new_node->tail = NULL;
	return (new_node);
}

void	add_back(t_node **head, int value, int index)
{
	t_node	*new_node;

	new_node = ft_new_node(value, index);
	if (!new_node)
		return ;
	if (!(*head))
	{
		*head = new_node;
		(*head)->tail = *head;
	}
	else
	{
		new_node->prev = (*head)->tail;
		(*head)->tail->next = new_node;
		(*head)->tail = new_node;
		update_tail(head);
	}
}

void	ft_free_list(t_node **current_node)
{
	t_node	*aux;
	int		i;
	int		last_node;

	if (!(*current_node))
		return ;
	i = -1;
	last_node = (*current_node)->tail->index;
	while (++i < last_node)
	{
		aux = (*current_node)->next;
		free(*current_node);
		*current_node = aux;
	}
	free(*current_node);
}
