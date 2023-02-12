/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabd-el- <gabd-el-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 00:23:00 by gabd-el-          #+#    #+#             */
/*   Updated: 2023/02/12 20:07:45 by gabd-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*set_next_line(char *stati)
{
	// set_line is the line that will be set as the new stati.
	char	*set_line;
	size_t	i;

	i = 0;
	// LOOP untill new line is reached or end of string.
	while (stati[i] != '\n' && stati[i] != '\0')
		i++;
	// CASE where the line is empty.
	if (stati[i] == '\0')
		return (free(stati), NULL);
	// CASE where new line is at the beginning of the string.
	if (i == 0 && stati[i] == '\n')
	{
		set_line = (char *)malloc(sizeof(char) * ft_strlen(stati));
		if (set_line == NULL)
			return (free(stati), NULL);
		ft_strlcpy(set_line, &stati[i + 1], ft_strlen(stati));
		return (free(stati), set_line);
	}
	// last CASE where line isn't empty and \n isn't at the beginning.
	set_line = (char *)malloc(sizeof(char) * ft_strlen(stati) - i + 1);
	if (!set_line)
		return (free(stati), NULL);
	// copy the line to set_line.
	ft_strlcpy(set_line, &stati[i + 1], ft_strlen(stati) - i);
	return (free(stati), set_line);
}

char	*print_next_line(char *stati)
{
	// print_line is the line that will be printed.
	char	*print_line;
	size_t	i;

	i = 0;
	// CASE where the line is empty.
	if (stati[i] == '\0')
		return (NULL);
	// LOOP untill new line is reached or end of string.
	while (stati[i] != '\n' && stati[i] != '\0')
		i++;
	// CASE where new line is at the beginning of the string.
	if (i == 0 && stati[i] == '\n')
	{
		// malloc the print_line with the size of 2.
		// 2 because we need to add the \n and the \0.
		print_line = (char *)malloc(sizeof(char) * 2);
		if (print_line == NULL)
			return (NULL);
		print_line[0] = '\n';
		print_line[1] = '\0';
		return (print_line);
	}
	// last CASE where line isn't empty and \n isn't at the beginning.
	// malloc the print_line with the size of (i + 2). 
	// (i + 2) because 'i' is the size of the line and '+ 2' because we need to add the \n and the\0.
	print_line = (char *)malloc(sizeof(char) * i + 2);
	// check if malloc failed.
	if (!print_line)
		return (NULL);
	// copy the line to print_line.
	ft_strlcpy(print_line, stati, i + 2);
	return (print_line);
}

char	*read_buf(char *stati, int fd)
{
	// buf is the buffer used to read the file.
	char	*buf;
	// nb_read is the number of bytes read by read().
	int		nb_read;
	
	// malloc the buffer with the size of BUFFER_SIZE + 1.
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	nb_read = -1;
	// Loop as long as read does not return 0, 0 means theres nothing left to read.
	while (nb_read != 0 && !ft_strchr(stati, '\n'))
	{
		nb_read = read(fd, buf, BUFFER_SIZE);
		// check if read() returned -1, which means read encountered an error.
		if (nb_read == -1)
			return (free(buf), free(stati), NULL);
		// add the NULL terminator because read() doesnt add it.
		buf[nb_read] = '\0';
		// call ft_strjoin() to join the buffer to stati.
		stati = ft_strjoin(stati, buf);
	}
	// free the buffer and return stati.
	return (free(buf), stati);
}

char	*get_next_line(int fd)
{
	// stati is the static variable used throughout the process
	// it will keep its value between function calls.
	static char	*stati;
	char		*print_line;

	// if "fd" || "BUFFER_SIZE" are not valid values retruns 0
	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	// call the read function to read the file and store it in stati.
	stati = read_buf(stati, fd);
	// if stati is NULL return NULL.
	if (!stati)
		return (NULL);
	// call the print function to print the line.
	print_line = print_next_line(stati);
	// call the set function to set the next line.
	stati = set_next_line(stati);
	// return the line.
	return (print_line);
}

// include these libraries to test the function. for printf() and open()
#include <fcntl.h>
#include <stdio.h>
// main function to test the function.
int main(void)
{
	int fd;
	char *line;

	fd = open("", O_RDONLY);
	line = get_next_line(fd);
	printf("|%s|", line);
	free(line);
	return (0);
}