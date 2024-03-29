/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:51:08 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/25 14:35:26 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit_success(t_arg *arg)
{
	destroy_image(arg->mlx, arg->sprites);
	mlx_destroy_image(arg->mlx, arg->frame->img);
	mlx_destroy_window(arg->mlx, arg->mlx_win);
	exit(EXIT_SUCCESS);
	return (1);
}

int	ft_exit_failure(t_arg *arg)
{
	destroy_image(arg->mlx, arg->sprites);
	mlx_destroy_image(arg->mlx, arg->frame->img);
	mlx_destroy_window(arg->mlx, arg->mlx_win);
	ft_putstr_fd("Error\n", 1);
	exit(EXIT_FAILURE);
	return (0);
}

int	ft_next(t_arg *arg)
{
	destroy_image(arg->mlx, arg->sprites);
	mlx_destroy_image(arg->mlx, arg->frame->img);
	mlx_destroy_window(arg->mlx, arg->mlx_win);
	if (arg->av)
		execve("so_long", arg->av, NULL);
	else
		exit(EXIT_SUCCESS);
	return (1);
}
