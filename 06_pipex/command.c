/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:36:40 by apayen            #+#    #+#             */
/*   Updated: 2023/04/11 11:05:37 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

_Noreturn void	execfailed(struct s_pipe *pipex, int j)
{
	int	i;

	i = 0;
	while (pipex->path[j] != NULL)
	{
		free(pipex->path[j]);
		j++;
	}
	free(pipex->path);
	while (pipex->arg[i] != NULL)
	{
		free(pipex->arg[i]);
		i++;
	}
	free(pipex->arg);
	perror("pipex: execve");
	close(0);
	close(1);
	close(2);
	exit(1);
}

_Noreturn void	cantexecute(struct s_pipe *pipex, char **argv)
{
	int	j;

	j = 0;
	while (pipex->arg[j] != NULL)
	{
		free(pipex->arg[j]);
		j++;
	}
	free(pipex->arg);
	j = 0;
	while (pipex->path[j] != NULL)
	{
		free(pipex->path[j]);
		j++;
	}
	free(pipex->path);
	pipex->arg = NULL;
	write(2, "pipex: ", 7);
	write(2, argv[pipex->i], (size_t)ft_strlen(argv[pipex->i]));
	write(2, ": Permission denied\n", 20);
	close(0);
	close(1);
	close(2);
	exit(126);
}

_Noreturn void	commandnotfound(struct s_pipe *pipex, char **argv)
{
	int	j;

	j = 0;
	while (pipex->arg[j] != NULL)
	{
		free(pipex->arg[j]);
		j++;
	}
	free(pipex->arg);
	pipex->arg = NULL;
	write(2, argv[pipex->i], (size_t)ft_strlen(argv[pipex->i]));
	write(2, ": command not found\n", 20);
	close(0);
	close(1);
	close(2);
	exit(127);
}

_Noreturn void	execcommand(char **argv, struct s_pipe *pipex, int i)
{
	if (ft_strlen(pipex->arg[0]) > 1 && (pipex->arg[0][0] == '/' \
			|| (pipex->arg[0][0] == '.' && (pipex->arg[0][1] == '/' \
			|| pipex->arg[0][1] == '.'))))
	{
		if (relative(pipex, argv, i) == 1)
			commandnotfound(pipex, argv);
	}
	else
		pipex->j = searchpath(pipex->arg[0], pipex);
	if (pipex->j == -1)
	{
		if (relative(pipex, argv, i) == 1)
			commandnotfound(pipex, argv);
	}
	execve(pipex->path[pipex->j], pipex->arg, pipex->env);
	execfailed(pipex, pipex->j);
}
