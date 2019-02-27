/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:06:17 by mshvets           #+#    #+#             */
/*   Updated: 2019/02/11 14:06:20 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "brainfuck.h"
#include "checkmate.h"

int main(int arc, char **argv)
{
//	brainfuck(argv[1]);
	ft_check_mate(arc, argv);
	system("leaks Exam -q");
}
