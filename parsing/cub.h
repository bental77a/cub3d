#ifndef CUB3D
# define CUB3D

#include "../libft/libft.h"
#include <fcntl.h>

typedef struct s_flors
{
    int r;
    int g;
    int b;
}   t_flors;


typedef struct s_info
{
    char *no;
    char *so;
    char *we;
    char *ea;
}   t_info;

typedef struct s_map
{
    int height;
    int width;
    char *header;// has header config (malloced)
    char *map;//   has map (malloced)
}   t_map;

typedef struct s_flags
{
    int no;
    int so;
    int ea;
    int we;
    int f;
    int c;
}   t_flags;

typedef struct s_cub
{
    t_map *map;
    t_info *info;
    t_flors *flors;
    t_flors *celing;
}   t_cub;

// int divded_file(char *str);'
int dived_content(char *content, t_map *map, t_info *info);
char	*read_file(char *map_path);
void free_split(char **str);
void init_strings(t_cub *cub);
// int		find_consecutive_newlines(char *str);
// int		init_map_structure(t_map *map,t_info *info);
// int		init_args(char **str, t_info *info);
// int		m_just_a_spaces(char *str);
// int fill(t_info *info, t_map *map);
int array_lenght(char **str);
int parse_header(t_cub *cub);
// int check_path_is_valid(char *str);

#endif