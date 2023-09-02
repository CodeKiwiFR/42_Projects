Le travail de resolution du probleme est divise en plusieurs parties:

	1)	Verification du parametre transmis au programme

	2)	Notre grille de taille 6x6 est initialisee pour ne contenir que des zeros:
	
		| 0 | 0 | 0 | 0 | 0 | 0 |
		| 0 | 0 | 0 | 0 | 0 | 0 |
		| 0 | 0 | 0 | 0 | 0 | 0 |
		| 0 | 0 | 0 | 0 | 0 | 0 |
		| 0 | 0 | 0 | 0 | 0 | 0 |
		| 0 | 0 | 0 | 0 | 0 | 0 |

		Pour rappel, notre grille contiendra:
		- nos contraintes pour le haut sur la ligne 0;
		- nos contraintes pour le bas sur la ligne 5;
		- nos contraintes pour la gauche sur la colonne 0;
		- nos contraintes pour la droite sur la colonne 5;
		- nos donnees sur les quatre lignes et quatre colonnes interieures
		(voir exemple ci-apres)

	3)	Recuperation des contraintes dans la chaine input, pour les placer dans
		notre grille. Si on prend l'exemple de l'enonce, voici ce qu'on obtient:

		./rush-01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"

		| 0 | 4 | 3 | 2 | 1 | 0 |
		| 4 | 0 | 0 | 0 | 0 | 1 |
		| 3 | 0 | 0 | 0 | 0 | 2 |
		| 2 | 0 | 0 | 0 | 0 | 2 |
		| 1 | 0 | 0 | 0 | 0 | 2 |
		| 0 | 1 | 2 | 2 | 2 | 0 |

	4)	Lancement de la resolution.
		On appelle la fonction: "found_solution = ft_find_solution(grid, 1, 1);"
		Cette derniere remplit le tableau pour trouver une solution, si elle en trouve
		une, elle return 1, sinon elle return 0.

	5) 	Si une solution a ete trouvee, on l'affiche, sinon on affiche Error et un saut
		de ligne.

---------------------------------------------------------------
DETAILS:

Fichier main.c:
	Il contient la fonction main dont le fonctionnement est detaille juste au-dessus.

Fichier tools.c:
	Il contient des fonctions outils, comme ft_putchar(), ft_putstr(), ft_strlen().

Fichier arg_checker.c:
	Il contient des fonctions qui permettent de verifier l'argument transmis a la main.
	La fonction ft_check_input() regard la chaine de caractere en entree.
	Si elle est bonne, elle return 1, sinon 0. Elle verifie la longueur de la chaine
	qui doit etre de 31 caracteres, et elle verifie qu'on ait le bon format
	(un chiffre suivi d'un espace).
	
Fichier data_management.c:
	Il contient la fonction ft_initialize_content() qui prend notre grille et met
	des zeros partout dedans.
	Il contient aussi la fonction ft_extract_input_data() qui recupere la chaine de
	caractere avec les contraintes et les ajoute dans notre tableau.

Fichier display.c:
	Contient simplement un fonction qui permet d'afficher notre grille comme
	demande dans l'enonce.

Fichier solver.c:
	C'est ici que nous avons la fonction ft_find_solution().
	Elle s'occupe de remplir notre tableau avec toutes les valeurs possibles.
	Il serait long de detailler tout ce qu'elle fait, il vaut mieux voir
	ca a l'oral.
	Il y a aussi la fonction ft_is_valid() qui regarde, pour une position donnee,
	si notre grille est valide.

Fichier grid_checker.c:
	Ici, nous avons toutes les fonctions qui verifient la coherence de notre grille.
	Voici un detail:
		ft_check_up_visible() => regarde si les contraintes du haut sont respectees;
		ft_check_down_visible() => idem pour le bas;
		ft_check_left_visible() => idem pour la gauche;
		ft_check_right_visible() => idem pour la droite;
		ft_check_row_col() => verifie que l'on n'a pas de doublons sur une ligne
		ou sur une colonne.

Voila les grandes lignes du projet.
Pour le tester, il suffit de faire comme dans l'enonce:
	cc -Wall -Wextra -Werror -o rush-01 *.c
N'hesitez pas a faire des tests de votre cote.
Demain, nous parlerons a nouveau de l'algorithme de resolution.
