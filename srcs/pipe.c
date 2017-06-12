/*
** pipe.c for minishell in /home/ibanez_j/PSU_2016_minishell2
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Wed Apr  5 15:58:02 2017 Jean-Alexandre IBANEZ
** Last update Mon May  8 15:50:55 2017 Jean-Alexandre IBANEZ
*/

#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

int	is_there_pipe(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '|')
	return (1);
      i++;
    }
  return (0);
}

void	run_source(t_pipe pipes, char **newarg, char *path,
	       char ***newenv)
{
  int	pid;

  pid = fork();
  if (pid == 0)
    {
      dup2(pipes.fd[1], 1);
      close(pipes.fd[0]);
      choose_exec(pipes.command[0],
		  (newarg = put_in_tab(pipes.command[0], ' ')),
		  newenv, path);
      kill(getpid(), SIGTERM);
    }
  else if (pid == -1)
    {
      perror("fork");
      exit(0);
    }
}

void	run_dest(t_pipe pipes, char **newarg, char *path,
	     char ***newenv)
{
  int	pid;

  pid = fork();
  if (pid == 0)
    {
      dup2(pipes.fd[0], 0);
      close(pipes.fd[1]);
      choose_exec(pipes.command[1],
		  (newarg = put_in_tab(pipes.command[1], ' ')),
		  newenv, path);
    }
  else if (pid == -1)
    {
      perror("fork");
      exit(0);
    }
}

void	my_pipe(char *s, char **newarg, char ***newenv, char *path)
{
  int	pid;
  int	status;
  t_pipe	pipes;

  pipes.command = command_point(s, '|');
  pipe(pipes.fd);
  run_source(pipes, newarg, path, newenv);
  run_dest(pipes, newarg, path, newenv);
  close(pipes.fd[0]);
  close(pipes.fd[1]);
  g_exit_value = status;
  while ((pid = wait(&status)) != -1);
}
