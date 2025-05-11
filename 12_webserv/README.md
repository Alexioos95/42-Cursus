# Exemple

Pour un exemple de fichier fonctionnel, regardez le fichier `config`.

## Règles générales

- Seul les mots clés indiqués et les whitespaces sont autorisés. Dans le cas où un bloc server ne respecte pas une des règles, la totalité du fichier est invalidé.  
- Un élément = une ligne.   
- Il est possible d'avoir des lignes contenant uniquement un `\n`.  
- Les accolades ouvrantes des blocs peuvent être sur la même ligne après plusieurs whitespaces, ou plusieurs en dessous.  
- 1 ou plusieurs whitespaces sont possible au debut et à la fin de la ligne.  
- 1 whitespace minimum (plusieurs possible) entre le nom et la valeur d'un element.  
- Les lignes se finissent par un point virgule, sauf pour le nom des méthodes dans le bloc `method` du bloc `location`.  
- Au minimum 1 `listen` obligatoire, mais plusieurs possible.  
- `server_name` est obligatoire, et il ne peut y en avoir qu'un.  
- `root` est obligatoire, et il ne peut y en avoir qu'un.  
- Le bloc `error` est facultatif. S'il est présent, il ne doit y en avoir qu'un.  
- Si le bloc `error` est présent, il est possible qu'il soit vide. S'il ne l'est pas, chaque numero d'erreur doit obligatoirement avoir un path.  
- Le bloc `location` est facultatif.  
- `body_size` est optionnel. S'il est défini, la valeur se doit d'être un int.

## Légende

`server_name`: le nom du serveur.  
`listen`: le ou les ports a écouter.  
`root`: l'emplacement du dossier du serveur pour le programme, dans le dossier `Servers`.  
`body_size`: la taille maximale autorisé pour les body des requêtes HTTP.  
`error`: l'emplacement du dossier contenant les erreurs, avec le bloc contenant le numéro de l'erreur et le path du fichier, relatif depuis le dossier des erreurs.  
`location`: bloc contenant les règles du dossier cible.

## Légende des locations

`allow_cgi`: autorise les CGI sur la location. False par défaut.  
`index`: path vers un fichier à repondre si la requête est faite sur un dossier.  
`method`: liste des méthodes HTTP autorisées sur la location.  
`allow_autoindex`: aurotise l'auto-indéxation. False par défaut. Il est possible d'ajouter un path derrière, pour avoir un fichier custom.  
`return`: path vers lequel la requête doit être redirigé.  
`dir_post`: path vers lequel rediriger les fichiers créer par un post.  
`alias`: path vers lequel la location actuelle est en réalité un alias.
