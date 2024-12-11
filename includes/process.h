/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayminmaw <zayminmaw@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:24:39 by zmin              #+#    #+#             */
/*   Updated: 2024/12/11 11:43:59 by zayminmaw        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

void	process_empty(t_data *d, unsigned short **matrix,
	unsigned int x, unsigned int y);

bool	process_end_check(t_data *d,
	unsigned int *x, unsigned int *y, unsigned int i);

bool	process(t_data *d, unsigned short **matrix);

#endif