/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:36:38 by anfi              #+#    #+#             */
/*   Updated: 2024/05/30 16:09:26 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

/**
 * Ft_atoi transforms a string to a char.
 * An adapted version of the libft atoi to accept a boolean value which holds
 * the validity state of the argument received.
*/
long	ft_atoi(const char *s, t_bool *valid)
{
	long	n;
	long	i;
	long	j;

	n = 0;
	i = 0;
	j = 1;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			j = j * -1;
		i++;
		if ((s[i - 1] == '-' && s[i] == '0') || (!(s[i] >= '0' && s[i] <= '9')))
			*valid = false;
	}
	if (s[i] == '0' && s[i + 1])
		*valid = false;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			*valid = false;
		n = (n * 10) + (s[i] - '0');
		i++;
	}
	return (n * j);
}

void	ft_is_repeated(t_node **head, t_bool *valid)
{
	t_node	*aux1;
	t_node	*aux2;

	if (!head)
		return ;
	aux1 = *head;
	while (*valid == true && aux1->next)
	{
		aux2 = aux1->next;
		while (aux2->next && *valid == true)
		{
			if (aux1->value == aux2->value)
				*valid = false;
			aux2 = aux2->next;
		}
		if (aux1->value == aux2->value)
			*valid = false;
		aux1 = aux1->next;
	}
}

int	ft_is_ordered(t_node *head)
{
	t_node	*aux;

	aux = head;
	while (aux && aux->next)
	{
		if (aux->value > aux->next->value)
			return (aux->next->index);
		if (aux->next)
			aux = aux->next;
	}
	return (0);
}
