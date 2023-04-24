/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:46:01 by apayen            #+#    #+#             */
/*   Updated: 2023/04/18 09:51:22 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
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
	char	**arg;
	char	**env;
	char	*fullpath;
	char	**path;
	int		*pid;
	int		fd[2][2];
	int		argc;
	int		heredoc;
	int		status;
	int		i;
	int		j;
	int		infile;
	int		outfile;
	int		badoutfile;
	int		badinfile;
	int		paddingstruct;
};

void		closeall(struct s_pipe *pipex);

int			init(struct s_pipe *pipex, int argc, char **argv, char **envp);
int			init2(struct s_pipe *pipex, int argc, char **argv);
int			mallocfds(struct s_pipe *pipex);
int			createpipe(struct s_pipe *pipex);
int			mallocpids(struct s_pipe *pipex);

int			checkheredoc(char *argv);
void		heredoc(struct s_pipe *pipex, int argc, char **argv);
int			loop(char *line, char **argv, int *fd);
int			checklimiter(char *line, char *limiter);
char		*get_next_line(int fd);
void		ft_cleanbuffer(char *buffer);
char		*ft_checkread(int fd, char *buffer, char *line, int *b);
char		*ft_substr(char *s, int start, int len);
char		*ft_strjoingnl(char *s1, char *s2, int b, char *buffer);
int			ft_strlen(char *s);
int			ft_checknl(char *str);

char		*ft_strjoin(char *s1, char *s2);
void		addslash(char *s1, char *strmalloc, int i);
char		*ft_strnstr(char *big, char *little);

int			childprocess(char **argv, struct s_pipe pipex, int i);
int			searchpath(char *arg, struct s_pipe *pipex);
int			relative(struct s_pipe *pipex, char **argv, int i);
int			firstchild(struct s_pipe *pipex);
int			lastchild(struct s_pipe *pipex, int i);
int			childs(struct s_pipe *pipex, int i);
void		execcommand(char **argv, struct s_pipe *pipex, int i);
void		commandnotfound(struct s_pipe *pipex, char **argv);
void		cantexecute(struct s_pipe *pipex, char **argv);
void		execfailed(struct s_pipe *pipex, int j);
int			badfile(struct s_pipe *pipex, int argc, char **argv, int i);

char		**ft_split(char *s, char c);
char		*ft_loop(char *s, char c, int i);
void		ft_free(char **strmalloc, int i);
char		*ft_strdupsplit(char *s, char c, int j);
int			ft_countstr(char *s, char c);

void		freefds(struct s_pipe *pipex);

#endif
