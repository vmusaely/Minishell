/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusaely <vmusaely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/3 16:58:43 by vmusaely          #+#    #+#             */
/*   Updated: 2022/05/8 12:34:17 by vmusaely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_export(int argc, char **argv)
{
	char	**env;
	int		i;
	int		code;

	if (argc < 2)
	{
		env = env_to_string(true);
		argument_print(env, "declare -x ");
		argument_destroy(env);
	}
	i = 1;
	code = 0;
	while (i < argc)
		if (env_from_string(argv[i++]) && code == 0)
			code = 1;
	return (code);
}
