# 42-Cursus

Ce repo contient tous les projets du tronc commun (cursus principal) de l'école 42 de Paris, dans l'ordre par lequel je les ai réalisés. Vous trouverez ci-dessous un très court résumé des projets, en plus de leurs dates de commencement et de fin.

> [!NOTE]  
> Tous les projets (hormis ```get_next_line```) contiennent un Makefile pour compiler les sources.  
> Les projets en C se doivent de strictement suivre la [norme de 42Paris](https://smallpdf.com/file#s=102dad73-62e5-40ec-8122-5b87b83ff6fc), sans quoi la note est automatiquement 0.

## [00 - libft](https://github.com/Alexioos95/42-Cursus/tree/main/00_libft)

Création de ma propre librairie C, contenant principalement des reproductions des fonctions de la glibc.  

> [!NOTE]  
> Contient un ```make bonus```, qui ajoute des fonctions de liste chaînées à la librairie.

Commencé le Lundi 07 Novembre 2022, rendu le Mardi 22 Novembre 2022.

## [01 - ft_printf](https://github.com/Alexioos95/42-Cursus/tree/main/01_ft_printf)

Reproduction partielle de la fonction ```printf``` de la glibc, gérant les formats suivants : ```%c```, ```%s```, ```%d```, ```%i```, ```%u```, ```%p```, ```%x```, ```%X``` et ```%%```.

Commencé le Mardi 22 Novembre 2022, rendu le Vendredi 25 Novembre 2022.

## 02 - born2beroot

Installation et configuration d'une machine virtuelle Debian 11, sous politique de sécurité stricte.  
en.subject : https://smallpdf.com/fr/file#s=5a9178ba-c3b4-4516-886f-7af9d29a3b0e

Commencé le Lundi 28 Novembre 2022, rendu le Lundi 05 Décembre 2022.

## [03 - get_next_line](https://github.com/Alexioos95/42-Cursus/tree/main/03_get_next_line)

Fonction lisant la ligne suivante d'un fichier. L'utiliser sur le même fichier plusieurs fois permet de le lire, jusqu'à sa fin.

> [!NOTE]  
> Contient des sources ```_bonus```, qui permet de lire la ligne suivante de multiple fichier, alternativement.

Commencé le Mardi 06 Décembre 2022, rendu le Lundi 12 Décembre 2022.

## [04 - push_swap](https://github.com/Alexioos95/42-Cursus/tree/main/04_push_swap)

Programme triant en ordre croissant une pile contenant les nombres passés en argument. Mon interprétation du projet utilise un algorithme ```LSD Radix```, en binaire.

Commencé le Mercredi 04 Janvier 2023, rendu le Lundi 16 Janvier 2023.

## [05 - so_long](https://github.com/Alexioos95/42-Cursus/tree/main/05_so_long)

Simple jeu 2D, réalisé avec la MiniLibX, la bibliothèque graphique maison de 42. Le but du jeu est de ramasser tous les collectibles dans un labyrinthe, avant de sortir par la porte.

> [!NOTE]  
> Contient un ```make bonus```, qui permet de lancer un jeu Pac-mac.
>   
> Le bonus de ce projet nous permettant de laisser libre cours à notre imagination, je suis parti sur l'idée d'un clone de pac-man ! Les fonctionnalités du jeu étant choisies par moi-même, vous les trouverez détaillées dans le dossier du projet. J'ai cependant utilisé des tics pour le temps des animations, et les ai réglé spécialement pour les postes iMacs de l'école 42 de Paris. Il est donc très fortement probable que le programme tourne en accéléré ou en ralenti sur votre système.

Commencé le Mardi 17 Janvier 2023, rendu le Lundi 27 Mars 2023.

## [06 - pipex](https://github.com/Alexioos95/42-Cursus/tree/main/06_pipex)

Reproduction du fonctionnement du pipe (```|```) d'un shell Unix.

> [!NOTE]  
> Contient un ```make bonus```, qui ajoute la gestion de multiple pipes sur une seule ligne de commande, ainsi qu'une gestion prototype de heredocs.

Commencé le Lundi 27 Février 2023, rendu le Lundi 24 Avril 2023.

## [07 - philosophers](https://github.com/Alexioos95/42-Cursus/tree/main/07_philosophers)

Programme reprenant le problème des "Dining Philosophers", avec des ```threads``` et des ```mutex```. Mon interprétation du projet utilise la solution des ```pairs/impairs```, en priorisant les impairs au tout début de la simulation.

Commencé le Mardi 25 Avril 2023, rendu le Mardi 16 Mai 2023.

## [08 - minishell](https://github.com/Alexioos95/42-Cursus/tree/main/08_minishell)

Reproduction partielle d'un ```shell bash```. Vous pouvez voir le repo utilisé durant le développement du projet [ici](https://github.com/Alexioos95/ms).

Crédits:  
[Alexis Payen](https://github.com/Alexioos95/) - Mise en place de la boucle Shell; execution des heredocs; expands des variables; fonctions built-ins; gestion de signaux.  
[Eli Ewu](https://github.com/Uweile) - Lexical analyser de l'input; executeur de commande et redirection; récupération des code de status des commandes.

Commencé le Lundi 22 Mai 2023, rendu le 22 Septembre 2023.

## 09 - netpractice

Petits exercices afin d'apprendre comment l'adressage IP fonctionne.

Commencé le Vendredi 16 Septembre, rendu le Mardi 26 Septembre 2023.

## 10 - cub3d

Reproduction du système de raycasting de Wolfenstein 3D, avec la MiniLibX.  
en.subject : https://smallpdf.com/fr/file#s=76d950c0-e29b-498e-bced-f6e125c5d4cb

> [!IMPORTANT]  
> Je m'étais occupé du parsing, tandis que mon partenaire devait prendre en charge la partie des calculs de raycast.
> Cependant, due à certaines circonstances, je refuse de partager le code du projet.

Commencé le Mardi 15 Aout 2023, rendu le 23 Novembre 2023.

## [11 - piscine cpp](https://github.com/Alexioos95/42-Cursus/tree/main/11_cpp)

Piscine de petits exercices en C++, afin de découvrir la programmation orientée objet.

Commencé le Mardi 17 Octobre 2023, rendu progressivement du Vendredi 20 Octobre, au Vendredi 07 Décembre 2023.

## [12 - webserv](https://github.com/Alexioos95/42-Cursus/tree/main/12_webserv)

Développement d'un serveur web non bloquant via multiplexage en C++.  
Veuillez lire le README du dossier pour les détails sur le fichier de configuration.

Crédits:  
[Alexis Payen](https://github.com/Alexioos95/) - Entièreté du système de communication entre le serveur et les clients; designing partiel du fichier de configuration.  
[Mathieu Daguenet](https://github.com/Daguenet-Mathieu) - Designing et parsing du fichier de configuration; lancement de scripts CGI et cookies.  
[Eli Ewu](https://github.com/Uweile) - Aide à la création des scripts CGI de test; nettoyage et lisibilité du code.

Commencé le Jeudi 14 Décembre 2023, rendu le Jeudi 28 Mars 2024.

## [13 - inception](https://github.com/Alexioos95/42-Cursus/tree/main/13_inception)

Découverte de Docker, et setup d'un site Wordpress hébergé localement sur Nginx.

Commencé le Mardi 9 Avril, rendu le Vendredi 19 Avril 2024.

## [14 - ft_transcendance](https://github.com/Alexioos95/transcendance)

Single-page web application d'un jeu Pong en JavaScript Vanilla pour le Front-end et Django en Back-end.

> [!NOTE]  
> Le site sera herbergé localement sur le port ```4433```.

> [!IMPORTANT]  
> Dûe à un cruel manque de temps, de nombreuses features ont été abandonné, en cours de développement ou à l'état de simple idées.

Crédits:  
[Alexis Payen](https://github.com/Alexioos95/) - Entièreté du Front-end (hormis le Tetris abandonné en cours de développement); documentation de l'API.  
[Mathieu Daguenet](https://github.com/Daguenet-Mathieu) - Planification et organisation du projet; Back-end côté user, mail et bases de données; Tetris Front-end (abandonnée en cours développement).  
[Fabrice Guarraci](https://github.com/djfg0) - Dockerisation; Back-end côté user et bases de données.  
[Nassim Salhi](https://github.com/Notte7692) - Back-end côté live chat et pong (partiellement abandonnée en cours développement).

Commencé le Mercredi 22 Mai 2024, rendu le 18 Septembre 2024.
