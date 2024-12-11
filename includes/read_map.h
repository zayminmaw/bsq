/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayminmaw <zayminmaw@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:21:06 by zmin              #+#    #+#             */
/*   Updated: 2024/12/11 12:55:19 by zayminmaw        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_MAP_H
# define READ_MAP_H

# define BUF_SIZE 4096
# define BIG_BUF_SIZE	100000000
# include "type.h"

bool	read_map(t_data *d, int fd, size_t buffer_size);

bool	read_big_map(t_data *d, int fd, size_t buffer_size, size_t size);

bool	read_file(t_data *d, char *file);

bool	read_stdin(t_data *d);

#endif