/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames_calculate_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:32:43 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/12/29 19:38:16 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

long long	current_time_in_milliseconds(void)
{
	struct timeval	te;
	long long		milliseconds;

	gettimeofday(&te, NULL);
	milliseconds = te.tv_sec * 1000LL + te.tv_usec / 1000;
	return (milliseconds);
}

void	calculate_frames(int *image, int *image_enemies)
{
	static long long	old_time_coins;
	static long long	old_time_enemies;
	long long			current_time;

	current_time = current_time_in_milliseconds();
	if (old_time_coins == 0)
		old_time_coins = current_time;
	if (old_time_enemies == 0)
		old_time_enemies = current_time;
	if (current_time - old_time_coins >= COINS_ANIM_SPEED)
	{
		(*image)++;
		if (*image == 18)
			*image = 0;
		old_time_coins = current_time;
	}
	if (current_time - old_time_enemies >= PLAYER_ANIM_SPEED)
	{
		(*image_enemies)++;
		if (*image_enemies == 4)
			*image_enemies = 0;
		old_time_enemies = current_time;
	}
}
