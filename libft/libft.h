/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:22:00 by jrasser           #+#    #+#             */
/*   Updated: 2022/05/29 21:12:57 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# define PTR "0123456789abcdef"
# define BUFFER_SIZE 100

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* LIBFT */

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
size_t			ft_strlen(const char *s);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strnstr(const char *haystack, const char *needle, \
				size_t len);
int				ft_atoi(const char *str);

void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *s1);

char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/* LISTE CHAIN */

void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);

/* PRINTF */

int				ft_printf(const char *str, ...);
unsigned int	ft_printf_char(va_list ptr);
unsigned int	ft_put_char(char c);
char			*ft_put_ptr(unsigned long long int nbr, char *base);
char			*ft_putunbr_base(unsigned int nbr, char *base);
char			*ft_uitoa(unsigned int n);
char			*ft_itoa_printf(int n);
unsigned int	ft_putstr(char *str, char c);
char			*ft_litoa(long int n);
char			*ctos(char c);
char			*ft_sub_char(char c, va_list ptr);
unsigned int	ft_putstrstr(char *str);
unsigned int	ft_putstr_minus_less(char *str, char c);
char			*ft_arg_multi(const char *str, int i);
char			*ft_arg_multi(const char *str, int i);
int				ft_dash_flag(const char *str, int i, va_list ptr, int *z);
int				ft_dot_flag(const char *str, int i, va_list ptr, int *z);
int				ft_zero_flag(const char *str, int i, va_list ptr, int *z);
int				ft_space_flag(const char *str, int i, va_list ptr, int *z);
int				ft_diese_flag(const char *str, int i, va_list ptr, int *z);
int				ft_plus_flag(const char *str, int i, va_list ptr, int *z);

/* GET_NEXT_LINE */

int				ft_read(int fd, char *buffer);
char			*ft_calloc_line(char *buffer, long size);
char			*ft_check_retour(int ret, char *buffer, char *line);
char			*ft_check_buffer_line(char *buffer);
char			*get_next_line(int fd);
char			*ft_strconcat(char *line, char *buffer);
char			*update_buffer(char *buffer);
int				ft_check_buffer_empty(char **buffer, int fd);
int				ft_is_buffer_end_line(char *buffer);

#endif


