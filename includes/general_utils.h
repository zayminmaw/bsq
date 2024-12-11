/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayminmaw <zayminmaw@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:21:06 by zmin              #+#    #+#             */
/*   Updated: 2024/12/11 10:21:22 by zayminmaw        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_UTILS_H
# define GENERAL_UTILS_H

# include "core.h"

int ft_strlen(char *str);

bool ft_print_error(char *str);

int	ft_strncpy(char *dst, const char *src, const size_t size);

char	*ft_strjoin(char *s1, const size_t size1, char *s2, const size_t size2);

#endif