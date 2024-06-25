/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 21:17:52 by anfi              #+#    #+#             */
/*   Updated: 2024/05/30 16:07:19 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * ft_lstsize counts how many nodes there are inside a list.
 * It is also useful to see their content or order since it iterates from head
 * to tail. But this would be commented if needed and the norm does not
 * accept comments inside functions. Sad.
*/
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

/**
 * ft_new_node creates a new node. It allocates memory and initializes
 * it's content.
*/
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

/**
 * add_back creates a node and adds it as the tail of a list.
 * It receives the direction of the head of said list, and the values we want
 * to give the node. It creates the node thanks to ft_new_node and if the
 * head is NULL meaning the list is empty,it makes this new node both the
 * head and the tail of the list.
*/
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

/**
 * ft_free_list frees a list by freeing each node it is conformed by
*/
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
