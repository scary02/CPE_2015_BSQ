/*
** main.c for main in /home/barbe_j/rendu/CPE_BSQ_2015
** 
** Made by jordan barbé
** Login   <barbe_j@epitech.net>
** 
** Started on  Wed Aug 10 15:27:06 2016 jordan barbé
** Last update Tue Aug 16 22:35:55 2016 jordan barbé
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"
#include "bsq.h"

static void	init_struct(t_bsq *in)
{
  in->x = 0;
  in->y = 0;
  in->i = 0;
  in->c = 0;
  in->tab = NULL;
  in->tab2 = NULL;
  in->str = NULL;
  in->fd = 0;
  in->col = 0;
  in->line = 0;
}

static int	process_open_next(t_bsq *in)
{
  in->col = return_col(in) - 1;
  if (!(in->tab[in->c] = malloc(sizeof(int) * in->col * 3)))
    return (-1);
  if (!(in->tab2[in->c] = malloc(sizeof(int) * in->col * 3)))
    return (-1);
  while (in->str[in->i])
    {
      if (in->str[in->i] == '.')
	in->tab[in->c][in->i] = 2;
      else if (in->str[in->i] == 'o')
	in->tab[in->c][in->i] = 1;
      else
	return (-1);
      in->i++;
    }
  in->tab[in->c][in->i] = 0;
  in->c++;
  in->i = 0;
  return (0);
}

static int	next_pross(t_bsq *in, int line)
{
  if (!in->str)
    return (-1);
  in->line = my_getnbr(in->str);
  if (in->line == 0)
    return (-1);
  line = in->line;
  if (!(in->tab = malloc(sizeof(int *) * in->line * 2)))
    return (-1);
  if (!(in->tab2 = malloc(sizeof(int *) * in->line * 2)))
    return (-1);
  return (0);
}

static int	process_open(t_bsq *in, char *av)
{
  static int	stat = 0;
  int		line;

  if ((in->fd = open(av, O_RDONLY)) == -1)
    return (-1);
  while ((in->str = get_next_line(in->fd)))
    {
      if (stat > line)
	return (-1);
      if (stat == 0)
	{
	  if (next_pross(in, line) == -1)
	    return (-1);
	}
      else if (stat >= 1)
	if (process_open_next(in) == -1)
	  return (-1);
      stat++;
    }
  if (stat == 0)
    return (-1);
  in->tab[in->c] = 0;
  return (0);
}

int		main(int ac, char **av)
{
  t_bsq		in;

  if (ac != 2)
    return (my_puterror(ERROR_ARG));
  init_struct(&in);
  if (process_open(&in, av[1]) == -1)
    return (1);
  my_algo(&in);
  print_result(&in);
  close(in.fd);
  return (0);
}
