/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrios <angrios@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:35:47 by angrios           #+#    #+#             */
/*   Updated: 2025/06/20 19:37:00 by angrios          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 1024

static char	*append_buffer(char *stash, char *buffer, size_t bytes_read)
{
	char	*old_stash;

	old_stash = stash;
	buffer[bytes_read] = '\0';
	stash = ft_strjoin(old_stash, buffer);
	if (!stash)
	{
		free(old_stash);
		return (NULL);
	}
	free(old_stash);
	return (stash);
}

static char	*trim_stash(char *stash)
{
	char	*new_line;
	char	*new_stash;

	if (!stash)
		return (NULL);
	new_line = ft_strchr(stash, '\n');
	if (!new_line)
	{
		free(stash);
		return (NULL);
	}
	new_stash = ft_strdup(new_line + 1);
	free(stash);
	return (new_stash);
}

static char	*read_until_new_line(int fd, char *stash)
{
	char	*buffer;
	size_t	bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		stash = append_buffer(stash, buffer, bytes_read);
		if (!stash)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (stash);
}

static char	*extract_line(char *stash)
{
	size_t	len;

	len = 0;
	if (!stash)
		return (NULL);
	while (stash[len] && stash[len] != '\n')
		len++;
	if (stash[len] == '\n')
		len++;
	return (ft_substr(stash, 0, len));
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	return (NULL);
}
