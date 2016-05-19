/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 13:08:43 by mbuclin           #+#    #+#             */
/*   Updated: 2016/04/25 14:14:19 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "push_swap_incstruc.h"

int			pile_len(t_pile *head);
void		put_tmp(t_pile *head);
void		put_pos(t_pile *head);
void		print_info(t_inf *info);
void		print_moov(t_moov *moov);
t_turn		*reset_pos(t_turn *head);
int			check_sort(t_turn *node, int max);
int			ft_isoption(int c);
int			after_option(char **args);
void		del_pile(t_pile *head);
t_turn		*del_turn(t_turn *head);
t_cmd		*del_command(t_cmd *cmd);
void		*del_moov(t_moov *moov);
void		*del_info(t_inf *info);
int			ft_del_tab(ssize_t *tab, int ret);
t_pile		*goto_pos(t_pile *head, int pos);
t_pile		*goto_tmp(t_pile *head, int num);
t_pile		*goto_minstack(t_pile *head);
t_inf		*goto_lastinfo(t_inf *info);
int			check_stack(t_pile *b, int num);
int			check_before(t_pile *stack, int pos, int max, int n);
int			change_choice(int na, int nb, int choice);
int			condition_push_a(t_turn *head, t_pile *tmp, int max);
int			condition_swap_a(t_turn *head, t_pile *tmp, int max);
int			condition_push_b(t_turn *head, t_pile *tmp, int max);
t_turn		*push(t_turn *head, int c);
t_pile		*swap(t_pile *swap);
t_pile		*rotate(t_pile *rotate);
t_pile		*revrotate(t_pile *revrot);
void		rotation(int choice, t_turn *turn);
void		print_pile_a(t_turn *node, int color, int ncmd);
void		print_pile_b(t_turn *node, int color, int ncmd);
void		put_piles(t_turn *node, const char *option, int cmd);
void		put_command(t_cmd *command, int n);
int			reverse_process_command(char *cmd);
char		*get_command(int cmd);
t_turn		*make_the_action(t_turn *turn, char *cmd);
void		print_option_and_command(t_turn *turn, char *option);
t_pile		*get_lowernode(t_pile *head, ssize_t prev);
int			get_nnode(t_turn *head, int pos, int choice);
int			get_pos(t_pile *stack, int pos);
t_cmd		*last_cmd(t_cmd *cmd);
int			count_low(t_pile *head, int num);
int			count_nrot_pb(t_pile *stack, t_inf *info);
int			count_rot_stack(t_pile *stack, t_moov *moov);
int			count_distfrom_n(t_turn *turn, t_inf *inf);
t_cmd		*create_node_command(int action);
t_cmd		*fill_list_command(t_cmd **cmd, int action);
t_turn		*make_rotate_int(t_sop *sop, t_turn *head, t_cmd **cmd);
t_turn		*rot_or_rev_to_order(t_turn *head, t_cmd **cmd);
t_turn		*push_stack_b_in_a(t_turn *head, t_cmd **cmd);
t_turn		*make_action(t_turn *head, int act, t_cmd **cmd);
t_sop		*push_or_swap(t_turn *turn);
t_turn		*make_moov(t_turn *turn, int action);
t_turn		*make_rotate(t_turn *turn);
t_inf		*search_info(t_turn *turn, int max);
int			search_n_rot(t_turn *turn, t_inf *info, int action);
int			search_wayrot(t_turn *turn, t_inf *info, int action);
t_moov		*treat_info(t_turn *turn);
t_moov		*choose_node_moov(t_moov *moov, int last);
t_turn		*choose_moov(t_turn *turn, int last);
t_inf		*get_info_a(t_turn *turn, int max);
t_inf		*get_info_b(t_turn *turn, int max);
char		*init_option(char **args);
t_pile		*init_tmp_and_pos(t_pile **head, int size);
t_turn		*init_turn(char **args);
t_turn		*push_to_a(t_turn *turn, int pos, int sens);
t_turn		*push_n_a(t_turn *turn, int n);
t_turn		*push_a_order(t_turn *turn, int max);
t_turn		*push_to_b(t_turn *turn, int pos);
t_turn		*push_med_b(t_turn *turn, int med);
t_turn		*push_b_mediane(t_turn *turn, int med);
t_turn		*big_stack_algo(t_turn *turn, int max);
t_turn		*inteligent_sort(t_turn *head);
t_turn		*distance_sort(t_turn *turn, int max);
t_turn		*little_stack_algo(t_turn *turn, int len);
t_turn		*cpy_turn(t_turn *turn);
t_turn		*init_sort(t_turn *head, char *option);
int			parse_arg(char **av);

#endif
