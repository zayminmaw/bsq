/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayminmaw <zayminmaw@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:21:06 by zmin              #+#    #+#             */
/*   Updated: 2024/12/11 11:27:28 by zayminmaw        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

/*
* @brief Free inner array of matrix. 
*/
unsigned short	**free_matrix_i(unsigned short **matrix, int i)
{
	while (--i >= 0)
		free(matrix[i]);
	free(matrix);
	return (NULL);
}

/*
* @brief Free entire array of matrix. 
*/
void	free_matrix(unsigned short **matrix, t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->nbr_lines)
	{
		free(matrix[i]);
		i++;
	}
	if (data->len_lines != 0)
		free(matrix);
}

/*
* @brief Build an empty data struct for the program.
*/
void	init_data(t_data *data)
{
	data->nbr_lines = 0;
	data->len_lines = 0;
	data->bsq_x = 0;
	data->bsq_y = 0;
	data->map = NULL;
}

/*
* @brief Build a two dimension array for processing.
*/
unsigned short	**init_matrix(t_data *d)
{
	unsigned short	**matrix;
	unsigned int	i;

	matrix = malloc(sizeof(unsigned short *) * d->nbr_lines);
	if (!matrix)
	{
		ft_pser("Error: Malloc failed\n");
		return (NULL);
	}
	i = 0;
	while (i < d->nbr_lines)
	{
		matrix[i] = malloc(sizeof(unsigned short) * d->len_lines);
		if (!matrix[i])
			return (free_matrix_i(matrix, i));
		i++;
	}
	return (matrix);
}