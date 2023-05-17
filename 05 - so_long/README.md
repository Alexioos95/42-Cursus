# Fonctionnalités bonus mise en place

- Animation de déplacement du joueur.  
- Animation de mort du joueur.  
- Déplacement continue automatique du joueur.  
- Keylogger, gardant en mémoire le prochain déplacement voulu, mais non faisable du joueur.  
- Présence d'ennemis. (G sur la map Ascii.)  
- Animation de déplacement des ennemis.  
- Algorithme de chasse des ennemis, différent selon leur couleur.  
- Présence de Super Collectibles, permettant de faire passer le jeu en mode "Panic". (Les ennemis ne vous chassent plus, ils se déplacent plus lentement, et vous pouvez les manger.)  
- Téléporteurs sur les côtés. (Case vide sur la 2ème ou avant dernière colonne, avec des murs sur les 2 cases au dessus et en dessous de celle-ci, en plus d'avoir la même configuration en miroir de l'autre extrémité.)  
- Recommencer le jeu à Zero en pressant R.  
- Quitter le jeu en pressant Q.  
- Nombre de changement de direction inscrit sur le bas de l'écran.

## Fonctionnalités que j'aurais voulu faire...

...mais n'ai pas eu le temps :

- Fix le bug de rafraîchissement qui arrive parfois lorsque l'on mange un ennemi.  
- Faire un décor de borne d'arcade sur les côtés de la fenêtre.  
- Ajouter des codes secrets, transformant le jeu. (Comme par exemple le Konami Code, qui inverserait les rôles entre joueur et ennemis, ou mon login 42, qui créerais un mini-jeu Snake.)  
- Réaliser plus de carte pour jouer.  
- Augmenter la taille maximum des cartes autorisées, et mettre un "scroll" pour plus de fluidité/lisiblité.  
- Ajouter un système de niveau.  
- Ajouter un menu.  
- Au niveau du code, passer de simple fichiers xpm collé à la fenêtre, à un calque permettant un rafraîchissement de chaque unité bien plus performant.