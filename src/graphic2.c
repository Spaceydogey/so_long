/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:56:39 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/22 17:42:05 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_pixel_color(t_img src, t_img dst, t_pixel pxl)
{
	char	*pxl_addr;
	t_uint	clr;

	pxl_addr = dst.addr + ((pxl.y_fr)
			* dst.line_len + (pxl.x_fr) * (dst.bpp / 8));
	clr = *(t_uint *)(src.addr + (pxl.y_sp * src.line_len
				+ pxl.x_sp * (src.bpp / 8)));
	if (clr != 4278190080)
		*(t_uint *)pxl_addr = clr;

}
