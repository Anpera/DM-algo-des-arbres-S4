<div style = "text-align: center;"> 

<h1> DM Algo des arbres&nbsp;: Filtrage d'un texte </h1>
<h2> Par Amal ABDALLAH et Rayan ALVES </h2>
</div>

---

<br>

<h1 style= "text-align:center"> Sommaire </h1>

<div style = "text-align:center">

## [Manuel d'utilisateur](#Manuel) 
## [Etat d'avancement du projet](#Etat)
## [Organisation du travail](#Organisation)
## [Conclusion](#Conclusion)

</div>

---
<div style = "text-align:center">

# <a name="Manuel">Manuel d'utilisateur</a>
</div>

## **Compilation**

Pour pouvoir compiler le programme de filtrage, il suffit de taper la commande suivante dans le terminal&nbsp;:
```bash
make Filtrage
```
Une fois ceci fait, vous devriez avoir en plus normalement un fichier <code>Filtrage</code> ainsi que deux dossiers
<code>pdfs</code> où seront stockés les futures fichiers pdfs produits par le programme, 
mais également un dossier <code>objets</code> qui sert à entreposer les fichiers objets pour la compilation.

## **Éxécution** 

Pour lancer le programme il vous faut obligatoirement deux fichiers textes, l'un servant de filtre
à utiliser pour l'autre.

Dans cet exemple, nous utiliserons <code>texte.txt</code> pour parler du fichier texte à filtré, et
<code>filtre.txt</code> pour parler du fichier texte qui servira de filtre.

Pour lancer le programme il faut taper dans le terminal la commande suivante.

```bash
./Filtrage texte.txt filtre.txt
```
L'ordre entre texte.txt et filtre.txt est très importante, elle permet de savoir ce qui sert de filtre.

De plus, vous pouvez ajouter l'option <code>-v</code> où vous voulez en tant qu'argument pour activer l'option verbose, permettant de créer quatres fichiers pdfs trouvables dans le dossier <code>pdfs</code> représentant respectivement :
- <code>texte.pdf</code>&nbsp;: L'arbre contenant les mots du fichier <code>texte.txt</code> (le nom du fichier dépend du nom du fichier .txt)
- <code>filtre.pdf</code>&nbsp;: L'arbre contenant les mots du fichier <code>filtre.txt</code> (le nom du fichier dépend du nom du fichier .txt)
- <code>filtrage.pdf</code>&nbsp;: L'arbre contenant les mots présents dans le fichier <code>texte.txt</code> et absent de <code>filtre.txt</code>
- <code>en_commun.pdf</code>&nbsp; L'arbre contenant les mots communs aux fichiers <code>texte.txt</code> et <code>filtre.txt</code>

## **Nettoyage**
Pour finir, si vous voulez nettoyer le contenu des dossiers `objets` et `pdfs`, il suffit de lancer les fonctions&nbsp;:

    make cleanDeluxe
qui exécute 

    make cleanObj
    make cleanPdf
nettoyant respectivement le dossier `objets` et le dossier `pdfs`

---
<div style = "text-align:center">

# <a name="Etat">Etat d'avancement du projet</a>
</div>

Le projet est 100% fonctionnel.

Nous avons rempli les tâches suivantes:
- Création et gestion d'un arbre de chaînes de caractères
    - Gestion de l'allocation de la mémoire
    - Parcours des mots contenus dans l'arbre sur la sortie standard dans 
    l'ordre d'un parcours infixe
    - Ajout d'un noeud en suivant la structure d'un arbre binaire de recherche
    - Possibilité de supprimer un noeuudnoeud, mais également d'extraire le noeud maximum
    - Libération de tous les emplacements de mémoire alloués
    - Fonction pour dessiner les arbres dans un fichiers pdfs
- Création d'un arbre binaire de recherche à partir d'un fichier texte
    - Découpage du fichier en tokens pour lire le fichier mot par mot
- Filtrage des mots d'un texte
    - Suppresion d'un noeud et le transférer dans un autre arbre
    - Affichage sur la sortie standard des mots présents que dans le fichier texte,
    puis que des mots en communs avec le filtre
    - Gestion des arguments avec un argument optionnel pour lancer les fonctions de représentations
    graphiques des arbres
- Vérification et correction des possibles fuites de mémoires.

C'est donc un programme garantit sans fuites de mémoires.

---
<div style = "text-align: center">

# <a name="Organisation">Organisation du travail</a>
</div>

<p> Partie d'Amal : </p>
<ul>
<li>alloue_noeud qui fait l'allocation mémoire d'un noeud en recopiant le mot passé en argument</li>
<li>parcours_infixe qui fait un parcours infixe de l'arbre</li>
<li>ajout qui ajoute un noeud à un arbre</li>
<li>libere qui libère la place mémoire de tous les noeud de l'arbre</li>
<li>Les fonctions de gestion des fichiers .dot :</li>
<ul>
<li>ecrireDebut</li>
<li>ecrireArbre</li>
<li>ecrireFin</li>
<li>dessine</li>
</ul>
<li>cree_arbre qui crée l'arbre à partir d'un fichier texte
<li>écriture du main du fichier test_ABR.c</li>
</ul>
<p> Partie de Rayan :</p>
<ul>
<li> extrait_max qui extrait de l'arbre le plus grand noeud </li>
<li>suppression qui supprime un mot s'il est dans l'arbre et repositionne l'arbre</li>
<li>Gestion du filtre et écriture du main du fichier filtrage.c
</ul>

---
<div style = "text-align:center">

# <a name="Conclusion">Conclusion</a>
</div>

Ce projet a été fort instrustif sur l'utilisation de nouveaux outils comme Valgrind et fût très intéressant sur la gestion de la mémoire.
Mais ce projet a aussi renforcé nos acquis sur l'utilisation et la manipulation des arbres binaires de recherches  
