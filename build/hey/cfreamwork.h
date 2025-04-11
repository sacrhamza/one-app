/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cfreamwork.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsacr <hsacr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 23:36:04 by hsacr             #+#    #+#             */
/*   Updated: 2025/04/11 18:54:31 by hsacr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CFREAMWORK_H
# define CFREAMWORK_H
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>
# include "libft.h"
# include "colors.h"
# define TRUE 1
# define FALSE 0

//this function can check wheter the string is 
//numbers or not
//empty string or string that contains only spaces ' ' are not valid
int	is_nbr(char *str);
#endif
