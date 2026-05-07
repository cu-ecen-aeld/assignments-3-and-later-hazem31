#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    
    openlog("writer-app", LOG_PID, LOG_USER);

    if (argc != 3) {
        syslog(LOG_ERR, "Invalid number of arguments: %d", argc - 1);
        fprintf(stderr, "Usage: %s <writefile> <writestr>\n", argv[0]);
        return 1;
    }

    const char *writefile = argv[1];
    const char *writestr = argv[2];

    syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);


    int fd = open(writefile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        syslog(LOG_ERR, "Error opening file %s: %s", writefile, strerror(errno));
        return 1;
    }


    if (write(fd, writestr, strlen(writestr)) == -1) {
        syslog(LOG_ERR, "Error writing to file %s: %s", writefile, strerror(errno));
        close(fd);
        return 1;
    }
    
    // TODO: Implement write logic here

    // 6. Clean up
    close(fd);
    closelog();

    return 0;
}