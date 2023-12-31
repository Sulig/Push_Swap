/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:27:16 by sadoming          #+#    #+#             */
/*   Updated: 2023/12/05 12:17:30 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

void	ft_bzero(void *s, size_t n);
void	*ft_free_str(char *str);
void	*ft_auto_free_arr(char **arr);
void	ft_auto_free_all(char ***arr);
void	*ft_free_arr(size_t size, char **words);
void	*ft_calloc(size_t count, size_t size);

int		ft_putchar(char ch);
int		ft_putnbr(int nbr);
int		ft_putstr(char *str);
int		ft_putunsig(size_t nbr, char cast);
int		ft_printf(char const *str, ...);

size_t	ft_arr_strlen(char **s);
size_t	ft_strlen(const char *s);
size_t	ft_strllen(const char *s);
size_t	ft_cnttoch_in(const char *str, char c);
size_t	ft_cnttoch_out(const char *str, char c);
size_t	ft_numlen(size_t n, int base);

int		ft_is_prime(size_t num);

int		ft_atoi(const char *str);
long	ft_atol(const char *str);
size_t	ft_atos(const char *str);
char	*ft_itoa(int n);
char	*ft_itoa_unsig(size_t n, char *base);
char	*ft_unsig_tobase(size_t num, char base);

int		my_strcmp(const char *str, const char *cmp);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *haystack, const char *needle);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

char	*ft_strcut(char *str, char cut, char mode, char inc);
char	*ft_strdup(const char *s1);
char	*ft_strcpyl(const char *s1, size_t len);
char	*ft_strinter(const char *str, const char *inter, size_t pos);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strjoin_s(const char *s1, const char *s2);
char	*ft_strjoin_free_first(char *s1, const char *s2);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_substr(const char*s, unsigned int start, size_t len);

char	**ft_strarrdup(char **to_copy);
char	**ft_split(const char *s, char c);

char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *haystack, const char *needle);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

char	*get_next_line(int fd);

#endif
