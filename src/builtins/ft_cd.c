/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:07:24 by adjoly            #+#    #+#             */
/*   Updated: 2024/06/25 11:22:08 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env.h"
#include "libft.h"
#include "builtins.h"

char	*__get_parent_directory(char *pwd)
{
	char	*tmp;
	char	*dir;
	char	*parent;

	tmp = pwd;
	while (*tmp)
	{
		if (*tmp == '/')
			dir = tmp;
		tmp++;
	}
	parent = ft_calloc(dir - pwd + 1, sizeof(char));
	ft_strlcpy(parent, pwd, dir - pwd + 1);
	return (parent);
}

void	ft_cd(t_env *env, char *args)
{
	char	*pwd;
	char	*new_pwd;
	int		ret;

	new_pwd = NULL;
	pwd = ret_cwd();
	ft_putendl_fd(args, STDOUT_FILENO);
	ft_putendl_fd(pwd, STDOUT_FILENO);
	if (!args)
		new_pwd = env_get_value("HOME", env);
	else if (args[0] == '/')
		new_pwd = ft_strdup(args);
	else if (is_str(args, ".."))
		new_pwd = __get_parent_directory(pwd);
	ft_putendl_fd(new_pwd, STDOUT_FILENO);
	ret = chdir(new_pwd);
	if (ret == -1)
	{
		return ;
	}
	env_edit("PWD", new_pwd, env);
	free(args);
}