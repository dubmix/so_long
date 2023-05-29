/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 17:10:35 by pdelanno          #+#    #+#             */
/*   Updated: 2023/05/25 08:02:24 by pdelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

unsigned int	ft_strlcpy(char *dest, const char *src, size_t size)

{
	unsigned int	i;

	i = 0;
	if (dest == 0 || src == 0)
		return (0);
	while (src[i] != '\0')
		i++;
	if (size == 0)
		return (i);
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

int	nb_of_strs(char const *s, char c)
{
	int	i;
	int	nbstr;

	i = 0;
	nbstr = 0;
	if (s[0] == 0)
		return (0);
	while (s[i] != '\0' && s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			nbstr++;
			while (s[i] != '\0' && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		nbstr++;
	return (nbstr);
}

void	get_next_str(char **next_str, size_t *next_strlen, char c)
{
	size_t	i;

	*next_str = *next_str + *next_strlen;
	*next_strlen = 0;
	i = 0;
	while (**next_str != '\0' && **next_str == c)
		(*next_str)++;
	while ((*next_str)[i] != '\0')
	{
		if ((*next_str)[i] == c)
			return ;
		(*next_strlen)++;
		i++;
	}
}

char	**ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	char	*next_str;
	size_t	next_strlen;
	int		i;

	i = 0;
	if (s == 0)
		return (NULL);
	tab = malloc(sizeof(char *) * (nb_of_strs(s, c) + 1));
	if (tab == 0)
		return (NULL);
	next_str = (char *)s;
	next_strlen = 0;
	while (i < nb_of_strs(s, c))
	{
		get_next_str(&next_str, &next_strlen, c);
		tab[i] = (char *)malloc(sizeof(char) * (next_strlen + 1));
		if (tab[i] == 0)
			return (ft_free(tab));
		ft_strlcpy(tab[i], next_str, next_strlen + 1);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
