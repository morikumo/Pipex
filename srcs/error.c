/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <mabid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:45:12 by mabid             #+#    #+#             */
/*   Updated: 2022/06/18 19:46:03 by mabid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pipex.h"

/**
 * @brief  Commande qui va selon ce qu'on lui donne en parametre va afficher
 * le nom de la commande probleme et l'erreur qui va avec. le tout en exit 127.
 * 
 * 
 * @param name 
 * @param err 
 * @param c_fd 
 */
void	command_not_found(char *name, char *err, int *c_fd)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_fin_de_phrase(err, 2);
	close(c_fd[0]);
	close(c_fd[1]);
	exit(127);
}

/**
 * @brief Une simple fonction d'affichage d'erreur.
 * 
 */
void	error(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}
