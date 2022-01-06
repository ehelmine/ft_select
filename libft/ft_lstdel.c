/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 14:52:19 by ehelmine          #+#    #+#             */
/*   Updated: 2021/05/20 13:15:30 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Prototype void ft_lstdel(t_list **alst, void (*del)(void *, size_t));
** Description Takes as a parameter the adress of a pointer to a link and
** frees the memory of this link and every successors of that link
** using the functions del and free(3). Finally the pointer to the link that
**  was just freed must be set to NULL (quite similar
** to the function ft_memdel from the mandatory part).
** Param. #1 The address of a pointer to the first link of a list that needs
** to be freed.
** Return value None.
** Libc functions free(3)
*/

#include "includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	while (*alst)
	{
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = (*alst)->next;
	}
	*alst = NULL;
}
