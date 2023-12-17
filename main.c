/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:16:13 by jeada-si          #+#    #+#             */
/*   Updated: 2023/12/15 13:56:12 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "mlx.h

int main(void)
{
    void    *conn;
    void    *window;

    conn = mlx_init();
    window = mlx_new_window(conn, 500, 500, "mlx 42");
    mlx_string_put(conn, window, 250, 250, 0xFFFFFF, "Hello World!");
    sleep(5);
    mlx_destroy_window(conn, window);
}
