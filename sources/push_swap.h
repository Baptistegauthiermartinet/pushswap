/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:07:53 by bgauthie          #+#    #+#             */
/*   Updated: 2023/05/02 12:11:42 by bgauthie         ###   ########.fr       */
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

void	print_stacks(t_list *a, t_list *b);
void	print_stack(t_list *lst);

void	rotate_stack(t_list **stack);
void	rev_rotate_stack(t_list **stack);
void	rotate_both(t_list **stack_a, t_list **stack_b);
void	rev_rotate_both(t_list **stack_a, t_list **stack_b);

void	push_stack(t_list **stack_to, t_list **stack_from);
int		nbr_comp(char *nbr, char *argument, int n);

void    swap_stack(t_list **stack, int n);
void	swap_both(t_list **stack_a, t_list **stack_b);

int is_sorted(t_list *stack);




#endif