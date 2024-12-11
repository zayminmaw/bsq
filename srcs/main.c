/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayminmaw <zayminmaw@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:21:06 by zmin              #+#    #+#             */
/*   Updated: 2024/12/10 23:55:31 by zayminmaw        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

bool start(t_data *d, char *file)
{
    unsigned short	**matrix;
    
    init_data(d);
    if (!file)
		if (!read_stdin(d))
			return (ft_clear(d, NULL, false));
	else
		if (!read_file(d, file))
			return (ft_clear(d, NULL, false));
    return 1;
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