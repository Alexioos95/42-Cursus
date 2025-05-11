# 42-Cursus

Ce repo contient tous les projets du tronc commun (cursus principal) de l'école 42 de Paris, dans l'ordre par lequel je les ai réalisés.

> [!NOTE]  
> Tous les projets (hormis ```get_next_line```) contiennent un Makefile pour compiler les sources.

## [00 - libft](https://github.com/Alexioos95/42-Cursus/tree/main/00_libft)

Création de ma propre librairie C, contenant principalement des reproductions des fonctions de la glibc.  

> [!NOTE]  
> Contient un ```make bonus```, qui ajoute des fonctions de liste chaînées à la librairie.

## [01 - ft_printf](https://github.com/Alexioos95/42-Cursus/tree/main/01_ft_printf)

Reproduction partielle de la fonction ```printf``` de la glibc, gérant les formats suivants : ```%c```, ```%s```, ```%d```, ```%i```, ```%u```, ```%p```, ```%x```, ```%X``` et ```%%```.

## 02 - born2beroot

Installation et configuration d'une machine virtuelle Debian 11, sous politique de sécurité stricte.  

## [03 - get_next_line](https://github.com/Alexioos95/42-Cursus/tree/main/03_get_next_line)

Fonction lisant la ligne suivante d'un fichier. L'utiliser sur le même fichier plusieurs fois permet de le lire jusqu'à sa fin.

> [!NOTE]  
> Contient des sources ```_bonus```, qui permettent de lire la ligne suivante de multiple fichiers, alternativement.

## [04 - push_swap](https://github.com/Alexioos95/42-Cursus/tree/main/04_push_swap)

Programme triant en ordre croissant une pile contenant les nombres passés en argument. Mon interprétation du projet utilise un algorithme ```LSD Radix``` en binaire.

## [05 - so_long](https://github.com/Alexioos95/42-Cursus/tree/main/05_so_long)

Simple jeu 2D, réalisé avec la MiniLibX, la bibliothèque graphique maison de 42. Le but du jeu est de ramasser tous les collectibles dans un labyrinthe, avant de sortir par la porte.

> [!NOTE]  
> Contient un ```make bonus```, qui permet de lancer un jeu Pac-mac.
>   
> Le bonus de ce projet nous permettant de laisser libre cours à notre imagination, je suis parti sur l'idée d'un clone de pac-man ! Les fonctionnalités du jeu étant choisies par moi-même, vous les trouverez détaillées dans le dossier du projet. J'ai cependant utilisé des tics pour le temps des animations, et les ai réglés spécialement pour les postes iMacs de l'école 42 de Paris. Il est donc très fortement probable que le programme tourne en accéléré ou en ralenti sur tout autre système.

## [06 - pipex](https://github.com/Alexioos95/42-Cursus/tree/main/06_pipex)

Reproduction du fonctionnement du pipe (```|```) d'un shell Unix.

> [!NOTE]  
> Contient un ```make bonus```, qui ajoute la gestion de multiple pipes sur une seule ligne de commande, ainsi qu'une gestion prototype de heredocs.

## [07 - philosophers](https://github.com/Alexioos95/42-Cursus/tree/main/07_philosophers)

Programme reprenant le problème des "Dining Philosophers", avec des ```threads``` et des ```mutex```.

## [08 - minishell](https://github.com/Alexioos95/42-Cursus/tree/main/08_minishell)

Reproduction partielle d'un ```shell bash```. Vous pouvez voir le repo utilisé durant le développement du projet [ici](https://github.com/Alexioos95/ms).

Crédits:  
[Alexis Payen](https://github.com/Alexioos95/) - Mise en place de la boucle Shell; execution des heredocs; expands des variables; fonctions built-ins; gestion de signaux.  
[Eli Ewu](https://github.com/Uweile) - Lexical analyser de l'input; executeur de commande et redirection; récupération des code de status des commandes.

## 09 - netpractice

Petits exercices afin de comprendre comment l'adressage IP fonctionne.

## 10 - cub3d

Reproduction du système de raycasting de Wolfenstein 3D, avec la MiniLibX.  

> [!IMPORTANT]  
> Je m'étais occupé du parsing, tandis que mon partenaire devait prendre en charge la partie des calculs de raycast.
> Cependant, due à certaines circonstances, je refuse de partager le code du projet.

## [11 - piscine cpp](https://github.com/Alexioos95/42-Cursus/tree/main/11_cpp)

Piscine de petits exercices en C++ 98, afin de découvrir la programmation orientée objet.

## [12 - webserv](https://github.com/Alexioos95/42-Cursus/tree/main/12_webserv)

Développement d'un serveur web non bloquant via multiplexage en C++.  
Veuillez lire le README du dossier pour les détails sur le fichier de configuration.

Crédits:  
[Alexis Payen](https://github.com/Alexioos95/) - Entièreté du système de communication entre le serveur et les clients; designing partiel du fichier de configuration.  
[Mathieu Daguenet](https://github.com/Daguenet-Mathieu) - Designing et parsing du fichier de configuration; lancement de scripts CGI et cookies.  
[Eli Ewu](https://github.com/Uweile) - Aide à la création des scripts CGI de test; nettoyage et lisibilité du code.

## [13 - inception](https://github.com/Alexioos95/42-Cursus/tree/main/13_inception)

Découverte de Docker, et setup d'un site Wordpress hébergé localement sur Nginx.

## [14 - ft_transcendance](https://github.com/Alexioos95/transcendance)

Single-page web application d'un jeu Pong en JavaScript Vanilla pour le Front-end et Django en Back-end.

> [!NOTE]  
> Le site sera hebergé localement sur le port ```4433```.  

> [!IMPORTANT]  
> Due à un cruel manque de temps, de nombreuses features ont été abandonnées, en cours de développement ou à l'état de simple idées.  
> Cela comprend un stabilisateur de FPS, ce qui cause le jeu d'être paramétré uniquement pour les Dells de 42 Paris, et étant en accéléré ou ralenti selon les systèmes.

Crédits:  
[Alexis Payen](https://github.com/Alexioos95/) - Entièreté du Front-end (hormis le Tetris); documentation de l'API.  
[Mathieu Daguenet](https://github.com/Daguenet-Mathieu) - Planification et organisation du projet; Back-end côté user, mail et bases de données; Tetris Front-end (abandonnée en cours d'intégration).  
[Fabrice Guarraci](https://github.com/djfg0) - Dockerisation; Back-end côté user et bases de données.  
[Nassim Salhi](https://github.com/Notte7692) - Back-end côté live chat et pong (partiellement abandonné en cours développement).
