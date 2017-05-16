/*
** basic.c for basic func in /home/barbe_j/rendu/CPE_BSQ_2015
** 
** Made by jordan barbé
** Login   <barbe_j@epitech.net>
** 
** Started on  Wed Aug 10 15:43:28 2016 jordan barbé
** Last update Wed Aug 10 17:04:13 2016 jordan barbé
*/

#include <unistd.h>
#include "bsq.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int	my_puterror(char *str)
{
  write(2, str, my_strlen(str));
  return (-1);
}

static void	my_check(char *str, int *cpt, int *compt)
{
  while (str[*cpt] == '+' || str[*cpt] == '-')
    {
      if (str[*cpt] == '-')
        *compt = *compt + 1;
      *cpt = *cpt + 1;
    }
}

int	my_getnbr(char *str)
{
  long	result;
  int	cpt;
  int	compt;

  compt = 0;
  result = 0;
  cpt = 0;
  my_check(str, &cpt, &compt);
  while (str[cpt] && str[cpt] >= '0' && str[cpt] <= '9')
    {
      result = (result * 10) + (str[cpt] - 48);
      if ((result > 2147483647 && !(compt % 2 == 1)) ||
	  (result > 2147483648 && (compt % 2 == 1)))
        return (0);
      cpt = cpt + 1;
    }
  if (compt % 2 == 1)
    result = result * -1;
  return (result);
}
