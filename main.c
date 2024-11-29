/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miclandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:36:21 by miclandr          #+#    #+#             */
/*   Updated: 2024/11/28 20:38:12 by miclandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
    int fd;
    char *line;
    int line_count = 0;

	(void)argc;

    // Abre el archivo
    fd = open(argv[1], O_RDONLY);

    if (fd == -1)
    {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    // Lee y muestra cada línea
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Línea %d: %s", ++line_count, line);
        free(line);

        // Opción de seguridad para evitar bucles infinitos
        if (line_count > 1000)
        {
            printf("Posible bucle infinito detectado\n");
            break;
        }
    }

    // Comprueba si se alcanzó el final del archivo
    if (line_count == 0)
        printf("El archivo está vacío o hubo un error en la lectura\n");
    else
        printf("Total de líneas leídas: %d\n", line_count);

    // Cierra el archivo
    close(fd);

    return 0;
}
