# 42-Cursus

Ce repo contient tous les projets du tronc commun (cursus principal) de l'école 42 de Paris.

## [Projet 00 - libft](https://github.com/Alexioos95/42-Cursus/tree/main/00_libft)

Bibliothèque C, contenant principalement des reproductions de fonctions existantes de la ```glibc```. J'ai cependant évité de l'inclure au projets suivants afin de ne pas avoir à suivre les règles voulues dans ce cas, et ai préféré ré-écrire, souvent différement, les fonctions dont j'avais besoin sur le moment.

Usage: ```make``` afin de créer une bibliothèque static ```libft.a```, que l'on peut ensuite inclure au linkage d'un programme.
```c
#include "libft.h"

int main()
{ ft_putstr_fd("Hello world\n", 0); }
```
```sh
$ cc your_code.c libft.a
$ ./a.out
```

> [!NOTE]  
> Contient un ```make bonus```, qui ajoute des fonctions servant à l'utilisation de listes chaînées à la bibliothèque.

## [Projet 01 - ft_printf](https://github.com/Alexioos95/42-Cursus/tree/main/01_ft_printf)

Bibliothèque C contenant une fonction reproduisant l'utilité de la fonction ```printf``` de la ```glibc```, gérant les formats les plus simples.

Usage: ```make``` afin de créer une bibliothèque static ```libftprintf.a```, que l'on peut ensuite inclure au linkage d'un programme.
```c
#include "libftprintf.h"

int main()
{ int char_printed = ft_printf("Hello %s by from %i\n", "world", 42); }
```
```sh
$ cc your_code.c libftprintf.a
$ ./a.out
```

## Projet 02 - born2beroot

Découverte de la virtualisation, à travers l'installation et configuration d'une machine virtuelle Debian 11 sous politique de sécurité stricte, via VirtualBox.

## [Projet 03 - get_next_line](https://github.com/Alexioos95/42-Cursus/tree/main/03_get_next_line)

Fonction lisant une ligne d'un fichier. L'utiliser plusieurs fois permet de le lire jusqu'à sa fin.

Usage:
```c
#include "get_next_line.h"

int main()
{
	int fd = open("/dev/stdin", O_RDONLY);
	char *str = get_next_line(fd);
	close(fd);

	fd = open("/dev/stdin", O_RDONLY);
	char *file_content = "";
	while (str = get_next_line(fd))
		strjoin(file_content, str);
}
```
```sh
$ cc your_code.c get_next_line.c get_next_line_utils.c
```

> [!NOTE]  
> Contient des sources ```_bonus```, qui permettent à la fonction de faire la différence entre les fds.

## [Projet 04 - push_swap](https://github.com/Alexioos95/42-Cursus/tree/main/04_push_swap)

Programme triant en ordre croissant une pile contenant les nombres passés en argument, en utilisant 2 piles (```a``` et ```b```) et des opérations simples (```PushA```, ```PushB```, ```SwapA```, ```RotateA```, et ```ReverseRotateA```).  
Mon interprétation du projet utilise un algorithme ```LSD Radix``` en binaire.

Usage: ```make``` afin de créer le programme ```push_swap```.
```sh
$ ./push_swap "5" "1 2"
```

## [05 - so_long](https://github.com/Alexioos95/42-Cursus/tree/main/05_so_long)

Simple jeu 2D, réalisé avec la bibliothèque graphique minimale de 42. Le but du jeu est de ramasser tous les collectibles dans un labyrinthe, avant de sortir par la porte.

Usage: ```make``` afin de créer le programme ```so_long```.
```sh
$ ./so_long <map.ber>
$ ./so_long maps/small.ber
```

> [!NOTE]  
> Contient un ```make bonus```, qui permet de lancer un jeu Pac-mac.  
> $ ./so_long bonus/maps_bonus/classic.ber
>   
> Le bonus de ce projet nous permettant de laisser libre cours à notre imagination, je suis parti sur l'idée d'un clone de pac-man ! Les fonctionnalités du jeu étant choisies par moi-même, vous les trouverez détaillées dans le dossier du projet. J'ai cependant utilisé des tics pour le temps des animations, et les ai réglés spécialement pour les postes iMacs de l'école 42 de Paris. Il est donc très fortement probable que le programme tourne en accéléré ou en ralenti sur tout autre système.

## [06 - pipex](https://github.com/Alexioos95/42-Cursus/tree/main/06_pipex)

Programme reproduisant le fonctionnement du pipe (```|```) d'un shell Unix.

Usage: ```make``` afin de créer le programme ```pipex```.
```sh
$ ./pipex <infile> <cmd> <cmd> <outfile>
$ ./pipex /dev/stdin "ls -la" "cat" /dev/stdout
```
> [!NOTE]  
> Contient un ```make bonus```, qui ajoute la gestion de multiple pipes sur une seule ligne de commande, ainsi qu'une gestion prototype de heredocs.  
> $ ./pipex /dev/stdin "ls -la" "cat" "wc -l" /dev/stdout  
> $ ./pipex here_doc delim ls cat /dev/stdout

