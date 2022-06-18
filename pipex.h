/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <mabid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 13:46:59 by morikumo          #+#    #+#             */
/*   Updated: 2022/06/18 19:46:35 by mabid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include "./srcs/lib.h"

typedef struct s_path
{
	char	**paths;
	char	*path;
	char	*part_path;
	pid_t	pid1;
	pid_t	pid2;
}				t_path;

/*      UTILS       */
void	error(void);
char	*find_path(char *cmd, char **envp);
void	execute(char *argv, char **envp, int *c_fd);
void	command_not_found(char *name, char *err, int *c_fd);

/*      PIPEX       */
void	child_process(char **argv, char **envp, int *fd);
void	child_process2(char **argv, char **envp, int *fd);
void	child_process3(char **argv, char **envp, int *fd, t_path *pid);

#endif
