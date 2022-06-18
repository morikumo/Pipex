/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <mabid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 13:47:39 by morikumo          #+#    #+#             */
/*   Updated: 2022/06/17 21:38:42 by mabid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* La fonction strnstr() localise la première occurrence de la chaine little 
qui fini par NULL dans la chaine big. La ou il n'y a plus de len a chercher.
Si little est une chaîne vide, big est renvoyé ; si little se produit nulle part 
dans big, NULL est retourné ; sinon un pointeur sur le premier caractère 
du premier occurrence de little est renvoyée. */

#include "lib.h"
/**
 * @brief 
 * 
 * @param big 
 * @param little 
 * @param len 
 * @return char* 
 */
char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)big + i);
			j++;
		}
		i++;
	}
	return (0);
}
