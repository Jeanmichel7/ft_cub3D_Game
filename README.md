# Cub3D - 42 School Project

<img src="https://github.com/Jeanmichel7/ft_cub3D_Game/blob/image/Screenshot%202023-09-01%20223140.png" alt="Cub3D" width="400"/>

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

<table>
  <tr>
    <td>
      <img src="https://raw.githubusercontent.com/Jeanmichel7/ft_cub3D_Game/image/Screenshot%202023-09-01%20222732.png" alt="Image 1" width="800"/>
    </td>
    <td>
      <img src="https://raw.githubusercontent.com/Jeanmichel7/ft_cub3D_Game/image/Screenshot%202023-09-01%20223049.png" alt="Image 2" width="1200"/>
    </td>
  </tr>
</table>
