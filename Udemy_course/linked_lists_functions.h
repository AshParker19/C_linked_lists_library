
#ifndef LINKED_LISTS_FUNCTIONS
#define LINKED_LISTS_FUNCTIONS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int num;
    struct node *next;
} Node;

void ft_print_list(Node *head);
Node *ft_insert_at_head(Node *head, int new_num);
Node *ft_insert_at_tail(Node *head, int new_num);
Node *ft_delete_at_head(Node *head);
Node *ft_delete_at_tail(Node *head);
int ft_list_length(Node *list);
int ft_recursive_length(Node *list);
bool ft_is_member(Node *list, int find_num);
int ft_count_matches(Node *list, int find_num);
void ft_replace(Node *list, int find_num, int replace_num);
Node *ft_delete_first_match(Node *head, int to_delete, bool *deleted);
Node *ft_delete_efficiently(Node *head, int to_delete, int *num_deleted);
Node *ft_append(Node *head1, Node *head2);
Node *ft_reverse_list(Node *list);
void ft_sort_list(Node *head);
void ft_remove_duplicates(Node *head);
Node *ft_insert_after(Node *head, int new_value, int after_value);
Node *ft_delete_list(Node *list);
void ft_add_lists(Node *list1, Node *list2);
void ft_add_lists_recursively(Node *list1, Node *list2);
Node *ft_duplicate_list(Node *original);

#endif