/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshovah <anshovah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:56:14 by anshovah          #+#    #+#             */
/*   Updated: 2023/12/10 17:01:21 by anshovah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    this function traverses trough both A and B stacks linked list and prints
    all the corresponding data for each node:
        1. if the node is empty or not
        2. values in a previous and next nodes
        3. index of a node in a stack
        4. corresponding chunk of values
*/
void	ft_print_list(t_store *store)
{
	t_stack *current_a = store->stack_a;
	t_stack *current_b = store->stack_b;
	
	printf(YELLOW"╔═══════════════╗\n"RESET);
	printf(PURPLE"        A        \n"RESET);
	if (!current_a)
		printf (RED"     EMPTY!!\n" RESET);
	else if (!current_a->next && !current_a->prev)
		printf (RED"    ONLY HEAD\n"RESET);
	while (current_a)
	{
		printf (SALMON" INDEX %d\n", current_a->index);
		printf (GREEN" CURRENT_A NUM %d\n"RESET, current_a->value);
		if (!current_a->prev)
			printf (CYAN" PREV - NULL\n"RESET);
		else 
			printf (CYAN" PREV VALUE - %d\n"RESET, current_a->prev->value);	
		if (!current_a->next)	
			printf(CYAN" NEXT - NULL\n"RESET);
		else
			printf (CYAN" NEXT VALUE - %d\n"RESET, current_a->next->value);
		printf (RED "FLAG %d\n", current_a->fl)	
		if (current_a->flag == 1)	
			printf (SBLUE" 0-10%%\n");
		else if (current_a->flag == 2)	
			printf (SBLUE" 10-20%%\n");
		else if (current_a->flag == 3)	
			printf (SBLUE" 20-30%%\n");
		else if (current_a->flag == 4)	
			printf (SBLUE" 30-40%%\n");
		else if (current_a->flag == 5)	
			printf (SBLUE" 40-50%%\n");
		else if (current_a->flag == 6)	
			printf (SBLUE" 50-60%%\n");
		else if (current_a->flag == 7)	
			printf (SBLUE" 60-70%%\n");
		else if (current_a->flag == 8)	
			printf (SBLUE" 70-80%%\n");
		else if (current_a->flag == 9)	
			printf (SBLUE" 80-90%%\n");
		else if (current_a->flag == 10)	
			printf (SBLUE" 90-100%%\n");										
		if (current_a->next)
			printf (YELLOW"=================\n"RESET);	
		current_a = current_a->next;
	}
	if (store->tail_a)
		printf (SALMON" TAIL A VALUE %d\n", store->tail_a->value);
	printf (YELLOW"╚═══════════════╝\n"RESET);
	
	// print stack B
	printf (YELLOW"╔═══════════════╗\n"RESET);
	printf (PURPLE"        B        \n"RESET);
	if (!current_b)
		printf (RED"     EMPTY!!\n"RESET);
	else if (!current_b->next && ! current_b->prev)
		printf (RED"    ONLY HEAD\n"RESET);	
	while (current_b)
	{
		printf (SALMON" INDEX %d\n", current_b->index);
		printf(GREEN" CURRENT_B NUM %d\n"RESET, current_b->value);
		if (!current_b->prev)
			printf (CYAN" PREV - NULL\n"RESET);
		else 
			printf (CYAN" PREV VALUE - %d\n"RESET, current_b->prev->value);	
		if (!current_b->next)	
			printf(CYAN" NEXT - NULL\n"RESET);
		else
			printf (CYAN" NEXT VALUE - %d\n"RESET, current_b->next->value);
		if (current_b->next)	
			printf (YELLOW"=================\n"RESET);	
		current_b = current_b->next;
	}
	if (store->tail_b)
		printf (SALMON" TAIL B VALUE %d\n", store->tail_b->value);
	printf (YELLOW"╚═══════════════╝\n"RESET);
}
