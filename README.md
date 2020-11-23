# Travail pratique 2

## Description

Ce programme traite des transactions provenant d'une puce qui sont passées au programme au travers du stdin. Ces transactions sont traitées une à la fois et le programme affiche les résultats sur le stdout. 

J'ai complété ce travail dans le cadre du cours INF3135 qui s'est donné à l'automne 2020 à l'Université du Québec à l'UQÀM.

## Auteur

Maxime Ouellet (OUEM03019908)

## Fonctionnement

### En utilisant le fichier Makefile :

`make` : Exécute la cible `default`.

`make lib` : Télécharge ou met à jour les fichiers `tcv.h` et `tcv.o`.

![](./ressources/makeLib.png)

`make tp1` : Produit ou met à jour l'éxécutable `tp1`.

`make tp2` : Produit ou met à jour l'éxécutable `tp2`.

`make test-tp1a` : Exécute le programme `tp1`.

`make test-tp1b` : Exécute le programme `tp1` puis le script `liste.sh`.

`make test-tp2` : Exécute le programme `tp2`.

`make clean` : Réinitialise le projet à son état d'origine.

![](./ressources/makeClean.png)

## Contenu du projet

`.gitignore` : Contient le REGEX des fichiers à ne pas inclure dans le dépôt git.

`Makefile` : Permet de télécharger, produire, réinitialiser et éxécuter le projet.

`cp.txt` : Contient mon code permanent en majuscule.

`liste.sh` : Script bash qui affiche les noms des fonctions qui sont valides et fonctionnelles.

`tp1.c` : Contient le code source de mon travail pratique 1.

`tp2.c` : Contient la fonction main de mon travail pratique 2.

`malib.h` : Fichier headers contenant les fonctions de ma librairie que j'utilise pour le travail pratique 2.

`malib.c` : Fichier contenant le code source des fonctions de ma librairie que j'utilise pour le travail pratique 2.

Répertoire `ressources` : Contient les images pour ce fichier et les fichiers contenant des transactions en entrée (Pour tester).

`reflexion.md` : Démontre ma réflexion par rapport au développement de ce travail.

`tp2.yml` : Workflow pour github.

## Processus de réflexion et démarche

Voir mon processus de réflexion et démarche [ici](reflexion.md).

## Références

### CUnit

http://cunit.sourceforge.net/example.html

## Statut

Complété.

## Autoévaluation

### Récupération :

La récupération du projet est sans problème et le dépôt est privé. 1.0/1.0

### Makefile :

Le fichier Makefile offre tous les services demandés. 2.0/2.0

### malib.h/c :

Détection des inclusions multiples. 1.0/1.0

### Compilation :

Il n'y a aucun avertissement ou erreur lors de la compilation et de l'exécution du projet. 2.0/2.0

### Fonctionnabilité :

Les tests sont lancés et sont fonctionnels. Ils testent la totalité des restrictions des différentes fonctions. 8.0/8.0

### Branche (git) :

La branche est une branche de développement nommée tp2. 1.0/1.0

### Issues (git) :

Je suis intervenu au moins une fois et au plus deux fois. 1.0/1.0

### Optimal (git) :

1.0/1.0

### Professionnel : 

Le projet est simple, organisé et compréhensible. 2.0/2.0

### Markdown :

Le fichier README et reflexion sont de type markdown et bien structurés. 1.0/1.0

### Bonus :

GitHub action (YAML). 1.0/1.0

