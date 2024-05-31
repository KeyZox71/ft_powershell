/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:00:32 by adjoly            #+#    #+#             */
/*   Updated: 2024/05/31 12:57:18 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"

t_cmd	*split_cmd(char *cmd_av, t_cmd *cmd)
{
	char	*tmp;
	char	**split;

	tmp = cmd_av;
	split = ft_split(cmd_av, ' ');
	cmd->cmd = ft_strdup(*split);
	ft_free("a", &split);
	while (*tmp && *tmp == ' ')
		tmp++;
	cmd->argv = ft_strdup(tmp);
	return (cmd);
}
