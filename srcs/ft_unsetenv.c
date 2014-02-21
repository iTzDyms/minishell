/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 16:41:56 by cheron            #+#    #+#             */
/*   Updated: 2014/01/24 17:06:34 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "ft_minishell.h"

static int		ft_getnewsize(t_dat *dat, char **cmd_split);

void			ft_unsetenv(t_dat *dat, char **cmd_split)
{
	int		size;
	char	**new;
	int		i;
	int		len;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(cmd_split[1]);
	size = ft_getnewsize(dat, cmd_split);
	new = malloc(sizeof(char **) * size + 1);
	while (dat->env[i])
	{
		if (cmd_split[1] && ft_strncmp(cmd_split[1], dat->env[i], len))
		{
			new[j] = ft_strdup(dat->env[i]);
			j++;
		}
		i++;
	}
	dat->env = new;
}

static int		ft_getnewsize(t_dat *dat, char **cmd_split)
{
	int		size;
	int		i;
	int	len;

	i = 0;
	size = 0;
	len = ft_strlen(cmd_split[1]);
	while (dat->env[i])
	{
		if (cmd_split[1] && ft_strncmp(cmd_split[1], dat->env[i], len))
			size += ft_strlen(dat->env[i]);
		i++;
	}
	return (size);
}
