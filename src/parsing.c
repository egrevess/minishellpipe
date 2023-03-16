/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmagrevesse <emmagrevesse@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:29:54 by viburton          #+#    #+#             */
/*   Updated: 2023/03/08 15:50:50 by emmagrevess      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

#include <stdio.h>		// A retirer !!!

int	check_pipe(t_struc *s, t_pipe *p)
{
	int	i;

	i = 0;
	if (p->nb_pipe == 0)
		return (0);
	else 
	{
		while(s->pars[i])
		{
			if (s->pars[i][0] == '|' && (int) ft_strlen(s->pars[i]) > 1)
				return(1);
			i++;
		}
	}
	return (0);
}

int	len_pars(char **pars)
{
	int	i;

	i = 0;
	while (pars[i])
	{
		i++;
	}
	return (i);
}

int	ft_count_pipe(char **line, t_pipe *p)
{
	int	i;
	int	j;
	int	nb;
	int check;
	int	len;
	
	i = 0;
	nb = 0;
	while (line[i])
	{
		check = -2;
		j = 0;
		len = ft_strlen(line[i]);
		while (line[i][j])
		{
			if (line[i][j] == '|' && len > 1)
			{
				if (check != j - 1 && j != 0)
					nb++;
				check = j;
			}
			else if (check != -2 && line[i][j - 1] == '|' && line[i][j] != '|')
				nb++;
			j++;
		}
		i++;
	}
	p->nb_pipe = nb;
	return (nb);
}

char	**ft_pipe(t_struc *s, t_pipe *p)
{
	int		i;
	int		j;
	int		until;
	int		start;
	int 	nb_pipe;
	char	**temp;
	int		index;

	j = 0;
	i = 0;
	index = 0;
	nb_pipe = ft_count_pipe(s->pars, p);
	if (nb_pipe > 0)
	{
		temp = malloc(sizeof(*temp) * (s->size_pars + nb_pipe + 1));
		if (!temp)
			exit(EXIT_FAILURE);
		while (s->pars[i])
		{
			j = 0;
			while (j <= ((int) ft_strlen(s->pars[i]) - 1))
			{
				nb_pipe = 0;
				if (s->pars[i][j] != '|')
				{
					until = 0;
					start = j;
					while(s->pars[i][j])
					{
						if (s->pars[i][j] == '|')
							break;
						j++;
					}
					temp[index] = malloc(sizeof(*temp[index]) * (j - start + 1));
					while (j > start)
					{
						temp[index][until] = s->pars[i][start];
						until++;
						start++;
					}
					temp[index][until] = '\0';
					index++;
				}
				else if (s->pars[i][j] == '|')
				{
					until = 0;
					while(s->pars[i][j] == '|')
					{
						nb_pipe++;
						j++;
					}
					temp[index] = malloc(sizeof(*temp[index]) * (nb_pipe + 1));
					while (nb_pipe > 0)
					{
						temp[index][until] = '|';
						nb_pipe--;
						until++;
					}
					temp[index][until] = '\0';
					index++;
				}
			}
			i++;
		}
		temp[index] = NULL;
		//free(s->pars);
		return (temp);
	}	
	else 
		return (s->pars);
}


char    **ft_parse(char *str)
	{
		char **line;
		int i =0;
		
		line = ft_split(str, ' ');
		while (line[i])
		{
			//printf("%s\n", line[i]);
			i++;
		}
		return (ft_split(str, ' '));
	}
	