# GIT

## Processus

### PULL
...
git pull
...

[] Modifier vos fichiers

### STATUS
...
git status (facultatif, permet d'affichier le status)
...

Pour ajouter tous les fichiers

### ADD
...
git add .
...
ou
Pour ajouter un ou plusieurs fichiers
...
git add nom_du_fichier.c
...

### COMMIT
...
git commit -m "Commentaire"
...

### PUSH
...
git push
...

# Annexe
si problème avec git pull, executer la cmd ci-dessous pour forcer la conf a partir du serveur. (attention risque de perte de modification locale)
...
git config --global pull.rebase true
...
