#include "../inc/minitalk.h"

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0 && power == 0)
		return (1);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}

void	*calloc_exit(size_t count, size_t size)
{
	size_t	total_size;
	void	*ret;

	total_size = size * count;
	ret = malloc(total_size);
	if (!ret)
		exit(1);
	ft_bzero(ret, total_size);
	return (ret);
}

void	restart_variables(int *len, char **str, int *i)
{
	*len = 0;
	printf("Restarting variables ...\n");
	if (str)
	{
		ft_printf("%s", *str);
		free(*str);
		*str = 0;
	}
	*i = 0;
}

void    recive_len(int *current_bit, char **final_str, int *len_recived, int signal)
{
	static int	len_val = 0;

	if (signal == SIGUSR2)
	{
		//printf("Signal is SIGUSR2\n");
		len_val += ft_recursive_power(2, *current_bit);
		printf("Current len (recive len) %d\n", len_recived);
		printf("Final len (recive len) %d\n", len_val);
	}
	if (*current_bit == 31)
	{
		*len_recived = 1;
		*final_str = calloc_exit((len_val + 1), sizeof(char));
		*current_bit = 0;
		len_val = 0;
	}
	(*current_bit)++;
	//ft_printf("Reciving len ...curr_bit: %d\n", current_bit);
}
/*
void	recive_char(int *len, int *current_bit, char **final_str)
{
	int	char_val;
	int	i;

	char_val = 0;
	i = 0;
	if (signal == SIGUSR2);
		{
			char_val |= (1 << *current_bit);
			ft_printf("current_bit: %d, char_val: %c\n", current_bit, char_val);
		}
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
*/

void	recive_client_data(int signal)
{
	static int	char_val = 0;
	static int	current_bit = 0;
	static int	len_recived = 0;
	static int	i = 0;
	static char *final_str = 0;

	printf("Current len (recive client data) %d\n", len_recived);		// Current bit 0 ... 31
	if (!len_recived)
	{
		recive_len(&current_bit, &final_str, &len_recived, signal);
		printf("Current len (after recive len) %d\n", len_recived);		// Current bit 0 ... 31
	}
	else	
	{
		if (signal == SIGUSR2);
		{
			char_val += ft_recursive_power(2, current_bit);
			ft_printf("current_bit: %d, char_val: %c\n", current_bit, char_val);
		}
		if (current_bit == 7)
		{
			final_str[i++] = char_val;
			current_bit = 0;
			if (char_val == 0)
				return (restart_variables(&len_recived, &final_str, &i));
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