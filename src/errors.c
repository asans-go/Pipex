/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asans-go <asans-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:36:05 by asans-go          #+#    #+#             */
/*   Updated: 2024/03/28 19:36:18 by asans-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_matrix(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}

void	clean_pipex(t_pipe *pipex)
{
	if (pipex && pipex->all_path)
		free_matrix(pipex->all_path);
	if (pipex && pipex->path1)
		free(pipex->path1);
	if (pipex && pipex->path2)
		free(pipex->path2);
	if (pipex && pipex->cmd1)
		free_matrix(pipex->cmd1);
	if (pipex && pipex->cmd2)
		free_matrix(pipex->cmd2);
	if (pipex)
		free(pipex);
	pipex = NULL;
}

int	print_err_free(char *msg, t_pipe *pipex, int flag)
{
	if (pipex)
		clean_pipex(pipex);
	if (flag == 1)
		perror(msg);
	else
		write(2, msg, ft_strlen(msg));
	exit(errno);
}
