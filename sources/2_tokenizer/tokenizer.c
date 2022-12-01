/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:58:48 by tkomeno           #+#    #+#             */
/*   Updated: 2022/12/01 19:45:58 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define METACHARACTERS "|$><'\""

char	**tokenizer(char *line)
{
	char		**tokens;

	tokens = ft_split_by_set(line, METACHARACTERS);
	return (tokens);
}
