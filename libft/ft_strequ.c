/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:08:56 by msole             #+#    #+#             */
/*   Updated: 2019/09/23 13:38:54 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int i;
	int diff;

	diff = 0;
	i = 0;
	if (s1 && s2)
	{
		while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
			i++;
		diff = s1[i] - s2[i];
		if (diff == 0)
			return (1);
		else
			return (0);
	}
	return (0);
}
