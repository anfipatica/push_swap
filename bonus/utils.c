/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:45:15 by ymunoz-m          #+#    #+#             */
/*   Updated: 2024/06/25 15:37:33 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/**
 * A function that calls both ft_free_list() and free_memory() to free
 * argv and the list.
*/
void	free_all(t_node **head, char **argv)
{
	ft_free_list(head);
	free_memory(argv);
}

/**
 * A function to allocate memory and fill that space with null characters
 * to have a clean memory to write on.
*/
void	*ft_calloc(size_t nitems, size_t size)
{
	void	*str;
	size_t	i;

	str = (malloc(nitems * size));
	if (str == 0)
		return (NULL);
	i = 0;
	while (i < nitems)
	{
		((char *)str)[i] = '\0';
		i++;
	}
	return (str);
}

/**
 * A function to free the memory of a string array.
*/
void	free_memory(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	ft_isdigit(char *c)
{
	long	i;

	i = -1;
	if (c[0] && c[1] && (c[0] == '+' || c[0] == '-'))
		i++;
	while (c[++i])
	{
		if ((c[i] < '0' || c[i] > '9'))
			return (1);
	}
	i = ft_atoi(c, NULL);
	if (i > MAX_INT || i < MIN_INT)
		return (1);
	return (0);
}
