/*
** my_algo.c for my_algo in /home/barbe_j/rendu/CPE_BSQ_2015
** 
** Made by jordan barbé
** Login   <barbe_j@epitech.net>
** 
** Started on  Wed Aug 10 17:19:28 2016 jordan barbé
** Last update Thu Aug 11 18:08:01 2016 jordan barbé
*/

#include <stdio.h>
#include <stdlib.h>
#include "bsq.h"

static int	return_algo(int a, int b, int c)
{
  int	min;

  if (a < b)
    min = a;
  else
    min = b;
  if (min < c)
    return (min);
  else
    return (c);
}

void	my_algo(t_bsq *in)
{
  int	i;
  int	c;

  i = 1;
  c = 1;
  in->col += 2;
  while (c < in->line && in->tab[c])
    {
      while (i < in->col && in->tab[c][i])
        {
	  while (in->tab[c][i] == 1 && in->tab[c][i])
	    i = i + 1;
	  if (in->tab[c][i])
	    {
	      in->tab[c][i] = return_algo(in->tab[c - 1][i],
					  in->tab[c][i - 1],
					  in->tab[c - 1][i - 1]) + 1;
	      i++;
	    }
        }
      in->tab[c][i] = 0;
      i = 1;
      c++;
    }
  in->tab[c] = 0;
}
