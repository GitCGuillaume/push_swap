# Projet Push_swap

Ce projet demande à trier des nombres sous forme d'action en utilisant 2 piles (piles A et B), en un minimum d'action possible.
Je me suis inspiré pour ce projet de l'algorithme de tri rapide (https://fr.wikipedia.org/wiki/Tri_rapide), et en divisant par la suite en fonction du nombre d'élément

![psw1](https://github.com/GitCGuillaume/push_swap/assets/34135668/dd377271-c425-43ce-afa2-8ee70dc639f8)
![psw2](https://github.com/GitCGuillaume/push_swap/assets/34135668/5002ea26-26f8-4935-b9f8-8d66268656cf)


Source sujet
>sa (swap a) : Intervertit les 2 premiers éléments au sommet de la pile a.
Ne fait rien s’il n’y en a qu’un ou aucun.
>
>sb (swap b ) : Intervertit les 2 premiers éléments au sommet de la pile b.
Ne fait rien s’il n’y en a qu’un ou aucun.
>
>ss : sa et sb en même temps.
>
>pa (push a) : Prend le premier élément au sommet de b et le met sur a.
Ne fait rien si b est vide.
>
>pb (push b) : Prend le premier élément au sommet de a et le met sur b.
Ne fait rien si a est vide.
>
>ra (rotate a) : Décale d’une position vers le haut tous les élements de la pile a.
Le premier élément devient le dernier.
>
>rb (rotate b) : Décale d’une position vers le haut tous les élements de la pile b.
Le premier élément devient le dernier.
>
>rr : ra et rb en même temps.
>
>rra (reverse rotate a) : Décale d’une position vers le bas tous les élements de
la pile a. Le dernier élément devient le premier
>
>rrb (reverse rotate b) : Décale d’une position vers le bas tous les élements de
la pile b. Le dernier élément devient le premier
>
>rrr : rra et rrb en même temps.
