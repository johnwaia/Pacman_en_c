#include "fantome.h"
#include "Labyrinthe.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fonction pour initialiser la position d'un fantôme au hasard
void initFantomeRand(Fantome *fantome, Labyrinthe *lab) {
    srand(time(NULL));
    int x, y;

    do {
        x = rand() % lab->rows;
        y = rand() % lab->cols;
    } while (lab->grid[x][y] != '.'); // Assurez-vous que ce n'est pas un mur ou un autre fantôme

    fantome->x = x;
    fantome->y = y;
    fantome->memoire = NULL;
    fantome->memoireDur = 0;

    // Placer le fantôme sur la grille
    lab->grid[fantome->x][fantome->y] = 'F';
}

// Fonction pour déplacer un fantôme au hasard
void moveFantomeRand(Fantome *fantome, Labyrinthe *lab) {
    int dx = 0, dy = 0;
    int direction = rand() % 4;

    switch (direction) {
    case 0:
        dx = -1;
        break; // Haut
    case 1:
        dx = 1;
        break; // Bas
    case 2:
        dy = -1;
        break; // Gauche
    case 3:
        dy = 1;
        break; // Droite
    }

    int newX = fantome->x + dx;
    int newY = fantome->y + dy;

    if (newX >= 0 && newX < lab->rows && newY >= 0 && newY < lab->cols && lab->grid[newX][newY] != '#' && lab->grid[newX][newY] != 'F') {
        // Effacer la position précédente du fantôme
        lab->grid[fantome->x][fantome->y] = ' ';
        // Mettre à jour la nouvelle position du fantôme
        fantome->x = newX;
        fantome->y = newY;
        lab->grid[fantome->x][fantome->y] = 'F';
    }
}
