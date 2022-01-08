/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybestrio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 12:37:32 by ybestrio          #+#    #+#             */
/*   Updated: 2022/01/08 18:17:12 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
void	ft_errorhandler1(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Argument count incorrect, abandon the ship\n");
		exit(1);
	}

	ft_emptyarg(argv[1]);
	ft_isber(argv[1]);
//	ft_contentinvalid(argv[1]);
}

void	ft_contentinvalid(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0 && str[i] != '\n')
	{
		ft_checkprechar(str[i]);
		i++;
	}
}

void	ft_emptyarg(char *str)
{

	if (str[0] == 0)
	{
	printf("STOP MESSING WITH THE ARGUMENTS OR IMMA DO CRAZY STUFF");
		exit(1);
	}



}

void	ft_isber(char *str)
{
	int i;
	int k;
	char line[5];

	k = 0;
	i = strlen(str) - 4; // need to put rmy own function
	
	while (str[i] != 0)
	{
		line[k] = str[i];
		i++;
		k++;
	}
		line[k] = 0;

	if(strncmp(line, ".ber", 4) != 0) //need my own strncmp
	{
		printf("ENTER A GODDAMN .ber FILE, UNDERSTOOD ??\n");
		exit(1);
	
	}

}
