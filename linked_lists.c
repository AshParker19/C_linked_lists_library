
#include "linked_lists_functions.h"

void ft_print_list(Node *head)
{
    Node *current = head;
    int i = 0;

    while(current != NULL)
    {
        printf("The value of the list %d is %d\n", i, current->num);
        i++;
        current = current->next;
    }
}

Node *ft_insert_at_head(Node *head, int new_num)
{
    Node *new_head = calloc(1, sizeof(Node));
    new_head->num = new_num;
    if(new_head == NULL)
        return new_head;
    else
    {
        new_head->next = head;
        return new_head;
    }
}

Node *ft_insert_at_tail(Node *head, int new_num)
{
    Node *new_tail = calloc(1, sizeof(Node));
    new_tail->num = new_num;

    if(head == NULL)
        return new_tail;
    else
    {
        Node *current = head;

        while(current->next != NULL)
            current = current->next;
        current->next = new_tail;
        return head;    
    }    
}

Node *ft_delete_at_head(Node *head)
{
    if(head == NULL)
        return NULL;
    else
    {
        Node *to_return = head->next;
        free(head);
        return to_return;
    }    
}

Node *ft_delete_at_tail(Node *head)
{
    if(head == NULL)
        return NULL;
    else if(head->next == NULL)
    {
        free(head);
        return NULL;
    }    
    else
    {
        Node *current = head;
        Node *prev = NULL;

        while(current->next != NULL)
        {
            prev = current;
            current = current->next;
        }
        prev->next = NULL;
        free(current);
        return head;
    }
}

int ft_list_length(Node *list)
{
    Node *current = list;
    int length = 0;

    while(current != NULL)
    {
        length++;
        current = current->next;
    }
    return length;
}

int ft_recursive_length(Node *list)
{
    if(list == NULL)
        return 0;
    else
        return 1 + ft_recursive_length(list->next);    
}

bool ft_is_member(Node *list, int find_num)
{
    if(list == NULL)
        return false;
    else if(list->num == find_num)
        return true;
    else
        return ft_is_member(list->next, find_num);     
}

int ft_count_matches(Node *list, int find_num)
{
    if(list == NULL)
        return 0;
    if(list->num == find_num)
        return 1 + ft_count_matches(list->next, find_num);
    else
        return ft_count_matches(list->next, find_num);        
}

void ft_replace(Node *list, int find_num, int replace_num)
{
    if(list != NULL)
    {
        if(list->num == find_num)
            list->num = replace_num;
        ft_replace(list->next, find_num, replace_num);    
    }
}

Node *ft_delete_first_match(Node *head, int to_delete, bool *deleted)
{
    if(head == NULL)
    {
        *deleted = false;
        return NULL;
    }
    if(head->num == to_delete)
    {
        Node *to_return = head->next;
        free(head);
        *deleted = true;
        return to_return;
    }

    Node *current = head->next;
    Node *prev = head;

    while(current != NULL)
    {
        if(current->num == to_delete)
        {
            prev->next = current->next;
            free(current);
            *deleted = true;
            return head;
        }
        prev = current;
        current = current->next;
    }

    *deleted = false;
    return head;
}

Node *ft_delete_efficiently(Node *head, int to_delete, int *num_deleted)
{
    *num_deleted = 0;
    if(head == NULL)
        return NULL;
    Node *current, *temp, *new_head;
    current = head;

    while(current->num == to_delete)
    {
        temp = current;
        current = current->next;
        free(temp);
        *num_deleted += 1;
    }    
    new_head = current;
    while(current->next != NULL)
    {
        if(current->next->num == to_delete)
        {
            temp = current->next;
            current->next = current->next->next;
            free(temp);
            *num_deleted += 1;
        }
        else
        current = current->next;
    }
    return new_head;
}

Node *ft_append(Node *head1, Node *head2)
{
    if(head1 == NULL)
        return head2;

    Node *current = head1;

    while(current->next != NULL)
        current = current->next;
    current->next = head2;
    return head1;        
}

Node *ft_reverse_list(Node *head)
{
    if(head == NULL)
        return NULL;
    if(head->next == NULL)
        return head;

    Node *current = head;
    Node *next_node = head->next;

    current->next = NULL;

    while(next_node != NULL)
    {
        Node *tmp = next_node->next;
        next_node->next = current;
        current = next_node;
        next_node = tmp;
    }
    return current;
}

void    ft_sort_list(Node *head)
{
    if(head == NULL)
        return ;
    if(head->next == NULL)
        return ;    
    int swap;
    Node *save = head;

    while(head->next != NULL)
    {
        if(head->num > head->next->num)
        {
            swap = head->num;
            head->num = head->next->num;
            head->next->num = swap;
            head = save;
        }
        else
        head = head->next;
    }
    head = save;
}

void ft_remove_duplicates(Node *head)
{
    if(head == NULL)
        return ;
    if(head->next == NULL)
        return ;
    Node *current1, *current2, *duplicate;
    current1 = head;

    while(current1 != NULL && current1->next != NULL)
    {
        current2 = current1;
        while(current2->next != NULL)
        {
            if(current1->num == current2->next->num)
            {
                duplicate = current2->next;
                current2->next = current2->next->next;
                free(duplicate);
            }
            else
            current2 = current2->next;
        }
        current1 = current1->next;
    }        
}

Node *ft_insert_after(Node *head, int new_value, int after_value)
{
   Node *new_node = calloc(1, sizeof(Node));
   new_node->num = new_value;

   if(head == NULL)
    return new_node;
   else
   {
     Node *current = head;
     while(current->next != NULL)
     {
        if(current->num == after_value)
        {
            new_node->next = current->next;
            current->next = new_node;
            return head;
        }
        else
        current = current->next;
     }
     new_node->next = current->next;
     current->next = new_node;
     return head;
   }   
}

Node *ft_delete_list(Node *list)
{
    if(list != NULL)
    {
        ft_delete_list(list->next);
        free(list);
    }
    return NULL;
}

void ft_add_lists(Node *list1, Node *list2)
{
    Node *current1 = list1;
    Node *current2 = list2;
   
    while(current1)
    {
        if(current2 != NULL)
        {    
            current1->num += current2->num;
            current2 = current2->next;    
        }    
            current1 = current1->next;
    }    
}

void ft_add_lists_recursively(Node *list1, Node *list2)
{
    if(list1 == NULL || list2 == NULL)
        return ;
    list1->num = list1->num + list2->num;
    ft_add_lists_recursively(list1->next, list2->next);    
}

Node *ft_duplicate_list(Node *original)
{
    if(original == NULL)
        return NULL;
    Node *copy = calloc(1, sizeof(Node));
    copy->num = original->num;
    copy->next = ft_duplicate_list(original->next);
    return copy;
}
