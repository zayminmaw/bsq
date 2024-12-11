/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayminmaw <zayminmaw@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:21:06 by zmin              #+#    #+#             */
/*   Updated: 2024/12/11 12:36:10 by zayminmaw        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

bool	ft_release_mem(t_data *d, unsigned short **matrix, bool ret)
{
	if (d->map)
		free(d->map);
	if (matrix)
		free_matrix(matrix, d);
	return (ret);
}

bool start(t_data *d, char *file)
{
    unsigned short	**matrix;
    
    init_data(d);
    if (!file)
    {
		if (!read_default(d))
			return (ft_release_mem(d, NULL, false));
    }
	else
    {
		if (!read_file(d, file))
			return (ft_release_mem(d, NULL, false));
    }
    matrix = init_matrix(d);
	if (!matrix)
		return (ft_release_mem(d, NULL, false));
	if (!process(d, matrix))
		return (ft_release_mem(d, matrix, false));
	display(d, matrix);
	return (ft_release_mem(d, matrix, true));
}

int main(int argc, char **argv)
{
    t_data	d;
    int i;

    if (argc > 1)
    {
        i = 1;
		while (i < argc && start(&d, argv[i]))
			i++;
		if (i < argc)
			return (1);
    }
    else
    {
        return (start(&d, NULL));
    }
    return (0);
}