#include "Labyrinthe.h"
#include "colors.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fonction pour créer un labyrinthe vide
Labyrinthe createEmptyLab(int rows, int cols) {
  Labyrinthe lab;
  lab.rows = rows;
  lab.cols = cols;
  lab.pacGommes = 0;

  lab.grid = (char **)malloc(rows * sizeof(char *));
  for (int i = 0; i < rows; i++) {
    lab.grid[i] = (char *)malloc(cols * sizeof(char));
    for (int j = 0; j < cols; j++) {
      lab.grid[i][j] = ' ';
    }
  }

  return lab;
}

// Fonction pour libérer la mémoire d'un labyrinthe
void freeLab(Labyrinthe *lab) {
  for (int i = 0; i < lab->rows; i++) {
    free(lab->grid[i]);
  }
  free(lab->grid);
}

// Fonction pour initialiser un labyrinthe aléatoire
void initLab(Labyrinthe *lab) {
  srand(time(NULL));

  for (int i = 0; i < lab->rows; i++) {
    for (int j = 0; j < lab->cols; j++) {
      lab->grid[i][j] = (rand() % 4 == 0) ? '#' : '.';
    }
  }

  lab->grid[0][0] = 'C'; // Pac-Man start position
  lab->pacGommes = 0;

  for (int i = 0; i < lab->rows; i++) {
    for (int j = 0; j < lab->cols; j++) {
      if (lab->grid[i][j] == '.') {
        lab->pacGommes++;
      }
    }
  }
}

// Fonction pour afficher un labyrinthe dans le terminal
void printScreen(const Labyrinthe *lab) {
  for (int i = 0; i < lab->rows; i++) {
    for (int j = 0; j < lab->cols; j++) {
      switch (lab->grid[i][j]) {
      case '#':
        printf(WALL_COLOR "#"); // Mur
        break;
      case 'C':
        printf(PACMAN_COLOR "C"); // Pac-Man
        break;
      case 'F':
        printf(GHOST_COLOR "F"); // Fantôme
        break;
      default:
        printf(RESET "%c", lab->grid[i][j]); // Pac-gommes et espaces
        break;
      }
    }
    printf(RESET "\n");
  }
}
