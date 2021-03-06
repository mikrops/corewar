/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:18:13 by mmonahan          #+#    #+#             */
/*   Updated: 2020/11/13 18:24:01 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	main(int argc, char **argv)
{
	t_core	core;

	check_param(argc, argv, &core);
	validation(argv, &core);

	printf("Hello, corewar!\n");
	return (0);
}
