# 42-Cursus

Ce repo contient tous les projets du tronc commun de l'école 42 de Paris, dans l'ordre par lequel je les ai réalisés.  
Les sujets de chaque projet se trouvent dans les dossiers correspondants.

Vous trouverez ci-dessous un court résumé des projets, en plus de leurs dates de commencement et de fin, ainsi qu'une estimation du nombre d'heures de travail effectuées. Les heures de travail approximatives ne sont pas uniquement le temps passé à écrire le code, mais également le temps nécessaire pour chercher et lire de la documentation, discuter des interprétations et choix d'implémentations avec mes collègues, et de tester le tout.

> [!NOTE]  
> Les projets en C se doivent de strictement suivre la [norme de 42Paris](https://smallpdf.com/file#s=102dad73-62e5-40ec-8122-5b87b83ff6fc), sans quoi la note est automatiquement 0.

## [00 - libft](https://github.com/Alexioos95/42-Cursus/tree/main/00_libft)

Création de ma propre librairie C, contenant principalement des reproductions des fonctions de la glibc.  
Les "bonus", sont des fonctions permettant l'utilisation de listes chaînées.

Utilisez ```make``` pour compiler la librairie en ```libft.a```. (```make bonus``` pour le faire avec ces derniers.)

Commencé le Lundi 07 Novembre 2022, rendu le Mardi 22 Novembre 2022. (Environ 70 heures de travail)

## [01 - ft_printf](https://github.com/Alexioos95/42-Cursus/tree/main/01_ft_printf)

Reproduction partielle de la fonction ```printf``` de la glibc, gérant les formats suivants : ```%c```, ```%s```, ```%d```, ```%i```, ```%u```, ```%p```, ```%x```, ```%X``` et ```%%```.

Utilisez ```make``` pour compiler la librairie en ```libftprintf.a```.

Commencé le Mardi 22 Novembre 2022, rendu le Vendredi 25 Novembre 2022. (Environ 15 heures de travail)

## 02 - born2beroot

Installation et configuration d'une machine virtuelle Debian 11, sous politique de sécurité stricte.  
en.subject : https://smallpdf.com/fr/file#s=5a9178ba-c3b4-4516-886f-7af9d29a3b0e

Commencé le Lundi 28 Novembre 2022, rendu le Lundi 05 Décembre 2022. (Environ 20h de travail)

## [03 - get_next_line](https://github.com/Alexioos95/42-Cursus/tree/main/03_get_next_line)

Programme lisant la ligne suivante d'un fichier. (L'utiliser sur le même fichier plusieurs fois permet de le lire, jusqu'à sa fin.)

Compilez ```get_next_line.c``` et ```get_next_line_utils.c``` pour afficher la première ligne du fichier pointé (en chemin relatif présent) dans la fonction ```main``` de ```get_next_line.c```. Faites le avec ```get_next_line_bonus.c``` et ```get_next_line_utils_bonus.c``` pour pouvoir afficher celles de plusieurs fichiers en même temps.

Ajouter le flag ```-D BUFFER_SIZE=n``` lors de la compilation permet de modifier la taille du buffer utilisé par la fonction ```read``` à ```n```. (La taille du buffer a été mise à 42 par défaut.)

Commencé le Mardi 06 Décembre 2022, rendu le Lundi 12 Décembre 2022. (Environ 25h de travail)

## [04 - push_swap](https://github.com/Alexioos95/42-Cursus/tree/main/04_push_swap)

Programme triant (en ordre croissant) une pile contenant les nombres passés en argument.

Le programme ne peut utiliser que certaines opérations, qui sont écrites sur le terminal une fois exécuté.  
Veuillez lire le sujet présent dans le dossier correspondant au projet pour plus de détails.

Mon interprétation du projet utilise un algorithme ```LSD Radix```, en binaire.

Utilisez ```make``` pour compiler le programme en un exécutable ```push_swap```.  
Exécutez ensuite ```push_swap```, suivi des nombres à trier.

Commencé le Mercredi 04 Janvier 2023, rendu le Lundi 16 Janvier 2023. (Environ 50h de travail)

## [05 - so_long](https://github.com/Alexioos95/42-Cursus/tree/main/05_so_long)

> [!NOTE]  
> J'ai utilisé des tics pour le temps des animations, et l'ai réglé spécialement pour les iMacs de l'école 42 de Paris. Il est donc très fortement probable que le programme tourne en accéléré ou en ralenti sur votre système.

Simple jeu 2D, réalisé avec la MiniLibX, la bibliothèque graphique maison de 42.  
Le but du jeu est de ramasser tous les collectibles dans le labyrinthe, avant de sortir par la porte.

Le bonus de ce projet nous permet de laisser libre cours à notre imagination, et d'utiliser et faire tout ce que l'on veut. Je suis donc parti sur l'idée d'un clone de pac-man !  
Les fonctionnalités du jeu étant choisies par moi-même, vous les trouverez détaillées dans le dossier du projet.

Utilisez ```make``` pour compiler le programme en un exécutable ```so_long```. (```make bonus``` pour avoir le véritable jeu.) Exécutez ensuite ```so_long```, suivi du chemin relatif d'une carte au format ```.ber```. (Voir le sujet pour les précisions liées à la création de cartes.) Le dossier ```maps``` en contient quelques-unes pour tester le programme, et le dossier ```bonus/maps_bonus``` en contient d'autres, faîtes spécialement pour le bonus.

Commencé le Mardi 17 Janvier 2023, rendu le Lundi 27 Mars 2023. (Environ 150h de travail)

## [06 - pipex](https://github.com/Alexioos95/42-Cursus/tree/main/06_pipex)

Reproduction du fonctionnement du ```pipe (|)``` du système Unix.

Utilisez ```make``` pour compiler le programme en un exécutable ```pipex```.  
Donnez à l'executable des arguments comme ceci : "./pipex ```Infile``` ```Command 1``` ```Command 2``` ```Outfile```".  
Le bonus permet d'utiliser plusieurs pipes, ainsi que le ```here_doc (<<)```.

Commencé le Lundi 27 Février 2023, rendu le Lundi 24 Avril 2023. (Environ 70h de travail)

## [07 - philosophers](https://github.com/Alexioos95/42-Cursus/tree/main/07_philosophers)

Programme reprenant le problème des "Dining Philosophers", avec des ```threads``` et des ```mutexs```.

Utilisez ```make``` pour compiler le programme en un exécutable ```philo```.  
Exécutez ensuite ```philo```, comme ceci : "./philo ```"Nombre_de_philo"``` ```"Temps_de_vie_sans_manger"``` ```"Temps_nécessaire_pour_manger"``` ```"Temps_nécessaire_pour_dormir"``` ```"(Optionnel)_Nombre_de_repas_pour_terminer_la_simulation"```".

Mon interprétation du projet utilise la solution des ```pairs/impairs```, en priorisant les impairs au tout début de la simulation. Je fais, en plus, attendre chaque thread une petite portion de leur ```Temps_de_vie_sans_manger``` après qu'ils aient dormis, afin d'éviter un potentiel vol de fourchette.

Commencé le Mardi 25 Avril 2023, rendu le Mardi 16 Mai 2023. (Environ 70h de travail)

## [08 - minishell](https://github.com/Alexioos95/42-Cursus/tree/main/08_minishell)

Reproduction partielle d'un ```shell bash```.

Utilisez ```make``` pour compiler le programme en un exécutable ```minishell```.  
Veuillez lire le sujet pour tous les détails.

Réalisé en duo avec [Eli Ewu](https://github.com/Uweile).  
Il s'est occupé du lexical analyser ainsi que de l'implémentation de l'exécuteur des commandes et redirections, tandis que j'ai fait tout le reste. (Boucle shell, readline, heredoc, expand, built-ins, et signaux.) Vous pouvez voir le repo utilisé durant le développement du projet [ici](https://github.com/Alexioos95/ms).

Suite à la validation du projet, 3 problèmes ont été trouvés...  
1 - Une erreur de if/else if font que ./a_valid_command nous fais chercher dans le PATH du env, trouvant la commande, et l'exécutant sans problème.  
2 - La recherche en relatif est exécuté en regardant si l'argument envoyé contient un ```.``` en premier caractère, alors que bash regarde s'il y a un ```/``` quelque part.  
3 - Les signaux se superposent lorsque Minishell est lancé dans Minishell.

Commencé le Lundi 22 Mai 2023, rendu le 22 Septembre 2023. (Environ 450h de travail)

## 09 - netpractice

Petits exercices afin d'apprendre comment l'adressage IP fonctionne.

Commencé le Vendredi 16 Septembre, rendu le Mardi 26 Septembre 2023. (Environ 20h de travail)

## 10 - cub3d

> [!IMPORTANT]  
> Je m'étais occupé du parsing, tandis que mon partenaire devait prendre en charge la partie des calculs de raycast. Cependant, suite à un désaccord et manque de communication entre lui et moi, il a choisi de tout effacer et réécrire de lui-même... Rien ne sera donc partagé ici.

Reproduction du système de raycasting de Wolfenstein 3D, avec la MiniLibX.  
en.subject : https://smallpdf.com/fr/file#s=76d950c0-e29b-498e-bced-f6e125c5d4cb

Commencé le Mardi 15 Aout 2023, rendu le 23 Novembre 2023. (Environ 48h de travail)

## [11 - piscine cpp](https://github.com/Alexioos95/42-Cursus/tree/main/11_cpp)

Piscine de petits exercices en C++, afin de découvrir la programmation orientée objet.

Commencé le Mardi 17 Octobre 2023, rendu progressivement du Vendredi 20 Octobre, au Vendredi 07 Décembre 2023. (Environ 110h de travail)

## [12 - webserv](https://github.com/Alexioos95/42-Cursus/tree/main/12_webserv)

Développement d'un serveur web non bloquant via multiplexage en C++.

Utilisez ```make``` pour compiler le programme en un exécutable ```webserv```.  
Veuillez lire le readme du dossier pour les détails sur le fichier de configuration.

Réalisé en trio avec [Mathieu Daguenet](https://github.com/Uweile) et [Eli Ewu](https://github.com/Uweile).  
Je me suis occupé de la totalité de la gestion des communications entre le serveur et les clients, Mathieu s'est chargé du fichier de configuration, du lancement des CGI, et de la création des cookies, tandis qu'Eli a aider à la création des scripts CGI, et au nettoyage et lisibilité du code.

Commencé le Jeudi 14 Décembre 2023, rendu le Jeudi 28 Mars 2024. (Environ 250h de travail)

## [13 - inception](https://github.com/Alexioos95/42-Cursus/tree/main/13_inception)

> [!NOTE]  
> Du à la règle du sujet concernant le fichier ".env", il est nécessaire de le créer manuellement dans le dossier srcs, et y ajouter les différentes variables d'environnement que j'ai utilisé dans les scripts.

Découverte de Docker, et setup d'un site Wordpress, hébergé localement sur Nginx via ```docker compose```.

Commencé le Mardi 9 Avril, rendu le Vendredi 19 Avril 2024. (Environ 70 de travail)

## 14 - ft_transcendance

Single-page web application d'un jeu Pong.

En cours de développement.

Commencé le Mercredi 22 Mai 2024.
