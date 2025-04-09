/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:36:20 by athekkan          #+#    #+#             */
/*   Updated: 2025/03/24 17:52:40 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

// Free a 
void	free_split(char **split)
{
	int	i;

	if (split == NULL)
		return ;
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

// Splits `str` into an array of strings using `c` as a delimiter
char	**ft_split(char const *str, char c)
{
	char	*start;
	int		k;
	char	**array;

	array = ft_calloc(ft_count_word(str, c) + 1, sizeof(char *));
	if (array == NULL)
		return (NULL);
	k = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		start = (char *)str;
		while (*str && *str != c)
			str++;
		if (str > start)
		{
			array[k] = ft_substr(start, 0, str - start);
			if (array[k++] == NULL)
				return (free_split(array), NULL);
		}
	}
	return (array[k] = NULL, array);
}
