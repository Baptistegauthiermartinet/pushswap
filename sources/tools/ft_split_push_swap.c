/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_push_swap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:10:34 by bgauthie          #+#    #+#             */
/*   Updated: 2023/06/16 10:11:34 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static size_t	ft_count_word(char const *str, char sep)
{
	size_t	i;
	int		count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] != sep && str[i])
			i++;
		while (str[i] == sep && str[i])
			i++;
		count++;
	}
	return (count);
}

static char	*ft_get_next_word(const char **str, char sep)
{
	size_t	i;
	char	*word;

	i = 0;
	while ((*str)[i] && (*str)[i] != sep)
		i++;
	word = ft_substr(*str, 0, i);
	if (!word)
		return (NULL);
	while ((*str)[i] && (*str)[i] == sep)
		i++;
	*str += i;
	return (word);
}

static char	**ft_fill_tab(char **tab, const char *str, char sep, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		tab[i] = ft_get_next_word(&str, sep);
		if (!tab[i])
		{
			i--;
			while (i != 0)
				free(tab[i--]);
			free(tab);
			return (NULL);
		}
		i++;
	}
	tab[count] = NULL;
	return (tab);
}

static void	ft_trim_left(const char **str, char sep)
{
	while (**str && **str == sep)
		(*str)++;
}

char	**ft_split_push_swap(char const *str, char sep)
{
	char	**tab;
	size_t	count;

	if (str[0] == '\0' || is_str_valid(str) == 0 || full_sep(str, sep) == 0)
		return (NULL);
	ft_trim_left(&str, sep);
	count = ft_count_word(str, sep);
	tab = malloc(sizeof(str) * count + sizeof(str));
	if (!tab)
		return (NULL);
	tab = ft_fill_tab(tab, str, sep, count);
	if (!tab)
		return (NULL);
	return (tab);
}
