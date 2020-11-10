/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 17:18:13 by mmonahan          #+#    #+#             */
/*   Updated: 2020/11/03 01:53:48 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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