/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:07:23 by tkomeno           #+#    #+#             */
/*   Updated: 2022/12/01 19:07:39 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_three(char *s1, char *s2, char *s3)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strjoin(s1, s2);
	tmp2 = ft_strjoin(tmp, s3);
	free(tmp);
	return (tmp2);
}

