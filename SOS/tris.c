

#include <stdio.h>
void triFusion(int i, int j, int tab[], int tmp[]) {
    if(j <= i){ return;}
  
    int m = (i + j) / 2;
    
    triFusion(i, m, tab, tmp);     //trier la moitié gauche récursivement
    triFusion(m + 1, j, tab, tmp); //trier la moitié droite récursivement
    int pg = i;     //pg pointe au début du sous-tableau de gauche
    int pd = m + 1; //pd pointe au début du sous-tableau de droite
    int c;          //compteur
// on boucle de i à j pour remplir chaque élément du tableau final fusionné
    for(c = i; c <= j; c++) {
        if(pg == m + 1) { //le pointeur du sous-tableau de gauche a atteint la limite
            tmp[c] = tab[pd];
            pd++;
        }else if (pd == j + 1) { //le pointeur du sous-tableau de droite a atteint la limite
            tmp[c] = tab[pg];
            pg++;
        }else if (tab[pg] < tab[pd]) { //le pointeur du sous-tableau de gauche pointe vers un élément plus petit
            tmp[c] = tab[pg];
            pg++;
        }else {  //le pointeur du sous-tableau de droite pointe vers un élément plus petit
            tmp[c] = tab[pd];
            pd++;
        }
    }
    for(c = i; c <= j; c++) {  //copier les éléments de tmp[] à tab[]
        tab[c] = tmp[c];
    }
}

 
void fusion (int *a, int n, int m) {
    int i, j, k;
    int *x = malloc(n * sizeof (int));
    for (i = 0, j = m, k = 0; k < n; k++) {
        x[k] = j == n      ? a[i++]

             : i == m      ? a[j++]
             : a[j] < a[i] ? a[j++]
             :               a[i++];
    }
    for (i = 0; i < n; i++) {
        a[i] = x[i];
    }
    free(x);
}
 
void tri_fusion (int *liste, int taille) {
    if (taille < 2) return;
    int milieu = taille / 2;
    tri_fusion(liste, milieu);
    tri_fusion(liste milieu, taille - milieu);
    fusion(liste, taille, milieu);
}




void bulle(int* tableau, int p) {
    int i_b = p;
    while ((i_b>0) && (tableau[i_b]<tableau[i_b - 1])) {
        int t = tableau[i_b -1];
        tableau[i_b - 1]= tableau[i_b];
        tableau[i_b ] = t;
        i_b --;
    }
}
 
void tri_gnome (int* tableau) {
    for (int i_i=0;i_i<20;i_i++) bulle(tableau,i_i);
}





typedef int bool;
enum { false, true };
 
void tri_peigne(int* tableau)
{
    int gap = 20;
    bool permutation = true;
    int en_cours;
   
    while (( permutation) || (gap>1)) {
        permutation = false;
        gap = gap / 1.3;
        if (gap<1) gap=1;
        for (en_cours=0;en_cours<20-gap;en_cours++) {
            if (tableau[en_cours]>tableau[en_cours+gap]){
                permutation = true;
                // on echange les deux elements
                int temp = tableau[en_cours];
                tableau[en_cours] = tableau[en_cours+gap];
                tableau[en_cours+gap] = temp;
            }
        }
    }
}



void tri_insertion(int* t, int gap, int debut)
{
    int j,en_cours;
    for (int i = gap + debut; i < 20; i+=gap) {
        en_cours = t[i];
        for (j = i; j >= gap && t[j - gap] > en_cours; j-=gap) {
            t[j] = t[j - gap];
        }
        t[j] = en_cours;
    }
}
 
void tri_shell(int* t) {
    int intervalles[5]={6,4,3,2,1};
    for (int ngap=0;ngap<5;ngap++) {
        for (int i=0;i<intervalles[ngap];i++)
            tri_insertion(t,intervalles[ngap],i);
    }
}




typedef int bool;
enum { false, true };
 
void tri_shaker(int* tableau) {
    bool permutation;
    int en_cours=0, sens=1;
    int debut=1, fin=19;
    do {
        permutation=false;
        while (((sens==1) && (en_cours<fin)) || ((sens==-1) && (en_cours>debut))) {
            en_cours += sens;
            if (tableau[en_cours]<tableau[en_cours-1]) {
                int temp = tableau[en_cours];
                tableau[en_cours]=tableau[en_cours-1];
                tableau[en_cours-1]=temp;
                permutation=true;
            }
        }
        if (sens==1) fin--; else debut++;
        sens = -sens;
    } while (permutation);
}



