/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:36:40 by apayen            #+#    #+#             */
/*   Updated: 2023/04/18 11:27:04 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	badfile(struct s_pipe *pipex, int argc, char **argv, int i)
{
	if (i == 0)
	{
		pipex->badinfile = 1;
		write(2, "pipex: ", 7);
		write(2, argv[1], (unsigned int)ft_strlen(argv[1]));
		write(2, ": ", 2);
		perror(NULL);
		pipex->infile = open("/dev/null", O_RDONLY);
		if (pipex->infile == -1)
			return (1);
	}
	else
	{
		pipex->badoutfile = 1;
		close(pipex->infile);
		write(2, "pipex: ", 7);
		write(2, argv[argc - 1], (unsigned int)ft_strlen(argv[argc - 1]));
		write(2, ": ", 2);
		perror(NULL);
		pipex->outfile = open("/dev/null", O_RDONLY);
		if (pipex->outfile == -1)
			return (1);
	}
	return (0);
}

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
	free(pipex->pid);
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
	free(pipex->pid);
	write(2, "pipex: ", 7);
	write(2, argv[pipex->i], (unsigned int)ft_strlen(argv[pipex->i]));
	write(2, ": Permission denied\n", 20);
	close(0);
	close(1);
	close(2);
	exit (126);
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
	free(pipex->pid);
	write(2, argv[pipex->i], (unsigned int)ft_strlen(argv[pipex->i]));
	write(2, ": command not found\n", 20);
	close(0);
	close(1);
	close(2);
	exit (127);
}

_Noreturn void	execcommand(char **argv, struct s_pipe *pipex, int i)
{
	if (ft_strlen(pipex->arg[0]) > 0 && (pipex->arg[0][0] == '/' \
		|| pipex->arg[0][0] == '.' ))
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
