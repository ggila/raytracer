#ifndef PROTO_H
# define PROTO_H

// read_map.c
char	read_map(char *str);


// lib/ft_bzero.c
void	ft_bzero(void *dst, size_t n);

// matrix/add.c
void add(t_mat *lhs, t_mat *rhs, t_mat *buf);

// matrix/print.c
void	print_mat(t_mat mat);

// matrix/trans.c
void	trans(t_vect *vect, t_mat mat);

// matrix/rot.c
void		rot(t_mat *ret, float alpha, float beta, float gamma);

// matrix/dot.c
void			dot(t_mat *lhs, t_mat *rhs, t_mat *buf);


#endif
