/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:14:02 by ymunoz-m          #+#    #+#             */
/*   Updated: 2024/06/25 15:42:12 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# define MAX_INT 2147483647
# define MIN_INT -2147483648

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum t_boolean
{
	false = 0,
	true = 1
}		t_bool;

typedef struct node
{
	int			value;
	int			index;
	int			push_cost;
	char		stack;
	struct node	*next;
	struct node	*prev;
	struct node	*target;
	struct node	*tail;
}				t_node;

/*		checker.c				*/
	//Where the main is. Calls to the functions:
	// 1. to check the arguments.
	// 2. to create stack_a and check if its ordered.
	// 3. to start ordenating the stack based on user's input.
	//And finally frees the memory designated to all the nodes.

void	create_stack_a(t_node **head, char **argv, t_bool *valid);
int		main(int argc, char **argv);

/*		utils.c			*/
	//functions to allocate and free memory.

void	free_all(t_node **head, char **argv);
void	*ft_calloc(size_t nitems, size_t size);
void	free_memory(char **str);
int		ft_isdigit(char *c);

/*		ft_split.c		*/
	//The split (and ft_calloc) from the libft adapted for this program.
	//We clean the data received as argv to have always the same format.

char	**ft_split(char **s, char c);
void	**split_str(char *src, char **dst, char c, int length);
int		count_words(char **s, char c);
char	*write_word(char const *s, int len);

/*		check_arguments.c		*/
	//Functions to check if the arguments are correct.

int		check_one_argument(const char *s);
long	ft_atoi(const char *s, t_bool *valid);
int		ft_is_ordered(t_node *head);
void	ft_is_repeated(t_node **head, t_bool *valid);

/*		check_orders.c		*/
	//This is a simpler version of gnl.
	//We receive the orders from the stdin using read.
	//We will read char by char until we find the end of line with the order.
	//Once we got the order, we compare it using strcmp and when
	// we find a coincidence, we execute that order.
int		get_order(int fd, t_node **head_a, t_node **head_b, t_bool *valid);
char	*ft_read(int fd, char *remain);
int		ft_find_end_line(char *line);
char	*ft_strnjoin(char *s1, char *s2, int n);
int		execute_order(char *order, t_node **head_a, t_node **head_b);

/*		gnl_utils.c		*/
	//Functions that are needed for this simpler version of gnl to work
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strlen(const char *string);
void	ft_free(char **str);

/*		list_functions.c		*/
	//Funtions related to the libft's bonus functions to work with lists.
int		ft_lstsize(t_node *lst);
t_node	*ft_new_node(int value, int index);
void	add_back(t_node **head, int value, int index);
void	ft_free_list(t_node **current_t_node);

/*		rotate_nodes.c		*/
	//functions to rotate the nodes, either one or both stacks.
void	ra(t_node **head);
void	rra(t_node **head);
void	rrr(t_node **head_one, t_node **head_two);
void	rr(t_node **head_one, t_node **head_two);

/*		swap_push_nodes.c		*/
	// Functions to push the nodes and swap them 
	//(sa() will only be used to order three nodes in stack_a).
void	sa(t_node **head);
void	pb(t_node **head_one, t_node **head_two);
void	pb_last_node(t_node **head_b, t_node **head_a);
void	pb_empty_stack(t_node **head_a, t_node **head_b);

/*		update_index.c		*/
	//Functions to update the index of each node
	//and the tail they point at whenever needed.
void	update_index(t_node	**head);
void	update_tail(t_node **current_node);

#endif