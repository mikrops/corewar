/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:18:13 by mmonahan          #+#    #+#             */
/*   Updated: 2020/11/04 08:11:55 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Проверка параметров.
**	повторяемые флаги игнорируются
*/

#include "corewar.h"

int	check_name_player(char *player)
{
	int length;

	length = ft_strlen(player);
	if (ft_strstr(&player[length - 4], ".cor"))
		return (0);
	else
		return (1);
}

int	check_flag_n_old(int count, char **player)
{
	int	i;
	int param_n;
	int count_param;

	i = 1;
	param_n = 0;
	count_param = 0;
	while (i < count)
	{
		if (!ft_strcmp(player[i], "-n"))
		{
			if (i >= count - 2)
			{
				printf("--Неверное фладение флагом!--\n");
				exit(1); //ошибка, когда флаг стоит не на своем месте.
			}
			count_param++;
		}
		else if (!ft_strcmp(player[i - 1], "-n"))
		{
			param_n = ft_atoi(player[i]);
			if (param_n < 1 || param_n > MAX_PLAYERS)
			{
				printf("-- Неверный 1-й параметр [%i] флага n!--\n", param_n);
				exit(3); //ошибка, неверный первый параметр флага n
			}
			count_param++;
		}
		else if (i > 1 && ft_strcmp(player[i - 2], "-n"))
		{
			if (check_name_player(player[i]))
			{
				printf("--Неверный 2-й параметр [%s] флага n!--\n", player[i]);
				exit(4); //ошибка, неверный второй параметр флага n
			}
		}
		else if (check_name_player(player[i]))
		{
			printf("--Неверное имя [%s] файла!--\n", player[i]);
			exit(5); //ошибка, неверный второй параметр флага n
		}
		i++;
	}
	return (count_param);
}

void	check_count_players_old(int count, char **player)
{
	int	i;
	int param_flag;

	i = 1;
	param_flag = 0;
	if (count == 1)
	{
		printf("Нет игроков\n");
		return ;//запуск функции обработки ошибки //ошибка, т.к. нет игроков
	}
	param_flag = check_flag_n_old(count, player);
	if (count - 1 > MAX_PLAYERS + param_flag)
	{
		printf("Слишком много игроков\n");
		return ;//запуск функции обработки ошибки //ошибка, т.к. игроков
		// больше чем MAX_PLAYERS
	}
	while (i < count)
	{
		printf("%s\n", player[i]);
		i++;
	}
}

void	check_param(int count, char **players)
{
	check_count_players_old(count, players);

	int	i;
	int count_param;
	int count_players;

	i = 1;
	count_param = 0;
	count_players = 0;
	while (i < count)
	{
		count_param++;		// += check_flag(count, players);
		count_players++;	// += check_count_players_old(count, players);
		i++;
	}
}