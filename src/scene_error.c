/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:50:28 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/28 11:14:48 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void		scene_error(int type, int line)
{
	char	b[2];

	write(1, READ_ERROR, 22);
	if (line > 0)
	{
		write(1, "line ", 5);
		b[0] = line / 10 - '0';
		b[1] = line % 10 - '0';
		write(1, b, 2);
		write(1, " :", 2);
	}
	ft_errno(type);
	exit(KO);
}
