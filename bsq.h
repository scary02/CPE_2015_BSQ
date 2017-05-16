/*
** bsq.h for bsq in /home/barbe_j/rendu/CPE_BSQ_2015
** 
** Made by jordan barbé
** Login   <barbe_j@epitech.net>
** 
** Started on  Wed Aug 10 15:38:29 2016 jordan barbé
** Last update Thu Aug 11 18:09:32 2016 jordan barbé
*/

#ifndef BSQ_H_
# define BSQ_H_

# define ERROR_ARG "\n"

typedef struct	s_bsq
{
  int		x;
  int		y;
  int		i;
  int		c;
  int		**tab;
  char		**tab2;
  int		fd;
  int		line;
  int		col;
  char		*str;
}		t_bsq;

int		my_strlen(char *);
int		my_puterror(char *);
int		my_getnbr(char *);
void		my_putchar(char);
void		my_print_tab(int **);
void		my_algo(t_bsq *);
int		return_col(t_bsq *);
void		print_result(t_bsq *);

#endif /* !BSQ_H_ */
