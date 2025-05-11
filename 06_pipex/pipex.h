/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:46:01 by apayen            #+#    #+#             */
/*   Updated: 2023/04/11 10:35:10 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdnoreturn.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>

struct		s_pipe
{
	int		i;
	int		j;
	int		argc;
	int		status;
	char	**env;
	char	**argv;
	int		infile;
	int		badinfile;
	int		outfile;
	int		badoutfile;
	int		fd[2];
	int		pid[2];
	char	*fullpath;
	char	**path;
	char	**arg;
};

int			init(struct s_pipe *pipex, int argc, char **argv, char **envp);
int			badfile(struct s_pipe *pipex, int argc, char **argv, int i);
void		closeall(struct s_pipe *pipex);

int			childprocess(char **argv, struct s_pipe pipex, int i);
int			childone(struct s_pipe *pipex);
int			childtwo(struct s_pipe *pipex);

int			searchpath(char *arg, struct s_pipe *pipex);
int			relative(struct s_pipe *pipex, char **argv, int i);
void		execcommand(char **argv, struct s_pipe *pipex, int i);
void		commandnotfound(struct s_pipe *pipex, char **argv);
void		cantexecute(struct s_pipe *pipex, char **argv);
void		execfailed(struct s_pipe *pipex, int j);

char		**ft_split(char *s, char c);
char		*ft_loop(char *s, char c, int i);
void		ft_free(char **strmalloc, int i);
char		*ft_strdupsplit(char *s, char c, int j);
int			ft_countstr(char *s, char c);

char		*ft_strjoin(char *s1, char *s2);
void		addslash(char *s1, char *strmalloc, int i);
int			ft_strlen(char *str);
char		*ft_strnstr(char *big, char *little);

#endif
