#include "cub3d.h"

void    delfirst_node(t_list **q)
{
    t_list *temp;
    temp = *q;
    *q = (*q)->next;
    free(temp);
}

int floodfill(t_config *conf, t_map m)
{
    int i;
    int j;
    t_list *q;
    t_map map;

    map = m;
    q = ft_lstnew(conf->player.x, conf->player.y);
printf("q[%d][%d] == %c\n", q->x, q->y, map.map[q->y][q->x]);
    ft_lstadd_back(&q, ft_lstnew(q->x + 1, q->y));
    ft_lstadd_back(&q, ft_lstnew(q->x, q->y + 1));
    if (q->x)
        ft_lstadd_back(&q, ft_lstnew(q->x - 1, q->y));
    if (q->y)
        ft_lstadd_back(&q, ft_lstnew(q->x, q->y - 1));
    while (ft_lstsize(q))
    {
printf("\nQ SIZE == %d\n", ft_lstsize(q));
printf("for q[%d][%d] == '%c'\n", q->y, q->x, map.map[q->y][q->x]);
print_map(map);
printf("Width == %d\tHeight == %d\n", map.map_width, map.map_height);
        if (map.map[q->y][q->x] == '0')
        {
printf("COUCOU!\n");
            map.map[q->y][q->x] = 'x';
            ft_lstadd_back(&q, ft_lstnew(q->x + 1, q->y));
            ft_lstadd_back(&q, ft_lstnew(q->x, q->y + 1));
            if (q->x)
                ft_lstadd_back(&q, ft_lstnew(q->x - 1, q->y));
            if (q->y)
                ft_lstadd_back(&q, ft_lstnew(q->x, q->y - 1));
        }
        if (ft_isspace(map.map[q->y][q->x]) || !ft_isprint(map.map[q->y][q->x]) || (map.map[q->y][q->x] == 'x' && (q->x == 0 || q->x == map.map_width - 1 || q->y == 0 || q->y == map.map_height - 1)))
        {
            ft_lstclear(&q, free);
printf("\n_____________________________________________________________\n");
            return 1;
        }
        delfirst_node(&q);
    }
    ft_lstclear(&q, free);
    return 0;
}