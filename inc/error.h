/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:01:24 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/24 12:02:03 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define OPEN 0
# define OPEN_MSG "open() failed"
# define OPEN_LEN 14

# define READ 1
# define READ_MSG "read() failed"
# define READ_LEN 14

# define MISSING_TOKEN 2
# define MISSING_TOKEN_MSG "missing token \'|\'"
# define MISSING_TOKEN_LEN 20

# define UKNOWN_SHAPE 3
# define UKNOWN_SHAPE_MSG "4 differents objects available (identifier from 0 to 3)"
# define UKNOWN_SHAPE_LEN 56

# define NB_OBJECT 4
# define NB_OBJECT_MSG "do not exceed 10 objects"
# define NB_OBJECT_LEN 25

# define END_OBJ 5
# define END_OBJ_MSG "too many stuffs for describe this object"
# define END_OBJ_LEN 41

# define CAM_END 6
# define CAM_END_MSG "expected blank line between cam and object"
# define CAM_END_LEN 43

# define WRONG_TRIPLE 7
# define WRONG_TRIPLE_MSG "wrong format, expected three float separated with comma"
# define WRONG_TRIPLE_LEN 56

# define CAM_IDENTIFIER 8
# define CAM_IDENTIFIER_MSG "file must begin with camera definition (\"100|...\")"
# define CAM_IDENTIFIER_LEN 53

#endif
