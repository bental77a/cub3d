#include "../parsing/cub.h"


char	*read_file(char *map_path)
{
	int		fd;
	char	*line;
	char	*content;
	char	*temp;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	content = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = content;
		content = ft_strjoin(content, line);
		free(temp);
		free(line);
	}
	close(fd);
	return (content);
}

// int	find_consecutive_newlines(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '\n' && str[i + 1] == '\n')
// 			return (1);
// 		str++;
// 	}
// 	return (0);
// }

void init(t_flags *flags)
{
	flags->no = 0;
	flags->so = 0;
	flags->we = 0;
	flags->ea = 0;
	flags->f = 0;
	flags->c = 0;
}

void init_strings(t_cub *cub)
{
	cub->info->no = NULL;
	cub->info->so = NULL;
	cub->info->we = NULL;
	cub->info->ea = NULL;
}
// int	init_map_structure(t_map *map,t_info *info)
// {
// 	int	i;
// 	int	j;

// 	map->height = 0;
// 	map->grid = ft_split(map->header, '\n');
// 	if (!map->grid)
// 		return (0);
// 	i = 0;
// 	while (map->grid[i])
// 	{
// 		if (!m_just_a_spaces(map->grid[i]))
// 			map->height++;
// 		i++;
// 	}
// 	info->file_content = (char **)malloc(sizeof(char *) * (map->height + 1));
// 	if (!info->file_content)
// 		return (0);
// 	i = 0;
// 	j= 0;
// 	while (map->grid[i])
// 	{
// 		if (!m_just_a_spaces(map->grid[i]))
// 		{
// 			info->file_content[j] = ft_strdup(map->grid[i]);
// 			j++;
// 		}
// 		free(map->grid[i]);
// 		i++;
// 	}
// 	free(map->grid);
// 	info->file_content[j] = NULL;
// 	return (1);
// }



// void skip_spaces(char *str)
// {
// 	int i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == ' ' && (str[i] >= 9 && str[i] <= 13))
// 			i++;
// 	}
// }

// int init_args_texteurs(char **str, t_info *info)
// {
//     int     i;
//     char    **tmp;
	
//     init(info);
//     i = 0;
//     while (str[i])
//     {
//         tmp = ft_split_space(str[i]);
//         if (tmp[0])
//         {
// 			if (array_lenght(tmp) == 2)
// 			{
//             	if (ft_strncmp(tmp[0], "NO", 2) == 0 && !info->no && ft_strlen(tmp[0]) == 2)
//             	    info->no = ft_strdup(tmp[1]);
//             	else if (ft_strncmp(tmp[0], "SO", 2) == 0 && !info->so && ft_strlen(tmp[0]) == 2)
//             	    info->so = ft_strdup(tmp[1]);
//             	else if (ft_strncmp(tmp[0], "WE", 2) == 0 && !info->we && ft_strlen(tmp[0]) == 2)
//             	    info->we = ft_strdup(tmp[1]);
//             	else if (ft_strncmp(tmp[0], "EA", 2) == 0 && !info->ea && ft_strlen(tmp[0]) == 2)
//             	    info->ea = ft_strdup(tmp[1]);
// 				else
				
// 					return (-1);
// 			}
// 			else
			
// 				return -1;
//         }
// 		if (info->no && info->so && info->we && info->ea)
// 			break;
//         free_split(tmp);
//         i++;
//     }
// 	return (free_split(tmp),0);
// }

// int fill(t_info *info, t_map *map)
// {
// 	int	i;
// 	int start_index;
// 	int	size;
	
// 	start_index = info->index + 1;
// 	size = map->height - start_index;
// 	info->map = malloc(sizeof(char *) * (size + 1));
// 	if (!info->map)
// 		return (1);
// 	i = 0;
// 	while (i < size)
// 	{
// 		info->map[i] = ft_strdup(info->file_content[start_index + i]);
// 		if (!info->map[i])
// 			return (1);
// 		i++;
// 	}
// 	info->map[i]= NULL;
// 	return 0;
// }






// int create_rgb(char *color)
// {
//     char    **tmp;
//     int     r, g, b;
//     int     rgb;

//     if (!color)
//         return (ft_putstr_fd("Error: empty color\n", 2), -1);

//     tmp = ft_split(color, ',');
//     if (!tmp || !tmp[0] || !tmp[1] || !tmp[2] || tmp[3])
//         return (ft_putstr_fd("Error: invalid RGB format\n", 2), -1);
//     r = ft_atoi(tmp[0]);
//     g = ft_atoi(tmp[1]);
//     b = ft_atoi(tmp[2]);
//     if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
//         return (ft_putstr_fd("Error: RGB values must be between 0-255\n", 2), -1);
//     rgb = (r << 16) | (g << 8) | b;
//     for (int i = 0; tmp[i]; i++)
//         free(tmp[i]);
//     free(tmp);
//     return rgb;
// }

// int find_map(char *content)
// {
// 	int 	i;

// 	i= 0;
// 	char ft_strchr(content,'1');
// 	while (content[i])
// 	{
		
