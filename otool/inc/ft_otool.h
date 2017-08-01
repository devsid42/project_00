/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:27:30 by avasseur          #+#    #+#             */
/*   Updated: 2017/04/21 09:16:44 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OTOOL_H
# define FT_OTOOL_H

# include "libft.h"
# include <sys/mman.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/fat.h>
# include <mach-o/ranlib.h>
# include <ar.h>

# define ONE ft_putstr("ONE\n");
# define TWO ft_putstr("TWO\n");
# define GNL "get_next_line.o"
# define SWAP "ft_swap.o"
# define AR_END "__eh_frame"
# define FAT_AR 0x21

typedef struct mach_header_64		t_header_64;
typedef struct load_command			t_load_cmd;
typedef struct symtab_command		t_symtab_cmd;
typedef struct segment_command_64	t_segment_cmd_64;
typedef struct section_64			t_section_64;
typedef struct nlist_64				t_nlist_64;
typedef struct ar_hdr				t_ar_hdr;
typedef struct ranlib				t_ranlib;
typedef struct fat_header			t_fat_hdr;
typedef struct fat_arch				t_fat_arch;

typedef struct mach_header			t_header;
typedef struct segment_command		t_segment_cmd;
typedef struct section				t_section;
typedef struct nlist				t_nlist;

typedef struct		s_env
{
	t_cchar				*app;
	int					filetype;
	char				*map;
	char				*map_origin;
	void				*fat_map;
	t_ar_hdr			*ar_hdr;
	t_uint				magic_origin;
	t_uint				magic;
	int					rev_origin;
	int					rev;
	void				*m_ptr;
	t_header_64			*hdr;
	t_load_cmd			*lc;
	t_segment_cmd_64	*seg;
	t_section_64		*sect;
	t_header			*hdr_32;
	t_segment_cmd		*seg_32;
	t_section			*sect_32;
	size_t				map_size;
	int					extended;
	int					verbose;
	int					opt_hdr;
	int					opt_all;
	int					is_swap;
	int					is_gnl;
	int					is_32;
	int					is_ppc;
}					t_env;

typedef struct		s_sect_text
{
	void		*map_offset;
	uint64_t	size;
	uint64_t	addr;
}					t_sect_text;

void				usage(t_cchar *app);
int					init_env(t_env *e, t_cchar *app, t_cchar *binary);
int					option(t_env *e, char **argv);
void				*get_map(size_t size, int fd);
int					drop_map(void *map, size_t size);
uint32_t			swap_uint32(uint32_t val);
int					binary2map(const char *bin, char **map, size_t *map_size);
int					set_magic_rev(void *map, t_uint *magic, int *rev);
int					is_rev_endian(t_uint magic);

uint32_t			rev_uint32_endian(uint32_t val, int active);
uint64_t			rev_uint64_endian(uint64_t val, int active);

int					handle_64b_binary(t_env *e);
int					handle_32b_binary(t_env *e);
int					handle_archive(t_env *e, const char *bin);
int					handle_fat(t_env *e, const char *bin);

void				ft_puthexmem(t_sect_text *txt, size_t maxlen, int is_ppc);

void				put_header_64(t_header_64 *hdr);

int					handle_64b_archive(t_env *e, const char *bin);
int					handle_64b_fat(t_env *e);

int					is_mapped(t_env *e, void *test_map);

#endif
