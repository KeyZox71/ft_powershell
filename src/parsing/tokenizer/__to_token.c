/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __to_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 21:05:04 by adjoly            #+#    #+#             */
/*   Updated: 2024/05/26 17:39:37 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"
#include "parsing.h"

size_t	__get_sizeof_redir(char *redir_s, t_redirection *redir)
{
	size_t	i;
	char	*tmp;

	if (!redir_s || !redir)
		return (0);
	if (redir->sign == HEREDOC)
		return (1);
	else if (redir->sign == OUT_APPEND)
		i = 1;
	else
		i = 0;
	if (!redir->file_name)
		return (i);
	tmp = redir_s;
	if (!i)
		i++;
	if (*tmp && *tmp == ' ')
		i++;
	i += ft_strlen(redir->file_name);
	return (i);
}

t_token	*__to_token(char *cmd)
{
	t_token			*token;
	t_redirection	*tmp_redir;
	char			*tmp;

	token = ft_calloc(sizeof(t_token), 1);
	token->argv = ft_calloc(sizeof(t_token), 1);
	tmp = cmd;
	while (*tmp)
	{
		if (*tmp == '<' || *tmp == '>')
		{
			tmp_redir = __to_redir(tmp);
			ft_lstadd_back(&(token->redirection), ft_lstnew((void*)tmp_redir));
			tmp += __get_sizeof_redir(tmp, tmp_redir);
		}
		else
			token->argv = ft_strjoin(token->argv, ft_substr(tmp, 0, 1));
		tmp++;
	}
	return (token);
}
