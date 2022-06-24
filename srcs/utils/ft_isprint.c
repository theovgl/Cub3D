#include <unistd.h>
#include "cub3d.h"

int		ft_isprint(int c)
{
	if ((c >= 32 && c < 127))
		return (1);
	return (0);
}