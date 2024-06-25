/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:14:02 by ymunoz-m          #+#    #+#             */
/*   Updated: 2024/06/25 21:08:09 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Once split_string found a new word it sends the character where is starts
 * and how long that word is. Then, it returns it as a new word which will be
 * the one saved in the dst array.
*/
char	*write_word(char const *s, int len)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (0);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}

/**
 * A function to count how many words divided by c we find inside an
 * array of strings.
*/
int	count_words(char **s, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	count;

	i = 0;
	count = 0;
	while (s[++i])
	{
		j = 0;
		while (s[i][j])
		{
			while (s[i][j] == c && s[i][j])
				j++;
			while (s[i][j] != c && s[i][j])
				j++;
			if (s[i][j - 1] != c)
				count++;
		}
	}
	return (count);
}

/**
 * ft_split sends here every position of the string array, and here we split
 * each of these strings and save each resulting word inside dst.
*/
void	**split_str(char *src, char **dst, char c, int length)
{
	static int	i;
	int			j;

	j = 0;
	while (src[j])
	{
		length = 0;
		while (src[j] && src[j] == c)
			j++;
		while (src[j] && src[j] != c)
		{
			length++;
			j++;
		}
		if (src[j - 1] != c)
			dst[i] = write_word(&src[j - (length)], length);
		else
			return (NULL);
		if (!dst[i])
			return (free_memory(dst), NULL);
		i++;
	}
	return (NULL);
}

/**
 * An adapted version of the libft split to accept a string array instead of
 * a string. It receives a string array and returns another string array,
 * each string being separated by the c character.
*/
char	**ft_split(char **s, char c)
{
	int				i;
	int				n;
	char			**str;

	i = 0;
	n = count_words(s, c);
	str = ft_calloc(n + 1, sizeof(char *));
	if (str == NULL)
		return (NULL);
	while (s[++i])
	{
		split_str(s[i], str, c, 0);
	}
	str[n] = '\0';
	return (str);
}
