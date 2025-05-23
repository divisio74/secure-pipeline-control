/*
** EPITECH PROJECT, 2025
** ref-G-SEC-210-project
** File description:
** load_config
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

void load_config()
{
    char array[8] = {};
    dprintf(1, "Loading configuration file from ./config.ini\n");
    int fd = open("./config.ini", O_RDONLY);

    read(fd, array, 100);
    if (array != 0) {
        printf("\n%s is loaded !\n", array);
    } else {
        printf("failure!\n");
    }
    close(fd);
    return;
}
