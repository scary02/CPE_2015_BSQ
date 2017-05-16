/*
** basic_next.c for next in /home/barbe_j/rendu/CPE_BSQ_2015
** 
** Made by jordan barbé
** Login   <barbe_j@epitech.net>
** 
** Started on  Wed Aug 10 18:32:30 2016 jordan barbé
** Last update Thu Aug 11 17:45:54 2016 jordan barbé
*/

#include <stdio.h>
#include <stdlib.h>
#include "bsq.h"

int		return_col(t_bsq *in)
{
  static int	save = 0;
  int		i;

  i = 0;
  while (in->str[i] != '\n' && in->str[i])
    i++;
  if (save != i && save)
    exit(1);
  save = i;
  if (i == 1)
    i = 2;
  return (i - 1);
}
