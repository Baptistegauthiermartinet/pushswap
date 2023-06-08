/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:07:53 by bgauthie          #+#    #+#             */
/*   Updated: 2023/06/08 16:16:35 by bgauthie         ###   ########.fr       */
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
char	**ft_split(char const *str, char sep);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);

/*Fonctions ft_printf*/
void	ft_putnbr_base_fd(long long nbr, char *base, int *printed, int fd);
void	ft_putptr_fd(void *ptr, char *base, int *printed, int fd);
void	ft_putchar_fd_pf(char c, int *printed, int fd);
void	ft_putstr_fd_pf(char *s, int *printed, int fd);
int		ft_printf(const char *str, ...);
void	get_type(const char *str, va_list a, size_t *i, int *printed);

/*Fonctins push_swap*/
t_list	*ft_lstnew_push_swap(int content);

int		print_error(void);
int		is_str_valid(const char *str);
int		check_errors(int argc, char **argv, t_list **a);
int		is_str_int(const char *str);

t_list	*create_stack_a(char **argv);
t_list	*create_stack_from_tab(char **argv);
void	add_prev_ptr(t_list *lst);

void	rotate_stack(t_list **stack);
void	rev_rotate_stack(t_list **stack);
void	rotate_both(t_list **stack_a, t_list **stack_b);
void	rev_rotate_both(t_list **stack_a, t_list **stack_b);
void	push_stack(t_list **stack_to, t_list **stack_from);
void	swap_stack(t_list **stack, int n);
void	swap_both(t_list **stack_a, t_list **stack_b);

int		nbr_comp(char *nbr, char *argument, int n);
int		is_sorted(t_list *stack);
int		get_len_tab(char **tab);
int		ft_lstsize_push_swap(t_list *lst);
int		full_sep(const char *str, char sep);
int		choose_segment(t_list **stack);

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
void	empty_sort(t_list **stack_a, t_list **stack_b);
void	go_next(t_list **stack, int cpt);

void	free_stack(t_list *stack);
void	free_tab(char **tab);

#endif