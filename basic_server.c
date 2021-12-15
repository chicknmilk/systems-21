#include "pipe_networking.h"

int toupper(int c) {
  if (c >= 'a' && c <= 'z') {
    return c - 'a' + 'A';
  }
  return c;
}

int main() {

  while (1) {
    int to_client;
    int from_client;

    from_client = server_handshake( &to_client );

    char *res = malloc(BUFFER_SIZE);

    while (1) {
      int fd = read(from_client, res, BUFFER_SIZE);
      
      if (fd == 0) break;
      else {
        int i;
        for (i = 0; i < BUFFER_SIZE; i++) {
          res[i] = toupper(res[i]);
        }
        write(to_client, res, BUFFER_SIZE);
      }
    }

  }


  return 0;
}
