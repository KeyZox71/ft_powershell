/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redir_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:48:41 by adjoly            #+#    #+#             */
/*   Updated: 2024/06/30 17:34:47 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "tokenizer.h"
#include "execution.h"
#include <fcntl.h>
#include "minishell.h"
#include <stdio.h>
#include "libft.h"

t_cmd	*get_redir_fd(void *content)
{
	t_list			*tmp;
	t_redir_sign	sign[2];
	t_cmd			*cmd;

	tmp = ((t_token *)content)->redirection;
	cmd = NULL;
	sign[0] = INFILE;
	sign[1] = OUTFILE;
	cmd = ft_calloc(sizeof(t_cmd), 1);
	while (tmp)
	{
		open_redir((t_redirection *)tmp->content, cmd, sign);
		tmp = tmp->next;
	}
	if (sign[0] == INFILE)
		cmd->outfile = STDOUT_FILENO;
	if (sign[1] == OUTFILE)
		cmd->infile = STDIN_FILENO;
	cmd = split_cmd(((t_token *)content)->argv, cmd);
	return (cmd);
}
