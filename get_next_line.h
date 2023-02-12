/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabd-el- <gabd-el-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 00:23:59 by gabd-el-          #+#    #+#             */
/*   Updated: 2023/02/12 19:31:52 by gabd-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

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