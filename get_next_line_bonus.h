/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabd-el- <gabd-el-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:42:55 by gabd-el-          #+#    #+#             */
/*   Updated: 2023/02/12 20:03:59 by gabd-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This is the bonus version of get_next_line.
** it can manage multiple file descriptors at the same time.
*/

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

/*
**  Libraries   
*/
# include <unistd.h>
# include <stdlib.h>

/*
**  BUFFER_SIZE is the size of the buffer used to read the file
*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/*
**  FD_MAX is the maximum number of file descriptors
*/
# define FD_MAX 1024

/*
**  Main Function get_next_line
*/
char	*get_next_line(int fd);

/*
**  Read Buffer Function
*/
char	*read_buf(char *stati, int fd);

/*
**  Function that Prints the Line
*/
char	*print_next_line(char *stati);

/*
**  Function that Sets the Next line
*/
char	*set_next_line(char *stati);

/*
**  Libft Helper Functions
*/
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *stati, char *buf);
void	ft_strlcpy(char *dst, const char *src, size_t dstsize);
#endif