/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:39:09 by vtestut           #+#    #+#             */
/*   Updated: 2023/02/02 16:04:44 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read_and_add(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_clear_buffer(buffer);
	return (line);
}

char	*ft_read_and_add(int fd, char *buffer)
{
	char	*tmp;
	int		nbyte;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	nbyte = 1;
	while (nbyte > 0)
	{
		nbyte = read(fd, tmp, BUFFER_SIZE);
		if (nbyte == -1)
		{
			free(buffer);
			free(tmp);
			return (NULL);
		}
		tmp[nbyte] = '\0';
		buffer = ft_join_and_free(buffer, tmp);
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	free(tmp);
	return (buffer);
}

char	*ft_join_and_free(char *buffer, char *tmp)
{
	char	*ret;

	ret = ft_strjoin(buffer, tmp);
	free(buffer);
	return (ret);
}

char	*ft_get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*ft_clear_buffer(char *buffer)
{
	char	*next_line;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	next_line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		next_line[j++] = buffer[i++];
	free(buffer);
	return (next_line);
}

// int main()
// {
//     int     fd;
//     char    *line;

//     fd = open("song", O_RDONLY);
//     while (1)
//     {
//         line = get_next_line(fd);
//         printf("%s", line);
//         if (line == NULL)
//             break;
//         free(line);
//     }
//     return (0);
// }