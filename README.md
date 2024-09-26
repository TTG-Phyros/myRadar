# MyRadar

**MyRadar** est une simulation de trafic aérien simple mais immersive où les avions voyagent d'un point A à un point B, sous la menace de collisions et d'explosions. Le joueur doit observer et gérer le trafic aérien tout en utilisant les outils à sa disposition pour éviter les accidents.

## 🎮 Gameplay

Les règles du jeu sont simples mais engageantes :

- **Déplacement des avions** : Chaque avion se dirige d'un point A à un point B.
- **Collision et explosion** : Si deux avions se percutent, ils explosent.
- **Tours de contrôle** : Elles protègent les avions et jouent un rôle clé pour éviter les collisions.

L'utilisateur peut interagir avec la simulation en activant ou désactivant plusieurs options.

### ⚙️ Options d'affichage :

- **Sprites** : Les images des avions et éléments de la simulation peuvent être activées ou désactivées pour une meilleure visualisation.
- **Hitboxes** : Les zones d'application des collisions peuvent être affichées ou cachées, selon les préférences de l'utilisateur pour observer les interactions plus précisément.

### ⏲️ Chronomètre :

Un chronomètre est inclus dans la simulation pour permettre à l'utilisateur de garder un œil sur la durée de l'observation, et peut être utilisé pour mesurer la performance ou simplement pour observer le trafic aérien dans une durée définie.

## 🕹️ Contrôles

- **Activer/Désactiver les sprites** : H
- **Activer/Désactiver les hitboxes** : L
- **Observations générales** : L'utilisateur peut observer le trafic aérien et intervenir en activant/désactivant des éléments visuels.

## 📈 Système de gestion

- Les avions voyagent automatiquement de leur point d'origine (A) à leur destination (B).
- Le joueur ne contrôle pas directement les avions, mais peut observer et interagir avec les paramètres visuels.
  
L'objectif principal est de simuler le trafic aérien de manière réaliste tout en évitant les collisions entre avions.

## 🚧 Fonctionnalités à venir

- [ ] Ajout de nouveaux types d'avions avec des comportements variés.
- [ ] Intégration de météo simulée affectant le trafic aérien.
- [ ] Ajout d'un mode gestion de trafic aérien pour influencer les avions.
  
## 🖼️ Captures d'écran

![MyRadar](https://github.com/TTG-Phyros/repositoriesPhotos/blob/main/MyRadar/My_Radar.png)

## 🚀 Installation
### Prérequis

    [MakeFile, SFML, GCC]

## Instructions

### Clone le dépôt :

    git clone https://github.com/ton-compte/MyRadar.git

### Accède au dossier du projet :

    cd MyRadar

### Compile le projet :

    make

### Lance le jeu :

    ./my_radar [script en .rdr]

### Pour Nettoyer les fichiers :

    make fclean