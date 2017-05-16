/*
** get_next_line.c for get in /home/barbe_j/rendu/CPE_BSQ_2015/CPE_2015_BSQ
** 
** Made by jordan barbé
** Login   <barbe_j@epitech.net>
** 
** Started on  Thu Aug 11 18:06:27 2016 jordan barbé
** Last update Tue Aug 16 22:22:55 2016 jordan barbé
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

static int		main_get(char *str)
{
  t_fd			in;

  in.i = 0;
  if (!str)
    return (0);
  while (str[in.i])
    {
      if (str[in.i] == ENTER)
	return (1);
      in.i++;
    }
  return (0);
}

static t_fd		*create(t_fd **pile_fd, int fd)
{
  t_fd			*tmp;
  t_fd			*new;

  tmp = *pile_fd;
  if (tmp && tmp->fd == fd)
    return (tmp);
  while (tmp && (tmp = tmp->next) != *pile_fd)
    if (tmp->fd == fd)
      return (tmp);
  new = NULL;
  if (!(new = malloc(sizeof(t_fd))))
    return (NULL);
  new->str = NULL;
  new->fd = fd;
  if (*pile_fd)
    {
      new->next = *pile_fd;
      tmp = *pile_fd;
      while (tmp->next != *pile_fd)
	tmp = tmp->next;
      tmp->next = new;
    }
  else
    new->next = new;
  return (new);
}

static int		add_str_to(char **dest, char *src)
{
  t_fd			in;

  in.i = 0;
  in.j = 0;
  src[READ_SIZE] = BACK;
  while (*dest && (*dest)[in.i])
    in.i++;
  while (src[in.j++]);
  in.i = in.i + in.j;
  if (!(in.tmp = malloc(sizeof(char) * (in.i + 1))))
    return (1);
  in.i = 0;
  while (*dest && (*dest)[in.i])
    in.tmp[in.i] = (*dest)[in.i++];
  in.j = 0;
  while (src[in.j])
    in.tmp[in.i++] = src[in.j++];
  in.tmp[in.i] = 0;
  in.tmp2 = *dest;
  free(in.tmp2);
  *dest = in.tmp;
  return (0);
}

static char		*get_next(char **str, char **to_return)
{
  char			*new_str;
  t_fd			in;

  in.i = 0;
  in.j = 0;
  while ((*str)[in.i] != ENTER)
    in.i++;
  while ((*str)[in.i] && (*str)[in.i + in.j])
    in.j++;
  if (!(new_str = malloc(sizeof(char) * (in.j + 1))))
    return (NULL);
  if (!(*to_return = malloc(sizeof(char) * (in.i + 1))))
    return (NULL);
  (*to_return)[in.i] = 0;
  in.i = 0;
  while ((*str)[in.i] != ENTER && (*str)[in.i])
    (*to_return)[in.i] = (*str)[in.i++];
  new_str[in.j] = 0;
  in.j = 0;
  while ((*str)[++in.i])
    new_str[in.j++] = (*str)[in.i];
  new_str[in.j] = 0;
  free(*str);
  return (new_str);
}

char		*get_next_line(const int fd)
{
  char		*ret;
  static t_fd	*in;
  char		*str_tmp;

  if (!(str_tmp = malloc(sizeof(char) * (READ_SIZE + 3))))
    return (NULL);
  if (!(in = create(&in, fd)) || READ_SIZE <= 0)
    return (NULL);
  while (main_get(in->str) == 0)
    {
      if ((in->rd = read(fd, str_tmp, READ_SIZE)) < 0)
	return (NULL);
      (in->rd < READ_SIZE) ? (str_tmp[in->rd] = 0) : (0);
      if (in->rd < READ_SIZE && str_tmp[in->rd - 1] != ENTER)
	str_tmp[in->rd + 1] = 0;
      if (in->rd < READ_SIZE && str_tmp[in->rd - 1] != ENTER)
	str_tmp[in->rd] = ENTER;
      if (((add_str_to(&(in->str), str_tmp)) > 0)
	  || (in->rd == 0 && in->str[0] == ENTER))
	return (NULL);
    }
  free(str_tmp);
  in->str = get_next(&(in->str), &ret);
  return ((!in->str) ? (NULL) : (ret));
}
