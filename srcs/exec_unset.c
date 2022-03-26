/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 23:08:18 by hel-makh          #+#    #+#             */
/*   Updated: 2022/03/26 23:51:18 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	builtin_unset(char **cmd, char ***envp)
{
	char	**empty_arr;
	int		i;
	int		j;

	empty_arr = ft_calloc (1, sizeof(char *));
	if (!empty_arr)
		return (0);
	i = 1;
	while (cmd[i])
	{
		j = 0;
		printf("hh\n");
		while (*envp[j])
		{
			printf("hh 2\n");
			if (ft_strnstr(*envp[j], cmd[i], ft_strlen(cmd[i]))
				&& *envp[j][ft_strlen(cmd[i])] == '=')
			{
				*envp = ft_replace_arr(*envp, empty_arr, j, 1);
				break ;
			}
			j ++;
		}
		i ++;
	}
	empty_arr = ft_free_2d(empty_arr);
	return (1);
}