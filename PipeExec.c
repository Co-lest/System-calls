#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main()
{
  int pipefd[2]; //reps the pipe's file descriptors
  int outputFile;

  if (pipe(pipefd) == -1)
  {
    write(STDERR_FILENO, "Error creating pipe\n", 19);
    return 1;
  }

  int pid = fork();

  if (pid == 0)
  {
    // Child process

    // Close read end of pipe
    close(pipefd[0]);
    dup2(pipefd[1], STDOUT_FILENO); // Any standard output to parent process
    // Execute the exec program
    char *args[] = {"hello", "world", NULL};
    if (execv("./exec3", args) == -1)
    {
      write(STDERR_FILENO, "Error executing exec3.c\n", 25);
      return 2;
    }
  }
  else
  {
    // Parent process

    // Close write end of pipe 
    close(pipefd[1]);

    // Read data from pipe
    char buffer[19];
    int bytesRead = read(pipefd[0], buffer, sizeof(buffer));
    if (bytesRead == -1)
    {
      write(STDERR_FILENO, "Error reading from pipe\n", 22);
      return 4;
    }

    int file = open("output.txt", O_WRONLY | O_CREAT, 0777);

    for (int i = 0; i <= sizeof(buffer); i++)
    {
      write(file, &buffer[i], 1);
    }

    close(pipefd[0]); // Close read end of pipe

    // Wait for child process to finish
    wait(NULL);
  }

  return 0;
}
