/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 18:55:29 by yribeiro          #+#    #+#             */
/*   Updated: 2018/04/16 20:20:51 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list t_list;

struct s_list
{
	void     *data;
	t_list  *next;
};

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*lst;

	lst = begin_list;
	while (lst)
	{
		(*f)(lst->data);
		lst = lst->next;
	}
}

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*current;
	t_list	*previous;

	current = *begin_list;
	previous = 0;
	while (current)
	{
		if ((cmp)(current->data, data_ref) == 0)
		{
			if (previous == 0)
				*begin_list = current->next;
			else
				previous->next = current->next;
		}
		previous = current;
		current = current->next;
	}
}

t_list	*lst_new(void *data)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return node;
}

void	print_list(t_list *head)
{
	while (head)
	{
		printf("[%d]", (int)head->data);
		if (head->next)
			printf("->");
		head = head->next;
	}
	printf("\n");
}

int		cmp(void *a, void *b)
{
	if ((int)a == (int)b)
		return (0);
	else
		return (1);
}

int main()
{
	t_list 	*node1;
	t_list	*node2;

	node1 = lst_new((void*)1);
	node1->next = lst_new((void*)2);
	node1->next->next = lst_new((void*)3);
	ft_list_remove_if(&node1, (void*)1, &cmp);

	print_list(node1);
}