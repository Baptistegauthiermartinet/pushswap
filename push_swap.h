/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:07:53 by bgauthie          #+#    #+#             */
/*   Updated: 2023/01/30 14:48:13 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	int				nbr;
	struct s_list	*next;
	struct s_list	*previous;	
}	t_list;

// typedef struct s_push_swap
// {
// 	t_list stack_a;
// 	t_list stack_b;
// 	t_insn_list insn_list;
// }

/*Fonctions Libft*/
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *str, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*Fonctions GNL*/
size_t	ft_strlen_nocrash(const char *s);
size_t	ft_strchr_nl(const char *s, int c);
char	*ft_substr_gnl(char const *s, unsigned int start, size_t len);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*get_next_line(int fd);
char	*join_and_free(char	*s1, char	*s2);
char	*join_buffer(int fd, char *str);
char	*cut_temp(char	*str);
char	*stock_supp(char *str);

/*Fonctions ft_printf*/
void	ft_putnbr_base_fd(long long nbr, char *base, int *printed, int fd);
void	ft_putptr_fd(void *ptr, char *base, int *printed, int fd);
void	ft_putchar_fd_pf(char c, int *printed, int fd);
void	ft_putstr_fd_pf(char *s, int *printed, int fd);
int		ft_printf(const char *str, ...);
void	get_type(const char *str, va_list a, size_t *i, int *printed);

/*Fonctins push_swp*/
t_list	*ft_lstnew_push_swap(int content);

int		print_error(void);
int		check_errors(int argc, char **argv, t_list **a);
int		is_str_int(char *str);
int		ft_is_int(int argc, char **argv);
int		check_duplicates(t_list	*a);

t_list	*create_stack_a(char **argv);
void	add_prev_ptr(t_list *lst);

void	print_stacks(t_list *a, t_list *b);
void	print_stack(t_list *lst);


void	remove_one_node(t_list *lst);

#endif