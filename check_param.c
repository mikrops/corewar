/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:18:13 by mmonahan          #+#    #+#             */
/*   Updated: 2020/11/11 06:57:03 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Проверка параметров.
**	Обработка флагов
 *
 *
**	НАДО НАЙТИ КОЛИЧЕСТВО ИГРОКОВ И СОХРАНИТЬ В CORE
**	Надо учитывать количество игроков при флаге -n!
*/

int	check_count_players(int count, char **player, t_core *core)
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
			core->champ[++max_p].number = i;//max_p;
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

void	check_param(int count, char **players, t_core *core)
{

	core->count = check_count_players(count, players, core);
	int i = 1;
	while (i <= MAX_PLAYERS)
	{
		printf("p%i - [%i], ", i, core->champ[i].number);
		i++;
	}
	printf("\n");

	check_flag_n(count, players, core);
	i = 1;
	while (i <= MAX_PLAYERS)
	{
		printf("p%i - [%i], ", i, core->champ[i].number);
		i++;
	}
	printf("\nКоличество игроков: [%i]\n", core->count);
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