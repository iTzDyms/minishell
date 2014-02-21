/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 12:33:28 by cheron            #+#    #+#             */
/*   Updated: 2014/02/21 14:58:04 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	**ft_cpenv(void)
{
	int			size;
	int			i;
	char		**env;
	extern char	**environ;

	i = 0;
	size = 0;
	while (environ[i])
	{
		size += ft_strlen(environ[i]);
		i++;
	}
	if (!*environ)
		ft_fatal("fatal: no environement\n");
	env = malloc(sizeof(char **) * size);
	i = 0;
	while (environ[i])
	{
		env[i] = ft_strdup(environ[i]);
		i++;
	}
	env[i] = '\0';
	return (env);
}