## [07 - philosophers](https://github.com/Alexioos95/42-Cursus/tree/main/07_philosophers)

Programme faisant une simulation du problème des "Dining Philosophers", avec des ```threads``` et des ```mutex```.

Usage: ```make``` afin de créer le programme ```philo```.
```sh
$ ./philo <nb_philo> <time_to_live> <time_to_eat> <time_to_sleep>
$ ./philo 4 500 200 100
```

## [08 - minishell](https://github.com/Alexioos95/42-Cursus/tree/main/08_minishell)

Reproduction partielle d'un ```shell bash```. Vous pouvez voir le repo utilisé durant le développement du projet [ici](https://github.com/Alexioos95/ms).

Usage: ```make``` afin de créer le programme ```minishell```.
```sh
$ ./minishell
apayen&eewu@minishell$ <cmd>
```

Crédits:  
[Alexis Payen](https://github.com/Alexioos95/) - Mise en place de la boucle Shell; execution des heredocs; expands des variables; fonctions built-ins; gestion de signaux.  
[Eli Ewu](https://github.com/Uweile) - Lexical analyser de l'input; executeur de commande et redirection; récupération des code de status des commandes.

## 09 - netpractice

Petits exercices afin de comprendre comment l'adressage IP fonctionne.

## 10 - cub3d

Programme affichant un labyrinthe en raycasting, avec la bibliothèque graphique minimale de 42.  

> [!IMPORTANT]  
> Projet à réaliser en groupe de deux, mais dû à certaines circonstances du côté de mon partenaire, je refuse de partager le code du projet.

## [11 - piscine cpp](https://github.com/Alexioos95/42-Cursus/tree/main/11_cpp)

Groupement de petits exercices en C++ 98, afin de découvrir la programmation orientée objet.

Chaque module se concentre sur une thématique:

0. Syntaxes C++ et classes  
1. Allocations dynamiques et références  
2. Surcharges d'opérateurs  
3. Héritage  
4. Polymorphisme  
5. Exceptions  
6. Casts  
7. Templates  
8. Containers et itérateurs  
9. Utilisations de containers

## [12 - webserv](https://github.com/Alexioos95/42-Cursus/tree/main/12_webserv)

Développement d'un serveur web HTTP 1.1 non bloquant via multiplexage en C++.  
Veuillez lire le README du dossier pour les détails sur le fichier de configuration.

Usage: ```make``` afin de créer le programme ```webserv```.
```sh
$ ./webserv <config_file>
```

Crédits:  
[Alexis Payen](https://github.com/Alexioos95/) - Entièreté du système de communication entre le serveur et les clients; designing partiel du fichier de configuration.  
[Mathieu Daguenet](https://github.com/Daguenet-Mathieu) - Designing et parsing du fichier de configuration; lancement de scripts CGI et cookies.  
[Eli Ewu](https://github.com/Uweile) - Aide à la création des scripts CGI de test; nettoyage et lisibilité du code.

## [13 - inception](https://github.com/Alexioos95/42-Cursus/tree/main/13_inception)

Découverte de Docker, à travers l'installation d'un site WordPress hébergé sur un Nginx local.

Usage: ```make``` afin de lancer les 3 Dockers, ce qui permettra l'accès au site depuis ```localhost```.

## [14 - ft_transcendance](https://github.com/Alexioos95/transcendance)

Single-page web application d'un jeu Pong en JavaScript Vanilla et Django.

Usage: Créer un ```.env``` dans le dossier service (un exemple est fourni), puis ```make``` afin de lancer les Dockers, ce qui permettra l'accès au site depuis le localhost.

> [!NOTE]  
> Dû au setup de 42, nous avons utilisé le port 4433 sur une VM, avec une redirection sur le port 443 pour le host.

> [!IMPORTANT]  
> Suite à un cruel manque de temps, de nombreuses features ont été abandonnées, en cours de développement ou à l'état de simple idées.  
> Cela comprend un stabilisateur de FPS, ce qui cause le jeu d'être paramétré uniquement pour les Dells de 42 Paris, et étant en accéléré ou ralenti selon les systèmes.

Crédits:  
[Alexis Payen](https://github.com/Alexioos95/) - Entièreté du Front-end (hormis le Tetris); documentation de l'API.  
[Mathieu Daguenet](https://github.com/Daguenet-Mathieu) - Planification et organisation du projet; Back-end côté user, mail et bases de données; Tetris Front-end (abandonnée en cours d'intégration).  
[Fabrice Guarraci](https://github.com/djfg0) - Dockerisation; Back-end côté user et bases de données.  
[Nassim Salhi](https://github.com/Notte7692) - Back-end côté live chat et pong (partiellement abandonné en cours développement).
