/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:18:13 by mmonahan          #+#    #+#             */
/*   Updated: 2020/11/05 09:03:01 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Проверка параметров.
**	Обработка флага -n
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

int	check_count_players_min(int count, char **player, t_core *core)
{
	int	i;
	int max_p;

	i = 1;
	max_p = 0;
	while (i < count)
	{
		if (!check_name_player(player[i]))
		{
			//max_p++;
			core->player[++max_p].number = i;//max_p;
		}
		if (max_p > MAX_PLAYERS)
		{
			printf("--Слишком много игроков!--\n");
			exit(1);
		}
		i++;
	}
	if (max_p < 1)
	{
		printf("--Слишком мало игроков!--\n");
		exit (2);
	}
	return (max_p);
}

int	check_arg_one(int adr, char *value)
{
	int param_n;

	param_n = ft_atoi(value);
	if (param_n < 1 || param_n > MAX_PLAYERS)
	{
		printf("-- Неверный 1-й параметр [%i] флага n!--\n", param_n);
		exit (3); //ошибка, неверный первый параметр флага n
	}
	return (param_n);
}

void	check_arg_two(char *value)
{
	if (check_name_player(value))
	{
		printf("--Неверный 2-й параметр [%s] флага n!--\n", value);
		exit (4); //ошибка, неверный второй параметр флага n
	}
}

void	queue_players(t_core *core, char *queue, int adr, int value)
{
	int	i;

	i = 1;
	while (i <= MAX_PLAYERS + 1)
	{
		if (core->player[i].number == adr)
			queue[i] = (char)value;
		i++;
	}
}

int		check_flag_n_min(int count, char **player, t_core *core)
{
	int		i;
	int		param_n;
	char	queue[MAX_PLAYERS + 1];

	i = 1;
	param_n = 0;
	ft_bzero(queue, MAX_PLAYERS + 1);
	while (i < count)
	{
		if (!ft_strcmp(player[i], "-n"))// && i < count - 2)
		{
			if (i < count - 2)
			{
				param_n = check_arg_one(i, player[i + 1]);
				check_arg_two(player[i + 2]);
				queue_players(core, queue, i + 2, param_n);
				// sort queue!
			}
			else
			{
				printf("--Неверное владение флагом -n!--\n");
				exit (5);
			}
		}
		i++;
	}
	//проверить на дубликаты....!!!
	i = 1;
	printf("очередь: ");
	while (i < MAX_PLAYERS + 1)
	{
		printf("%i ", queue[i]);
		i++;
	}
	printf("\n");
	return (0);
}

void	check_param(int count, char **players, t_core *core)
{

	check_count_players_min(count, players, core);
	int i = 1;
	while (i <= MAX_PLAYERS)
	{
		printf("p%i - [%i], ", i, core->player[i].number);
		i++;
	}
	printf("\n");

	check_flag_n_min(count, players, core);
	i = 1;
	while (i <= MAX_PLAYERS)
	{
		printf("p%i - [%i], ", i, core->player[i].number);
		i++;
	}
	printf("\n");

}

/*
 * проверяем на имя файла
 * * +1 к игроку
 * * задать номер
 * * запоминаем каой он по номеру в аргументах
 * проверяем на тег
 * * + кол-во параметров
 * * + кол-во шагов, но главное не перепрыгнуть общее кол-во
 * * обрабатываем номер игрока, если флаг -n
 * иначе ошибка

 * */