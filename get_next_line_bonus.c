/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:53:21 by zel-bouz          #+#    #+#             */
/*   Updated: 2022/11/14 13:33:14 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_line(char *saved)
{
	int		i;
	char	*line;

	i = 0;
	if (!saved[i])
		return (NULL);
	while (saved[i] && saved[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (saved[i] && saved[i] != '\n')
	{
		line[i] = saved[i];
		i++;
	}
	if (saved[i] == '\n')
	{
		line[i] = saved[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_get_left_str(char *saved)
{
	int		i;
	int		j;
	char	*left_str;

	i = 0;
	while (saved[i] && saved[i] != '\n')
		i++;
	if (!saved[i])
	{
		free(saved);
		return (NULL);
	}
	left_str = (char *)malloc(sizeof(char) * (ft_strlen(saved) - i + 1));
	if (!left_str)
		return (NULL);
	i++;
	j = 0;
	while (saved[i])
		left_str[j++] = saved[i++];
	left_str[j] = '\0';
	return (free(saved), left_str);
}

char	*ft_read_from_file(int fd, char *saved)
{
	char	*buff;
	int		read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(saved, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(buff), NULL);
		buff[read_bytes] = '\0';
		saved = ft_strjoin(saved, buff);
	}
	free(buff);
	return (saved);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*saved[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	saved[fd] = ft_read_from_file(fd, saved[fd]);
	if (!saved[fd])
		return (NULL);
	line = ft_get_line(saved[fd]);
	saved[fd] = ft_get_left_str(saved[fd]);
	return (line);
}

// int main()
// {
//     int file1 = open("file.txt", O_RDONLY);
//     int file2 = open("file1.txt", O_RDONLY);
//     int file3 = open("file2.txt", O_RDONLY);
//     printf("#####################################\n");
//     printf("%s", get_next_line(file1));
//     printf("%s", get_next_line(file2));
//     printf("%s", get_next_line(file3));
//     printf("#####################################\n");
//     printf("%s", get_next_line(file1));
//     printf("%s", get_next_line(file2));
//     printf("%s", get_next_line(file3));
//     printf("#####################################\n");

// }