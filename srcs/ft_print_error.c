/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 15:00:40 by cheron            #+#    #+#             */
/*   Updated: 2014/02/01 14:19:55 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_minishell.h"

void	ft_print_error(char *cmd, int code)
{
	if (code == 1)
	{
		ft_putstr("ft_minishell: command not found: ");
		ft_putendl(cmd);
	}
}
