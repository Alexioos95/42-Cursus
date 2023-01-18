# 42-Cursus

Ce repo contient absolument tous les projets que j'ai fait lors de mon cursus à l'école 42, dans l'ordre par lequel je les ai réalisés.  
Les projets sont ici uploadés tel que je les ai rendus, nul modification n'a été apporté. Des erreurs/maladresses sont donc possiblement présentes dans le code.

Ci-dessous se trouve un court résumé des projets, en plus de leurs dates de commencement/fin, ainsi qu'une estimation du nombre d'heures de travail effectuées.  
Les sujets de chaque projet se trouvent dans les dossiers correspondant.

## [00 - libft](https://github.com/Alexioos95/42-Cursus/tree/main/00%20-%20libft)

Création de ma propre librairie C, contenant principalement des fonctions de la ```glibc```.  
Les "bonus", que j'ai réalisés, sont des fonctions permettant l'utilisation de listes chaînées.

Utilisez ```make``` pour compiler la librairie en format ".a". (```make bonus``` pour le faire avec les bonus.)

Commencé le Lundi 07 Novembre 2022, rendu le Mardi 22 Novembre 2022. (Environ 70 heures de travail)

## [01 - printf](https://github.com/Alexioos95/42-Cursus/tree/main/01%20-%20printf)

Recréation de la fonction printf de la ```glibc```, gérant uniquement les formats suivants : c, s, d, i, u, p, x, X et %.

Utilisez ```make``` pour compiler la librairie en format ".a".

Commencé le Mardi 22 Novembre 2022, rendu le Vendredi 25 Novembre 2022. (Environ 15 heures de travail)

## 02 - born2beroot

Installation et configuration d'une machine virtuelle Debian 11, sous politique de sécurité stricte.

Sujet : https://cdn.intra.42.fr/pdf/pdf/68740/en.subject.pdf (Suite à une mise à jour récente, le sujet n'est disponible qu'en Anglais.)

Commencé le Lundi 28 Novembre 2022, rendu le Lundi 05 Décembre 2022. (Environ 20h de travail)

## [03 - get_next_line](https://github.com/Alexioos95/42-Cursus/tree/main/03%20-%20get_next_line)

Création d'un programme affichant le contenu d'un fichier, ligne par ligne.

Compilez ```get_next_line.c``` et ```get_next_line_utils.c``` pour afficher le fichier pointé en chemin relatif présent dans la fonction ```main``` de ```get_next_line.c```.  
Faîtes le avec ```get_next_line_bonus.c``` et ```get_next_line_utils_bonus.c``` pour afficher plusieurs fichiers en même temps.  
Ajouter le flag ```-D BUFFER_SIZE=n``` lors de la compilation permet de modifier la taille du buffer utilisé par la fonction ```read``` à ```n```. (La taille du buffer à été mise à 42 par défaut.)

Commencé le Mardi 06 Décembre 2022, rendu le Lundi 12 Décembre 2022. (Environ 25h de travail)

## [04 - push_swap](https://github.com/Alexioos95/42-Cursus/tree/main/04%20-%20push_swap)

Création d'un programme triant (en ordre croissant) une pile contenant les nombres passés en argument.

Le programme ne peut utiliser que certaines opérations, qui sont écrites sur le terminal une fois executé.  
Veuillez lire le sujet présent dans le dossier correspondant au projet pour plus de détail.  
Les arguments passés en argument ne doivent contenir aucun doublon, ni dépasser les limites d'un ```int```.
Mon programme utilise un algorithme ```LSD Radix```, en binaire.

Utilisez ```make``` pour compiler le programme en un executable ```push_swap```.  
Executez ensuite ```push_swap```, suivi des nombres à trier.

Commencé le Mercredi 04 Janvier 2023, rendu le Lundi 16 Janvier 2023. (Environ 50h de travail)
