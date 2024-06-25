/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:20:36 by anfi              #+#    #+#             */
/*   Updated: 2024/06/25 21:10:02 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

/*		push_swap.c				*/
	//Where the main is. Calls to the functions:
	// 1. to check the arguments.
	// 2. to create stack_a and check if its ordered.
	// 3. to choose how to proceed with the ordering based on argc.
	//And finally frees the memory designated to all the nodes.

void	create_stack_a(t_node **head, char **argv, t_bool *valid);
int		main(int argc, char **argv);

/*		validate_argvs		*/
int		validate_argvs(char **argv);
int		validate_argv(char *argv);

/*		utils.c			*/
	//functions to allocate and free memory.

void	*ft_calloc(size_t nitems, size_t size);
void	free_memory(char **str);
void	free_all(t_node **head, char **argv);
int		ft_isdigit(char *c);

/*		ft_split.c		*/
	//The split (and ft_calloc) from the libft adapted for this program.
	//We clean the data received as argv to have always the same format.

char	**ft_split(char **s, char c);
void	**split_str(char *src, char **dst, char c, int length);
int		count_words(char **s, char c);
char	*write_word(char const *s, int len);

/*		check_arguments.c		*/
	//Data validation functions. Where we to check if the arguments are correct.

int		check_one_argument(const char *s);
long	ft_atoi(const char *s, t_bool *valid);
int		ft_is_ordered(t_node *head);
void	ft_is_repeated(t_node **head, t_bool *valid);

/*		choose_method.c			*/
	//We check if we receive only 2 or 3 arguments and we order them.
	//Any other case will activate the turk algorithm.

void	order_list(t_node **head_a, t_node **head_b);
void	ft_order_three(t_node **head);
void	ft_order_two(t_node **head);

/*		turk_algorithm.c		*/
	//Where we implement the algorithm.
	//We pair each node of the main stack (the one we're going to push from)
	// with the correct target node.
	//Then we check the cost of the movement of each node and move the
	// cheapest one.
	//Lastly, a function that calls ra() or rra() until the min int is on top.

void	turk_algorithm(t_node **head_a, t_node **head_b);
void	ft_order_min_int(t_node **head);

/*		get_best_target.c*/
	//It pairs each node of the main stack with its target, checks the push_cost
	// of each of this nodes and returns the cheapest one.

void	smallest_target(t_node *one, t_node *two);
void	biggest_target(t_node *one, t_node *two);
t_node	*pair_nodes(t_node *node_one, t_node *node_two);

/*		get_cost.c		*/
	//Functions to get the cost of the movement of sent node and it's target.

int		return_cost(int index, int total);
void	decrease_cost(int *cost_a, int *cost_b, int *total_cost);
void	increase_cost(int *cost_a, int *cost_b, int *total_cost);
int		get_cost(t_node *current_node);

/*		mode_nodes_to_head.c	*/
	//We move both nodes involved in the cheapest movement into
	// the head of each stack. We first check in case we can
	// use rr or rrr, and then we rotate each stack if needed.

void	move_node(t_node **head, int index, int median);
void	move_nodes_to_head(t_node **head_main, t_node **head_target,
			int main_index, int target_index);

/*		rotate_nodes.c		*/
	//functions to rotate the nodes, either one or both stacks.

void	ra(t_node **head);
void	rra(t_node **head);
void	rrr(t_node **head_one, t_node **head_two, int *index_one,
			int *index_two);
void	rr(t_node **head_one, t_node **head_two, int *index_one,
			int *index_two);

/*		swap_push_nodes		*/
	// Functions to push the nodes and swap them 
	//(sa() will only be used to order three nodes in stack_a).

void	sa(t_node **head, int i);
void	pb(t_node **head_one, t_node **head_two);
void	pb_last_node(t_node **head_b, t_node **head_a);
void	pb_empty_stack(t_node **head_a, t_node **head_b);

/*		update_index.c		*/
	//Functions to update the index of each node
	//and the tail they point at whenever needed.

void	update_index(t_node	**head);
void	update_tail(t_node **current_node);

/*		list_functions.c		*/
	//Funtions related to the libft's bonus functions to work with lists.

int		ft_lstsize(t_node *lst);
t_node	*ft_new_node(int value, int index);
void	add_back(t_node **head, int value, int index);
void	ft_free_list(t_node **current_t_node);

#endif