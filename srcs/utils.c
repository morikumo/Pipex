/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <mabid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 13:46:53 by morikumo          #+#    #+#             */
/*   Updated: 2022/06/18 19:46:11 by mabid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pipex.h"

char	*ft_verif(char *cmd)
{
	if (ft_chara(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (cmd);
		return (NULL);
	}
	return (0);
}

char	*ft_free(char **paths)
{
	int	i;

	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (0);
}

/**
 * @brief Va chercher la commande dans l'environement  
	et tester chaque chemin par le access, et renvoie le bon chemin
 * 
 * @param cmd 
 * @param envp 
 * @return char* 
 */
char	*find_path(char *cmd, char **envp)
{
	int		i;
	t_path	path;

	if (ft_chara(cmd, '/'))
		return (ft_verif(cmd));
	i = 0;
	while (envp && envp[i] && ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	if (!envp[i])
		return (NULL);
	path.paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (path.paths[i])
	{
		path.part_path = ft_strjoindre(path.paths[i], "/");
		path.path = ft_strjoindre(path.part_path, cmd);
		free(path.part_path);
		if (access(path.path, X_OK) == 0)
			return (path.path);
		free(path.path);
		i++;
	}
	ft_free(path.paths);
	return (NULL);
}

/**
 * @brief Fonction qui prend la commande et l'envoie à find_path
 avant de l'exécuter.
 * 
 * @param argv 
 * @param envp 
 * @param c_fd 
 */
void	execute(char *argv, char **envp, int *c_fd)
{
	char	**cmd;
	int		i;
	char	*path;

	i = -1;
	cmd = ft_split(argv, ' ');
	if (cmd[0] == NULL)
	{
		free(cmd[0]);
		free(cmd);
		command_not_found(argv, "permission denied", c_fd);
	}
	path = find_path(cmd[0], envp);
	if (!path)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		command_not_found(argv, "command not found", c_fd);
	}
	if (execve(path, cmd, envp) == -1)
		error();
}
