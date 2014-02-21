/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 14:14:33 by cheron            #+#    #+#             */
/*   Updated: 2014/02/02 15:52:06 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_minishell.h"

void	ft_check_cd(char *dir)
{
	if (access(dir, F_OK) == -1)
	{
		write(2, "cd: no such file or directory: ", 31);
		ft_putendl_fd(dir, 2);
	}
	else if (access(dir, R_OK) == -1)
	{
		write(2, "cd: permission denied: ", 23);
		ft_putendl_fd(dir, 2);
	}
	else if (access(dir, X_OK) == -1)
	{
		write(2, "cd: not a directory: ", 21);
		ft_putendl_fd(dir, 2);
	}
}

int		check_error(char **cmd_split, int check)
{
	if ((cmd_split[3] != NULL) && (cmd_split[2] != NULL))
	{
		ft_putstr_fd("cd: too many arguments: ", 2);
		return (-1);
	}
	else if (cmd_split[2] != NULL)
	{
		if (check == 1)
			return (0);
		ft_putstr_fd("cd: string not in pwd: ", 2);
		ft_putendl_fd(cmd_split[1], 2);
		return (1);
	}
	return (0);
}

int		ft_builtin_cd(t_dat *dat, char **cmd_split)
{
	int		i;

	i = 0;
	while ((dat->env[i] != NULL) && (ft_strncmp(dat->env[i], "PWD=", 3) != 0))
		i++;
	if (dat->env[i] == NULL)
	{
		ft_putendl_fd("Error PWD not found", 2);
		return (1);
	}
	i = 0;
	while ((dat->env[i] != NULL) && (ft_strncmp(dat->env[i], "OLDPWD=", 6) != 0))
		i++;
	if (dat->env[i] == NULL)
	{
		ft_putendl_fd("Error OLDPWD not found", 2);
		return (1);
	}
	ft_cd(dat, cmd_split);
	return (1);
}
