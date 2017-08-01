/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 14:51:16 by avasseur          #+#    #+#             */
/*   Updated: 2017/04/06 14:51:20 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	*ft_mmap(size_t size, int fd)
{
	char	*map;

	if ((map = mmap(0, size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
	{
		ft_printf(2, "[!] Mmap() failed (bad input file)\n");
		return ((void*)-1);
	}
	return (map);
}

int		ft_munmap(void **map, size_t size)
{
	if (!map)
	{
		ft_printf(2, "[!] No mapping\n");
		return (-1);
	}
	if (munmap(*map, size) == -1)
	{
		ft_printf(2, "[!] Munmap failed\n");
		return (-1);
	}
	*map = NULL;
	return (0);
}

int		is_mapped(t_env *e, void *test_map)
{
	if (test_map < (void *)e->map_origin
		|| test_map > (void *)e->map_origin + e->map_size)
	{
		ft_printf(2, "[!] Out of map\n");
		return (0);
	}
	return (1);
}

int		binary2map(const char *binary, char **map, size_t *map_size)
{
	int				fd;
	struct stat		st;
	char			*ptr;

	if ((fd = open(binary, O_RDONLY)) == -1)
	{
		ft_printf(1, "[!] No such file: %s\n", binary);
		return (-1);
	}
	if (fstat(fd, &st) == -1)
	{
		ft_printf(1, "[!] Error fstat()\n");
		return (-1);
	}
	if ((ptr = ft_mmap(st.st_size, fd)) == (void *)-1)
		return (-1);
	*map_size = st.st_size;
	*map = ptr;
	close(fd);
	return (1);
}
