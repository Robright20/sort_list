/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaz <zaz@staff.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 13:14:10 by zaz               #+#    #+#             */
/*   Updated: 2019/08/06 14:31:55 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
typedef struct s_list t_list;

struct s_list
{
	int     data;
	t_list  *next;
};
#endif
