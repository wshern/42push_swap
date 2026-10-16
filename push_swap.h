/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werlim <werlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 13:37:21 by werlim            #+#    #+#             */
/*   Updated: 2026/10/16 16:22:26 by werlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ps_printf/ps_printf.h"

typedef struct s_node
{
	int				data;
	int				rank;
	struct s_node	*next;
}	t_node;

typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_NUM
}	t_op;

typedef enum e_strat
{
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX,
	STRAT_ADAPTIVE,
}	t_strat;

typedef struct s_ps
{
	t_node	*a;
	t_node	*b;
	int		size_a;
	int		size_b;
	double	disorder;
	int		type_strat;
	int		type_class;
	int		counter[OP_NUM];
	int		bench;
}	t_ps;

/* Parse - Rank Assignment */
void	assign_rank(t_node *node);

/* Disorder Calculation */
double	calc_disorder(t_node *node);

/* Sort - Complex (Radix) */
void	sort_complex(t_ps *ps);
void	radix_algo(t_ps *ps, int divide);

/* Sort - Adaptive */
void	sort_adaptive(t_ps *ps);

/* Sort Checker (not bonus) */
int		ps_is_sorted(t_node *node);

/* Operations - Swap */
void	op_swap(t_node **node);
void	op_sa(t_ps *ps);
void	op_sb(t_ps *ps);
void	op_ss(t_ps *ps);

/* Operations - Push */
int		op_push(t_node **src, t_node **dest);
void	op_pa(t_ps *ps);
void	op_pb(t_ps *ps);

/* Operations - Rotate */
void	op_rotate(t_node **node);
void	op_ra(t_ps *ps);
void	op_rb(t_ps *ps);
void	op_rr(t_ps *ps);
void	op_rrotate(t_node **node);
void	op_rra(t_ps *ps);
void	op_rrb(t_ps *ps);
void	op_rrr(t_ps *ps);

/* Helper Functions - Node */
t_node	*ps_ndnew(int data, int rank);
t_node	*ps_ndlast(t_node *node);
void	ps_ndaddlast(t_node **node, t_node *new);
void	ps_ndclear(t_node **node);

#endif