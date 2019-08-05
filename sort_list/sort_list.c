/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 02:59:31 by fokrober          #+#    #+#             */
/*   Updated: 2019/08/05 14:25:22 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_swap(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

int		croissant(int a, int b)
{
	return (a <= b);
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	(void)lst;
	printf("%d\n", cmp(2, 1));
	return (0);
}

void	printab(int *tab, int n)
{
	int		i;

	i = 0;
	while (i < n)
		printf("%d\t", tab[i++]);
	printf("\n");
}

int		sort(int *a, int len)
{
	int			i;
	int			j;
	int			order;

	i = 0;
	order = 1;
	while (i < len - 1)
	{
		j = i + 1;
		order = 1;
		while (j < len && (order = croissant(a[i], a[j])))
			j++;
		if (!order)
			ft_swap(a + i, a + j);
		i++;
	}
	if (len && !order)
		return (sort(a, len - 1));
	return (1);
}

int		main(void)
{
	int		a[] = {1, 6, 9, 2, 1, 4, 11, 5, 7, 0, -1};
	int		len;
	t_list	t;

	len = sizeof(a) / 4;
	sort(a, len);
	printab(a, len);
	(void)sort_list(&t , &croissant);
	return (0);
}
