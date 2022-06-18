/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <mabid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 13:28:30 by morikumo          #+#    #+#             */
/*   Updated: 2022/06/17 21:34:18 by mabid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H

# define LIB_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

char	*ft_strnstr(const char	*big, const char *little, size_t len);
char	*ft_strjoindre(char const *s1, char const *s2);
char	**ft_split(char	const *s, char c);
char	*ft_chara(const char *s, int c);
void	ft_putstr_fd(char *s, int fd);
void	ft_fin_de_phrase(char *s, int fd);
size_t	ft_strlen(const char *s);

#endif
