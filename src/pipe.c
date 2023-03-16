/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmagrevesse <emmagrevesse@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:56:16 by emmagrevess       #+#    #+#             */
/*   Updated: 2023/03/08 16:37:41 by emmagrevess      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	ft_pipes(t_struc *s, t_pipe *p)
{
	if (check_pipe(s,p) == 1)
		printf("Error: syntax error near unexpected token\n");
	else
	{
        
	}
}