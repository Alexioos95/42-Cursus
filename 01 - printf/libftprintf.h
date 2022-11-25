/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:11:59 by apayen            #+#    #+#             */
/*   Updated: 2022/11/24 16:44:19 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_isformat(char c);
int	ft_format(va_list args, char c);
int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_strlen(char *str);
int	ft_putnbr(int nb);
int	ft_putnbrui(unsigned int nb);
int	ft_hexa(unsigned int nb, char c);
int	ft_ptr(unsigned long int nb, char c);

#endif
