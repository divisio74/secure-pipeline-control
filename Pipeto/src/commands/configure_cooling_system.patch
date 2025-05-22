/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** configure_cooling_system
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void configure_cooling_system()
{
    char *config_file = "Data/cooling_config.txt";
    char buffer[64];
    FILE *file = fopen(config_file, "r");

    if (!file) {
        printf("Error: Unable to open configuration file: %s\n", config_file);
        return;
    }

    printf("Reading configuration file: %s\n", config_file);
    fread(buffer, 1, sizeof(buffer) - 1, file);
    buffer[sizeof(buffer) - 1] = '\0';
    fclose(file);

    printf("Applying configuration: %s\n", buffer);

    int result = system(buffer);

    if (result == 0) {
        printf("Configuration applied successfully.\n");
    } else {
        printf("Failed to apply configuration. Command returned: %d\n", result);
    }
}

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_safe_command(const char *command)
{
    const char *allowed_commands[] = {"cooling_on", "cooling_off",
        "set_temp"};
    size_t num_commands =
        sizeof(allowed_commands) / sizeof(allowed_commands[0]);

    for (size_t i = 0; i < num_commands; i++) {
        if (strcmp(command, allowed_commands[i]) == 0) {
            return true;
        }
    }
    return false;
}

void configure_cooling_system() {
    char *config_file = "Data/cooling_config.txt";
    char buffer[64];
    FILE *file = fopen(config_file, "r");

    if (!file) {
        printf("Error: Unable to open configuration file.\n");
        return;
    }
    printf("Reading configuration file: %s\n", config_file);
    fgets(buffer, sizeof(buffer), file);
    fclose(file);
    buffer[strcspn(buffer, "\n")] = '\0';
    printf("Applying configuration: %s\n", buffer);
    if (is_safe_command(buffer)) {
        system(buffer);
        printf("Configuration applied successfully.\n");
    } else {
        printf("Failed to apply configuration.\n");
    }
}