// 	}
	
// }


int	find_map_start(char *content)
{
	int	i;

	i = 0;
	while (content[i])
	{
		while (content[i] == ' ' || content[i] == '\t')
			i++;
		if (content[i] == '1')
			return (i);
		while (content[i] && content[i] != '\n')
			i++;
		if (content[i] == '\n')
			i++;
	}
	return (-1);
}

int dived_content(char *content, t_map *map, t_info *info)
{
	int		start;

	start = find_map_start(content);
	if (start == -1)
	return (-1);
	// printf("============== < start : %d > ======================\n", start);
	map->header = ft_strndup(content, start);
	map->map = ft_strdup(content + start);
	return (0);
}

int check_line(char *line, t_flags *flags)
{
    int j = 0;
    while (line[j] == ' ' || line[j] == '\t')
        j++;
    if (!ft_strncmp(line + j, "NO ", 3) && !flags->no)
        return (flags->no = 1, 0);
    if (!ft_strncmp(line + j, "SO ", 3) && !flags->so)
        return (flags->so = 1, 0);
    if (!ft_strncmp(line + j, "WE ", 3) && !flags->we)
        return (flags->we = 1, 0);
    if (!ft_strncmp(line + j, "EA ", 3) && !flags->ea)
        return (flags->ea = 1, 0);
    if (!ft_strncmp(line + j, "F ", 2) && !flags->f)
        return (flags->f = 1, 0);
    if (!ft_strncmp(line + j, "C ", 2) && !flags->c)
        return (flags->c = 1, 0);
    return (1);
}

int check_for_errors(t_cub *cub)
{
	int i;
	int j;
	char **grid;
	t_flags flags;

	init(&flags);
	grid = ft_split(cub->map->header, '\n');
	if (!grid)
		return (1);
	i = 0;
	while (grid[i])
    {
        if (check_line(grid[i], &flags))
            return (free_split(grid), 1);
        i++;
    }
	free_split(grid);
	if (flags.we && flags.no && flags.so && flags.ea && flags.c && flags.f)
		return (0);
	return (1);
}

int	skip_spaces(char *line, int j)
{
	while (line[j] == ' ' || (line[j] >= 9 && line[j] <= 13))
		j++;
	return (j);
}

int	parse_rgb(char *line, t_flors *color)
{
	char	**tmp;

	tmp = ft_split(line, ',');
	if (!tmp || array_lenght(tmp) != 3)
		return (1);
	color->r = ft_atoi(tmp[0]);
	color->g = ft_atoi(tmp[1]);
	color->b = ft_atoi(tmp[2]);
	 if ((color->r < 0 || color->r > 255) || (color->g < 0 || color->g > 255) || (color->b < 0 || color->b > 255))
        return (1);
	free_split(tmp);
	return (0);
}

int	parse_colors(char **grid, t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (grid[i])
	{
		j = skip_spaces(grid[i], 0);
		if (!ft_strncmp(grid[i] + j, "F ", 2))
		{
			j = skip_spaces(grid[i], j + 1);
			if (parse_rgb(grid[i] + j, cub->flors))
				return (1);
		}
		else if (!ft_strncmp(grid[i] + j, "C ", 2))
		{
			j = skip_spaces(grid[i], j + 1);
			if (parse_rgb(grid[i] + j, cub->celing))
				return (1);
		}
		i++;
	}
	return (0);
}

int parse_texteurs(char **grid, t_cub *cub)
{
	char **tmp;
	int i;

	i = 0;
    while (grid[i])
    {
        tmp = ft_split_space(grid[i]);
        if (tmp[0])
        {
			if (array_lenght(tmp) == 2)
			{
            	if (ft_strncmp(tmp[0], "NO", 2) == 0 && !cub->info->no && ft_strlen(tmp[0]) == 2)
            	    cub->info->no = ft_strdup(tmp[1]);
            	else if (ft_strncmp(tmp[0], "SO", 2) == 0 && !cub->info->so && ft_strlen(tmp[0]) == 2)
            	    cub->info->so = ft_strdup(tmp[1]);
            	else if (ft_strncmp(tmp[0], "WE", 2) == 0 && !cub->info->we && ft_strlen(tmp[0]) == 2)
            	    cub->info->we = ft_strdup(tmp[1]);
            	else if (ft_strncmp(tmp[0], "EA", 2) == 0 && !cub->info->ea && ft_strlen(tmp[0]) == 2)
            	    cub->info->ea = ft_strdup(tmp[1]);
			}
			else
			{
				free_split(tmp);
				i++;
				continue;
			}
        }
        free_split(tmp);
		if (cub->info->no && cub->info->so && cub->info->we && cub->info->ea)
			return (0);
        i++;
    }
	return (0);
}
int parse_header(t_cub *cub)
{
	char **grid;

	if (check_for_errors(cub))
		return (1);
	grid = ft_split(cub->map->header, '\n');
	if (!grid)
		return (1);
	if (parse_colors(grid, cub))
		return (1);
	if (parse_texteurs(grid, cub))
		return (1);
	return (0);
}