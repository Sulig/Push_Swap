/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:33:46 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/22 20:55:45 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_index **array_of_index_table(char **stack_a)
{
	int arr_index; 
	int total_pieces;
	t_index **index_table;
	
	arr_index = 0;
	total_pieces = ft_arr_strlen(stack_a);
	index_table = malloc(sizeof(t_index *) * (total_pieces + 1));
	if(!index_table)
		return NULL;
	while(total_pieces)
	{
		t_index *tmp;
		tmp = malloc(sizeof(t_piece));
		if(!tmp)
			return NULL;
		tmp->p = stack_a[arr_index];
		index_table[arr_index] = tmp;
		total_pieces--;
		arr_index++;
	}
	index_table[arr_index] = NULL;
	return index_table;
}

int give_me_the_index(t_index **index_table, char *pieza)
{
	int i = 0;
	while(index_table[i])
	{
		if (index_table[i]->p == pieza)
			return index;
		i++;
	}
	return -1;
}

void set_index_in_index_table(t_index **table, char **stack)
{
	int i;
	int j;
	int total;
	int index;

	i = 0;
	j = 0;
	index = 0;
	total = ft_arr_strlen(stack);
	while(i < total)
	{
		j = 0;
		index = 0;
		while(j < total)
		{
			if (ft_atoi(stack[i]) > ft_atoi(stack[j]))
				index++;
			j++;
		}
		table[i]->index = index;
		i++;
	}
}
