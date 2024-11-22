/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envillan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:53:05 by envillan          #+#    #+#             */
/*   Updated: 2024/11/21 16:30:15 by envillan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

unsigned int	get_pixel(t_img *img, int pixel_x, int pixel_y)
{
	return (*(unsigned int *)(img->data + (pixel_x * img->bpp / 8 + pixel_y
				* img->size_line)));
}

void	draw_pixel(t_img *img, int pixel_x, int pixel_y, int pixel_color)
{
	char	*target;

	target = img->data + (pixel_x * img->bpp / 8 + pixel_y * img->size_line);
	*(unsigned int *)target = pixel_color;
}

unsigned int	rgb_to_int(int opacity, int red, int green, int blue)
{
	return (opacity << 24 | red << 16 | green << 8 | blue);
}
