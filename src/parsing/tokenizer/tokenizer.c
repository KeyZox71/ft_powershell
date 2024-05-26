/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:13:50 by adjoly            #+#    #+#             */
/*   Updated: 2024/05/26 17:59:27 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

t_list	*tokenizer(char *readline)
{
	t_list	*token;
	t_list	*piped;
	t_list	*tmp;
	
	piped = __split_pipe(readline);
	token = NULL;
	tmp = piped;
	while (tmp)
	{
		ft_lstadd_back(&token, ft_lstnew((void*)__to_token(tmp->content)));
		tmp = tmp->next;
	}
	return (token);
}
