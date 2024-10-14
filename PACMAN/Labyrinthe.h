#ifndef LABYRINTHE_H
#define LABYRINTHE_H

typedef struct {
  char **grid;   // Matrice représentant le labyrinthe
  int rows;      // Nombre de lignes
  int cols;      // Nombre de colonnes
  int pacGommes; // Nombre de pac-gommes restantes
} Labyrinthe;

// Fonction pour créer un labyrinthe vide
Labyrinthe createEmptyLab(int rows, int cols);

// Fonction pour libérer la mémoire d'un labyrinthe
void freeLab(Labyrinthe *lab);

// Fonction pour initialiser un labyrinthe aléatoire
void initLab(Labyrinthe *lab);

// Fonction pour afficher un labyrinthe dans le terminal
void printScreen(const Labyrinthe *lab);

// Fonction pour copier un labyrinthe
Labyrinthe copieLab(const Labyrinthe *lab);

#endif // LABYRINTHE_H
