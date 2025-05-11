/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childprocess.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:14:55 by apayen            #+#    #+#             */
/*   Updated: 2023/04/18 11:40:21 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
	if (pipex->fullpath == NULL)
		return (-1);
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
	return ((void)free(pipex->path), -1);
}

int	childprocess(char **argv, struct s_pipe pipex, int i)
{
	if ((pipex.badinfile == 1 && i == 2) \
		|| (pipex.badoutfile == 1 && i == pipex.argc - 2))
		return ((void)freefds(&pipex), (void)free(pipex.pid), 1);
	if (i == 2 || (pipex.heredoc == 1 && i == 3))
	{
		if (firstchild(&pipex) == 1)
			return (1);
	}
	else if (i == pipex.argc - 2)
	{
		if (lastchild(&pipex, (i - 2 - pipex.heredoc)) == 1)
			return (1);
	}
	else
	{
		if (childs(&pipex, (i - 2 - pipex.heredoc)) == 1)
			return (1);
	}
	pipex.arg = ft_split(argv[i], ' ');
	if (pipex.arg == NULL)
		return ((void)freefds(&pipex), (void)free(pipex.pid), 1);
	execcommand(argv, &pipex, i);
	return (1);
}
