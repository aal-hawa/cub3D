/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:16:56 by aal-hawa          #+#    #+#             */
/*   Updated: 2025/05/15 21:19:00 by aal-hawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_after_parse(t_info *info)
{
	// if (info->cnt_collc == 0)
	// 	exitmassege("You Must Have At Least One Collectible\n", info);
	if (info->is_hv_plr == 0)
		exitmassege("You Must Have A Player\n", info);
	// if (info->is_hv_ext == 0)
	// 	exitmassege("You Must Have A Exit\n", info);
}

void	surrounded_map(char *test_line_map, t_info *info)
{
	int	i;

	i = 0;
	if (info->is_hv_err == 1)
		return ;
	if (info->is_f_m_l == 0 || info->is_f_m_l == 2)
	{
		while (test_line_map[i])
		{
			if (!(test_line_map[i] == '1' || test_line_map[i] == ' '))
				exitmassege("You Must Arround The Map By Walls\n", info);
			i++;
		}
		info->is_f_m_l++;
	}
	if (!(test_line_map[0] == '1' || test_line_map[0] == ' '))
		exitmassege("You Must Arround The Map By Walls\n", info);
	if (!(test_line_map[ft_strlen(test_line_map) - 1] == '1' || test_line_map[ft_strlen(test_line_map) - 1] == ' '))
		exitmassege("You Must Arround The Map By Walls\n", info);
}

void	after_get_lines(int fd, t_info *info)
{
	check_after_parse(info);
	// if (info->is_hv_err != 1)
	// {
	// 	can_get_it(info, 't');
	// 	can_get_it(info, 's');
	// 	can_get_it(info, 'z');
	// }
	close(fd);
	if (info->is_hv_err == 1)
		exit(1);
}

void	ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	if (src)
	{
		while (src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
}
void	replace_spaces2one(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while(info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			if (info->map[i][j] == ' ')
				info->map[i][j] = '1';
			j++;
		}
		i++;
	}
}

int	check_spaces_allowed(t_info *info)
{
	int	i;
	int	j;
	int	previous_len_x;
	int	next_len_x;
	
	i = 0;
	previous_len_x = ft_strlen(info->map[i]) - 1;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			if (info->map[i][j] == ' ')
			{
				if (info->map[i][j + 1] && !(info->map[i][j + 1] == ' ' || info->map[i][j + 1] == '1'))
					return (1);
				if (j > 0 && !(info->map[i][j - 1] == ' ' || info->map[i][j - 1] == '1'))
					return (1);
				if (i > 0 && previous_len_x >= j && !(info->map[i - 1][j] == ' ' || info->map[i - 1][j] == '1'))
					return (1);
				if (info->map[i + 1])
				{
					next_len_x = ft_strlen(info->map[i + 1]) - 1;
					if (next_len_x >= j && info->map[i + 1] && !(info->map[i + 1][j] == ' ' || info->map[i + 1][j] == '1'))
						return (1);
				}
			
			}
			j++;
		}
		previous_len_x = ft_strlen(info->map[i]) - 1;
		i++;
	}
	return (0);
}

void	map_pars_main(int fd, t_info *info)
{
	char	*test_line_map;

	while (1)
	{
		test_line_map = get_next_line(fd, info);
		if (!test_line_map)
			break ;
		if (info->number_of_elemnts < 6)
			header_parsing(&test_line_map, info);
		else if (info->is_hv_err != 1)
		{
			if (info->x_lngth_mp == -1 && !test_line_map[0])
				continue ;
			info->map =	add_in_array2d(&info->map, test_line_map);
			// ft_strcpy(info->map[info->y_lngth_mp], test_line_map);
			info->y_lngth_mp++;
			// if (info->y_lngth_mp > 27)
			// 	exitmassege("The Length Of (y) It Must Less Or Equal 27\n",
			// 		info);
			if (info->x_lngth_mp == -1)
				info->x_lngth_mp = ft_strlen(test_line_map);
			data_map(test_line_map, info);
			surrounded_map(test_line_map, info);
		}
		test_line_map = free_char(test_line_map);
		test_line_map = NULL;
	}
	if (info->number_of_elemnts < 6)
	{
		exitmassege("header data not compleaed\n", info);
		return ;
	}
	if (!info->map)
	{
		exitmassege("No map data\n", info);
		return ;
	}
	
	 if (check_spaces_allowed(info) == 1)
	 {
		exitmassege("spaces not allowed in this way\n",
					info);
		return ;
	 }
	replace_spaces2one(info);
	after_get_lines(fd, info);
}
