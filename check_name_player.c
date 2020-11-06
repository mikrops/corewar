//
// Created by mmonahan on 06.11.2020.
//

#include "corewar.h"

/*
**	Проверяет имя игрока на окончание .cor
*/

int	check_name_player(char *player)
{
	int length;

	length = ft_strlen(player);
	if (ft_strstr(&player[length - 4], ".cor"))
		return (0);
	else
		return (1);
}