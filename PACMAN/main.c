#include "fantome.h"
#include "Labyrinthe.h"
#include "pacman.h"
#include <stdio.h>
#include <stdlib.h>

void clearInputBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

int main() {
  Labyrinthe lab = createEmptyLab(10, 10);
  initLab(&lab);

  Pacman pacman;
  initPacman(&pacman, 0, 0, &lab);
  lab.grid[pacman.x][pacman.y] = 'C'; // Placer Pac-Man dans la grille

  Fantome fantome;
  initFantomeRand(&fantome, &lab);

  char command;
  while (pacman.enVie && lab.pacGommes > 0) {
    printScreen(&lab);
    printf("Commandes: z (haut), s (bas), q (gauche), d (droite), e (exit)\n");

    command = getchar();
    clearInputBuffer(); // Nettoyer le buffer après getchar()

    switch (command) {
    case 'z':
      movePacmanTop(&pacman, &lab);
      break;
    case 's':
      movePacmanBottom(&pacman, &lab);
      break;
    case 'q':
      movePacmanLeft(&pacman, &lab);
      break;
    case 'd':
      movePacmanRight(&pacman, &lab);
      break;
    case 'e':
      freeLab(&lab);
      return 0;
    }

    moveFantomeRand(&fantome, &lab);

    // Vérifier si Pac-Man rencontre un fantôme
    if (pacman.x == fantome.x && pacman.y == fantome.y) {
      pacman.enVie = 0;
      printf("Pac-Man a été attrapé par un fantôme !\n");
    }
  }

  if (pacman.enVie) {
    printf("Félicitations ! Vous avez mangé toutes les pac-gommes !\n");
  }

  freeLab(&lab);
  return 0;
}
