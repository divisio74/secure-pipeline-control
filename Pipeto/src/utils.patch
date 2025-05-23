#include "ansi-colors.h"
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

void write_color(int fd, const char *color, const char *str)
{
  if (fd < 0 || !color || !str)
      return;
  dprintf(fd, "%s%s%s", color, str, CRESET);
}

int is_valid_file(const char *filename)
{
    struct stat file_stat;
    uid_t user_id;

    if (stat(filename, &file_stat) != 0)
        return 0;
    user_id = getuid();
    if (file_stat.st_uid != user_id)
        return 0;
    if (file_stat.st_mode & (S_IWGRP | S_IWOTH))
        return 0;
    return 1;
}

void process_rc_file(FILE *rc_file)
{
    char line[1024];

    while (fgets(line, sizeof(line), rc_file)) {
        if (line[0] == '#' || line[0] == '\n') {
            continue;
        }
        line[strcspn(line, "\n")] = '\0';
        if (strncmp(line, "exec ", 5) == 0) {
            printf("Executing command: %s\n", line + 5);
            system(line + 5);
        } else {
            printf("Pipeto command: %s\n", line);
        }
    }
}

void load_pipetorc()
{
	FILE *rc_file;
    char *home = getenv("HOME");
    char home_rc[1024];

    snprintf(home_rc, sizeof(home_rc), "%s/.pipetorc", home);
    if (is_valid_file(".pipetorc")) {
    	rc_file = fopen(".pipetorc", "r");
    } else if (is_valid_file(home_rc)) {
        rc_file = fopen(home_rc, "r");
    } else
        return;
    if (!rc_file)
        rc_file = fopen(home_rc, "r");
    if (!rc_file) {
        printf("No valid configuration file found.\n");
        return;
    }
    process_rc_file(rc_file);
    fclose(rc_file);
}

