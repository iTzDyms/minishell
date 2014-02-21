/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 17:13:34 by cheron            #+#    #+#             */
/*   Updated: 2014/02/21 15:27:19 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <libft.h>
#include <get_next_line.h>
#include "ft_minishell.h"

//static t_dat ft_run_commands(t_dat *dat, char *buf);

int			main(void)
{
	char			*buf;
	int				ret;
	t_dat			dat;

	dat.env = ft_cpenv();
	ft_put_prompt(dat.env);
	while ((ret = get_next_line(0, &buf))
		   && (ft_strcmp(ft_strtrim(buf), "exit") != 0))
	{
		ft_minishell(buf, &dat);
		free(buf);
	}
		//ft_run_commands(&dat, buf);
	if (ret == 0)
		free(buf);
	else if (ret == -1)
		return (1);
	return (0);
}

/*static t_dat	ft_run_commands(t_dat *dat, char *buf)
{
	char	**cmd;
	int		pid;

	cmd = ft_strsplit(buf, ';');
	while (*cmd)
	{
		if (ft_strcmp(ft_strtrim(*cmd), "exit") == 0)
		{
			while (*cmd)
			{
				free(*cmd);
				cmd++;
			}
			exit(0);
		}
		if ((pid = fork()) == -1)
			exit(1);
		if (pid > 0)
			wait(NULL);
		else if ((pid) == 0)
		{
			*dat = ft_minishell(*cmd, dat);
			exit(0);
		}
		free(*cmd);
		cmd++;
	}
	ft_put_prompt(dat->env);
	return (*dat);
}
*/
