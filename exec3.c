#include <unistd.h>
#include <fcntl.h>
//extern pipefd[2];

int main() {
  // Generate message
  char message[] = {"From child process!"};

  // Write message to pipe (inherited from parent)
  int bytesWritten = write(STDOUT_FILENO, message, sizeof(message));
  if (bytesWritten == -1) {
    write(STDERR_FILENO, "Error writing to pipe\n", 20);
    return 2;
  }

  return 0;
}
