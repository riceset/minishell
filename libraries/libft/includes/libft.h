/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 04:20:12 by tkomeno           #+#    #+#             */
/*   Updated: 2022/12/12 22:34:45 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_bool
{
	FALSE,
	TRUE
}					t_bool;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
size_t				ft_strlen(const char *s);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *b, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t cpysize);
size_t				ft_strlcat(char *dst, const char *src, size_t f_dst_s);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *v1, const void *v2, size_t n);
char				*ft_strnstr(const char *str, const char *substr,
						size_t len);
int					ft_atoi(const char *str);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *s1);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
void				ft_putchar(char c);
void				ft_putstr(char *s);
void				ft_putnbr(int n);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strncpy(char *dest, char *src, unsigned int n);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strcat(char *dest, char *src);
char				*ft_strncat(char *dest, char *src, unsigned int nb);
char				*ft_strstr(char *str, char *to_find);
void				ft_putnbr_base(int nbr, char *base);
int					ft_atoi_base(char *str, char *base);
int					*ft_range(int min, int max);
char				*ft_strjoin2(int size, char **strs, char *sep);
void				ft_matrixfree(char **matrix);

#endif
