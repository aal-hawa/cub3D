/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:09:49 by aal-hawa          #+#    #+#             */
/*   Updated: 2025/05/15 14:58:04 by aal-hawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

ssize_t	ft_strclen(const char *s, char to_char)
{
	ssize_t	i;

	i = 0;
	while (s[i] && s[i] != to_char)
		i++;
	if (!s[i])
		return (0);
	if (i == 0)
		i = -1;
	return (i);
}

char	*ft_strccpy(char *str, char to_char)
{
	char	*dest;
	ssize_t	i;

	if (!str)
		return (NULL);
	i = ft_strclen(str, to_char);
	if (i == 0)
		return (NULL);
	if (i == -1)
		return (ft_strdup(""));
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != to_char)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
