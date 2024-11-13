/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:45:57 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/09/04 13:59:56 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

// Definition: Counts the number of words within a string,
// separated by a specific character
static int	word_counter(char *str, char sep)
{
	int	words;
	int	separator;

	words = 0;
	separator = 0;
	while (*str)
	{
		if (*str != sep && separator == 0)
		{
			separator = 1;
			words++;
		}
		else if (*str == sep)
			separator = 0;
		str++;
	}
	return (words);
}

// Definition: This function will allocate the
// required ammount of memory for each word,
// and return a string with the word
static char	*next_word(char *str, char sep)
{
	static int	loc = 0;
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[loc] == sep)
		loc++;
	while ((str[loc + len] != sep) && str[loc + len])
		len++;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while ((str[loc] != sep) && str[loc])
		next_word[i++] = str[loc++];
	next_word[i] = '\0';
	return (next_word);
}

// Definition: This function will effectively
//split the string into multiple strings
char	**ft_split(char *str, char sep)
{
	int		i;
	int		word_count;
	char	**result;

	i = 0;
	word_count = word_counter(str, sep);
	if (!word_count)
		exit(1);
	result = malloc((size_t)(word_count + 2) * sizeof(char *));
	if (!result)
		return (NULL);
	while (word_count-- >= 0)
	{
		if (i == 0)
		{
			result[i] = malloc(sizeof(char));
			if (!result[i])
				return (NULL);
			result[i++][0] = '\0';
			continue ;
		}
		result[i++] = next_word(str, sep);
	}
	result[i] = NULL;
	return (result);
}
