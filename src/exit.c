/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmagrevesse <emmagrevesse@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:00:01 by emmagrevess       #+#    #+#             */
/*   Updated: 2023/03/14 18:33:37 by emmagrevess      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	ft_exit(void)
{
	exit(EXIT_SUCCESS);
}

int	ft_atoi_em(const char *str, int *check)
{
	long int	i;
	long		nb;
	long int	neg;

	i = 0;
	nb = 0;
	neg = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1 * neg;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = str[i] + (nb * 10) - 48;
		i++;
	}
	if (str[i] || i == 0)
		(*check) = 1;
	return (nb * neg);
}

void	ft_exit_par(t_struc *s)
{
	int	check;

	check = 0;
	if (s->size_pars > 2)
		printf("exit\nminishell: exit: too many arguments\n");
	else if (s->size_pars == 2)
	{
		ft_atoi_em(s->pars[1], &check);
		if (check == 1)
		{
			printf("exit\nminishell: exit: ");
			printf("%s: numeric argument required\n", s->pars[1]);
		}
		else if(check == 0)
			printf("exit\n");
	}
	exit(EXIT_SUCCESS);
}