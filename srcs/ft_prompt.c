/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 18:51:06 by cheron            #+#    #+#             */
/*   Updated: 2014/02/01 14:44:39 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void		ft_put_uname(char **environ);
static void		ft_put_pwd(char **environ);

void			ft_put_prompt(char **environ)
{
	ft_put_uname(environ);
	ft_put_pwd(environ);
}

static void		ft_put_pwd(char **environ)
{
	int				i;
	char			*pwd;
	char			*home;

	i = 0;
	while (environ[i])
	{
		if (ft_strnstr(environ[i], "PWD", 3))
			pwd = ft_strchr(environ[i], '=') + 1;
		if (ft_strnstr(environ[i], "HOME", 4))
			home = ft_strchr(environ[i], '=') + 1;
		i++;
	}
	i = ft_strlen(home);
	if (ft_strnstr(pwd, home, i))
	{
		ft_putstr("[");
		ft_putstr("~");
		ft_putstr(&pwd[i]);
		ft_putstr("]");
	}
	else
		ft_putstr(pwd);
	ft_putstr("~>\033[0m");
}

static void		ft_put_uname(char **environ)
{
	int				i;
	char			*uname;

	i = 0;
	while (environ[i])
	{
		if (ft_strnstr(environ[i], "USER", 4))
			uname = ft_strchr(environ[i], '=') + 1;
		i++;
	}
	ft_putstr("\033[1;1m[");
	ft_putstr(uname);
	ft_putstr("]");
}
