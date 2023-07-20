/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row_connector_and_print.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 20:48:43 by anshovah          #+#    #+#             */
/*   Updated: 2023/07/20 20:31:05 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  this function accepts the pointer to the head of the linked list 
    which stores the map in fdf format, it connects all the nodes 
    vertically, which in this case means it connects the row with the
    one below it so when the map, which is represented by the integer
    values is being dispalyed to the screen in 3D format, there's 
    a possibility to draw horizontal lines the same as vertical ones  */

// here's a corresponding structure
typedef struct s_point
{
    /*
        ... other info
    */
    // pointer to the next node
	struct s_point	*next;
    // pointer to the node below
	struct s_point	*down;
}					t_point;

t_point	*ft_row_connector(t_point *head, int num_nodes, int col_max)
{
	t_point	*current;
	t_point	*finder;
	int		last_possible;
	int		save;

	last_possible = num_nodes - col_max;
	current = head;
	while (last_possible--)
	{
		save = col_max;
		finder = current;
		while (save--)
			finder = finder->next;
		current->down = finder;
		current = current->next;
	}
	return (head);
}

// printing function too visualize the way rows were connected

void	ft_print_list(t_point *head)
{
	t_point	*current;

	current = head;
	while (current != NULL)
	{
		printf("Node (%d, %d, %d):\n", current->y, current->x, current->z);
		printf("  - Down Pointer: ");
		if (current->down != NULL)
			printf("(%d, %d, %d)\n", current->down->y,
				current->down->x, current->down->z);
		else
			printf("NULL\n");
		printf("  - Next Pointer: ");
		if (current->next != NULL)
			printf("(%d, %d, %d)\n", current->next->y,
				current->next->x, current->next->z);
		else
			printf("NULL\n");
		printf("\n");
		current = current->next;
	}
}