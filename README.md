# 42-Cursus

Ce repo contient absolument tous les projets que j'ai fait lors de mon cursus à l'école 42, dans l'ordre par lequel je les ai réalisés.

Les projets sont ici uploadés tel que je les ai rendus, nulle modification n'a été apporté.  
Des erreurs et maladresses sont donc possiblement présentes dans le code.

Ci-dessous se trouve un court résumé des projets, en plus de leurs dates de commencement/fin, ainsi qu'une estimation du nombre d'heures de travail effectuées.  
Les sujets de chaque projet se trouvent dans les dossiers correspondant.

## [00 - libft](https://github.com/Alexioos95/42-Cursus/tree/main/00%20-%20libft)

Création de ma propre librairie C, contenant principalement des fonctions de la ```glibc```.  
Les "bonus", sont des fonctions permettant l'utilisation de ```listes chaînées```.

Utilisez ```make``` pour compiler la librairie en ```libft.a```. (```make bonus``` pour le faire avec ces derniers.)

Commencé le Lundi 07 Novembre 2022, rendu le Mardi 22 Novembre 2022. (Environ 70 heures de travail)

## [01 - printf](https://github.com/Alexioos95/42-Cursus/tree/main/01%20-%20printf)

Reproduction partielle de la fonction printf de la ```glibc```, gérant uniquement les formats suivants : c, s, d, i, u, p, x, X et %.

Utilisez ```make``` pour compiler la librairie en ```libftprintf.a```.

Commencé le Mardi 22 Novembre 2022, rendu le Vendredi 25 Novembre 2022. (Environ 15 heures de travail)

## 02 - born2beroot

Installation et configuration d'une machine virtuelle Debian 11, sous politique de sécurité stricte.  
en.subject : https://cdn.intra.42.fr/pdf/pdf/68740/en.subject.pdf

Commencé le Lundi 28 Novembre 2022, rendu le Lundi 05 Décembre 2022. (Environ 20h de travail)

## [03 - get_next_line](https://github.com/Alexioos95/42-Cursus/tree/main/03%20-%20get_next_line)

Programme lisant la ligne suivante d'un fichier. (L'utiliser sur le même fichier plusieurs fois permets de le lire, jusqu'à sa fin.)

Compilez ```get_next_line.c``` et ```get_next_line_utils.c``` pour afficher la première ligne du fichier pointé en chemin relatif présent dans la fonction ```main``` de ```get_next_line.c```.  
Faîtes le avec ```get_next_line_bonus.c``` et ```get_next_line_utils_bonus.c``` pour pouvoir afficher celles de plusieurs fichiers en même temps.  
Ajouter le flag ```-D BUFFER_SIZE=n``` lors de la compilation permet de modifier la taille du buffer utilisé par la fonction ```read``` à ```n```. (La taille du buffer à été mise à 42 par défaut.)

Commencé le Mardi 06 Décembre 2022, rendu le Lundi 12 Décembre 2022. (Environ 25h de travail)

## [04 - push_swap](https://github.com/Alexioos95/42-Cursus/tree/main/04%20-%20push_swap)

Programme triant (en ordre croissant) une pile contenant les nombres passés en argument.

Le programme ne peut utiliser que certaines opérations, qui sont écrites sur le terminal une fois executé.  
Veuillez lire le sujet présent dans le dossier correspondant au projet pour plus de détail.  
Les arguments passés en argument ne doivent contenir aucun doublon, ni dépasser les limites d'un ```int```.

Mon interpretation du projet utilise un algorithme ```LSD Radix```, en binaire.

Utilisez ```make``` pour compiler le programme en un executable ```push_swap```.  
Executez ensuite ```push_swap```, suivi des nombres à trier.

Commencé le Mercredi 04 Janvier 2023, rendu le Lundi 16 Janvier 2023. (Environ 50h de travail)

## [05 - so_long](https://github.com/Alexioos95/42-Cursus/tree/main/05%20-%20so_long)

Simple jeu 2D, réalisé avec la ```MiniLibX```, la bibliothèque graphique maison de 42.  
Le but du jeu est de ramasser tous les collectibles dans le labyrinthe, avant de sortir par la porte.

Le bonus de ce projet nous permets de laisser libre cours à notre imagination, et d'utiliser et faire tout ce que l'on veut. Je suis donc parti sur l'idée d'un clone de pac-man !  
Les fonctionnalités du jeu étant choisies par moi-même, vous les trouverez détaillées dans le dossier du projet.

