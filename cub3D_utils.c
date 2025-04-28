/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:39:44 by aal-hawa          #+#    #+#             */
/*   Updated: 2024/10/20 14:24:31 by aal-hawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	exitmassege(char *error, t_info *info)
{
	if (info->is_hv_err == 1)
		return ;
	ft_putstr_fd("Error\n", 1, 0);
	ft_putstr_fd(error, 1, 0);
	info->is_hv_err = 1;
}

void	init_info(t_info *info)
{
	info->is_hv_plr = 0;
	info->is_hv_ext = 0;
	info->cnt_collc = 0;
	info->is_arnd_wall = 0;
	info->x_lngth_mp = -1;
	info->y_lngth_mp = 0;
	info->is_f_m_l = 0;
	info->sz = 50;
	info->is_hv_err = 0;
	info->steps = 0;
	info->is_bonus = 0;
	info->i_enemy = 0;
	info->ofset = 0;
}

void	flood(char **tab, t_point size, t_point cur, char to_flood)
{
	if (cur.x < 0 || cur.y < 0 || cur.x >= size.x || cur.y >= size.y
		|| tab[cur.y][cur.x] == to_flood || tab[cur.y][cur.x] == '1'
		|| (tab[cur.y][cur.x] == 'E' && to_flood == 's')
		|| (tab[cur.y][cur.x] == 'e' && to_flood == 'z'))
		return ;
	tab[cur.y][cur.x] = to_flood;
	flood(tab, size, (t_point){cur.x + 1, cur.y}, to_flood);
	flood(tab, size, (t_point){cur.x - 1, cur.y}, to_flood);
	flood(tab, size, (t_point){cur.x, cur.y - 1}, to_flood);
	flood(tab, size, (t_point){cur.x, cur.y + 1}, to_flood);
}

void	flood_fill(char **tab, t_point size, t_point begin, char to_flood)
{
	flood(tab, size, begin, to_flood);
}

int	open_map_fd(char *name_map, t_info *info)
{
	int		fd;
	char	*comp;
	int		i;
	int		ln;

	i = 4;
	comp = ".cub";
	ln = ft_strlen(name_map);
	if (ln < i)
		exitmassege("Error ending map file extension (.cub)\n", info);
	while (name_map[ln - i])
	{
		if (comp[4 - i] != name_map[ln - i])
			break ;
		i--;
	}
	if (i != 0 || name_map[ln - i])
		exitmassege("Error ending map file extension (.cub)\n", info);
	if (info->is_hv_err == 1)
		exit(1);
	fd = open(name_map, O_RDONLY);
	if (fd == -1)
	{
		exitmassege("Error File Open\n", info);
		exit(1);
	}
	return (fd);
}
