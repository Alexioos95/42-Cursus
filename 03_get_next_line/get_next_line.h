/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:40:44 by apayen            #+#    #+#             */
/*   Updated: 2022/12/12 10:18:38 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		ft_checknl(char *str);
char	*ft_checkread(int fd, char *buffer, char *line, int *b);
void	ft_cleanbuffer(char *buffer);
char	*ft_strjoin(char *s1, char *s2, int b, char *buffer);
char	*ft_substr(char *s, int start, int len);
void	ft_strcpy(char *dst, char *src);
int		ft_strlen(char *s);

#endif
