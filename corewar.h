/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:35:51 by mmonahan          #+#    #+#             */
/*   Updated: 2020/11/12 06:30:05 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_COREWAR_H
# define COREWAR_COREWAR_H

# include <stdio.h> // УДАЛИТЬ, ЗЛОЙ ПРИНТФ!

# include <fcntl.h> // для чтения файлов
# include "libft/libft.h"
# include "op.h"

/*
**	Для чтения чемпионов
*/

# define SIZE_MAGIC 4
# define SIZE_NULL 4
# define SIZE_CODE 4

/*
**	Сокращения
*/

# define CHAMP core->champ

typedef struct		s_champ
{
	int 			id;
	int 			arg;
	t_header		header;
	unsigned char 	code[CHAMP_MAX_SIZE + 1];
}					t_champ;

typedef struct		s_core
{
	int 			count;
	t_champ 		champ[MAX_PLAYERS + 1];
	unsigned char	game_memory[MEM_SIZE];
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
	{"-n", "--arg", 2, {NUMBER, CHAMP}},
	{0, 0, 0, {0}}
};
*/

int					check_name_player(char *player);
void 				check_param(int count, char **players, t_core *core);
void				check_flag_n(int count, char **players, t_core *core);
void				validation(char **players, t_core *core);

#endif //COREWAR_COREWAR_H
