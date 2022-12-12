/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:40:58 by tkomeno           #+#    #+#             */
/*   Updated: 2022/12/12 17:43:46 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_var g_var;

int main(int argc, char **argv, char **envp)
{
	if (argc > 1 || !argv[0])
		return (1);
	prepare_env_lst(envp);
	get_paths();
	free_env_lst();
	while (TRUE)
	{
		read_line();
	}
	return (0);
}
