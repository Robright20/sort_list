/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 02:59:31 by fokrober          #+#    #+#             */
/*   Updated: 2019/08/06 14:49:35 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	printab(t_list *head)
{
	while (head)
	{
		printf("[%d]\t", head->data);
		head = head->next;
	}
	printf("\n");
}

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

void	ft_swap(t_list *a, t_list *b)
{
	t_list	tmp;

	(void)ft_memcpy(&tmp, b, sizeof(t_list));
	(void)ft_memcpy(b, a, sizeof(t_list));
	(void)ft_memcpy(a, &tmp, sizeof(t_list));
	a->next = b->next;
	b->next = tmp.next;
}

int		croissant(int a, int b)
{
	return (a <= b);
}

t_list	*create_list(int n)
{
	t_list	*head;

	head = (t_list*)malloc(sizeof(t_list));
	head->data = 0;
	head->next = NULL;
	if (n)
	{
		head->data = arc4random_uniform(100);
		head->next = create_list(n - 1);
	}
	return (head);
}

t_list	*sort_list(t_list *head, int (*cmp)(int, int))
{	
	t_list		*nhead;
	t_list		*tmp;

	tmp = head;
	while (head && head->next)
	{
		nhead = head->next;
		while (nhead->next)
		{
			if (!cmp(head->data, nhead->data))
				ft_swap(head, nhead);
			nhead = nhead->next;
		}
		head = head->next;
	}
	return (tmp);
}

int		main(void)
{
	t_list	*t;

	t = create_list(10);
	printab(t);
	(void)sort_list(t , &croissant);
	printab(t);
	return (0);
}
