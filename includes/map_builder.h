/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_builder.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayminmaw <zayminmaw@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:21:06 by zmin              #+#    #+#             */
/*   Updated: 2024/12/11 12:36:43 by zayminmaw        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_BUILDER_H
# define MAP_BUILDER_H

void	init_data(t_data *data);

unsigned short	**free_matrix_i(unsigned short **matrix, int i);

void	free_matrix(unsigned short **matrix, t_data *data);

unsigned short	**init_matrix(t_data *d);

#endif