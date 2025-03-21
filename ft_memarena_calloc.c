/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memarena_calloc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 11:59:28 by jvarila           #+#    #+#             */
/*   Updated: 2025/03/21 12:09:27 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Used like calloc, returns a pointer that is pointing to memory that
 * is inside the memory arena's preallocated pool of heap memory.
 * <p>
 * If no memory is available function returns NULL
 *
 * @param arena	Pointer to primary memarena node
 * @param nmemb	Number of elements to allocate space for
 * @param size	Size of elements to accolate space for
 */
void	*ft_memarena_calloc(t_memarena *arena, size_t nmemb, size_t size)
{
	t_memarena	*initial_arena;
	void		*ptr;
	size_t		bytes_required;
	size_t		bytes_available;

	bytes_required = nmemb * size;
	if (bytes_required <= 0)
		return (NULL);
	if (bytes_required > arena->capacity)
		return (NULL);
	bytes_available = arena->capacity - arena->bytes_used;
	initial_arena = arena;
	while (bytes_available < bytes_required)
	{
		if (!arena->next)
			arena->next = ft_new_memarena();
		if (!arena->next)
			return (NULL);
		arena = arena->next;
		bytes_available = arena->capacity - arena->bytes_used;
	}
	ptr = arena->heap_memory + arena->bytes_used;
	arena->bytes_used += bytes_required;
	ft_memset(ptr, 0, bytes_required);
	return (ptr);
}
