/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:01:24 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/24 12:02:03 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	init_errno(void)
{
	g_errno[OPEN].msg = OPEN_MSG;
	g_errno[OPEN].len = OPEN_LEN;
	g_errno[READ].msg = READ_MSG;
	g_errno[READ].len = READ_LEN;
	g_errno[MISSING_TOKEN].msg = MISSING_TOKEN_MSG;
	g_errno[MISSING_TOKEN].len = MISSING_TOKEN_LEN;
	g_errno[UKNOWN_SHAPE].msg = UKNOWN_SHAPE_MSG;
	g_errno[UKNOWN_SHAPE].len = UKNOWN_SHAPE_LEN;
	g_errno[NB_OBJECT].msg = NB_OBJECT_MSG;
	g_errno[NB_OBJECT].len = NB_OBJECT_LEN;
	g_errno[END_OBJ].msg = END_OBJ_MSG;
	g_errno[END_OBJ].len = END_OBJ_LEN;
	g_errno[CAM_END].msg = CAM_END_MSG;
	g_errno[CAM_END].len = CAM_END_LEN;
	g_errno[WRONG_TRIPLE].msg = WRONG_TRIPLE_MSG;
	g_errno[WRONG_TRIPLE].len = WRONG_TRIPLE_LEN;
	g_errno[CAM_IDENTIFIER].msg = CAM_IDENTIFIER_MSG;
	g_errno[CAM_IDENTIFIER].len = CAM_IDENTIFIER_LEN;
	g_errno[SCREEN_CAM].msg = SCREEN_CAM_MSG;
	g_errno[SCREEN_CAM].len = SCREEN_CAM_LEN;
}
