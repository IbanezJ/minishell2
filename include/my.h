/*
** my.h for minishell in /home/ibanez_j/PSU_2016_minishell1
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Thu Jan 12 18:54:00 2017 Jean-Alexandre IBANEZ
** Last update Sat Apr  8 14:16:20 2017 Jean-Alexandre IBANEZ
*/

#ifndef MY_H_
# define MY_H_

extern int	g_exit_value;

/*
** struct used for pipe
*/
typedef struct	s_pipe
{
  int	fd[2];
  char	**command;
}		t_pipe;

/*
** cd_back.c
*/
void    my_cd_back(char ***envp);

/*
** getnbr.c
*/
int	my_getnbr(char *str);

/*
** lib my_printf
*/
void	my_printf(char *str, ...);

/*
** main.c
*/
void    free_func(char *s, char *path, char **newarg, char **newenv);
char    **command_point(char *s, char signe);

/*
** execution.c
*/
void    exec_commande(char *path, char *s, char ***envp);
void    choose_exec(char *s, char **newarg, char ***newenv, char *path);
void    exec_all(char **new_command, char ***newenv, char *path);

/*
** basics_disp.c
*/
void    printf_before_space(char *str);
void    my_putstr(char *str);

/*
** good_env_name.c
*/
int     good_env_name(char *str);

/*
** find_path.c
*/
char    *find_path(char **envp, char *path);

/*
** forking.c
*/
void    forking(char **str, char **envp);

/*
** my_cd.c
*/
int     my_cd(char *str, char ***envp);

/*
** my_env.c
*/
int     count_nbenv(char **envp);
char    **my_env(char **envp);
char    *cpy_env(char *newenv, char *env);
void    free_env(char **envp);
void    display_env(char **env);

/*
** my_setenv.c
*/
int     check_exist(char *envp, char *new);
char    **my_setenv(char **envp, char *new, char *value);

/*
** my_setenv_only_one.c
*/
char    **my_setenv_only_one(char **envp, char *new);

/*
** my_unsetenv.c
*/
char    **my_unsetenv(char **envp, char **argv);

/*
** no_env.c
*/
char    **no_env();

/*
** search_command.c
*/
char	*find_command(char **path, char *command);

/*
** strcmp.c
*/
int     my_strcmp(char *s1, char *s2);
int     my_strlen(char *str);

/*
** transfo.c
*/
char    *transfo(char *str);
char    *remove_point(char *str, char point);

/*
** word_tab.c
*/
void    free_tab(char **tab);
char    **put_in_tab(char *str, char search);
char    **wordtab(char *str, char search);
int     count_spaces(char *str, char search);

/*
** get_next_line.c
*/
char    *my_realloc(char *str, int nb);

/*
** pipe.c
*/
int	is_there_pipe(char *str);
void    my_pipe(char *s, char **newarg, char ***newenv, char *path);

#endif
