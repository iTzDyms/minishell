/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 13:03:28 by cheron            #+#    #+#             */
/*   Updated: 2014/01/24 16:40:20 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include "ft_minishell.h"

static int		ft_getnewsize(t_dat *dat, char **cmd_split);
static char		*envexist(t_dat *dat, char **cmd_split);
static void		ft_newenv(t_dat *dat, char **cmd_split);
static void		ft_replace(char *rep, t_dat *dat, char **cmd_split);

void			ft_setenv(t_dat *dat, char **cmd_split)
{
	char	*ret;

	if ((ret = envexist(dat, cmd_split)))
		ft_replace(ret, dat, cmd_split);
	else
		ft_newenv(dat, cmd_split);
}

static void		ft_replace(char *rep, t_dat *dat, char **cmd_split)
{
	int		size;
	char	**new;
	int		i;

	i = 0;
	size = ft_getnewsize(dat, cmd_split) - ft_strlen(rep);
	new = malloc(sizeof(char **) * size + 1);
	while (dat->env[i])
	{
		if ((rep == dat->env[i]))
		{
			if (cmd_split[1])
			{
				new[i] = ft_strdup(cmd_split[1]);
				new[i] = ft_strfjoin(new[i], "=");
			}
			if (cmd_split[2])
				new[i] = ft_strfjoin(new[i], cmd_split[2]);
		}
		else
			new[i] = ft_strdup(dat->env[i]);
		i++;
	}
	dat->env = new;
}

static int		ft_getnewsize(t_dat *dat, char **cmd_split)
{
	int		size;
	int		i;

	i = 0;
	size = 0;
	while (dat->env[i])
	{
		size += ft_strlen(dat->env[i]);
		i++;
	}
	i = 1;
	while (cmd_split[i])
	{
		size += ft_strlen(cmd_split[i]);
		i++;
	}
	return (size);
}

static char		*envexist(t_dat *dat, char **cmd_split)
{
	int		i;
	size_t	len;
	char	*ret;

	i = 0;
	if (!cmd_split[1])
		return (NULL);
	len = ft_strlen(cmd_split[1]);
	while (dat->env[i]
		   && (ret = ft_strnstr(dat->env[i], cmd_split[1], len)) == NULL)
		i++;
	return (ret);
}

static void		ft_newenv(t_dat *dat, char **cmd_split)
{
	int		size;
	char	**new;
	int		i;

	i = 0;
	size = ft_getnewsize(dat, cmd_split);
	new = malloc(sizeof(char **) * size + 1);
	while (dat->env[i])
	{
		new[i] = ft_strdup(dat->env[i]);
		i++;
	}
	if (cmd_split[1])
	{
		new[i] = ft_strdup(cmd_split[1]);
		new[i] = ft_strfjoin(new[i], "=");
	}
	if (cmd_split[2])
		new[i] = ft_strfjoin(new[i], cmd_split[2]);
	dat->env = new;
}
