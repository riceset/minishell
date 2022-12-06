/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:58:48 by tkomeno           #+#    #+#             */
/*   Updated: 2022/12/06 19:46:36 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

char	*ft_strjoin_char(char *s1, char c)
{
	char	*joined;
	size_t	joined_size;
	size_t  s1_len;

	if (s1 && c)
	{
		s1_len = ft_strlen(s1);
		joined_size = (s1_len + 2) * sizeof(char);
		joined = malloc(joined_size);
		if (joined)
		{
			ft_strlcpy(joined, s1, s1_len + 1);
			joined[s1_len] = c;
			joined[s1_len + 1] = '\0';
			return (joined);
		}
	}
	return (NULL);
}

char	**tokenizer(char *line)
{
	char **tokens;

	while (i)
	{
	}
	return (tokens);
}
