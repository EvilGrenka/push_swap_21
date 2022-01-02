/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:43:22 by rnoriko           #+#    #+#             */
/*   Updated: 2021/12/31 14:31:52 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

size_t		ft_strlen(const char *s);
long long	ft_atoi(const char *str);
int			ft_isdigit(int c);
char		**ft_split(char const *s, char c);
int			ft_strcmp(const char *s1, const char *s2);
void		ft_putendl_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
void		ft_putnbr_fd(int n, int fd);

#endif
