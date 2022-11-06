#include <mqueue.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void arg_error(void)
{
    const char *error_msg = "argv[1] = text to read from.\nargv[2] = size of text.\nargv[3] = name of message queue.\nargv[4] = msgsize.\n";
    fprintf(stderr, error_msg, strlen(error_msg));
    exit(1);
}

void error_output(char* msg)
{
    fprintf(stderr, msg, strlen(msg));
    exit(1);
}

/**
 * argv[1] = text to read from.
 * argv[2] = size of text.
 * argv[3] = name of message queue.
 * argv[4] = msqsize.
 **/
int main(int argc, char** argv)
{
    if(argc < 5)
        arg_error();

    const char *text_name = argv[1];
    int text_size = atoi(argv[2]);
    const char *mq_name = argv[3];
    int mq_msgsize = atoi(argv[4]);
    int maxmsg = 1;
    int flags = O_WRONLY;
    char buffer[text_size];

    struct mq_attr attr, *attr_ptr;


    int fd = open(text_name, O_RDONLY);
    ssize_t read_bytes = read(fd, buffer, text_size);



    fprintf(stdout, buffer, read_bytes);



}
