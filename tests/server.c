#include <constants.h>
#include <e_lib.h>

/*
START_SERVER:
    create TCP socket
    bind to IPv4:port 80, all interfaces
    listen for connections

    LOOP:
        accept a client connection
        fork process
        IF child:
            close server socket
            read HTTP request
            parse method and filename
            IF method == GET:
                open requested file for reading
                read contents
                send HTTP 200 OK
                send file contents
            ELSE IF method == POST:
                parse Content-Length
                find POST data start
                open requested file for writing
                write posted data to file
                send HTTP 200 OK
            exit
        ELSE (parent):
            close client connection
            repeat LOOP
    */

int main(void) { return 0; }