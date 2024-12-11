/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayminmaw <zayminmaw@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:24:39 by zmin              #+#    #+#             */
/*   Updated: 2024/12/11 11:10:36 by zayminmaw        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>

# include "read_map.h"
# include "map_builder.h"
# include "general_utils.h"
# include "parse_map.h"
typedef struct s_data
{
	char			*map;
	char			empty;
	char			obstacle;
	char			filler;
	unsigned int	nbr_lines;
	unsigned int	len_lines;
	unsigned int	bsq_x;
	unsigned int	bsq_y;
	unsigned long	n;
	int				fd;
}					t_data;

#endif
