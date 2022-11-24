/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:51:08 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/24 11:45:38 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit_success(t_arg *arg)
{
	destroy_image(arg->mlx, arg->sprites);
	mlx_destroy_image(arg->mlx, arg->frame->img);
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_exit_failure(t_arg *arg)
{
	destroy_image(arg->mlx, arg->sprites);
	mlx_destroy_image(arg->mlx, arg->frame->img);
	exit(EXIT_FAILURE);
	return (0);
}
