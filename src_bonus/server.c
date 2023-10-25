/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <danalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:26:53 by danalmei          #+#    #+#             */
/*   Updated: 2023/10/25 13:34:58 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

char	*recive_len(int signal, int *rec_len)
{
	static int	i;
	char		*final_str;

	if (i < 31 && signal == SIGUSR1)
		*rec_len = *rec_len + ft_pow(2, i);
	else if (i == 31)
	{
		final_str = ft_calloc(*rec_len + 1, sizeof(char));
		if (!final_str)
			return (NULL);
		i = 0;
		return (final_str);==360153== All heap blocks were freed -- no leaks are possible

	}
	i++;
	return (NULL);
}

int	recive_str(int signal, int message_len, char *final_str)
{
	static int	i;
	static char	ch;
	static int	c;

	if (i < 8 && signal == SIGUSR1)
		ch = ch + (char)ft_pow(2, i);
	i++;
	if (i == 8)
	{
		i = 0;
		final_str[c] = ch;
		ch = 0;
		c++;
		if (c == message_len)
		{
			c = 0;
			return (1);
		}
	}
	return (0);
}

void	recive_client_data(int signal)
{
	static int	message_len;
	static char	*final_str;

	if (final_str == NULL)
	{
		final_str = recive_len(signal, &message_len);
	}
	else if (recive_str(signal, message_len, final_str))
	{
		ft_printf("%s\n", final_str);
		free(final_str);
		final_str = NULL;
		message_len = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = (int)(getpid());
	ft_printf("%d\n", pid);
	signal(SIGUSR1, recive_client_data); 
	signal(SIGUSR2, recive_client_data);
	while (1)
		;
}
