/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 14:28:46 by saoh              #+#    #+#             */
/*   Updated: 2021/10/03 14:47:16 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	init_tp(t_pipe *tp, int argc, char **argv)
{
	ft_memset(tp, sizeof(t_pipe));
	tp->in_fd  = open(argv[1], O_RDONLY | O_EXCL);
	if (tp->in_fd < 0)
		return (error_occur(1));
	tp->out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT, 00644);
	if (tp->out_fd < 0)
		return (error_occur(1));
	if (pipe(tp->pipe_fd) < 0)
		return (error_occur(1));
	if (pipe(tp->pipe_tmp_fd) < 0)
		return (error_occur(1));
	tp->cnt_cut = argc - 4;
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe tp;
	int	cnt;

	if (init_tp(&tp, argc, argv))
		return (0);
	if (init_path(&tp, envp))
		return (0);
	cnt = 0;
	while (cnt <= tp.cnt_cut)
	{
		if (start_pipe(&tp, argv, envp, cnt))
			return (0);
		cnt++;
	}
}
