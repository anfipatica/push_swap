/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_orders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:32:44 by ymunoz-m          #+#    #+#             */
/*   Updated: 2024/05/29 19:06:12 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	execute_order(char *order, t_node **head_a, t_node **head_b)
{
	if (!ft_strcmp(order, "sa\n"))
		return (sa(head_a), 0);
	if (!ft_strcmp(order, "pa\n"))
		return (pb(head_b, head_a), 0);
	if (!ft_strcmp(order, "pb\n"))
		return (pb(head_a, head_b), 0);
	if (!ft_strcmp(order, "ra\n"))
		return (ra(head_a), 0);
	if (!ft_strcmp(order, "rra\n"))
		return (rra(head_a), 0);
	if (!ft_strcmp(order, "rb\n"))
		return (ra(head_b), 0);
	if (!ft_strcmp(order, "rrb\n"))
		return (rra(head_b), 0);
	if (!ft_strcmp(order, "rr\n"))
		return (rr(head_a, head_b), 0);
	if (!ft_strcmp(order, "rrr\n"))
		return (rrr(head_a, head_b), 0);
	write(1, "Error\n", 6);
	return (-1);
}

char	*ft_strnjoin(char *s1, char *s2, int n)
{
	char	*line;
	int		i;
	int		j;

	n += ft_strlen(s1);
	if (!s2 || n == 0)
		return (NULL);
	if (!s1)
	{
		s1 = ft_calloc(1, sizeof(char));
	}
	if (!s1)
		return (NULL);
	line = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!line)
		return (ft_free(&s1), NULL);
	i = -1;
	j = -1;
	while (s1[++i] && i < n)
		line[i] = s1[i];
	while (s2[++j] && (i + j) < n)
		line[i + j] = s2[j];
	return (ft_free(&s1), line);
}

int	ft_find_end_line(char *line)
{
	int	i;

	i = 0;
	if (!line || line == NULL)
	{
		return (0);
	}
	while (line[i])
	{
		if (line[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*ft_read(int fd, char *remain)
{
	char	*read_line;
	int		read_chars;

	read_line = ft_calloc(2, sizeof(char));
	if (!read_line)
		return (0);
	read_chars = 1;
	while (read_chars > 0 && ft_find_end_line(read_line) == 0)
	{
		read_chars = read(fd, read_line, read_chars);
		if (read_chars > 0)
			remain = ft_strnjoin(remain, read_line, read_chars);
		if (!remain)
			return (ft_free(&read_line), NULL);
	}
	if (read_chars == -1)
		return (ft_free(&remain), ft_free(&read_line), NULL);
	return (ft_free(&read_line), remain);
}

int	get_order(int fd, t_node **head_a, t_node **head_b, t_bool *valid)
{
	char	*remain;

	remain = NULL;
	remain = ft_read(fd, remain);
	if (!remain)
		return (-1);
	if (execute_order(remain, head_a, head_b) == -1)
	{
		*valid = false;
		return (ft_free(&remain), -1);
	}
	return (ft_free(&remain), 0);
}
