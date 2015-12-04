/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errno.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 11:05:43 by ggilaber          #+#    #+#             */
/*   Updated: 2015/12/04 10:58:05 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static const t_error g_errno[] =
{
	{"open() failed\n", 14},
	{"read() failed\n", 14},
	{"missing token \'|\'\n", 18},
	{"4 differents objects available (identifier from 0 to 3)\n", 56},
	{"do not exceed 10 objects\n", 25},
	{"too many stuffs for describe this object\n", 41},
	{"expected blank line between cam and object\n", 43},
	{"wrong format, expected three float separated with comma\n", 56},
	{"file must begin with camera definition (\"100|...\")\n", 51},
	{"camera should look straight to the screen\n", 42}
};

void	ft_errno(int type, int line, char flag)
{
	write(1, READ_ERROR, 22);
	if (line > 0)
	{
		write(1, "line ", 5);
		ft_putnbr(line);
		write(1, ": ", 2);
	}
	write(1, g_errno[type].msg, g_errno[type].len);
	if (flag == FATAL)
		exit(KO);
}
