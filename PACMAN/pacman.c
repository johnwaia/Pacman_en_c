#include "pacman.h"
#include "Labyrinthe.h"

// Fonction pour initialiser la position de Pac-Man
void initPacman(Pacman *pacman, int x, int y, Labyrinthe *lab) {
  pacman->x = x;
  pacman->y = y;
  pacman->pacGommesMangees = 0;
  pacman->enVie = 1;
}

// Fonction pour déplacer Pac-Man vers le haut
void movePacmanTop(Pacman *pacman, Labyrinthe *lab) {
  if (pacman->x > 0 && lab->grid[pacman->x - 1][pacman->y] != '#') {
    // Mettre à jour la grille
    lab->grid[pacman->x][pacman->y] = ' ';
    pacman->x--;
    // Mettre à jour la grille avec la nouvelle position
    if (lab->grid[pacman->x][pacman->y] == '.') {
      pacman->pacGommesMangees++;
      lab->pacGommes--;
    }
    lab->grid[pacman->x][pacman->y] = 'C';
  }
}

// Fonction pour déplacer Pac-Man vers le bas
void movePacmanBottom(Pacman *pacman, Labyrinthe *lab) {
  if (pacman->x < lab->rows - 1 && lab->grid[pacman->x + 1][pacman->y] != '#') {
    // Mettre à jour la grille
    lab->grid[pacman->x][pacman->y] = ' ';
    pacman->x++;
    // Mettre à jour la grille avec la nouvelle position
    if (lab->grid[pacman->x][pacman->y] == '.') {
      pacman->pacGommesMangees++;
      lab->pacGommes--;
    }
    lab->grid[pacman->x][pacman->y] = 'C';
  }
}

// Fonction pour déplacer Pac-Man vers la gauche
void movePacmanLeft(Pacman *pacman, Labyrinthe *lab) {
  if (pacman->y > 0 && lab->grid[pacman->x][pacman->y - 1] != '#') {
    // Mettre à jour la grille
    lab->grid[pacman->x][pacman->y] = ' ';
    pacman->y--;
    // Mettre à jour la grille avec la nouvelle position
    if (lab->grid[pacman->x][pacman->y] == '.') {
      pacman->pacGommesMangees++;
      lab->pacGommes--;
    }
    lab->grid[pacman->x][pacman->y] = 'C';
  }
}

// Fonction pour déplacer Pac-Man vers la droite
void movePacmanRight(Pacman *pacman, Labyrinthe *lab) {
  if (pacman->y < lab->cols - 1 && lab->grid[pacman->x][pacman->y + 1] != '#') {
    // Mettre à jour la grille
    lab->grid[pacman->x][pacman->y] = ' ';
    pacman->y++;
    // Mettre à jour la grille avec la nouvelle position
    if (lab->grid[pacman->x][pacman->y] == '.') {
      pacman->pacGommesMangees++;
      lab->pacGommes--;
    }
    lab->grid[pacman->x][pacman->y] = 'C';
  }
}
