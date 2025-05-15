/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:50:17 by aal-hawa          #+#    #+#             */
/*   Updated: 2025/05/15 14:54:54 by aal-hawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	**array2d_colors(char **array2d)
{
	char	**new_array2d;
	char	**array2d_split;
	int		i;
	int		j;
	
	i = 1;
	while(array2d[i])
	{
		j = 0;
		array2d_split = ft_split(array2d[i], ',');
		while(array2d_split[j])
		{
			new_array2d = add_in_array2d(&new_array2d,array2d_split[j]);
			j++;
		}
		i++;
		free_array2d(&array2d_split, 0);
	}
	return (new_array2d);
}

int	is_valid_color(char *str)
{
	int	number_of_color;
	
	number_of_color = ft_atoi(str);
	if (number_of_color < 0 || number_of_color > 255)
		return (-1);	
	return (number_of_color);
}
void f_value(char **array2d, t_info *info)
{
	char	**new_array2d;
	
	new_array2d = array2d_colors(array2d);
	if (info->floor_color.r != -2)
	{
		exitmassege("You have filled it out before.\n",	info);
		return ;
	}
	if (ft_array2d_len(new_array2d) != 4)
	{
		exitmassege("three numbers only(r, g, b).\n",	info);
		return ;
	}
	info->floor_color.r  = is_valid_color(new_array2d[0]);
	info->floor_color.g  = is_valid_color(new_array2d[1]);
	info->floor_color.b  = is_valid_color(new_array2d[2]);
	if (info->floor_color.r == -1 || info->floor_color.g == -1 || info->floor_color.b == -1)
		exitmassege("invalid number, it is must between 0-255\n",
					info);
	info->number_of_elemnts++;
	
}
void c_value(char **array2d, t_info *info)
{
	char	**new_array2d;
	
	new_array2d = array2d_colors(array2d);
	if (info->ceiling_color.r != -2)
	{
		info->is_hv_err = 1;
		return ;
	}
	if (ft_array2d_len(new_array2d) != 4)
	{
		info->is_hv_err = 1;
		return ;
	}
	info->ceiling_color.r  = is_valid_color(new_array2d[0]);
	info->ceiling_color.g  = is_valid_color(new_array2d[1]);
	info->ceiling_color.b  = is_valid_color(new_array2d[2]);
	if (info->ceiling_color.r == -1 || info->ceiling_color.g == -1 || info->ceiling_color.b == -1)
			exitmassege("invalid number, it is must between 0-255\n",
					info);
	info->number_of_elemnts++;
}