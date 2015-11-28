/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errno.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 11:05:43 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/28 12:16:41 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static const t_error *g_errno[] =
{
	{"ererg", 3},
	{"ererg", 3},
};

void	ft_errno()
{
	write(1, g_errno[type].msg, g_errno[type].len);
}
