/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmagrevesse <emmagrevesse@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:57:47 by emmagrevess       #+#    #+#             */
/*   Updated: 2023/03/15 14:14:02 by emmagrevess      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

char	*ft_find_pdw(t_struc *s)
{
	s->pwd = malloc(sizeof(*s->pwd) * 1024);
	// je vois pas à quoi sert la taille 1024
	getcwd(s->pwd, 1024);
	if (!s->pwd)
		exit (EXIT_FAILURE);
	return (s->pwd);
}

void	ft_builtins(t_struc *s)
{
	s->size_pars = len_pars(s->pars);
	if (s->size_pars == 1)
	{
		s->size_first_pars = (int) ft_strlen(s->pars[0]);
		//printf("size= %d\n",s->size_first_pars);
		if (ft_strncmp(s->pars[0], "env", (size_t) 3) == 0 && (int) ft_strlen(s->pars[0]) == 3)
			ft_printf_env(s);
		else if(ft_strncmp(s->pars[0], "pwd", (size_t) 3) == 0 && (int) ft_strlen(s->pars[0]) == 3)
			printf("%s\n",s->pwd);
		else if (ft_strncmp(s->pars[0], "echo", (size_t) 4) == 0 && (int) ft_strlen(s->pars[0]) == 4)
			printf("\n");
		else if (ft_strncmp(s->pars[0], "cd", (size_t) 2) == 0 && (int) ft_strlen(s->pars[0]) == 2)
			ft_cd(s);
		else if (ft_strncmp(s->pars[0], "exit", (size_t) 4) == 0 && (int) ft_strlen(s->pars[0]) == 4)
			ft_exit();
		else if (ft_strncmp(s->pars[0], "export", (size_t) 6) == 0 && (int) ft_strlen(s->pars[0]) == 6)
			ft_sort_env(s);
		else 
			ft_execve(s);
	}
	else if (s->size_pars > 1)
	{
		s->size_first_pars = (int) ft_strlen(s->pars[0]);
		//printf("size = %d\n",s->size_first_pars);
		if (ft_strncmp(s->pars[0], "echo", (size_t) 4) == 0 && (int) ft_strlen(s->pars[0]) == 4)
			ft_echo(s);
		else if (ft_strncmp(s->pars[0], "export", (size_t) 6) == 0 && (int) ft_strlen(s->pars[0]) == 6)
			ft_export(s);
		else if (ft_strncmp(s->pars[0], "unset", (size_t) 5) == 0 && (int) ft_strlen(s->pars[0]) == 5)
			ft_unset(s);
		else if (ft_strncmp(s->pars[0], "cd", (size_t) 2) == 0 && (int) ft_strlen(s->pars[0]) == 2)
			ft_cd(s);
		else if (ft_strncmp(s->pars[0], "exit", (size_t) 4) == 0 && (int) ft_strlen(s->pars[0]) == 4)
			ft_exit_par(s);
		else
			ft_execve(s);
	}
}