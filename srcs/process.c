/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayminmaw <zayminmaw@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:21:06 by zmin              #+#    #+#             */
/*   Updated: 2024/12/11 11:40:58 by zayminmaw        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	process_empty(t_data *d, unsigned short **matrix,
	unsigned int x, unsigned int y)
{
	unsigned short	tmp;

	if (x == 0 || y == 0)
		matrix[y][x] = 1;
	else
	{
		if (matrix[y - 1][x] > matrix[y][x - 1])
			tmp = matrix[y][x - 1];
		else
			tmp = matrix[y - 1][x];
		if (tmp > matrix[y - 1][x - 1])
			matrix[y][x] = matrix[y - 1][x - 1] + 1;
		else
			matrix[y][x] = tmp + 1;
		if (matrix[y][x] > matrix[d->bsq_y][d->bsq_x])
		{
			d->bsq_y = y;
			d->bsq_x = x;
		}
	}
}

/*
* @brief Check if we in end of line and increment y to next row.
*/
bool	process_end_check(t_data *d,
	unsigned int *x, unsigned int *y, unsigned int i)
{
	if (d->map[i] == '\n')
	{
		if (x[0] != d->len_lines)
			return (ft_print_error(
					"Error: map error\t(all lines should be the same length)\n"));
		x[0] = -1;
		y[0] += 1;
	}
	else
		return (ft_print_error(
				"Error: map error\t(all lines should be the same length)\n"));
	return (true);
}

bool	process(t_data *d, unsigned short **matrix)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	i;

	i = d->n;
	x = 0;
	y = 0;
	while (i < (d->len_lines + 1) * d->nbr_lines)
	{
		if (y >= d->nbr_lines)
			return (ft_print_error(
					"Error: map error\t(lines over number of lines in arg)\n"));
		else if (d->map[i] == d->empty)
			process_empty(d, matrix, x, y);
		else if (d->map[i] == d->obstacle)
			matrix[y][x] = 0;
		else if (!process_end_check(d, &x, &y, i))
			return (false);
		i++;
		x++;
	}
	return (true);
}