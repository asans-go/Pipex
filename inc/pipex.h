/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asans-go <asans-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:09:56 by asans-go          #+#    #+#             */
/*   Updated: 2024/03/28 19:46:41 by asans-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include "libft.h"
# include "ft_printf.h"
# include "ft_dprintf.h"

# define E_MALLOC "Error, Malloc's fault.\n"
# define E_ENV "Error, No enviroment.\n"
# define E_NOPATH "Error, No PATH in enviorment.\n"
# define E_OPEN "Error, Not Able to Open the File.\n"
# define E_W_KO "Error, No Perms to Write.\n"
# define E_R_KO "Error, No Perms to Read.\n"
# define E_F_KO "Error, Unexistant File.\n"

# define DEF_PATH "/usr/local/bin:/usr/bin:/bin:\
	/usr/sbin:/sbin:/usr/local/go/bin:"

typedef struct s_pipe
{
	int		in_fd;
	int		out_fd;
	char	**all_path;
	char	*path1;
	char	*path2;
	char	**cmd1;
	char	**cmd2;
	int		j;

}	t_pipe;

/// MAIN_PIPEX ///
int		parsing(char **av, char *envp[], t_pipe *pipex);
void	init_pipex(t_pipe *pipex);
void	init_all_paths(t_pipe *pipex, char **envp);

/// CHECK_ARGS ///
char	*check_cmd_access(t_pipe *pipex, char **cmd);
char	**final_cmd(char *cmd, t_pipe *pipex);
char	**split_with_quotes(char *cmd, t_pipe *pipex);
int		subsrt_space(const char *s, char c);
void	split_quotes(char **ret, char *cmd, int i, int j);

/// PROCESSES ///
void	child(char **envp, char *av, t_pipe *pipex, int fd[]);
void	parent(char **envp, char *av, t_pipe *pipex, int fd[]);

/// UTILS_PIPEX ///
int		strchr_count(char *str, char c);
void	*px_free(char **str);
char	*px_strjoin(char *raw, char *buf);
char	*px_barjoin(char *raw, char *buf);
char	*px_strtrim(char *s1, char *set);

/// ERRORS ///
void	free_matrix(char **arr);
void	clean_pipex(t_pipe *pipex);
int		print_err_free(char *msg, t_pipe *pipex, int flag);

#endif
