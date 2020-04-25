#include <unistd.h>
#include <stdio.h>

int main() {
    while(1) {
        printf("L W L \n");
        fflush(stdout);
        sleep(1);
    }
}
