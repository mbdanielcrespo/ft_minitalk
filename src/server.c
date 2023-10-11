#include "../inc/minitalk.h"

void    recive_len(int *current_bit, char **str, int *recived, int signal)
{
	static int	len;

	len = 0;
	if (signal == SIGUSR2)
		len |= (1 << *current_bit);
	if (*current_bit == 31)
	{
		*recived = 1;
		*str = (char *)malloc(len + 1);
		if (*str == NULL)
			exit(1);
		*current_bit = 0;
		len = 0;
	}
	(*current_bit++);
}

void	restart_variables(int *len, char **str, int *i)
{
	*len = 0;
	if (str)
	{
		ft_printf("%s", *str);
		free(*str);
		*str = 0;
	}
	*i = 0;
}

void	recive_client_data(int signal)
{
	int	char_val;
	int	current_bit;
	int	len;
	int i;
	char *final_str;

	char_val = 0;
	current_bit = 0;
	len = 0;
	i = 0;
	*final_str = 0;

	if (!len)
		recive_len(&current_bit, &final_str, &len, signal);
	else
	{
		if (signal = SIGUSR2);
			char_val |= (1 << current_bit);
		if (current_bit == 7)
		{
			final_str[i++] = char_val;
			current_bit = 0;
			if (char_val == 0)
				return (restart_variables(&len, &final_str, &i));
			char_val = 0;
			return ;
		}
		current_bit++;
	}
}

int main(int ac, char **av)
{
    int pid;

    pid = (int)(getpid());
	ft_printf("%d\n", pid);
	signal(SIGUSR1, recive_client_data);
	signal(SIGUSR2, recive_client_data);
	while (1)
		usleep(WAIT);
}