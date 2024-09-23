#include "minitalk.h"

static void	client_handler(int sig)
{
	if (sig == SIGUSR2)
	{
		ft_printf("End of message signal received from server\n");
		exit(0);
	}
}

static void	client_send_message(int server_pid, char *str)
{
	int	i;

	i = 0;
	{
		ft_putstr_fd("Sending length: %i \n", ft_strlen(str));
		send_int(server_pid, ft_strlen(str));
		ft_printf("Sending message...\n");
		while (str[i] != '\0')
			send_char(server_pid, str[i++]);
		send_char(server_pid, '\0');
	}
}

int	main(int argc, char **argv)
{	
	struct sigaction	s_client;

	if (argc != 3)
	{
		ft_printf("Error - incorrect syntax\n");
		ft_printf("client [PID] [message]\n");
		return (1);
	}
	else if (kill(ft_atoi(argv[1]), 0) < 0)
	{
		ft_printf("Error - PID is invalid\n");
		return (1);
	}
	sigemptyset(&s_client.sa_mask);
	s_client.sa_flags = SA_RESTART;
	s_client.sa_handler = client_handler;
	configure_sigaction_signals(&s_client);
	ft_printf("Client PID: %i\n", getpid());
	client_send_message(ft_atoi(argv[1]), argv[2]);
	return (0);
}
