/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 09:21:15 by gchopin           #+#    #+#             */
/*   Updated: 2021/11/22 10:01:09 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

/*
 ** Check_entries
*/

int		check_entry_a(char *split);
int		check_entry_b(char *split);
int		check_entry_both(char *split);
int		check_entries(t_stack **stack_a, char **split);
int		check_instruction(t_stack **stack_a, char *str);

/* Checker tools
 **
*/

int		compare_strings(char *str_one, char *str_two);
void	free_array(char **ptr);
void	read_parameters(int argc, char **argv, t_stack **stack_a);

/*
 ** Executes check
*/

int		execute_instruction(t_stack **stack_a, char **split);

#endif
