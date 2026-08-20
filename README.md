# 42-Cursus

Ce repo contient tous les projets du tronc commun (cursus principal) de l'école 42 de Paris.

## [Projet 00 - libft](https://github.com/Alexioos95/42-Cursus/tree/main/00_libft)

Bibliothèque C contenant principalement des reproductions de fonctions existantes de la ```glibc```.

Usage: ```make``` afin de créer une bibliothèque statique ```libft.a```, que l'on peut ensuite inclure au linking d'un programme.
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

Bibliothèque C contenant une fonction reproduisant le fonctionnement de la fonction ```printf``` de la ```glibc```, gérant les formats les plus simples.

Usage: ```make``` afin de créer une bibliothèque statique ```libftprintf.a```, que l'on peut ensuite inclure au linking d'un programme.
```c
#include "libftprintf.h"

int main()
{ int char_printed = ft_printf("Hello %s from %i\n", "world", 42); }
```
```sh
$ cc your_code.c libftprintf.a
$ ./a.out
```

## Projet 02 - born2beroot

Découverte de la virtualisation avec VirtualBox, à travers l'installation et configuration d'une machine virtuelle Debian 11 sous politique de sécurité stricte.

## [Projet 03 - get_next_line](https://github.com/Alexioos95/42-Cursus/tree/main/03_get_next_line)

Fonction permettant de lire un fichier, ligne par ligne. Plusieurs appels successifs permettent de parcourir le fichier jusqu'à sa fin.

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
	printf("%s\n", file_content);
}
```
```sh
$ cc your_code.c get_next_line.c get_next_line_utils.c
$ ./a.out
```

> [!NOTE]  
> Contient des sources ```<nom>_bonus```, qui permettent à la fonction de faire la différence entre plusieurs descripteur de fichier (fd).

## [Projet 04 - push_swap](https://github.com/Alexioos95/42-Cursus/tree/main/04_push_swap)

Programme triant dans l'ordre croissant une pile contenant les nombres passés en argument, en utilisant deux piles (```a``` et ```b```) et des opérations simples (```PushA```, ```PushB```, ```SwapA```, ```RotateA```, et ```ReverseRotateA```). Mon interprétation du projet utilise un algorithme ```LSD Radix``` en binaire.

Usage: ```make``` afin de créer le programme ```push_swap```.
```sh
$ ./push_swap "5" "1 2"
```

## [Projet 05 - so_long](https://github.com/Alexioos95/42-Cursus/tree/main/05_so_long)

Simple jeu 2D, réalisé avec la bibliothèque graphique minimale de 42. Le but du jeu est de ramasser tous les collectibles dans un labyrinthe, avant de sortir par la porte.

Usage: ```make``` afin de créer le programme ```so_long```.
```sh
$ ./so_long <map>.ber
$ ./so_long maps/small.ber
```

> [!NOTE]  
> Contient un ```make bonus```, qui permet de lancer un jeu Pac-man.  
> $ ./so_long bonus/maps_bonus/classic.ber
>   
> Le bonus de ce projet nous permettant de laisser libre cours à notre imagination, je suis parti sur l'idée d'un clone de pac-man ! Les fonctionnalités du jeu étant choisies par moi-même, vous les trouverez détaillées dans le dossier du projet. J'ai cependant utilisé des ticks pour le temps des animations, et les ai réglés spécialement pour les postes iMacs de l'école 42 de Paris. Il est donc très fortement probable que le programme tourne en accéléré ou en ralenti sur tout autre système.

## [Projet 06 - pipex](https://github.com/Alexioos95/42-Cursus/tree/main/06_pipex)

Programme reproduisant le fonctionnement du pipe (```|```) d'un shell Unix.

Usage: ```make``` afin de créer le programme ```pipex```.
```sh
$ ./pipex <infile> <cmd> <cmd> <outfile>
$ ./pipex /dev/stdin "ls -la" "cat" /dev/stdout
```
> [!NOTE]  
> Contient un ```make bonus``` qui ajoute la gestion de plusieurs pipes sur une seule ligne de commande, ainsi qu'une gestion expérimentale des heredocs.
> 
> $ ./pipex /dev/stdin "ls -la" "cat" "wc -l" /dev/stdout  
> $ ./pipex here_doc delim ls cat /dev/stdout

## [Projet 07 - philosophers](https://github.com/Alexioos95/42-Cursus/tree/main/07_philosophers)

Programme faisant une simulation du problème des "Dining Philosophers", à l'aide ```threads``` et ```mutex```.

Usage: ```make``` afin de créer le programme ```philo```.
```sh
$ ./philo <nb_philo> <time_to_live> <time_to_eat> <time_to_sleep>
$ ./philo 4 500 200 100
```

## [Projet 08 - minishell](https://github.com/Alexioos95/42-Cursus/tree/main/08_minishell)

Reproduction partielle d'un shell ```Bash```.

Usage: ```make``` afin de créer le programme ```minishell```.
```sh
$ ./minishell
apayen&eewu@minishell$ <cmd>

