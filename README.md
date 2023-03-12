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

---
<div style = "text-align:center">

# <a name="Etat">Etat d'avancement du projet</a>
</div>

Wow on a bien avancé

---
<div style = "text-align: center">

# <a name="Organisation">Organisation du travail</a>
</div>

50-50


---
<div style = "text-align:center">

# <a name="Conclusion">Conclusion</a>
</div>

Ct fun
