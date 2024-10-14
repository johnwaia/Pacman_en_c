# Projet Pacman en C

Ce projet implémente un jeu classique de Pacman en utilisant le langage de programmation C. Le jeu se déroule dans un labyrinthe où le joueur contrôle Pacman pour collecter des points tout en évitant des fantômes.

## Structure du Projet

Le projet est composé des fichiers suivants :

- **famtome.h / famtome.c** : Gère les comportements et les mouvements des fantômes dans le labyrinthe.
- **pacman.h / pacman.c** : Contient la logique du personnage Pacman, y compris ses mouvements et les interactions avec les éléments du jeu.
- **labirymte.h / labirymte.c** : Définit la structure du labyrinthe, y compris le chargement et l'affichage du labyrinthe.

## Compilation

Pour compiler le projet, assurez-vous d'avoir un compilateur C installé sur votre système. Vous pouvez utiliser `gcc` pour compiler les fichiers :

```bash
gcc -o pacman pacman.c famtome.c labirymte.c
```

## Exécution

Une fois le projet compilé, vous pouvez exécuter le jeu avec la commande suivante :

```bash
./pacman
```

## Instructions de jeu

- Utilisez les touches fléchées pour déplacer Pacman dans le labyrinthe.
- Collectez les points et évitez les fantômes.
- Le jeu se termine lorsque Pacman est touché par un fantôme.

## Contribuer

Les contributions sont les bienvenues ! N'hésitez pas à soumettre des pull requests ou à ouvrir des issues pour signaler des bogues ou suggérer des améliorations.

## License

Ce projet est sous licence MIT. Voir le fichier [LICENSE](LICENSE) pour plus de détails.

