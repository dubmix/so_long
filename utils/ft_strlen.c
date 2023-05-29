/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:13:58 by pdelanno          #+#    #+#             */
/*   Updated: 2023/05/18 10:14:05 by pdelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
			i++;
	}	
	return (i);
}