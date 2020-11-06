# Travail pratique 2

## Description

Le but premier de ce travail est de nous initier à la programmation en C. Dans ce travail, nous devrons implémenter les différentes fonctions qui testeront les fonctions présentes dans un programme C déjà compilé en fichier objet. Premier travail pratique à faire pour le cours INF3135 de l'UQÀM, session d'autômne 2020.

## Auteur

Maxime Ouellet (OUEM03019908)

## Fonctionnement

### En utilisant le fichier Makefile :

??? `make` : Exécute la cible `default`. ???

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

`tp2.c` : Contient le code source de mon travail pratique 2.

Répertoire `ressources` : Contient les images pour ce fichier et les fichiers contenant des transactions en entrée.

## Processus de réflexion et démarche

Voir mon processus de réflexion et démarche [ici](reflexion.md) 

## Références

### CUnit

http://cunit.sourceforge.net/example.html

## Statut

Non complété. En cours.

## Autoévaluation

### Fonctionnabilité :

Les tests sont lancés et sont fonctionnels. Ils testent la totalité des restrictions des différentes fonctions. 3.0/3.0

### Bash :

Le script bash liste tous les noms des fonctions dont les tests passent en entièreté. 1.0/1.0

### Compilation :

Il n'y a aucun avertissement ou erreur lors de la compilation et de l'exécution du projet. 1.0/1.0

### Récupération :

La récupération du projet est sans problème et le dépôt est privé. 1.0/1.0

### Branche (git) :

La branche est une branche de développement nommée testunitaire. 1.0/1.0

### Makefile :

Le fichier Makefile offre les quatres services demandés. 2.0/2.0

### Markdown :

Le fichier README est de type markdown et bien structuré. 0.5/0.5

### Professionnel : 

Le projet est simple, organisé et compréhensible. 0.5/0.5



