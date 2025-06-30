/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrios <angrios@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:35:47 by angrios           #+#    #+#             */
/*   Updated: 2025/06/30 14:56:20 by angrios          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*free_mem(char **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (NULL);
}

static void	trim_stash(char **stash)
{
	char	*new_stash;
	char	*post_newline;

	if (!stash || !*stash)
		return ;
	post_newline = ft_strchr(*stash, '\n');
	if (!post_newline || *(post_newline + 1) == '\0')
	{
		free_mem(stash);
		return ;
	}
	new_stash = ft_strdup(post_newline + 1);
	if (!new_stash)
		return ;
	free(*stash);
	*stash = new_stash;
}

static int	read_until_new_line(int fd, char **stash, char **buffer)
{
	char	*temp_stash;
	int		bytes_read;

	while (!ft_strchr(*stash, '\n'))
	{
		bytes_read = read(fd, *buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (0);
		if (bytes_read == 0)
			break ;
		(*buffer)[bytes_read] = '\0';
		temp_stash = ft_strjoin(*stash, *buffer, 0, 0);
		if (!temp_stash)
			return (0);
		free(*stash);
		*stash = temp_stash;
	}
	return (1);
}

static char	*extract_line(char *stash)
{
	int		len;
	char	*line;

	if (!stash || stash[0] == '\0')
		return (NULL);
	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	if (stash[len] == '\n')
		len++;
	line = ft_substr(stash, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (!read_until_new_line(fd, &stash, &buffer))
		return (free_mem(&stash), free_mem(&buffer));
	line = extract_line(stash);
	if (!line)
		return (free_mem(&stash), free_mem(&buffer), NULL);
	trim_stash(&stash);
	free(buffer);
	return (line);
}
