/*
** get_next_line.h for get in /home/barbe_j/rendu/CPE_BSQ_2015/CPE_2015_BSQ
** 
** Made by jordan barbé
** Login   <barbe_j@epitech.net>
** 
** Started on  Thu Aug 11 18:07:04 2016 jordan barbé
** Last update Tue Aug 16 21:53:37 2016 jordan barbé
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

#ifndef READ_SIZE
# define READ_SIZE	(42)
#endif /* !READ_SIZE */

# define ENTER	'\n'
# define BACK	'\0'

typedef struct	s_fd
{
  char		*str;
  int		fd;
  int		i;
  char		*tmp;
  char		*tmp2;
  int		rd;
  int		j;
  struct s_fd	*next;
}		t_fd;

char	*get_next_line(const int fd);

#endif /* !GET_NEXT_LIN_H_ */
