/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 14:00:21 by cheron            #+#    #+#             */
/*   Updated: 2014/02/02 16:26:41 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "ft_minishell.h"

static void	ft_change_env(t_dat *dat)
{
	int		i;
	int		j;
	char	**cmd_split;
	char	*cut;

	i = 0;
	while (ft_strncmp(dat->env[i], "PWD=", 4) != 0)
		i++;
	j = 0;
	while (ft_strncmp(dat->env[j], "HOME=", 5) != 0)
		j++;
	cmd_split = (char **) malloc(sizeof(char *) * 3);
	cmd_split[0] = ft_strdup("setenv");
	cmd_split[1] = ft_strdup("OLDPWD");
	cmd_split[2] = ft_strdup(&(dat->env[i][4]));
	ft_setenv(dat, cmd_split);
	free(cmd_split[2]);
	cmd_split[1] = "PWD\0";
	cmd_split[2] = NULL;
	cmd_split[2] = getcwd(cmd_split[2], 0);
	if ((cut = strstr(cmd_split[2], &(dat->env[j][5]))))
		cmd_split[2] = cut;
	ft_setenv(dat, cmd_split);
}

static void	ft_change_dir(t_dat *dat, char **cmd_split)
{
	DIR		*dir;

	dir = opendir(cmd_split[1]);
	if (dir == NULL)
		ft_check_cd(cmd_split[1]);
	else
	{
		chdir(cmd_split[1]);
		closedir(dir);
		ft_change_env(dat);
	}
}

static void	ft_check_cmd_split(t_dat *dat, char **cmd_split)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!check_error(cmd_split, 2))
	{
		if ((ft_strcmp(cmd_split[1], "-") != 0))
			ft_change_dir(dat, cmd_split);
		else
		{
			while (ft_strncmp(dat->env[i], "OLDPWD=", 7))
				i++;
			tmp = ft_strdup(&(dat->env[i][7]));
			chdir(tmp);
			ft_change_env(dat);
		}
	}
}


void		ft_cd(t_dat *dat, char **cmd_split)
{
	int		i;
	int		bol;

	bol = 0;
	i = 0;
	if (check_error(cmd_split, 1))
		return ;
	if ((cmd_split[1] == NULL) || (ft_strcmp(cmd_split[1], "~") == 0))
	{
		while ((dat->env[i]) && (bol == 0))
		{
			if (ft_strncmp(dat->env[i], "HOME=", 5) != 0)
				i++;
			else
			{
				chdir(&(dat->env[i][5]));
				ft_change_env(dat);
				bol = 1;
			}
		}
	}
	else
		ft_check_cmd_split(dat, cmd_split);
}
