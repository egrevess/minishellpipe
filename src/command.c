/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmagrevesse <emmagrevesse@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:34:44 by emmagrevess       #+#    #+#             */
/*   Updated: 2023/03/15 12:39:56 by emmagrevess      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	ft_execve(t_struc *s)
{
	pid_t	pid;

	pid = fork ();
	if (pid == 0) //processus enfant 
	{
		if (access(ft_strjoin("/bin/", s->pars[0]), X_OK) == 0)
				execve(ft_strjoin("/bin/",s->pars[0]), s->pars, s->env);
		else if (access(ft_strjoin("/usr/bin/", s->pars[0]), X_OK) == 0)
			execve(ft_strjoin("/usr/bin/",s->pars[0]), s->pars, s->env);
		else if (access(ft_strjoin("/usr/local/bin/", s->pars[0]), X_OK) == 0)
			execve(ft_strjoin("/usr/local/bin/",s->pars[0]), s->pars, s->env);
		else 
			printf("minishell: %s: command not found\n",s->pars[0]);
	}
	else if (pid < 0)
		exit(EXIT_FAILURE);
}