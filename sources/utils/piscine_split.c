/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piscine_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 09:30:48 by tkomeno           #+#    #+#             */
/*   Updated: 2022/12/01 19:44:49 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_issep(char check, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (check == charset[i])
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int	ft_count(char *str, char *charset)
{
	int	c;
	int	i;

	i = 0;
	c = 0;
	while (str[i])
	{
		while (str[i] && ft_issep(str[i], charset))
			i++;
		if (str[i])
			c++;
		while (str[i] && !ft_issep(str[i], charset))
			i++;
	}
	return (c);
}

int	ft_len(char *str, char *charset)
{
	int	len;

	len = 0;
	while (str[len] && !ft_issep(str[len], charset))
		len++;
	return (len);
}

char	*ft_strdup2(char *src, char *charset)
{
	char	*dup;
	int		len;
	int		i;

	len = ft_len(src, charset);
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**ft_split_by_set(char *str, char *charset)
{
	char	**strs;
	int		len;
	int		i;
	int		j;

	len = ft_count(str, charset);
	strs = malloc(sizeof(char *) * (len + 1));
	if (!strs)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && ft_issep(str[i], charset))
			i++;
		if (str[i])
		{
			strs[j] = ft_strdup2(&str[i], charset);
			j++;
		}
		while (str[i] && !ft_issep(str[i], charset))
			i++;
	}
	strs[j] = NULL;
	return (strs);
}
