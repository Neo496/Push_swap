#include "libft/libft/libft.h"
#include "push_swap.h"

void	display(t_list	*root)
{
	if (!root)
		return ;
	t_list	*curr = root;
	while (curr)
	{
		printf("%d ", (int)curr->n);
		curr = curr->next;
	}
}

int main()
{
	t_list	*head = ft_lstnew(5);
	head->next = ft_lstnew(10);
	head->next->next = ft_lstnew(15);
	display(head);
	printf("\n");
	// t_list	*last = ft_lstlast(head);
	t_list	*curr = head;
	while (curr->next)
		curr = curr->next;
	// free(curr->n);
	free(curr);
	curr = 0;
	display(head);
}