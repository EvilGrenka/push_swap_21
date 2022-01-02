/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 14:21:30 by rnoriko           #+#    #+#             */
/*   Updated: 2021/10/20 16:57:43 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordlen(const char *str, char c)
{
	int	len;

	len = 0;
	while (*str != c && *str)
	{
		len++;
		str++;
	}
	return (len);
}

static int	get_count_words(const char *str, char c)
{
	int	count_words;

	count_words = 0;
	while (*str == c && *str)
		++str;
	while (*str)
	{
		++count_words;
		while (*str != c && *str)
			++str;
		while (*str == c && *str)
			++str;
	}
	return (count_words);
}

static char	*word_dupe(const char *str, char c)
{
	int		i;
	int		len;
	char	*word;

	i = 0;
	len = wordlen(str, c);
	word = (char *) malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	word[len] = '\0';
	while (i < len)
	{
		word[i] = str[i];
		++i;
	}
	return (word);
}

static void	fill_words(char **array, const char *str, char c)
{
	int	word_index;

	word_index = 0;
	while (*str == c && *str)
		++str;
	while (*str != '\0')
	{
		array[word_index] = word_dupe(str, c);
		if (!array[word_index] && array[0])
		{
			while (word_index > -1)
			{
				free(array[word_index]);
				array[word_index] = NULL;
				word_index--;
			}
			return ;
		}
		++word_index;
		while (*str != c && *str)
			++str;
		while (*str == c && *str)
			++str;
	}
}

char	**ft_split(char const *s, char c)
{
	int		count_words;
	char	**array;

	if (!s)
		return (NULL);
	count_words = get_count_words(s, c);
	array = (char **)malloc(sizeof(char *) * (count_words + 1));
	if (!array)
		return (NULL);
	array[count_words] = NULL;
	fill_words(array, s, c);
	return (array);
}
