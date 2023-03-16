/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmagrevesse <emmagrevesse@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:29:01 by viburton          #+#    #+#             */
/*   Updated: 2023/03/15 14:18:33 by emmagrevess      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"



/*
void	execut(int sig)
{
	(void) sig;

	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	execut1(int sig)
{
	(void) sig;
	exit (EXIT_FAILURE);
}

void	execut2(int sig)
{
	(void) sig;
	//censé rien faire 
}
*/

int	main(int argc, char **argv, char **env)
{
	char *str;
	int	result;
	t_struc	s;
	t_pipe	p;
	//pid_t	pid;
	//char *arg;
	int		index;
	int i = 1;
	index = 0;

	(void) argv;
	put_head();
	//signal(SIGINT, execut);
	//signal(SIGQUIT,execut);
	if (argc == 1)
	{
		while (42)
    	{
    		str = readline("burtonshell >$ ");
			if (!str)
				ft_exit();
			add_history(str);
			s.pars = ft_parse(str);
			s.pars = ft_pipe(&s, &p);
			if (!s.pars)
				exit(EXIT_FAILURE);
			if (index == 0)
			{
				result = ft_init_env(&s,env);
				if (result == 0)
					exit (EXIT_FAILURE);
			}
			ft_sub_dollar(&s);
			ft_find_pdw(&s);
			if (p.nb_pipe == 0)
				ft_builtins(&s);
			else 
				ft_pipes(&s,&p);
			index++;
			wait(&i);
		}
	}
}
