/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:38:04 by danalmei          #+#    #+#             */
/*   Updated: 2023/04/18 16:01:07 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_i32	ft_isprint(t_i32 c)
{
	if (c < 32 || c > 126)
	{
		return (0);
	}
	return (1);
}
