/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:26:45 by avasseur          #+#    #+#             */
/*   Updated: 2017/03/24 19:06:53 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_H
# define FT_NM_H

# include "libft.h"
# include <sys/mman.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/fat.h>
# include <mach-o/ranlib.h>
# include <ar.h>

# define TYPE_LIB_PATH 0x64
# define TYPE_OBJ_PATH 0x66
# define TYPE_FILE_PATH 0x84
# define GNL "get_next_line.o"
# define SWAP "ft_swap.o"
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

typedef struct		s_symlst
{
	uint64_t			addr;
	uint32_t			nsect;
	uint32_t			type;
	uint32_t			desc;
	char				type_letter;
	int					*symtab;
	char				*name;
	struct s_symlst		*next;
}					t_symlst;

typedef struct		s_sectlst
{
	char				*name;
	struct s_sectlst	*next;
}					t_sectlst;

typedef struct		s_env
{
	char			*app;
	int				filetype;
	char			*map;
	char			*map_origin;
	void			*fat_map;
	t_ar_hdr		*ar_hdr;
	t_uint			magic;
	t_uint			magic_origin;
	int				rev_origin;
	int				rev;
	size_t			map_size;
	t_load_cmd		*lc;
	t_symlst		*symlst;
	t_sectlst		*sectlst;
	int				extended;
	int				x_opt;
	int				no_sort_opt;
	int				is_32;
	int				verbose;
}					t_env;

void				*ft_mmap(size_t size, int fd);
int					ft_munmap(void **map, size_t size);
int					binary2map(const char *bin, char **map, size_t *msize);
char				type(char *section, int type, int offset, int sect);
int					set_magic_rev(void *map, t_uint *magic, int *rev);
int					is_rev_endian(t_uint magic);

int					handle_64b_binary(t_env *e);
int					handle_32b_binary(t_env *e);
int					handle_fat(t_env *e, const char *bin);
int					handle_archive(t_env *e, const char *bin);

int					load_symbol(t_env *e);
int					load_segment(t_load_cmd *lc);

int					symlst_sort(t_symlst **symlst);
int					symlst_append(t_symlst **symlst, t_symlst *newlst);
int					symlst_swap(t_symlst *a, t_symlst *b);
int					symlst_delete_dup(t_symlst *symlst);
int					symlst_add_type_letter(t_symlst *symlst, t_sectlst *sect);
int					symlst_delete(t_symlst *symlst);
int					symlst_is_offset_exist(t_symlst *symlst, uint64_t offset);
int					symlst_is_name_exist(t_symlst *symlst, t_cchar *name);
int					sym_accept_condition(t_env *e, char *name, int value);

void				symlst_show(t_env *e, t_symlst *symlst);

int					option(t_env *e, char **argv);
void				usage(const char *app);

int					sectlst_append(t_env *e, t_sectlst **sectlst,\
					t_load_cmd *lc);
int					sectlst_append_32(t_env *e, t_sectlst **sectlst,\
					t_load_cmd *lc);
int					sectlst_delete(t_sectlst *sectlst);
int					sectlst_append_loop(t_sectlst **sectlst, char *sectname,\
					t_sectlst *tmp);
char				*put_section(t_segment_cmd_64 *seg);
char				*get_section_name_by_id(t_sectlst *sectlst, t_uint nb);
char				*get_section_name_by_id_32(t_sectlst *sectlst, t_uint nb);

uint32_t			swap_uint32(uint32_t val);
uint32_t			rev_uint32_endian(uint32_t val, int active);
uint64_t			rev_uint64_endian(uint64_t val, int active);

int					is_mapped(t_env *e, void *test_map);

#endif
