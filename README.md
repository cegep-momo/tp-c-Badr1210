# Construire le projet
Vous pouvez utiliser un dev container de base C++ de VScode.
Le projet utilise cmake, pensez à l'inclure dans votre dev container.

Voici les lignes de commandes pour compiler le projet:
```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

# Répertoire data

Il contient 2 fichiers `books.txt`et `users.txt` que vous pouvez utilisez pour tester votre code.
Pour ca il suffit de les copiers dans le repertoire `build` avec l'application `bibliotheque`

# Question 1
Une fonctionnalité importante utilisée dans le projet est la fonction lambda avec la STL. Elle permet d’écrire des petites fonctions directement dans le code, sans les déclarer ailleurs. Par exemple : 
std::sort(livres.begin(), livres.end(), [](const Book& a, const Book& b) {
    return a.getTitle() < b.getTitle();
});
Ici, on trie une liste de livres par titre sans créer une fonction séparée. C’est rapide, efficace et rend le code plus lisible. C’est aussi une technique moderne du C++ qu’on n’a pas beaucoup vue en cours.

# Question 2
Pour une très grande bibliothèque avec des millions de livres, le C++ seul ne serait pas suffisant. On pourrait utiliser une base de données SQL pour stocker les livres et faire des recherches rapides. Une API faite avec Node.js pourrait gérer les données et le C++ servirait d’interface pour communiquer avec elle. Cette méthode permet de faire une application rapide, modulaire et scalable qui serait capable de gérer une énorme quantité d’informations efficacement.