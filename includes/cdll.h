/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdll.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:08:31 by tkomeno           #+#    #+#             */
/*   Updated: 2022/11/29 18:34:29 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CDLL_H
# define CDLL_H

# include "libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

struct					s_env
{
	char				*key;
	char				*value;
	bool				is_sentinel;
	struct s_env		*next;
	struct s_env		*prev;
};

typedef struct s_env	t_env;

t_env					*env_cdll_lstnew(char *key, char *value);
void					env_cdll_lstadd_first(t_env **head, t_env *new);
void					env_cdll_lstadd_front(t_env **head, t_env *new);
void					env_cdll_lstadd_back(t_env **head, t_env *new);
t_env					*env_cdll_lstinit(void);
void					env_cdll_lstclear(t_env **head);

#endif
