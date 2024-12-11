/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayminmaw <zayminmaw@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:21:06 by zmin              #+#    #+#             */
/*   Updated: 2024/12/11 10:28:16 by zayminmaw        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

/*
* @briefc continue the read by chunks from read map function which first 4086 bytes is already read
*/
bool	read_big_map(t_data *d, int fd, size_t buffer_size, size_t size)
{
	char	*buffer;
	ssize_t	ret;

	buffer = (char *)malloc(sizeof(char) * buffer_size + 1);
	if (!buffer)
		return (ft_print_error("Error: Malloc failed\n"));
	ret = read(fd, buffer, buffer_size);
	buffer[ret] = '\0';
	while (ret != 0 && ret != EOF)
	{
		d->map = ft_strjoin(d->map, size, buffer, buffer_size);
		if (!d->map)
			return (ft_print_error("Error: Malloc failed\n"));
		size += ret;
		ret = read(fd, buffer, buffer_size);
		buffer[ret] = '\0';
	}
	free(buffer);
	return (true);
}

/*
* @brief Read first 4096 bytes and if there is more hand over to read big map. 
*/
bool	read_map(t_data *d, int fd, size_t buffer_size)
{
	ssize_t		ret;

	d->map = (char *)malloc(sizeof(char) * BUF_SIZE + 1);
	if (!d->map)
		return (ft_print_error("Error: Malloc failed\n"));
	ret = read(fd, d->map, BUF_SIZE);
	d->map[ret] = '\0';
	if (ret != 0 && ret != EOF)
		if (!read_big_map(d, fd, buffer_size, ret))
			return (false);
	return (true);
}