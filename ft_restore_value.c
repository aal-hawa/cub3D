/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_restore_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:07:27 by aal-hawa          #+#    #+#             */
/*   Updated: 2025/05/15 14:56:39 by aal-hawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*free_string(char **this_string)
{
	if (!this_string || !*this_string)
		return (NULL);
	free(*this_string);
	*this_string = NULL;
	return (NULL);
}

char	*ft_restore_value(char **dest, char **str, int is_str_malloc)
{
	if (!str || !*str)
		return (*dest);
	*dest = free_string(dest);
	*dest = ft_strdup(*str);
	if (!*dest)
		return (NULL);
	if (is_str_malloc == 1)
		*str = free_string(str);
	return (*dest);
}

char	*join_with_restore(char **dst, char *s1, char *s2, char *s3)
{
	char	*str_join;

	str_join = ft_strjoin(s1, s2);
	*dst = ft_restore_value(dst, &str_join, 1);
	if (s3)
	{
		str_join = ft_strjoin(*dst, s3);
		*dst = ft_restore_value(dst, &str_join, 1);
	}
	return (*dst);
}

char	**add_in_array2d(char ***array2d, char *add_str)
{
	int		i;
	int		j;
	int		len;
	char	**new_array2d;

	i = 0;
	j = 0;
	len = len_array2d(*array2d) + 1;
	new_array2d = malloc(sizeof(char *) * (len + 1));
	if (!new_array2d)
		return (NULL);
	while (*array2d && array2d[0][i])
	{
			new_array2d[j++] = ft_strdup(array2d[0][i++]);
	}
	if (!*array2d)
		new_array2d[j++] = ft_strdup(add_str);
	new_array2d[j] = NULL;
	free_array2d(array2d, len - 1);
	return (new_array2d);
}
