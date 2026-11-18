#include "kernel/types.h"
#include "user/user.h"

// Crea 3 hijos que hacen trabajo y reportan su avance.
// Con 1 CPU, el orden de los mensajes muestra como reparte la CPU el planificador.
int
main(void)
{
  for (int i = 0; i < 3; i++) {
    if (fork() == 0) {
      for (int ronda = 0; ronda < 3; ronda++) {
        for (volatile int k = 0; k < 20000000; k++)
          ;
        printf("hijo %d, ronda %d, pid %d\n", i, ronda, getpid());
      }
      exit(0);
    }
  }
  for (int i = 0; i < 3; i++)
    wait(0);
  exit(0);
}
