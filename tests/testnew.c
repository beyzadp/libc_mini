// libc_mini/tests/test.c

#include <constants.h>
#include <e_lib.h>
#include <syscall.h>

int main(void) {
  const char *http_200 = "HTTP/1.0 200 OK\r\n\r\n";
  const char *http_404 = "HTTP/1.0 404 Not Found\r\n\r\n";
  const char *new_line = "\n";
  const char *content_length = "Content-Length: ";
  char *buffer =
      "POST /post_test HTTP/1.1\r\nHost: localhost:1234\r\nUser-Agent: "
      "curl/8.16.0\r\nAccept: */*\r\nContent-Length: 7\r\nContent-Type: "
      "application/x-www-form-urlencoded\r\n\r\nhelowerewrw";
  char *test = "helloworld";

  int len_content = 0;
  const char *pos = NULL;
  pos = e_strstr(buffer, content_length);
  if (pos) {
    pos += e_strlen(content_length);
    // Skip whitespace
    while (*pos == ' ' || *pos == '\t')
      pos++;
    // Parse digits
    while (*pos >= '0' && *pos <= '9')
      len_content = len_content * 10 + (*pos++ - '0');
  }

  // now len_content has the length of the content
  // i double checked this. its working.

  const char *post_content = e_strstr(buffer, "helo");
  if (post_content) {
    post_content += 4;                   // Skip exactly past the separator
    write(1, post_content, len_content); // debug print to stdout
  } else {
    write(1, "Could not find POST body\n", 25);
  } // add new lines
}
