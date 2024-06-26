/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:14:02 by ymunoz-m          #+#    #+#             */
/*   Updated: 2024/06/26 20:11:43 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/**
 * Once we have our cleaned list of arguments inside a string array, we 
 * put them inside a list in the order they were sent.
*/
void	create_stack_a(t_node **head, char **argv, t_bool *valid)
{
	long	n;
	int		i;

	i = -1;
	while (argv[++i])
	{
		n = ft_atoi(argv[i], valid);
		if (n > MAX_INT || n < MIN_INT)
			*valid = false;
		if (*valid == false)
			return ;
		add_back(head, n, i);
	}
}

/**
 * Where the magic happens. The beginning and the end.
*/
int	main(int argc, char **argv)
{
	t_node	*head_a;
	t_node	*head_b;
	t_bool	valid;

	head_a = NULL;
	head_b = NULL;
	valid = true;
	if (argc == 1)
		return (0);
	if (validate_argvs(argv) != 0)
		return (write(2, "Error\n", 6));
	argv = ft_split(argv, ' ');
	create_stack_a(&head_a, argv, &valid);
	ft_is_repeated(&head_a, &valid);
	if (valid == false)
		return (write(2, "Error\n", 6), free_all(&head_a, argv), 0);
	while (get_order(0, &head_a, &head_b, &valid) == 0)
		;
	if (ft_is_ordered(head_a) == 0 && !head_b && valid == true)
		write(1, "OK\n", 3);
	else if (valid == true)
		write(1, "KO\n", 3);
	return (free_all(&head_a, argv), 0);
}
