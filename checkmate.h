/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmate.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:33:24 by mshvets           #+#    #+#             */
/*   Updated: 2019/02/11 15:35:47 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKMATE_H

#define CHECKMATE_H
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_crd
{
	int			i;
	int 		j;
}				t_crd;

void	ft_check_mate(int arc, char **argv);

#endif
