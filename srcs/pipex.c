/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <mabid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 13:46:48 by morikumo          #+#    #+#             */
/*   Updated: 2022/06/18 19:46:07 by mabid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pipex.h"

/**
 * @brief Processus enfant qui s'exécute à l'intérieur d'un fork, 
 * prend le filein, place l'output à l'intérieur
 * d'un pipe, puis ferme la fonction avec close
 * 
 * @param argv 
 * @param envp 
 * @param fd 
 */
void	child_process(char **argv, char **envp, int *fd)
{
	int		filein;
	int		c_fd[2];

	c_fd[0] = dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	close(fd[0]);
	filein = open(argv[1], O_RDONLY);
	if (filein == -1)
	{
		perror(argv[1]);
		exit(-1);
	}
	c_fd[1] = dup2(filein, STDIN_FILENO);
	close(filein);
	execute(argv[2], envp, c_fd);
}

/**
 * @brief Processus parent qui récupère les données du canal,
 *  modifie la sortie pour le fileout et aussi fermer avec la fonction close
 * 
 * @param argv 
 * @param envp 
 * @param fd 
 */
void	child_process2(char **argv, char **envp, int *fd)
{
	int		fileout;
	int		c_fd[2];

	c_fd[0] = dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fileout == -1)
	{
		perror(argv[4]);
		exit(-1);
	}
	c_fd[1] = dup2(fileout, STDOUT_FILENO);
	close(fileout);
	execute(argv[3], envp, c_fd);
}

/**
 * @brief Deuxieme processus a faire dans le main mais est fait a part pour 
 * les ligne...
 * 
 * @param argv 
 * @param envp 
 * @param fd 
 */
void	child_process3(char **argv, char **envp, int *fd, t_path *pid)
{
	pid->pid2 = fork();
	if (pid->pid2 == -1)
		error();
	else if (pid->pid2 == 0)
		child_process2(argv, envp, fd);
}

/**
 * @brief Fonction principale qui exécute le processus enfant et parent 
 * ou affiche une erreur message si les arguments sont erronés 
 * 
 * @param argc 
 * @param argv 
 * @param envp 
 * @return int 
 */
int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		status;
	t_path	pid;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error();
		pid.pid1 = fork();
		if (pid.pid1 == -1)
			error();
		if (pid.pid1 == 0)
			child_process(argv, envp, fd);
		else
			child_process3(argv, envp, fd, &pid);
		close(fd[0]);
		close(fd[1]);
		waitpid(pid.pid1, &status, 0);
		waitpid(pid.pid2, &status, 0);
	}
	else
		ft_putstr_fd("Error\nEx:./pipex <file1> <cmd1> <cmd2> <file2>\n", 2);
	return (0);
}
