/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:35:51 by mmonahan          #+#    #+#             */
/*   Updated: 2020/11/05 05:46:35 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_COREWAR_H
# define COREWAR_COREWAR_H

# include <stdio.h> // УДАЛИТЬ, ЗЛОЙ ПРИНТФ!

# include "libft/libft.h"
# include "op.h"

typedef struct		s_player
{
	int 			number;
	t_header		header;
}					t_player;

typedef struct		s_core
{
	t_player 		player[MAX_PLAYERS + 1];
	unsigned char	memory[MEM_SIZE];
}					t_core;


/*
 * маски тегов
*/

/*
typedef struct		s_flag
{
	char			*name;
	char			*full_name
	int 			count_arguments;
	char 			arguments[3];
}					t_flag;

static t_operation	op_flag[2] =
{
	{"-n", "--number", 2, {NUMBER, PLAYER}},
	{0, 0, 0, {0}}
};
*/

void 				check_param(int count, char **players, t_core *core);
void				validation(t_core *core);

#endif //COREWAR_COREWAR_H
