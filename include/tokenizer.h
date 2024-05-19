/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:14:15 by adjoly            #+#    #+#             */
/*   Updated: 2024/05/19 14:02:58 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	TOKENIZER_H
# define TOKENIZER_H

# include "libft.h"
# include <stdbool.h>

typedef	enum s_redirection_sign
{
	HEREDOC,
	INFILE,
	OUTFILE,
	OUT_APPEND,
}	t_redirection_sign;

typedef struct s_redirection
{
	char				*file_name;
	t_redirection_sign	sign;
}	t_redirection;

typedef struct s_token
{
	char	*argv;
	t_list	*redirection;
}	t_token;

/**
 * @brief				Convert the raw command into a t_token that contains the argv of the command an a linked list of redirection
 *
 * @param cmd			A string that containt the command to tokenize
 *
 * @return (t_token *)	The tokenized version of the command
 *						
 */
t_token	*__to_token(char *cmd);

/**
 * @brief				**
 *
 * @param 
 *
 * @return ()
 *
 */

/**
 * @brief				Convert the readline output, split all command and put it in linked list of t_token (given by t_token function)
 *
 * @param	readline	The readline output
 *
 * @return	(t_list	*)	Linked list of t_token
 *						
 */
t_list	*tokenizer(char	*readline);	

#endif