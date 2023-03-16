/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmagrevesse <emmagrevesse@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:33:19 by emmagrevess       #+#    #+#             */
/*   Updated: 2023/03/15 13:51:11 by emmagrevess      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	ft_printf_env(t_struc *s)
{
	int	i;

	i = 0;
	while (s->env[i])
	{
		printf("%s\n", s->env[i]);
		i++;
	}
}

int	ft_init_env(t_struc *s, char **env)
{
	int i;

	i = 0;
	s->env = malloc (sizeof(*s->env) * (240));
	if (!s->env)
		exit(EXIT_FAILURE);
	while (env[i])
	{
		s->env[i] = ft_strdup(env[i]);
		i++;
	}
	s->env[i] = NULL;
	s->lenght_env = i;
	return (1);
}
