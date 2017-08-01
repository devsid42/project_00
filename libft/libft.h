/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:56:26 by avasseur          #+#    #+#             */
/*   Updated: 2017/03/10 12:54:21 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define BUF_SIZE	2
# define FTPC ft_putchar
# define FTPS ft_putstr
# define FTPSD ft_putstr_d
# define FTPN ft_putnbr
# define CR ft_putchar('\n');
# define YA ft_putstr("YA");
# define PI ft_putstr("[");
# define PO ft_putstr("]");
# define RED		"\e[1;31m"
# define GREEN		"\e[1;32m"
# define YELLOW		"\e[1;33m"
# define BLUE		"\e[1;34m"
# define MAGENTA	"\e[1;35m"
# define CYAN		"\e[1;36m"
# define WHITE		"\e[1;37m"
# define RESET		"\e[1;0m"
# define PRED		FTPS(RED);
# define PRES		FTPS(RESET);
# define PSY(S) FTPS(YELLOW); FTPS(S); FTPS(RESET);
# define PSR(S) FTPS(RED); FTPS(S); FTPS(RESET);
# define PSG(S) FTPS(GREEN); FTPS(S); FTPS(RESET);
# define PSC(S) FTPS(CYAN); FTPS(S); FTPS(RESET);
# define GC ft_getchar("--\n");

typedef struct			s_list
{
	struct s_list		*next;
	struct s_list		*prev;
	void				*content;
	size_t				content_size;
	int					x;
}						t_list;

typedef unsigned int	t_uint;
typedef unsigned long	t_ulong;
typedef long long		t_ll;
typedef const char		t_cchar;
typedef unsigned char	t_uchar;

void					*ft_memset(void *b, int c, size_t len);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memccpy(void *d, const void *s, int c, size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
size_t					ft_strlen(const char *s);
size_t					ft_strnlen(const char *s, size_t maxlen);
char					*ft_strdup(const char *s1);
char					*ft_strndup(const char *s1, size_t n);
char					*ft_strcpy(char *dst, const char *src);
char					*ft_strncpy(char *dst, const char *src, size_t n);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strncat(char *s1, const char *s2, size_t n);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strstr(const char *s1, const char *s2);
char					*ft_strnstr(const char *s1, const char *s2, size_t n);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_strnccmp(const char *s1, const char *s2, size_t n);
int						ft_atoi(const char *str);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isnumber(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_ispaging(int c);
int						ft_isoper(int c);
int						ft_issign(int c);
int						ft_toupper(int c);
int						ft_tolower(int c);

void					*ft_memalloc(size_t size);
void					**ft_memalloc_multi(size_t h_size, size_t v_size);
void					ft_memdel(void **ap);
char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strmap(const char *s, char (*f)(char));
char					*ft_strmapi(const char *s, char (*f)(t_uint, char));
int						ft_strequ(const char *s1, const char *s2);
int						ft_strnequ(const char *s1, const char *s2, size_t n);
char					*ft_strsub(const char *s, t_uint start, size_t len);
char					*ft_strjoin(const char *s1, const char *s);
char					*ft_strtrim(const char *s);
char					*ft_strctrim(const char *s, char c);
char					**ft_strsplit(const char *s, char c);
char					**ft_split(char *s, char *spliter);
char					*ft_itoa(int n);
void					ft_putchar(char c);
void					ft_putstr(const char *s);
void					ft_putarray(char **ap, const char *separator);
void					ft_putendl(const char *s);
void					ft_putnbr(int n);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(const char *s, int fd);
void					ft_putendl_fd(const char *s, int fd);
void					ft_putnbr_fd(int n, int fd);
size_t					ft_intlen(int n);
t_ulong					ft_power(t_ulong n, t_ulong nn);
size_t					ft_strocc(const char *s, char c);
t_list					*ft_lstnew(const void *content, size_t content_size);
void					ft_lstdelone(t_list **al, void (*del)(void *, size_t));
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstadd(t_list **alst, t_list *newlst);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void					ft_putmem(char *s, size_t n);
char					*ft_strrev(const char *s);
void					ft_putlowhex(int n);
void					ft_putuphex(int n);
size_t					ft_arraylen(char **ap);
int						ft_ispair(int n);
char					*ft_strcjoin(t_cchar *s1, t_cchar *s, t_cchar c);
void					ft_putstr_d(const char *s);
size_t					ft_strlen_d(const char *s);
void					ft_putnstr(const char *s, size_t n);
t_ll					ft_decimaltobase(t_ll n, t_uint base);
char					*ft_ctos(char c);
char					*ft_itoahex(unsigned long n, char lower_upper);
char					ft_itochex(int n, char lower_upper);
void					ft_putlnbr(long n);
char					*ft_ltoa(long n);
size_t					ft_longlen(long n);
char					*ft_strcutdup(const char *s, size_t cutlen);
void					ft_putistr(int *s, char spacer);
void					ft_swapc(char *c1, char *c2);
void					ft_swapi(int *c1, int *c2);
void					ft_swap_ptr(char **p1, char **p2);
char					*ft_epurstr(char *s);
char					**ft_epurarray(char **a);
void					ft_freearray(char **array);
char					**ft_sort_array(char **a);
char					*ft_strtoupper(char *s, size_t limit);
char					*ft_strtolower(char *s, size_t limit);
char					*ft_replace_noprint(char *s);

int						get_next_line(const int fd, char **line);
int						ft_printf(int fd, char *format, ...);
char					ft_getchar(const char *msg);
#endif
