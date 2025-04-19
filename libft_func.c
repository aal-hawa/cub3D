/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:08:25 by aal-hawa          #+#    #+#             */
/*   Updated: 2024/10/20 14:24:44 by aal-hawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlen_line(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] && s[i] == '\n')
		i++;
	return (i);
}

char	*ft_strdup_line(char *str, int eof)
{
	char	*dst;
	size_t	i;
	size_t	len;

	i = 0;
	while (str[i] && str[i] != '\n' && eof == 1)
		i++;
	if (!str[i] && eof == 1)
		return (NULL);
	len = ft_strlen_line(str);
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strdup_after_line(char *str)
{
	char	*dst;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!str)
		return (NULL);
	len = ft_strlen(str) - ft_strlen_line(str);
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] && str[i] == '\n')
		i++;
	while (str[i])
		dst[j++] = str[i++];
	dst[j] = '\0';
	free_char(str);
	return (dst);
}

void	ft_putstr_fd(char *s, int fd, int is_malloc)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	if (is_malloc == 2 || is_malloc == -1)
		write(fd, "\n", 1);
	if (is_malloc == 1 || is_malloc == 2)
		free_char(s);
}