$ ./minishell
apayen&eewu@minishell$ cat Makefile|ls -la >./test
```

Crédits:  
[Alexis Payen](https://github.com/Alexioos95/) - Mise en place de la boucle Shell; exécution des heredocs; expansion des variables; fonctions built-ins; gestion de signaux.  
[Eli Ewu](https://github.com/Uweile) - Analyseur lexical de l'input; executeur de commande et redirection; récupération des code de statut des commandes.

## Projet 09 - netpractice

Petits exercices afin de comprendre comment l'adressage IP fonctionne.

## Projet 10 - cub3d

Programme affichant un labyrinthe en raycasting, avec la bibliothèque graphique minimale de 42.  

> [!IMPORTANT]  
> Projet à réaliser en groupe de deux. Cependant, en raison de certaines circonstances du côté de mon partenaire, je ne partagerai pas le code du projet ici.

## [Projet 11 - piscine C++](https://github.com/Alexioos95/42-Cursus/tree/main/11_cpp)

Groupement de petits exercices en C++98, afin de découvrir la programmation orientée objet. Chaque module se concentre sur une thématique:

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

## [Projet 12 - webserv](https://github.com/Alexioos95/42-Cursus/tree/main/12_webserv)

Développement d'un serveur web HTTP 1.1 non bloquant via le multiplexage en C++.  
Veuillez lire le README du dossier pour les détails sur le fichier de configuration.

Usage: ```make``` afin de créer le programme ```webserv```.
```sh
$ ./webserv <config_file>
```

Crédits:  
[Alexis Payen](https://github.com/Alexioos95/) - Totalité du système de communication entre le serveur et les clients; conception partiel du fichier de configuration.  
[Mathieu Daguenet](https://github.com/Daguenet-Mathieu) - Conception et parsing du fichier de configuration; lancement de scripts CGI et cookies.  
[Eli Ewu](https://github.com/Uweile) - Aide à la création des scripts CGI de test; nettoyage et lisibilité du code.

## [Projet 13 - inception](https://github.com/Alexioos95/42-Cursus/tree/main/13_inception)

Découverte de Docker, à travers l'installation d'un site WordPress hébergé sur un Nginx local.

Usage: ```make``` afin de lancer les 3 containers, ce qui permettra l'accès au site depuis ```localhost```.

## [Projet 14 - ft_transcendance](https://github.com/Alexioos95/transcendance)

Single Page Application (SPA) d'un jeu Pong en JavaScript et Django.

Usage: Créer un ```.env``` dans le dossier service (un exemple est fourni), puis ```make``` afin de lancer les containers, ce qui permettra l'accès au site depuis ```localhost```.

Crédits:  
[Alexis Payen](https://github.com/Alexioos95/) - Entièreté du Front-end (hormis le Tetris); documentation de l'API.  
[Mathieu Daguenet](https://github.com/Daguenet-Mathieu) - Planification et organisation du projet; Back-end côté utilisateur, mail et bases de données; Tetris Front-end (abandonné en cours d'intégration).  
[Fabrice Guarraci](https://github.com/djfg0) - Dockerisation; Back-end côté utilisateur et bases de données.  
[Nassim Salhi](https://github.com/Notte7692) - Back-end côté live chat et pong (partiellement abandonné en cours de développement).
