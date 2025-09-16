#include "../parsing/cub.h"

void free_split(char **str)
{
	int i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int array_lenght(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int main(int ac, char **av)
{
  t_cub cub;
  char *content;

  if (ac != 2)
	{
		ft_putstr_fd("Error: Invalid number of arguments\n", 2);
		ft_putstr_fd("Usage: ./cub3d <map_file.cub>\n", 2);
		return (1);
	}
  if (!ft_strnstr(av[1] + ft_strlen(av[1]) - 4, ".cub", 4) || ft_strlen(av[1]) <= 4)
    return (ft_putstr_fd("Error: invalid extension\n", 2), 1);
  cub.map = malloc(sizeof(t_map));
  cub.info = malloc(sizeof(t_info));
  cub.flors = malloc(sizeof(t_flors));
  cub.celing = malloc(sizeof(t_flors));
  if (!cub.map || !cub.info || !cub.flors || !cub.celing)
        return (ft_putstr_fd("Error: malloc failed\n", 2), 1);
  init_strings(&cub);
  content = read_file(av[1]);
  if (!content)
    return (ft_putstr_fd("Error: Empty file!\n",2),1);
  if (dived_content(content, cub.map, cub.info) == -1)
	  return (ft_putstr_fd("Error: invalid configfile\n", 2), 1);
  if (parse_header(&cub))
    return (ft_putstr_fd("Error: invalid configfile\n", 2), 1);













  









  // if (init_map_structure(&map,&info) == 0)
  //   return (ft_putstr_fd("Error : invalid configfile\n", 2), 1);
  // if (init_args_texteurs(info.file_content, &info) == -1)
  //     return (ft_putstr_fd("Error : invalid configfile\n", 2), 1);
  // printf("%s",map.header);
  // printf("=====================================\n");
  // printf("%s",map.map);
  // if (fill(&info, &map) == 1)
  //   return (ft_putstr_fd("Error : invalid initialisation maps\n", 2), 1);
    
  // for (int i = 0; info.map[i]; i++)
  //   printf("%s\n",info.map[i]);
  // printf("so:%s\n",info.so);
  // printf("no:%s\n",info.no);
  // printf("we:%s\n",info.we);
  // printf("ea:%s\n",info.ea);
  // printf("%s\n",info.f);
  // printf("%s\n",info.c);
  // if (find_consecutive_newlines(content) == 1)
	// 	return (ft_putstr_fd("find_consecutive_newlines",2),1);
}