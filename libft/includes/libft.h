/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 10:13:02 by ehelmine          #+#    #+#             */
/*   Updated: 2022/01/19 17:11:58 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 2000
# define MAX_FD 4500
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_putchar(char c);

void				ft_putstr(char const *s);

void				ft_putnbr(long long n);

long				ft_atoi(const char *str);

int					ft_strcmp(const char *str1, const char *str2);

size_t				ft_strlen(const char *str);

char				*ft_strdup(const char *s);

int					ft_strncmp(const char *str1, const char *str2, size_t n);

char				*ft_strcpy(char *dest, const char *src);

void				ft_strclr(char *s);

char				*ft_strncpy(char *dest, const char *src, size_t n);

char				*ft_strcat(char *dest, const char *src);

char				*ft_strncat(char *dest, const char *src, size_t n);

void				ft_putendl(char const *s);

size_t				ft_strlcat(char *dest, const char *src, size_t n);

void				ft_bzero(void *s, size_t n);

char				*ft_strchr(const char *s, int c);

char				*ft_strrchr(const char *s, int c);

int					ft_isalpha(int c);

int					ft_isdigit(int c);

int					ft_tolower(int c);

int					ft_toupper(int c);

char				*ft_strstr(const char *haystack, const char *needle);

char				*ft_strnstr(const char *haystack, const char *needle,
						size_t n);

int					ft_isalnum(int c);

int					ft_isascii(int c);

int					ft_isprint(int c);

void				*ft_memccpy(void *dst, const void *src, int c, size_t n);

void				*ft_memchr(const void *s, int c, size_t n);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

void				*ft_memcpy(void *dst, const void *src, size_t n);

void				*ft_memmove(void *dst, const void *src, size_t len);

void				*ft_memset(void *b, int c, size_t len);

int					ft_strequ(char const *s1, char const *s2);

int					ft_strnequ(char const *s1, char const *s2, size_t n);

void				*ft_memalloc(size_t size);

void				ft_memdel(void **ap);

char				*ft_strnew(size_t size);

void				ft_strdel(char **as);

char				*ft_strtrim(char const *s);

char				*ft_strjoin(char const *s1, char const *s2);

void				ft_striter(char *s, void (*f)(char *));

void				ft_striteri(char *s, void (*f)(unsigned int, char *));

char				**ft_strsplit(char const *s, char c);

char				*ft_strsub(char const *s, unsigned int start, size_t len);

char				*ft_strmap(char const *s, char (*f)(char));

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char				*ft_itoa(long n);

void				ft_putchar_fd(char c, int fd);

void				ft_putstr_fd(char const *s, int fd);

void				ft_putendl_fd(char const *s, int fd);

void				ft_putnbr_fd(int n, int fd);

intmax_t			ft_check_int_len(unsigned long long n);

t_list				*ft_lstnew(void const *content, size_t content_size);

void				ft_lstadd(t_list **alst, t_list *new);

void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));

void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));

void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

int					ft_isspace(int c);

int					ft_isupper(int c);

int					ft_islower(int c);

char				*ft_strndup(const char *s1, size_t n);

int					get_next_line(const int fd, char **line);

int					my_major(int x);

int					my_minor(int x);

void				ft_memdel_two(void **ptr1, void **ptr2);

void				ft_putarr(char **arr);

char				**ft_arrdup(char **arr);

char				**ft_arrnew(size_t rows, size_t first_row_len);

char				*ft_strstr_after(const char *haystack, const char *needle);

char				*ft_strjoin_three(char const *s1, char const *s2,
						char const *s3);

void				free_arr(void ***arr);

int					ft_return_char_index(char *str, char c, char startpoint);

char				*return_string_before_given_char(char *str, char c);

char				*return_string_before_whitespace(char *str);

int					ft_iscntrl(int c);

#endif
