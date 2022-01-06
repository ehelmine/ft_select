/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 15:24:09 by ehelmine          #+#    #+#             */
/*   Updated: 2021/05/20 13:15:42 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Prototype t_list * ft_lstmap(t_list *lst, t_list * (*f)(t_list *elem));
** Description Iterates a list lst and applies the function f to each link to
** create a “fresh” list (using malloc(3)) resulting from the successive
** applications of f. If the allocation fails, the function returns NULL.
** Param. #1 A pointer’s to the first link of a list.
** Param. #2 The address of a function to apply to each link of a list.
** Return value The new list.
** Libc functions malloc(3), free(3).
*/

#include "includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*temp;

	newlst = f(lst);
	if (newlst == NULL)
		return (NULL);
	temp = newlst;
	lst = lst->next;
	while (lst != NULL)
	{
		temp->next = f(lst);
		lst = lst->next;
		temp = temp->next;
	}
	return (newlst);
}
