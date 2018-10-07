# Market-project.01

1. „date1.in“

pe primul rand se va găsi numărul de produse din supermarket
pe următoarele rânduri sunt informații despre toate produsele din supermarket, acestea fiind ordonate alfabetic după câmpul „categorie“
un produs este descris de următoarea structură:
//produs listă supermarket - datele apar pe un rând, în această ordine
    char* nume;
    char* categorie;
    int pret;
    int cantitate;
    int stoc;
campul stoc este 0 sau 1( 1=dacă acel produs ce va trebui cumpărat este în stocul supermarket-ului, 0 în caz contrar )

----------------------------------------------------------------------------------------------------------------------------------------

2. „date2.in“

reprezintă lista de cumpărături
pe primul rand - numărul de produse ce trebuie achiziționate
pe următoarele linii se găsesc produsele caracterizate de:
//produs cumparat
    char* nume;
    char* categorie;
    int cantitate; //ceruta
    
    
----------------------------------------------------------------------------------------------------------------------------------------
3. „cerințe.in“
pe prima linie conține 6 numere, 1 sau 0,corespunzătoare fiecărei cerințe.
pentru 1 cerința se va realiza,pentru 0 cerința nu se va realiza (Exemplu: 0 1 1 0 1 0 → se vor realiza doar cerințele 2, 3 și 5 (imposibil, dar e doar un exemplu)).
pe a doua linie bugetul disponibil pentru a realiza cerința a 3-a (se va folosi doar in cadrul celei de-a treia cerințe)
Structuri esențiale:

  - listă, „lista1“, cu informațiile din „date1.in“ (sau lista_produse_supermarket)
  - listă, „lista2“, cu informațiile din „date2.in“ (sau lista_cumparaturi)
  - listă, „lista3“, cu informațiile produselor achiziționate (sau lista_produse_cumparate), cu structura produselor:
  //produs listă cumpărături - datele apar pe un rând, în această ordine
      char* nume;
      char* categorie;
      int cantitate; //cumparata
  - stiva
  - un arbore
   - Numele structurilor utilizate sunt pur orientative.
----------------------------------------------------------------------------------------------------------------------------------------
Cerințe:

1. Adăugarea produselor din „date2.in“ in „lista2“ (de cumpărături). Datele produselor se citesc şi produsele se adăuga, în ordine, la finalul listei.

2. Eliminarea din „lista2“ (de cumpărături) a tuturor produselor ce au în „lista1“ (supermarket) campul stoc nul (egal cu 0).

3. Realizarea cumpărăturilor cu buget: completarea listei „lista3“ (produse cumpărate) cu datele obiectelor achiziționate în limita bugetului disponibil (se cumpără, la rând, produsele din listă, în limitele date de buget si de cantităţile cerute/disponibile pentru fiecare produs).
----------------------------------------------------------------------------------------------------------------------------------------
4. Realizarea cumpărăturilor cu buget nelimitat și compensare (suprascrie „lista3“, adică nu ţine cont de rezultatul cerinţei 3):
Dacă un produs din „lista2“ (de cumpărături) prezintă o cantitate insuficientă în „lista1“ (supermarket), va fi cumpărat până la epuizare, iar completarea cantității cerute de produs se va face cu alt produs din „lista1“ (supermarket) ce aparține aceleiași categorii.

Condiții pentru cerința 4:

produsul cu care se completează are cel mai apropiat preț de cel dorit inițial (se compară numai produse din aceeaşi categorie);
dacă produsul „cel mai apropiat“ există în cantitate suficientă în supermarket,
atunci: se cumpără din acesta cât pentru completarea cantității
altfel: se cumpără din acesta cantitatea maximă (existentă în supermarket)
Lista de cumpărături se va parcurge și se vor cumpăra în ordine:
produsul curent, compensarea pentru produsul curent, produsul următor, compensarea pentru produsul respectiv și asa mai departe.

 --------------------------------------------------------------------------------------------------------------------------------------

5. Arbore:

Folosind datele din „lista3“ (produse cumpărate), se va crea un arbore binar ordonat crescător (la parcurgerea RSD) după cantitate.

 ---------------------------------------------------------------------------------------------------------------------------------------

6. Stiva:

Pentru fiecare produs P din „lista1“ (supermarket), sa se afle numărul de produse de pe poziții consecutive înainte de P care au prețul mai mare decat prețul lui P (numărul de produse la rand mai scumpe decat produsul curent, mergand spre anterior);

rezultatul se va adăuga într-un vector (poziția 0 pentru primul produs, poziţia 1 pentru următorul din listă și asa mai departe).

 ---------------------------------------------------------------------------------------------------------------------------------------
Fișiere Output:

Toate cerinţele marcate (în „cerinţe.in“) vor fi rezolvate, în ordine, apoi se va trece la afişarea rezultatelor;
în fișierul de output („rezultate.out“) se vor scrie integral datele produselor din liste, datele unui produs vor fi separate prin spaţiu, după fiecare produs urmează un final de linie;
după fiecare afişare a unei structuri (listă, arbore, vector) urmează un final de linie;
rezultatele cerinţelor se vor afişa în ordinea următoare:
dacă se rezolvă cerința 1 sau cerința 2, se va afișa „lista2“ (o singură dată);
dacă se rezolvă cerința 3 sau cerința 4, se va afișa „lista3“ (o singură dată);
dacă se rezolvă cerința 5, se va afișa arborele (doar fiecare cantitate, urmată de un spaţiu, prin parcurgerea RSD);
dacă se rezolvă cerința 6, se va afișa vectorul cu rezultatele (doar fiecare valoare din vector, urmată de un spaţiu)
