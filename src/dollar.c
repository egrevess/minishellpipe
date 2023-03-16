/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmagrevesse <emmagrevesse@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:49:41 by emmagrevess       #+#    #+#             */
/*   Updated: 2023/03/15 14:12:25 by emmagrevess      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

/*

int	ft_find_in_env_dollar(t_struc *s, int index)
{
	int		i;
	char	*par;
	int		check;

	check = 1;
	s->size_second_pars = (int) ft_strlen(s->pars[index]);
	par = malloc(sizeof(*par) * (s->size_second_pars));
	if (!par)
		exit (EXIT_FAILURE);
	par = ft_memcpy(par,&s->pars[index][1], (size_t) (s->size_second_pars - 1)); //cherche la dernière occurence de $
	i = 0;
	while (s->env[i])
	{
		if (ft_strncmp(s->env[i], par , (size_t) (s->size_second_pars - 1)) == 0
			&& (s->size_second_pars - 1) == (int) (ft_strrchr((const char*) s->env[i], '=') - s->env[i]))
		{
			check = 0;
			break;
		}
		i++;
	}
	return (check);
}


void	ft_dollar(t_struc *s)
{
	if (ft_find_in_env_dollar(s, 0) == 0)
	{
		printf("minishell: ");
		ft_find_in_env(s, 0);
		printf(": command not found\n");
	}
	else
		printf("");	
}

void	ft_find_in_env(t_struc *s, int index)
{
	int		i;
	int		j;
	char	*par;

	s->size_second_pars = (int) ft_strlen(s->pars[index]);
	par = malloc(sizeof(*par) * (s->size_second_pars));
	if (!par)
		exit (EXIT_FAILURE);
	par = ft_memcpy(par,&s->pars[index][1], (size_t) (s->size_second_pars - 1)); //cherche la dernière occurence de $
	i = 0;
	j = 0;
	while (s->env[i])
	{
		if (ft_strncmp(s->env[i], par , (size_t) (s->size_second_pars - 1)) == 0
			&& (s->size_second_pars - 1) == (int) (ft_strrchr((const char*) s->env[i], '=') - s->env[i]))
		{
			j = -1;
			break;
		}
		i++;
	}
	if (j == -1)
	{
		j = ft_strrchr((const char*) s->env[i], '=') - s->env[i];
		while (s->env[i][j++])
			printf("%c", s->env[i][j]);
	}
}
*/