/*
** print_result.c for print in /home/barbe_j/rendu/CPE_BSQ_2015
** 
** Made by jordan barbé
** Login   <barbe_j@epitech.net>
** 
** Started on  Thu Aug 11 00:04:09 2016 jordan barbé
** Last update Thu Aug 11 18:10:06 2016 jordan barbé
*/

#include <stdio.h>
#include "bsq.h"

static void    my_print_tab_char(char **tab)
{
  int   i;
  int   c;

  i = 0;
  c = 0;
  while (tab[c])
    {
      while (tab[c][i])
        {
	  my_putchar(tab[c][i]);
          i++;
        }
      my_putchar('\n');
      i = 0;
      c++;
    }
}

static void	print_x_next(t_bsq *in, int x, int y)
{
  int		c;
  int		i;
  int		max;

  i = 0;
  c = 0;
  max = in->tab[y][x];
  max = max - 1;
  while (c != max)
    {
      in->tab[y - i][x - c] = -1;
      while (i != max)
	{
	  in->tab[y - i][x - c] = -1;
	  i++;
	}
      i = 0;
      c++;
    }
}

static void	print_x(t_bsq *in)
{
  int		i;
  int		c;
  int		save;

  i = 0;
  c = 0;
  save = 0;
  while (in->tab[c])
    {
      while (in->tab[c][i])
	{
	  if (in->tab[c][i] >= 3 && in->tab[c][i])
	    if (in->tab[c][i] > save)
	      {
		save = in->tab[c][i];
		in->x = i;
		in->y = c;
	      }
	  i++;
	}
      i = 0;
      c++;
    }
  print_x_next(in, in->x, in->y);
}

void	print_result(t_bsq *in)
{
  int	i;
  int	c;

  i = 0;
  c = 0;
  print_x(in);
  while (in->tab[c])
    {
      while (in->tab[c][i])
	{
	  if (in->tab[c][i] == 2)
	    in->tab2[c][i] = '.';
	  else if (in->tab[c][i] == 1)
	    in->tab2[c][i] = 'o';
	  else if (in->tab[c][i] == -1)
	    in->tab2[c][i] = 'X';
	  else
	    in->tab2[c][i] = '.';
	  i++;
	}
      in->tab2[c][i] = 0;
      i = 0;
      c++;
    }
  in->tab2[c] = 0;
  my_print_tab_char(in->tab2);
}
