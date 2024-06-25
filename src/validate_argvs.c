/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_argvs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:27:43 by ymunoz-m          #+#    #+#             */
/*   Updated: 2024/06/25 21:10:23 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_argv(char *argv)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (argv[i])
	{
		while (argv[i] == ' ')
			i++;
		if (argv[i] && (argv[i] == '-' || argv[i] == '+'))
			i++;
		if (argv[i] && ((argv[i - 1] == '-' && argv[i] == '0')
				|| (argv[i] < '0' || argv[i] > '9')))
			return (-1);
		while (argv[i] && (argv[i] >= '0' && argv[i] <= '9'))
		{
			i++;
			if (!argv[i] || (argv[i] && argv[i] == ' '))
				n++;
			else if (argv[i] < '0' || argv[i] > '9')
				return (-1);
		}
	}
	return (n);
}

int	validate_argvs(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (validate_argv(argv[i]) <= 0)
			return (-1);
	}
	return (0);
}
