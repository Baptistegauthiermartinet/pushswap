/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:07:53 by bgauthie          #+#    #+#             */
/*   Updated: 2023/05/26 13:48:23 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_list
{
	char			location;
	int				nbr;
	int				index;
	struct s_list	*next;
	struct s_list	*previous;
}	t_list;

/*Fonctions Libft*/
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);

/*Fonctions ft_printf*/
void	ft_putnbr_base_fd(long long nbr, char *base, int *printed, int fd);
void	ft_putptr_fd(void *ptr, char *base, int *printed, int fd);
void	ft_putchar_fd_pf(char c, int *printed, int fd);
void	ft_putstr_fd_pf(char *s, int *printed, int fd);
int		ft_printf(const char *str, ...);
void	get_type(const char *str, va_list a, size_t *i, int *printed);

/*Fonctins push_swap*/
t_list	*ft_lstnew_push_swap(int content);
int		ft_lstsize_push_swap(t_list *lst);

int		check_errors(int argc, char **argv, t_list **a);

t_list	*create_stack_a(char **argv);
void	add_prev_ptr(t_list *lst);

void	print_stacks(t_list *a, t_list *b);		/*a retirer*/
void	print_stack(t_list *lst);		/*/*a retirer*/

void	rotate_stack(t_list **stack);
void	rev_rotate_stack(t_list **stack);
void	rotate_both(t_list **stack_a, t_list **stack_b);
void	rev_rotate_both(t_list **stack_a, t_list **stack_b);

void	push_stack(t_list **stack_to, t_list **stack_from);
int		nbr_comp(char *nbr, char *argument, int n);

void	swap_stack(t_list **stack, int n);
void	swap_both(t_list **stack_a, t_list **stack_b);

int		is_sorted(t_list *stack);

void	set_index(t_list *stack);

int		is_idx_max(t_list *stack);

void	sort_short(t_list **stack_a, t_list **stack_b, int len);
void	sort_two(t_list **stack);
void	sort_three(t_list **stack);
void	sort_four(t_list **stack_a, t_list **stack_b);
void	sort_five(t_list **stack_a, t_list **stack_b);

void	sort_long(t_list **stack_a, t_list **stack_b);
void	sort(t_list **stack_a, t_list **stack_b);

int		check_two_top(t_list **stack);
int		check_neighbours(t_list **stack);
int		get_idx_min(t_list **stack);
int		get_idx_max(t_list **stack);
int		get_median(int max, int min);

void	free_stack(t_list *stack);

#endif