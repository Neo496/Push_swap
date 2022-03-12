/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:28:19 by atouba            #+#    #+#             */
/*   Updated: 2022/03/12 17:12:23 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_sorted(int *a, int size_a)
{
	int	i;

	i = 0;
	while (i < size_a - 1)
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static	int	isneg(char c, int *i)
{
	if (c == '-')
	{
		*i = *i + 1;
		return (-1);
	}
	if (c == '+')
		*i = *i + 1;
	return (1);
}

static	void	initialise(int *a, unsigned long long *b, int *c)
{
	*a = 0;
	*b = 0;
	*c = 1;
}

int	is_sspace(char c)
{
	if (c == '\t' || c == '\n'
		|| c == '\v' || c == '\r' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int					i;
	unsigned long long	ans;
	int					sign;
	unsigned long long	max_long;

	max_long = 2147483647;
	initialise(&i, &ans, &sign);
	while (is_sspace(str[i]) == 1)
		i++;
	if (((str[i] == '+' || str[i] == '-')
			&& (str[i + 1] >= '0' && str[i + 1] <= '9'))
		|| (str[i] >= '0' && str[i] <= '9'))
	{
		sign = isneg(str[i], &i);
		while (str[i] >= '0' && str[i] <= '9')
			ans = (ans * 10 + str[i++] - '0');
	}
	if ((ans > max_long && sign > 0) || (ans > max_long + 1 && sign < 0))
		return (0);
	return (ans * sign);
}
