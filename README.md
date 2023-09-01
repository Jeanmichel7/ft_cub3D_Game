# Cub3D - 42 School Project

## 📋 Résumé

Cub3D est un projet de ray-casting qui s'inspire du légendaire jeu vidéo Wolfenstein 3D. Ce projet est conçu pour vous permettre d'explorer la technique du ray-casting. Il vous offre également une petite fenêtre pour aborder le monde complexe de la programmation graphique.

### Fonctionnalités

- Affichage en 3D à la première personne d'un labyrinthe
- Utilisation de textures pour les murs
- Affichage de sprites (objets)
- Parsing de fichiers de configuration pour les textures, les sprites et les paramètres de la carte

## 💻 Technologies Utilisées

- Langage de programmation C
- Bibliothèque graphique MinilibX
- Makefile pour la compilation

## 📦 Installation

Pour installer ce projet sur votre machine locale, suivez les étapes suivantes:

```bash
git clone https://github.com/Jeanmichel7/Cub3D.git
cd Cub3D
make[ bonus]
```

## 📜 Règles du projet

- Le projet doit être compilé à l'aide du Makefile fourni.
- Aucune fuite de mémoire n'est tolérée.
- Utilisation obligatoire du ray-casting pour la 3D.
- Normes de code
- Utilisation des bibliothèques autorisées uniquement

## 🛠️ Utilisation

Lancement du programme
Après la compilation, lancez le programme avec la commande suivante :

```bash
./cub3D maps/mandatory.cub
```

```bash
./cub3D_bonus maps/bonus.cub
```

### Configuration

Les fichiers de configuration .cub contiennent les informations nécessaires pour le rendu graphique, telles que les chemins vers les textures et les sprites, les couleurs du plafond et du sol, et la carte initiale.

### Contrôles

W pour avancer
S pour reculer
A pour aller à gauche
D pour aller à droite
Flèche gauche pour tourner à gauche
Flèche droite pour tourner à droite

## Gallery
