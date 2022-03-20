/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 11:42:23 by hel-makh          #+#    #+#             */
/*   Updated: 2022/03/19 18:15:26 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

// int	ft_exec_cmdline(t_vars *vars)
// {
// 	pid_t	pid;
// 	int		i;

// 	vars->pipeline = ft_split_pipes(vars->cmdline);
// 	if (!vars->pipeline)
// 		return (0);
// 	vars->cmd_count = ft_arrlen(vars->pipeline);
// 	i = 0;
// 	while (vars->pipeline[i])
// 	{
// 		if (pipe(vars->p) == -1)
// 			return (perror("pipe"), 0);
// 		pid = fork();
// 		if (pid == -1)
// 			return (perror("fork"), 0);
// 		if (pid == 0)
// 			ft_exec_pipeline(vars, i);
// 		waitpid(pid, NULL, 0);
// 		// char buff[100];
// 		// buff[0] = '\0';
// 		// int ret = read(vars->p[STDIN_FILENO], buff, 100);
// 		// buff[ret] = '\0';
// 		// printf("pipe: '%s'\n", buff);
// 		i ++;
// 	}
// 	return (1);
// }

int	main(int argc, char *argv[], char *envp[])
{
	t_vars	vars;

	ft_init_vars(argc, argv, envp, &vars);
	signal(SIGINT, ft_handle_signals);
	signal(SIGQUIT, ft_handle_signals);
	vars.cmdline = ft_strdup("");
	while (vars.cmdline)
	{
		vars.cmdline = ft_free(vars.cmdline);
		vars.cmdline = readline(PROMPT);
		if (!vars.cmdline)
			break ;
		add_history(vars.cmdline);
		ft_tokenization(&vars);
		if (!ft_token_lstsize(vars.tokens))
			continue ;

		t_token	*t_tokens = vars.tokens;
		while (t_tokens)
		{
			printf("%d - '%s'\n", t_tokens->type, t_tokens->data);
			t_tokens = t_tokens->next;
		}
		
		if (!ft_verify_syntax(&vars))
		{
			ft_putendl_fd("Syntax error.", STDOUT_FILENO);
			continue ;
		}
		
		// if (!ft_exec_cmdline(&vars))
		// 	return (ft_free_program(&vars), EXIT_FAILURE);
	}
	ft_free_program(&vars);
	return (EXIT_SUCCESS);
}
