/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:08:36 by aal-hawa          #+#    #+#             */
/*   Updated: 2025/05/15 14:08:37 by aal-hawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3D.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_strccmp(const char *s1, const char *s2, char c)
{
	size_t	i;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]) && s1[i] != c && s2[i] != c)
		i++;
	if ((!s1[i] && s2[i] == c) || (!s2[i] && s1[i] == c))
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}