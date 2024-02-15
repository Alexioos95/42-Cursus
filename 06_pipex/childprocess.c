/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childprocess.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:14:55 by apayen            #+#    #+#             */
/*   Updated: 2023/04/18 11:47:37 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	relative(struct s_pipe *pipex, char **argv, int i)
{
	int	j;

	j = 0;
	if (ft_strlen(argv[i]) == 0)
		return (1);
	pipex->path = ft_split(argv[i], ' ');
	if (pipex->path == NULL)
		return (1);
	if (access(pipex->path[0], F_OK) == 0)
	{
		if (access(pipex->path[0], X_OK) == 0)
		{
			if (execve(pipex->path[0], pipex->path, pipex->env) == 1)
				execfailed(pipex, -1);
		}
		else
			cantexecute(pipex, argv);
	}
	while (pipex->path[j] != NULL)
	{
		free(pipex->path[j]);
		j++;
	}
	free(pipex->path);
	return (1);
}

int	searchpath(char *arg, struct s_pipe *pipex)
{
	int	i;

	i = 0;
	if (ft_strlen(arg) == 0)
		return (-1);
	while (pipex->fullpath == NULL && pipex->env[i] != NULL)
	{
		pipex->fullpath = ft_strnstr(pipex->env[i], "PATH=");
		i++;
	}
	i = 0;
	pipex->path = ft_split(pipex->fullpath, ':');
	if (pipex->path == NULL)
		return (-1);
	while (pipex->path[i] != NULL)
	{
		pipex->path[i] = ft_strjoin(pipex->path[i], arg);
		if (access(pipex->path[i], F_OK | X_OK) == 0)
			return (i);
		free(pipex->path[i]);
		i++;
	}
	free(pipex->path);
	return (-1);
}

int	childtwo(struct s_pipe *pipex)
{
	close(pipex->fd[1]);
	if (dup2(pipex->outfile, STDOUT_FILENO) == -1)
		return ((void)close(pipex->infile), (void)close(pipex->outfile), \
			(void)close(pipex->fd[0]), (void)perror("pipex: dup2"), 1);
	close(pipex->outfile);
	if (dup2(pipex->fd[0], STDIN_FILENO) == -1)
		return ((void)close(pipex->infile), (void)close(pipex->fd[0]), \
			(void)perror("pipex: dup2"), 1);
	close(pipex->fd[0]);
	close(pipex->infile);
	return (0);
}

int	childone(struct s_pipe *pipex)
{
	close(pipex->fd[0]);
	if (dup2(pipex->infile, STDIN_FILENO) == -1)
		return ((void)close(pipex->infile), (void)close(pipex->outfile), \
			(void)close(pipex->fd[1]), (void)perror("pipex: dup2"), 1);
	close(pipex->infile);
	if (dup2(pipex->fd[1], STDOUT_FILENO) == -1)
		return ((void)close(pipex->outfile), (void)close(pipex->fd[1]), \
			(void)perror("pipex: dup2"), 1);
	close(pipex->fd[1]);
	close(pipex->outfile);
	return (0);
}

int	childprocess(char **argv, struct s_pipe pipex, int i)
{
	if ((pipex.badinfile == 1 && i == 2) || (pipex.badoutfile == 1 && i == 3))
		return ((void)close(pipex.infile), (void)close(pipex.outfile), \
			(void)close(pipex.fd[0]), (void)close(pipex.fd[1]), 1);
	if (i == 2)
	{
		if (childone(&pipex) == 1)
			return (1);
	}
	else if (i == 3)
		if (childtwo(&pipex) == 1)
			return (1);
	pipex.arg = ft_split(argv[i], ' ');
	if (pipex.arg == NULL)
		return ((void)close(pipex.infile), (void)close(pipex.outfile), \
			(void)close(pipex.fd[0]), (void)close(pipex.fd[1]), 1);
	execcommand(argv, &pipex, i);
	return (1);
}
