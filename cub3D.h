/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:07:00 by aal-hawa          #+#    #+#             */
/*   Updated: 2025/05/15 19:38:42 by aal-hawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D
# define CUB3D

# include "mlx_mac/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
// # include <errno.h>
# include <fcntl.h>
// #include <stdio.h>

typedef struct s_enemy
{
	void			*m;
}					t_enemy;

typedef struct s_enemes
{
	int				x;
	int				y;
	struct s_enemes	*next;
}					t_enemes;

typedef struct s_color_rgb
{
	int				r;
	int				g;
	int				b;
}	t_color_rgb;

typedef struct s_info
{
	int				is_hv_plr;
	int				is_hv_ext;
	int				cnt_collc;
	int				is_arnd_wall;
	int				x_lngth_mp;
	int				y_lngth_mp;
	int				is_f_m_l;
	int				sz;
	void			*mlx;
	void			*win;
	void			*img;
	int				x_plr;
	int				y_plr;
	char			facing_plr;
	void			*img_plr;
	char			**map;
	void			*img_wl;
	void			*img_wlk;
	void			*img_collc;
	void			*img_ext;
	int				is_hv_err;
	int				steps;
	int				is_bonus;
	int				i_enemy;
	int				ofset;
	int				is_plus;
	int				number_of_elemnts;
	char			*north_path;
	char			*south_path;
	char			*west_path;
	char			*east_path;
	t_color_rgb		floor_color;
	t_color_rgb		ceiling_color;
	t_enemy			m[7];
	t_enemes		*enemes;
}					t_info;

typedef struct s_point
{
	int				x;
	int				y;
}					t_point;

void				exitmassege(char *error, t_info *info);
void				map_pars_main(int fd, t_info *info);
int					keys_hook(int key_code, t_info *info);
void				put_imgs_to_wind(t_info *info);
int					close_win(t_info *info);
int					animited_enemy(t_info *info);
void				print_steps(t_info *info);
void				what_img_ptr(char char_pos, t_info *info);
void				flood_fill(char **tab, t_point size, t_point begin,
						char to_flood);
void				data_map(char *test_line_map, t_info *info);
int					ft_strlen(const char *s);
void				ft_putstr_fd(char *s, int fd, int is_malloc);
void				can_get_it(t_info *info, char to_flood);
char				*get_next_line(int fd, t_info *info);
char				*ft_strdup_line(char *str, int eof);
char				*ft_strdup_after_line(char *str);
char				*ft_strjoin(char *s1, char *s2);
char				*free_char(char *this_string);
int					open_map_fd(char *name_map, t_info *info);
void				move_up(t_info *info);
void				move_down(t_info *info);
void				move_right(t_info *info);
void				move_left(t_info *info);
void				init_info(t_info *info);
void				is_win(int y, int x, t_info *info);
void				is_lose(int y, int x, t_info *info);
char				**ft_split(char const *s, char c);
char				*ft_strdup(const char *str);
int					ft_array2d_len(char **array2d);
int					ft_atoi(const char *str);
void				header_parsing(char **test_line_map, t_info *info);
void 				c_value(char **array2d, t_info *info);
void 				f_value(char **array2d, t_info *info);
char				*ft_strccpy(char *str, char to_char);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strccmp(const char *s1, const char *s2, char c);
char				*ft_restore_value(char **dest, char **str, int is_str_malloc);
char				*join_with_restore(char **dst, char *s1, char *s2, char *s3);
char				**add_in_array2d(char ***array2d, char *add_str);
void				free_array2d(char ***dst, size_t i);
int					len_array2d(char **array2d);

#endif