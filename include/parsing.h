/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:20:26 by adjoly            #+#    #+#             */
/*   Updated: 2024/05/04 13:54:02 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef struct s_cmd
{
	char	*cmd;
	char	**argv;
}	t_cmd;

typedef struct s_parsing
{
	
}	t_parsing;

t_cmd	split_cmd(char *cmd_av);

#endif
