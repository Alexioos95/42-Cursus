/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:08:33 by apayen            #+#    #+#             */
/*   Updated: 2023/01/16 09:33:32 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

struct	s_stack
{
	int	*stacka;
	int	lena;
	int	*stackb;
	int	lenb;
	int	error;
};

int		*errorandparse(int argc, char **argv, int len);
int		*parsing(int argc, char **argv, int len);
int		issorted(int *stack, int len);
int		getlen(int argc, char **argv);
void	filltab(int argc, char **argv, int *tab, int *b);
int		ft_atoi(char *str, int i, int *b);
int		issp(char c);
int		isvalid(char b, char c, char d, int i);
int		notdouble(int *tab, int len);
int		notnum(int argc, char **argv);

void	sortsmallstack(struct s_stack stacks);
void	sort5num(int *stacka, int *stackb, int *lena, int *lenb);
void	sort4num(int *stacka, int *stackb, int *lena, int *lenb);
void	sort3num(int *stacka, int *lena);
int		getminmax(int *tab, int len, int b);

int		*simplifytab(int *tab, int len);
int		*copytab(int *tab, int len);
void	swap(int *tab, int i);
void	renametab(int *tab, int *new, int len);

void	radixsort(struct s_stack stacks);

void	pusha(int *stacka, int *stackb, int *lena, int *lenb);
void	pushb(int *stacka, int *stackb, int *lena, int *lenb);
void	swapa(int *stacka);
void	rotatea(int *stacka, int *lena);
void	reverserotatea(int *stacka, int *lena);

#endif
