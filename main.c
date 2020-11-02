/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:35:51 by mmonahan          #+#    #+#             */
/*   Updated: 2020/11/02 17:18:13 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argv)
		; //заглушка

	if (argc == 1)
	{
		printf("Нет игроков\n");
		return (1); //ошибка, т.к. нет игроков
	}

	if (argc > MAX_PLAYERS)
	{
		printf("Слишком много игроков\n");
		return (1); //ошибка, т.к. игроков больше чем MAX_PLAYERS
	}

	while(i < argc)
	{
		printf("%s\n", argv[i]);
		i++;
	}

	printf("Hello, corewar!\n");
	return (0);
}
