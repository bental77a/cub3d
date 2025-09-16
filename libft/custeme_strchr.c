/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custeme_strchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohben-t <mohben-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:15:24 by mohben-t          #+#    #+#             */
/*   Updated: 2025/08/21 16:21:19 by mohben-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int custeme_strchr(const char *s, int c)
{
	char	*ptr;
    int     i;

    i = 0;
	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == (unsigned char)c)
			i++;
		ptr++;
	}
	return (i);
}