Utilisez ```make``` pour compiler le programme en un executable ```so_long```. (```make bonus``` pour avoir le véritable jeu.)  
Executez ensuite ```so_long```, suivi du chemin relatif d'une carte au format ```.ber```. (Voir le sujet pour les précisions liées à la création de cartes.)  
Le dossier ```maps``` en contient quelques-unes pour tester le programme, et le dossier ```bonus/maps_bonus``` en contient d'autres, faîtes spécialement pour le bonus.

Commencé le Mardi 17 Janvier 2023, rendu le Lundi 27 Mars 2023. (Environ 150h de travail)

## [06 - pipex](https://github.com/Alexioos95/42-Cursus/tree/main/06%20-%20pipex)

Reproduction du fonctionnement du ```pipe``` (|) du système Unix.

Utilisez ```make``` pour compiler le programme en un executable ```pipex```.  
Donnez à l'executable des arguments comme ceci : ```Infile``` ```Command 1``` ```Command 2``` ```Outfile```.  
Le bonus permet d'utiliser plusieurs pipes, ainsi que le ```here_doc``` (<<).

Commencé le Lundi 27 Février 2023, rendu le Lundi 24 Avril 2023. (Environ 70h de travail)

## [07 - philosophers](https://github.com/Alexioos95/42-Cursus/tree/main/07%20-%20philosophers)

Programme reprenant le problème des ```Dining Philosophers```, avec des ```threads``` et des ```mutexs```.

Utilisez ```make``` pour compiler le programme en un executable ```philo```.  
Executez ensuite ```philo```, suivi des paramètres suivants : ```"Nombre_de_philo"``` ```"Temps_de_vie_sans_manger"``` ```"Temps_nécessaire_pour_manger"``` ```"Temps_nécessaire_pour_dormir"``` ```"(Optionnel)_Nombre_de_repas_pour_terminer_la_simulation"```.

Mon interpretation du projet utilise la solution des ```pairs/impairs```, en priorisant les impairs au tout début de la simulation.  
Je fais, en plus, attendre chaque threads une petite portion de leur ```Temps_de_vie_sans_manger``` après qu'ils aient dormis, afin d'éviter un potentiel vol de fourchette.

Commencé le Mardi 25 Avril 2023, rendu le Mardi 16 Mai 2023. (Environ 70h de travail)

## [08 - minishell](https://github.com/Alexioos95/42-Cursus/tree/main/08%20-%20minishell)

Reproduction partielle d'un ```shell bash```.

Utilisez ```make``` pour compiler le programme en un executable ```minishell```.  
Veuillez lire le sujet pour tous les détails.

Réalisé en duo avec [Eli Ewu](https://github.com/Uweile).  
Il s'est occupé du lexical analyser, ainsi que de l'implémentation de l'executeur des commandes et redirections, tandit que j'ai fait tout le reste. (Boucle shell, readline, heredoc, expand, built-ins, et signaux.) Vous pouvez voir le repository utilisé durant le développement du projet [ici](https://github.com/Alexioos95/ms).

Lors des corrections pour rendre le projet, 2 erreurs ont été remarquée. Les correcteurs les ont cependant trouvés suffisamment minime pour tout de même nous valider.  
1 - La recherche en relatif est executé en regardant si l'argument envoyé contient un ```.``` en premier charactère, alors que bash regarde s'il y a un ```/``` quelque part.  
2 - Les signaux se superposent lorsque Minishell est lancé dans Minishell.

Commencé le Lundi 22 Mai 2023, rendu le 22 Septembre 2023. (Environ 450h de travail)

## 09 - netpractice

Petits exercices afin d'apprendre comment l'adressage IP fonctionne.

Commencé le Vendredi 16 Septembre, rendu le Mardi 26 Septembre 2023. (Environ 20h de travail)

## 10 - cub3d

Reproduction du système de raycasting de Wolfenstein 3D, avec la ```MiniLibX```.  
en.subject : https://cdn.intra.42.fr/pdf/pdf/113971/en.subject.pdf

Je m'étais occupé du parsing, tandit que mon partenaire devait prendre en charge la partie des calculs de raycast.  
Cependant, suite à un désaccord et manque de communication entre lui et moi, il a choisi de tout effacer et ré-écrire de lui-même...  
Rien ne sera donc partagé ici.

Commencé le Mardi 15 Aout 2023, rendu le 23 Novembre 2023. (Environ 48h de travail)

## 11 - piscine c++

Piscine de petits exercices en c++, afin de découvrir la programmation orientée objet.

Commencé le Mardi 17 Octobre 2023, rendu progressivement du Vendredi 20 Octobre, au X. (Environ Xh de travail)
