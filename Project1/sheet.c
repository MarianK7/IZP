/******************** Vypracoval: Marián Keszi Login: xkeszi00 ********************/

//V programe prikomentaroch na funkciach sa odvolavam vacsinov na komentare na prvejfunkcii nakolko funkcie su vykonavane
// za rovnakych pripadne podobnych podmienok a su volane rovnakym sposobom.
// Ak je v niektorej funkcii nieco extra oproti funkcii na ktoru sa odvolavam je to tam dodatocne doplnene.
// Takto zvysujem prehladnost kodu,nakolkokeby je vsade pouzity viac menej ten isty komentar malo by to vyrazny podiel
//na naslednej neprahladnosti kodu
//FUNKCIE NA SELEKCIU RIADKOV NIESU SPRAVENE

#include <stdlib.h> // includujem si kniznice, ktore budem potrebovat
#include <stdio.h>
#include <string.h>
#include <ctype.h> // tuto kniznicu potrebujeme kvoli funkciam tolower a toupper
#include <stdbool.h>
#define LINE_LEN 10242 // definujem si max dlzku riadku(velkost)

void nahrad_znak(char *pole, char *delimeter, char change) // funkcia, ktora mi nahradza delimetre,za ine zvolene
{
    int dlzka_retazca = strlen(pole);         // zistim si  dlzku pola
    int pocet_delimetrov = strlen(delimeter); // zistim si dlzku(pocet) delimetrov
    for (int i = 0; i < dlzka_retazca; i++)   // pomocov dvoch forov prechadzam polom a porovnavam delimetre
    {
        for (int j = 0; j < pocet_delimetrov; j++)
        {
            if (pole[i] == delimeter[j]) // ak sa mi znak v poli na indexe i rovna znaku delimetra na indexe j
            {
                pole[i] = change; // zmenim hodnotu v poli na indexe i na pozadovany delimeter
            }
        }
    }
    return;
}

void removeN(char *str) // funkcia na odstranenie znaku noveho riadka z riadku
{
    if (str[strlen(str) - 1] == '\n') // ak sa mi na predposlednej pozicii v poli nachadza znak noveho riadku
        str[strlen(str) - 1] = '\0';  // priradim mu hodnotu konca riadku (teda znak noveho riadku vymazem)

    return;
}

int colls(char *line, char *delimeter) // funkcia na zistenie poctu stlpcov v riadku
{
    int collum = 1;                             // stlpce pocitam od 1
    for (int i = 0; i < (int)strlen(line); i++) // pomocov for prechadzam polom(riadkom)
    {
        if (line[i] == delimeter[0]) // ak sa mi znak na indexe i rovna delimetru
        {
            collum++; // inkrementujem pocet stlpcov
        }
    }
    return collum; // vraciam si pocet stlpcov
}

int drowR(char *line, int row, int remove) // funkcia na odstranenie zvolenho riadku
{
    if (row == remove) // ak sami cislo riadku rovna cislu riadku, ktory chcem vymazat
    {
        strcpy(line, "");   // pomocov funkcie nastavim do riadku prázdnu hodnotu(vymazem ho)
        printf("%s", line); // riadok vytlacim
    }
    return 0;
}

int drows(char *line, int row, int rmFrom, int rmTo) // funckia na vymazanie viacero riadkov
{
    if (rmFrom <= row && rmTo >= row) //ak mam cislo riadka od ktoreho chcem vymyzavat mensie alebo rovne cislu riadka
                                      // a zaroven je cislo riadka po ktory chcem vymazavat vacsie pripadne rovne cislu riadka
    {
        strcpy(line, ""); // do riadka nastavim prazdnu hodnotu(vymazem ho)
    }
    return 0;
}

int irowR(char *delimeter, int row, int Pdelimeter, int add) // funkciana vlozenie riadka pred zvoleny riadok
{
    if (row == add) // ak sa mi cislo riadka rovna cislo riadka pred ktory cchem vlozit riadok
    {
        for (int i = 0; i < Pdelimeter; i++) // cyklus, ktory mi prida pozadovany pocet delimetrov do prazdneho riadka na zaklade
                                             // hodnoty z predchadzajuceho riadka
        {
            printf("%c", delimeter[0]); // tlacim delimetre
        }
        printf("\n"); // vytlacim novy znak noveho riadka
    }
    else
    {
        return 0; // ak mi horna podmienka neplati vraciam 0 a pokracujem dalej
    }

    return 0;
}

void dcolC(char *delimeter, char *line, int rmCol) // funkcia na vymazanie jedneho stlpca
{
    char buff[10242];
    char *ptr1 = line - (rmCol > 1);         // do ukazovatela jedna si ulozim zaciatok bunky, ktoru chcem vymazat
    char *ptr2 = strchr(ptr1, delimeter[0]); // do ukazovatela 2 si najdem a  ulozim koniec danej bunky, ktoru  chcem vymazat
    if (rmCol == 1)                          //ak sa mi cislo stlpca, ktory cchem vymazat rovna 1 vykonavam nasledujuce veci
    {
        if (ptr2) // ak som nasiel koniec bunky
        {
            strcpy(buff, ptr2 + 1); // do buffra si nakopirujem riadok za danoubunkou
            strcpy(line, buff);     // nasledne dopola line nakopirujem upraveny riadok z buffra
        }
        else
        {
            line[0] = '\0'; // ak som nenasiel ptr2 nastavim do pola line na indexe 0 koniec raidku
        }
        return;
    }
    for (int i = 1; i < rmCol; i++) // ak spracovavam ine stlpce ako prvy vyuzijem cyklus na haldanie daneho stlpca
    {
        ptr1 = strchr(ptr1 + 1, delimeter[0]); // najdem si zaciatok bunky
    }
    ptr2 = strchr(ptr1 + 1, delimeter[0]); // najdem si koniec bunky

    if (ptr1 && !ptr2) // ak sa mi nepodarilo najst koniec bunky tedaspracovavam poslednystlpec
    {
        *ptr1 = '\0'; // do ptr1 si nastavim hodnotu konca null
    }
    else if (ptr2) // ak som  koniecnasielateda nespracovavam posledny stlpec postupujem podobne ako na zaciatku
    {
        strcpy(buff, ptr2); // do buffra si nakopirujem hodnotu ptr2
        strcpy(ptr1, buff); // nasledne mi uz len treba nakopirovat bufferdo ptr jedna
    }
}

void icol(char *line, char *delimeter, int addColTo) // funkcia na pridanie stlpca pred zvoleny stlpec
{
    // vykonavame podobny postup ako pri dcol akurat nam staci si najst iba stlpec, pred ktory vytlacime znak dalsieho stlpca(delimeter)
    // nepotrebujeme zistovat zaciatok a koniec teda nam staci iba jen'den pointer
    //znova ale musime uvazovat, ak chceme vykonat icol 1, tak nenajdeme delimeter, ktoryby namoznacil tento stlpec
    char *ptr = line - (addColTo > 1);
    char buff[10242];
    if (addColTo == 1)
    {
        strcpy(buff, ptr);
        line[0] = delimeter[0]; // teda si nastavime v poli naindex 0 iba hodnotu delimetra a postupujeme podobne ako v dcole
        strcpy(line + 1, buff);
        return;
    }
    for (int i = 1; i < addColTo; i++)
    {
        ptr = strchr(ptr + 1, delimeter[0]);
    }
    if (ptr)
    {
        strcpy(buff, ptr);
        *ptr = delimeter[0];
        strcpy(ptr + 1, buff);
    }
}

void cset(char *line, char *delimeter, char *set, int addColTo) // funkcia na nastavenie retazca do zvoleneho stlpca
{
    int setLen = strlen(set);               // musime si zistit velkost(dlzku) retazca, ktory chceme nastavit do bunky
    char *ptr = line - (addColTo > 1);      // hladame si zaciatok bunky
    char *ptr2 = strchr(ptr, delimeter[0]); // najdeme si koniec bunky
    char buff[10242];
    if (addColTo == 1) // ak spracovavame prvy stlpec
    {
        if (ptr2) // ak smenasli ptr2
        {
            strcpy(buff, ptr2);          // nakopirujeme si ptr2 do buffra
            strcpy(line, set);           // nasledne do line nakppirujeme retazec set
            strcpy(line + setLen, buff); // a nakoniec potrebujeme nakopirovat buffer do line ale musime pripocitat dlzku retazca set
        }
        else
        {
            strcpy(line, set);       // ak sme ptr2 nenasli nakopirujeme retazec set do line
            line[setLen + 1] = '\0'; // a v poli line na indexe setlen plus jedna nastavime hodnotu null
        }
        return;
    }
    for (int i = 1; i < addColTo; i++) // ak spracuvame iny ako prvy stlpec
    {
        ptr = strchr(ptr + 1, delimeter[0]); // najdeme si zaciatok bunky
    }
    ptr2 = strchr(ptr + 1, delimeter[0]); // najdeme si koniec bunky
    if (ptr && !ptr2)                     // ak sa nam koniec nepodarilo najst spracuvame teda posledny stlpec
    {
        strcpy(ptr + 1, set);   // do ptr + 1 si nakopirujeme pomocov strcpy retazec set
        ptr[setLen + 1] = '\0'; // a na v poli ptr na indexsetlen + 1 nastavime hodnotu null
    }
    else if (ptr2) // ak  sme koniec nasli anespracovavame posledny stlpec
    {
        strcpy(buff, ptr2);             // do buffra si nakopirujeme ptr2
        strcpy(ptr + 1, set);           // nasledne si musime nakopirovat retazec set do ptr + 1
        strcpy(ptr + 1 + setLen, buff); //na koniec si nakopirujeme buff do ptr + 1 + setlen, musime  pripocitat aj + 1 inak by nam miesto posledneho znaku vkladaneho retazcapisalo delimeter
    }
}

void findCol(char *line, char *delimeter, char *buff, int search) // funckia, ktora mi najde stlpec s ktorym chcem pracovat
{
    char *ptr;
    char *ptr2;
    int col = 1;
    int lineLen = strlen(line);
    bool b = true;
    for (int i = 0; i < lineLen + 1; i++)
    {
        if (search == col && b)
        {
            ptr = &line[i];
            b = false;
        }
        if (search + 1 == col)
        {
            ptr2 = &line[i];
            break;
        }
        if (line[i] == delimeter[0])
        {
            col++;
        }
        if (line[i] == '\0')
        {
            ptr2 = &line[i] + 1;
        }
    }

    memmove(buff, ptr, ptr2 - ptr - 1);
    buff[ptr2 - ptr - 1] = '\0';
}

void toLower(char *line, char *delimeter, int addColTo) // funkcia, ktora minastavi vo zvolenom stlpci znaky z velkych na male
{
    char buff[102];
    findCol(line, delimeter, buff, addColTo); // zavolame si funkciu, ktora nam najde stlpec, ktory ideme spracovavat
    int buffLen = strlen(buff);               // zistime si dlzku bunky, ktoru ideme upravovat a ulozime do pomocnej premennej
    for (int i = 0; i < buffLen; i++)         // v cykle for nasledne vykonaveme funkciu tolower pre kazdy znak na indexe od 0 az po posledny znak bunky
    {
        buff[i] = tolower(buff[i]); // vyuzivame funkciu tolower z kniznice ctype.h
    }

    cset(line, delimeter, buff, addColTo); // na konci si uz len zavolame funkciu cset, ktora nam nam nastavi upravenu bunku buff do daneho stlpca v tabulke
}

void toUpper(char *line, char *delimeter, int addColTo) // funkcia, ktora mi nastavi vo zvolenom stlpci znaky z malych na velke
{
    // pre funkciu toupper vykonavame presne to iste ako pre tolower akurat vyuzivame opacnu funkciu toupper z kniznice ctype.h
    char buff[102];
    findCol(line, delimeter, buff, addColTo);
    int buffLen = strlen(buff);
    for (int i = 0; i < buffLen; i++)
    {
        buff[i] = toupper(buff[i]);
    }

    cset(line, delimeter, buff, addColTo);
}

void RoundC(char *line, char *delimeter, int addColTo) // funkcia, ktora mi zaokruhli cislo vo zvolenom stlpci
{
    int result = 0;
    char *ptr;
    char buff[102];
    findCol(line, delimeter, buff, addColTo); // zavolame si funkciu, ktora nam najde stlpec, ktory ideme upravovat

    double number = strtod(buff, &ptr); // pomocov strdot si do premennej number ulozime cislo

    if (*ptr == '\0')
    {
        if (number < 0) // nasledne ak je cislo zaporne
        {
            number = number - 0.5; // od  cisla odcitame 0.5 a ulozime ho do number
            result = (int)number;  // nasledne cislo pretypujeme z double na int aulozime do premennej resulttypu int
        }
        else
        {
            number = number + 0.5; // ak je cislo nezaporne pripocitavame 0.5 a ukladame nazad do number
            result = (int)number;  // znova vykonavame pretypovanie z double na int a ukladame do premennej result typu int
        }
    }
    else
    {
        return;
    }

    sprintf(buff, "%i", result);           // funkcia sprintf nam vytlaci cislo do buffra
    cset(line, delimeter, buff, addColTo); // nasledne uz len volame funkciu cset, ktora nam nastavi buffer do stlpca pre ktory vykonavame funkciu
}

void makeInt(char *line, char *delimeter, int addColTo) //  funkcia, ktora mivo zvolenom riadku pretypuje cislo z desatinneho na interger
{
    // funkcia makeInt funguje velmi podobne ako round akurat tu vykonavame len ciste pretypovanie z typu double na int
    int result = 0;
    char *ptr;
    char buff[102];
    findCol(line, delimeter, buff, addColTo);

    double number = strtod(buff, &ptr);

    if (*ptr == '\0')
    {
        result = (int)number;
    }
    else
    {
        return;
    }

    sprintf(buff, "%i", result);
    cset(line, delimeter, buff, addColTo);
}

void copy(char *line, char *delimeter, int addColFrom, int addColTo) // funkcia, ktora mi skopiruje obsah jedneho stlpca do zvoleneho druheho
{
    char buff[102];
    findCol(line, delimeter, buff, addColFrom); // pomocov funkcie si najdeme stlpec, ktory ideme spracovavat
    cset(line, delimeter, buff, addColTo);      // nasledne zavolame cset, ktory nam najdeny stlpec nastavi z buffra do stlpca kam chceme kopirovat
}

void swap(char *line, char *delimeter, int addColFrom, int addColTo) // funkcia, ktora mi zameni hodnoty vo zvolenych stlpcoch
{
    char buff[102]; // potrebujeme dve buky
    char buff2[102];

    findCol(line, delimeter, buff, addColFrom); // najprv si najdeme prvu bunku
    findCol(line, delimeter, buff2, addColTo);  // nasledne si najdeme druhu bunku
    cset(line, delimeter, buff, addColTo);      // pomocov csetu si uz len ulozime hodnotu druhej bunky na prvej
    cset(line, delimeter, buff2, addColFrom);   // a rovnako nastavime pomocov csetu buff2 do bunky prvej
}

void move(char *line, char *delimeter, int addColFrom, int addColTo) // funkcia, ktora mi presunie zvoleny stlpec na poziciu druheho zvoleneho stlpca
{
    char buff[102];
    if (addColFrom < addColTo) // ak nastane pripad, ze je stlpec, ktory chcem nastavit mensej hodnoty ako stlpec kam chceme stlpec presunut
    {
        findCol(line, delimeter, buff, addColFrom); // najprv zavolame funkciu, ktora nam najde a vytiahne stlpec do buffra
        dcolC(delimeter, line, addColFrom);         // nasledne zavolame dcol, ktory nam odstrani dany stlpec z tabulky
        icol(line, delimeter, addColTo - 1);        // nasledne zavolame icol, ktory nam prida novy stlpec pred stlpec kam presunieme zvoleny stlpec
        cset(line, delimeter, buff, addColTo - 1);  // a ako posledne si zavolame cset, ktory nam nastavi buffer do stlpca na pozicii addColTo - 1
    }
    else
    {
        findCol(line, delimeter, buff, addColFrom); // v ostatnych pripadoch neni potrebne posuvat bunky o znak a staci nam cisto vykonat ten isty postup
        dcolC(delimeter, line, addColFrom);         // vymazeme stlpec
        icol(line, delimeter, addColTo);            // pridame stlpec
        cset(line, delimeter, buff, addColTo);      // a nastavime pomocov csetu stlpec na poziciu nami zvoleneho stlpca
    }
}

int main(int argc, char *argv[])
{
    char *delimeter = " "; // ak neni zadane inak defaultne nastavujem delimeter na medzeru
    if (argc > 2)          // ak je pocet argumentov vacsi ako 2
    {
        if (strcmp(argv[1], "-d") == 0) // ak sa mi v poli argumentov na indexe 1 nachadza -d
        {
            delimeter = argv[2]; // nastavim delimeter na delimeter zadany v poli argumentov na indexe 2
        }
    }

    int row = 1;                // premenna urcujuca hodnotu(cislo) riadku na ktorom sa nachadzam zacina sa vzdy od 1
    char line[LINE_LEN];        // pole s dopredu definovanou dlzkou do ktoreho nacitavam riadky
    int Lcounter;               // pomocna premenna sluziaca na prechod argumentmi a teda na riesenie logiky argumentov v programe
    int remove;                 // premenna, ktora mi udava, ktoryriadok chcem vo funkcii drow vymazat
    int rmFrom;                 // premenna, ktora mi urcuje od ktoreho riadka chcem vo funkcii drows mazat riadky
    int rmTo;                   //premenna, ktora mi urcuje po ktory riadok chcem vo funkcii drows mazat riadky
    int add;                    // premenna, ktora mi urcuje pred ktory riadok chcem vlozit prazdny novy riadok vo funkcii irow
    int Pcol;                   // pomocna premenna, kde si ulozim pocet stlpcov v prvom riadku a nasledne v programe kontrolujem pomocov nej ci sa pocty stlpcov zhoduju v celej tabulke
    int rmCol;                  // premenna, ktora mi udava, ktory stlpec chcem vo funkcii dcol vymazat
    int rmColFrom;              // premenna, ktora mi udava od  ktoreho stlpca chcem vo funkcii dcols mazat stlpce
    int rmColTo;                // premenna, ktora mmi udava po ktory stlpec chcem vo funkcii dcols mazat stlpce
    int count;                  // Pomocne pocitadlo, ktore nam urcuje kolko krat sa ma vykonat funkcia dcol vo funkcii dcols
    int addColTo;               // premenna, ktora sluzi na identifikovanie bud stlpca na pred ktorym chcem vykonavat nejaku funkciu ako napr. icol alebo cset...
                                // pripadne nam udava stlpec po ktory chcem vykonavat urcitu funkciu napr. copy,swap alebo move...
    int addColFrom;             //premenna, ktora nam udava po  ktory stlpec chcem vykonavat urcitu funkciu ako napr. copy, swap alebo move...
    int DataControll = 0;       // pomocna premenna sluziaca na kontrolu poctu prikazov na spracovanie dat
    int DataControllPerRow = 0; // pomocna premenna, ktoru v kazdom volani funkcie upravujem pomocov DataControll a row na hodnotu pre konkretny riadok

    while (fgets(line, LINE_LEN, stdin) != NULL) // v cykle while nacitavam zo standardneho vstupu do pola line postupne riadky az pokial nedojdem na koniec tabulky
    {
        removeN(line);                              // volam funkciu, ktora mi vymaze znak nove riadku
        nahrad_znak(line, delimeter, delimeter[0]); // volam funkciu, ktora mi nastavi pozadovane delimetre ak su zadane

        int Pdelimeter = colls(line, delimeter) - 1; // Premenna, ktora mi povie kolko mam v riadku delimetrov
        int coll = colls(line, delimeter);           // Premenna, ktora mi povie kolko mam v riadku stlpcov
        int lineControll = strlen(line);             // pomocna premenna, ktora mi sluzi na kontrolu ci riadok nepresahuje limit 10242 znakov
        //printf("Pocet stlpcov : %d", coll);
        //printf("\nPocet delimetrov : %d\n", Pdelimeter);

        if (lineControll > LINE_LEN - 2) // Kontrola obmedzenia dlzky riadku, ci riadok z tabulky nepresahuje limit -2 lebo musime pocitat s \n a \0
        {
            fprintf(stderr, "Riadok presahuje maximalnu dlzku riadku %i!!\n", LINE_LEN - 2); // ak je podmienka splnenaa teda  riadok je vacsi ako je limit tlacim spravu s errorom
                                                                                             // a ukoncujem program
            return 1;                                                                        // vraciam 1 aukoncujemprogram
        }

        if (row == 1) //ulozenie poctu stlpcov v prvom riadku
        {
            Pcol = colls(line, delimeter) - 1; //do premennej si ukladam pocetstlpcovv prvom riadku
        }

        if (argc <= 2) //kontrola poctu argumentov
        {
            fprintf(stderr, "Neboli zadane ziadne argumenty!!\n");
            return 1;
        }

        if (argc > 100) //kontrola maximalneho poctu argumentov
        {
            fprintf(stderr, "Maximalna dlzka argumentov je 100!!\n");
            return 1;
        }

        if (Pcol != colls(line, delimeter) - 1) // pre kazdy riadok  kontrolujem ci sedi pocet stlpcov v porovnani s  prvym riadkom
        {
            fprintf(stderr, "Pre zvoleny delimeter nesedi pocet stlpcov v tabulke!!\n");
            return 1;
        }
        for (Lcounter = 0; Lcounter < argc; Lcounter++) // vo for cykle prechadzam polom argumentov
        {
            if (strcmp(argv[Lcounter], "drow") == 0) //pomocov funkcie strcmp porovnavam ci sa mi v poli argumentov na indexe logickeho pocitadla
                                                     // nachadza argument s nazvom funkcie drow
            {
                if (argc - Lcounter < 2) // kontrolujem ci pre funkciu drow bolzadany spravny pocet parametrov ak nie ukoncujem program s prislusnym errorom
                {
                    fprintf(stderr, "Zle zadany drow!!\n");
                    return 1;
                }

                remove = atoi(argv[Lcounter + 1]); // pomocov funkcie atoi si do premennej remove priradim cislo z argumentu na nasledujucom indexe po indexe s nazvom funkcie, ktoru volam

                if (remove < 1) // v pripade ak jehodnota remove mensia ako 1 ukoncujem program kedze ako riadky tak aj stlpce pocitame od hodnoty 1
                {
                    fprintf(stderr, "Zle zadana hodnota argumentu pre drow!!\n");
                    return 1;
                }
                if (remove == 0) // kontrolujeme ak v parametroch funkcie nebola zadana ciselna hodnota ale znak funkcia ationam vrati 0, a ak sa hodnota remove
                                 // rovna 0 ukoncujem program errorom
                {
                    fprintf(stderr, "Zle zadany argument pre drow!!\n");
                    return 1;
                }
                if (remove != 0) // ak je vsetko v poriadku a premenna remove sa nerovna 0 a presla ostatnymi kontrolami volam si funkciu drowR
                {
                    drowR(line, row, remove); // volam funkciu, ktora sa ma vykonat
                }
            }
            else if (strcmp(argv[Lcounter], "drows") == 0) //vykonavam presne ten isty postup ako pri volani funkcie drow
            {
                if (argc - Lcounter < 3) // kedze funkcia drows musi mat dva parametre upravujem podmienku kde pocet argumentov - logicke pocitadlo musi byt viac ako 3
                {
                    fprintf(stderr, "Zle zadany drows!!\n");
                    return 1; // ak podmienka nebola splnena ukoncujem program errorom
                }

                rmFrom = atoi(argv[Lcounter + 1]); // pouzivam funkciu atio presne ako pri drow
                rmTo = atoi(argv[Lcounter + 2]);   // pouzivam funkciu atio presne ako pri drow

                if (rmFrom < 1 || rmTo < 1) //upravujem funkciu ak cislo riadku od ktoreho chcem vymazavat alebo cislo po ktory je mensie ako 1
                {
                    fprintf(stderr, "Zle zadana hodnota argumentu drows!!\n");
                    return 1; // ukoncujem program prislusnym errorom
                }
                if (rmFrom == 0 || rmTo == 0) // kontrolujem ci neni hodnota riadkov rovna nule rovnako ako pri funkcii drow
                {
                    fprintf(stderr, "Zle zadany argument pre drows!!\n");
                    return 1; // ak je aspon jedna z podmienok pravdiva ukoncujem program s prislusnym errorom
                }
                if (rmFrom != 0 && rmTo != 0) // ak je teda vsetko v poriadku a cisla riadkov su zadane spravne volam funkciu, ktoru chcem vykonat
                {

                    drows(line, row, rmFrom, rmTo); // volam funkciu drows na vykonanie
                }
            }
            else if (strcmp(argv[Lcounter], "irow") == 0) // funkcia IROW - vykonavam presne tak isto ako funkciu drow
            {
                if (argc - Lcounter < 2) // funkcia irow ma len jeden parameter pre kontrolujeme ci je rozdiel mensi ako 2 nie 3 ako v pripade napr. drows
                {
                    fprintf(stderr, "Zle zadany irow!!\n");
                    return 1;
                }
                add = atoi(argv[Lcounter + 1]);

                if (add < 1)
                {
                    fprintf(stderr, "Zle zadana hodnota argumentu pre irow!!\n");
                    return 1;
                }

                if (add == 0)
                {
                    fprintf(stderr, "Zle zadany argument pre irows!!\n");
                    return 1;
                }
                if (add != 0)
                {
                    irowR(delimeter, row, Pdelimeter, add);
                }
            }
            else if (strcmp(argv[Lcounter], "dcol") == 0) // funkcia DCOL - vykonavame presne ten isty postup ako pri funkcii dcol akurat volame funkciu nie pre riadky ale stlpce
            {
                if (argc - Lcounter < 2)
                {
                    fprintf(stderr, "Zle zadany dcol!!\n");
                    return 1;
                }
                rmCol = atoi(argv[Lcounter + 1]);
                if (rmCol <= 0)
                {
                    fprintf(stderr, "Zle zadany argument pre dcol!!\n");
                    return 1;
                }
                if (rmCol > coll) // v pripade ak nam je zadany stlpec, ktory sa nenachadza v tabulke tuto skutocnost ignorujeme
                {
                    break; // pomocov breaku teda vyskakujeme z funkcie bez jej vykonania (tlacime nezmenenu tabulku)
                }

                if (rmCol != 0)
                {
                    dcolC(delimeter, line, rmCol);
                }
            }
            else if (strcmp(argv[Lcounter], "dcols") == 0) //funkcia DCOLS - vykonavame presne ten isty postup ako pri funkcii dcol akurat volame funkciu nie pre riadky ale stlpce
            {
                if (argc - Lcounter < 3) // funkcia dcols ma 2 parametre preto kontrolujeme ci je rozdiel vacsi ako 3 argument dcols plus dva parametre
                {
                    fprintf(stderr, "Zle zadany dcols!!\n");
                    return 1;
                }
                rmColFrom = atoi(argv[Lcounter + 1]);
                rmColTo = atoi(argv[Lcounter + 2]);
                count = rmColTo - rmColFrom; //Pomocne pocitadlo, ktore nam urcuje kolko krat sa ma vykonat funkcia dcol
                if (rmColFrom <= 0 || rmColTo <= 0)
                {
                    fprintf(stderr, "Zle zadany argument pre dcols!!\n");
                    return 1;
                }
                if (rmColFrom > coll || rmColTo > coll) // rovnaky postup kontroly funkcie s viac parametrami ako pri funkcii dcols
                {
                    break;
                }

                for (int i = 0; i < count + 1; i++) // Pomocov premennej count vykonavame funkciu dcolC tolko krat, kolko je rozdiel zadanych hodnot v argumente ale +1 koli
                                                    // tomu, abz sa nam dcolC vykonal aj na poslednom zadanom stlpci
                {
                    dcolC(delimeter, line, rmColFrom);
                }
            }
            else if (strcmp(argv[Lcounter], "icol") == 0) //funkcia ICOL - vykonavame presne ten isty postup ako pri funkcii dcol akurat volame funkciu nie pre riadky ale stlpce
            {
                if (argc - Lcounter < 2) // funkcia ma jeden parameter
                {
                    fprintf(stderr, "Zle zadany icol!!\n");
                    return 1;
                }
                addColTo = atoi(argv[Lcounter + 1]);

                if (addColTo > coll)
                {
                    break;
                }
                if (addColTo <= 0)
                {
                    fprintf(stderr, "Zle zadany argument pre icol!!\n");
                    return 1;
                }

                icol(line, delimeter, addColTo);
            }
            else if (strcmp(argv[Lcounter], "cset") == 0) //funkcia CSET pre upravu dat -  vykonavame presne ten isty postup ako pri funkcii dcol akurat volame funkciu cset na upravu dat v tabulke
            {
                if (argc - Lcounter < 3) // funkcia ma 2 parametre
                {
                    fprintf(stderr, "Zle zadany cset!!\n");
                    return 1;
                }
                addColTo = atoi(argv[Lcounter + 1]);
                int setControll = strlen(argv[Lcounter + 2]); //kontrolna premenna sluzi na kontrolu, ci pocet znakov, ktory chce uzivatel nastavit do bunky neni vacsi ako limit
                                                              // bunky teda 100 znakov
                if (setControll > 100)                        // ak bol limit bunky prekroceny ukoncujeme program prislusnym errorom
                {
                    fprintf(stderr, "Do bunky neni mozne vlozit viac ako 100 znakov!!\n");
                    return 1;
                }

                DataControll++;                          // inkrementujeme pri kazdom volani funkcie kontrolne pocitadlo
                DataControllPerRow = DataControll / row; // kontrolne pocitadlo musime delit cislom riadku pre kazdy jeden spracovavany riadok inak by sa stalo,
                                                         // ze pri druhom riadku by hodnota kontrolneho pocitadla bola 2 aj ked bol zadany argument cset iba raz
                                                         // a program by bol ukonceny chybov
                if (DataControllPerRow > 1)              // ak bol prikaz pre spracovanie dat zadany viac ako raz pomocov kontrolneho pocitadla pre konkretny riadok ukoncime
                                                         // program prislusnym errorom
                {
                    fprintf(stderr, "Prekroceny pocet prikazov na spracovanie dat!!\n");
                    return 1;
                }
                if (addColTo <= 0)
                {
                    fprintf(stderr, "Zle zadany argument pre cset!!\n");
                    return 1;
                }
                if (addColTo > coll) // tak isto ako pri riadkoch a stlpcoch ak bol zadany pozadovany stlpec na ktorom chceme vykonac cset mimo
                                     // tabulky teda sa v nej taky stlpec nenachadza
                {
                    break; // pomocov breaku vyskakujeme z funkcie a tlacime neupravenu tabulku
                }

                cset(line, delimeter, argv[Lcounter + 2], addColTo); // ak boli vsetky parametre zadane spravne volame a vykonavame funkciu cset
            }
            else if (strcmp(argv[Lcounter], "tolower") == 0) // funkcia TOLOWER - vykonavame presne ten isty postup ako pri funkcii cset akurat volame funkciu tolower na upravu dat v tabulke
            {
                if (argc - Lcounter < 2)
                {
                    fprintf(stderr, "Zle zadany tolower!!\n");
                    return 1;
                }
                addColTo = atoi(argv[Lcounter + 1]);
                DataControll++;
                DataControllPerRow = DataControll / row;
                if (DataControllPerRow > 1)
                {
                    fprintf(stderr, "Prekroceny pocet prikazov na spracovanie dat!!\n");
                    return 1;
                }
                if (addColTo <= 0)
                {
                    fprintf(stderr, "Zle zadany argument pre tolower!!\n");
                    return 1;
                }
                if (addColTo > coll)
                {
                    break;
                }

                toLower(line, delimeter, addColTo);
            }
            else if (strcmp(argv[Lcounter], "toupper") == 0) // funkcia TOUPPER - vykonavame presne ten isty postup ako pri funkcii cset akurat volame funkciu toupper na upravu dat v tabulke
            {
                if (argc - Lcounter < 2) // funkcia ma jeden parameter
                {
                    fprintf(stderr, "Zle zadany toupper!!\n");
                    return 1;
                }
                addColTo = atoi(argv[Lcounter + 1]);
                DataControll++;
                DataControllPerRow = DataControll / row;
                if (DataControllPerRow > 1)
                {
                    fprintf(stderr, "Prekroceny pocet prikazov na spracovanie dat!!\n");
                    return 1;
                }
                if (addColTo <= 0)
                {
                    fprintf(stderr, "Zle zadany argument pre toupper!!\n");
                    return 1;
                }
                if (addColTo > coll)
                {
                    break;
                }

                toUpper(line, delimeter, addColTo); // volam a vykonavam funkciu toupper
            }
            else if (strcmp(argv[Lcounter], "round") == 0) //funkcia ROUND - vykonavame presne ten isty postup ako pri funkcii cset akurat volame funkciu round na upravu dat v tabulke
            {
                if (argc - Lcounter < 2) // funkcia ma len jeden parameter
                {
                    fprintf(stderr, "Zle zadany round!!\n");
                    return 1;
                }
                addColTo = atoi(argv[Lcounter + 1]);
                DataControll++;
                DataControllPerRow = DataControll / row;
                if (DataControllPerRow > 1)
                {
                    fprintf(stderr, "Prekroceny pocet prikazov na spracovanie dat!!\n");
                    return 1;
                }
                if (addColTo <= 0)
                {
                    fprintf(stderr, "Zle zadany argument pre round!!\n");
                    return 1;
                }
                if (addColTo > coll)
                {
                    break;
                }

                RoundC(line, delimeter, addColTo); // volam a vykonavam funkciu round
            }
            else if (strcmp(argv[Lcounter], "int") == 0) //funkcia INT -  vykonavame presne ten isty postup ako pri funkcii cset akurat volame funkciu int na upravu dat v tabulke
            {
                if (argc - Lcounter < 2) // funkcia ma len jeden parameter
                {
                    fprintf(stderr, "Zle zadany int!!\n");
                    return 1;
                }
                addColTo = atoi(argv[Lcounter + 1]);
                DataControll++;
                DataControllPerRow = DataControll / row;
                if (DataControllPerRow > 1)
                {
                    fprintf(stderr, "Prekroceny pocet prikazov na spracovanie dat!!\n");
                    return 1;
                }
                if (addColTo <= 0)
                {
                    fprintf(stderr, "Zle zadany argument pre tolower!!\n");
                    return 1;
                }
                if (addColTo > coll)
                {
                    break;
                }

                makeInt(line, delimeter, addColTo); // volame a vykonavame funkciu makeInt
            }
            else if (strcmp(argv[Lcounter], "copy") == 0) //funkcia COPY - vykonavame presne ten isty postup ako pri funkcii cset akurat volame funkciu copy na upravu dat v tabulke
            {
                if (argc - Lcounter < 3) // funkcia ma dva parametre
                {
                    fprintf(stderr, "Zle zadany copy!!\n");
                    return 1;
                }
                addColFrom = atoi(argv[Lcounter + 1]);
                addColTo = atoi(argv[Lcounter + 2]);
                DataControll++;
                DataControllPerRow = DataControll / row;
                if (DataControllPerRow > 1)
                {
                    fprintf(stderr, "Prekroceny pocet prikazov na spracovanie dat!!\n");
                    return 1;
                }
                if (addColFrom <= 0 || addColTo <= 0)
                {
                    fprintf(stderr, "Zle zadany argument pre copy!!\n");
                    return 1;
                }
                if (addColFrom > coll || addColTo > coll)
                {
                    break;
                }

                copy(line, delimeter, addColFrom, addColTo); // volame a vykonavame funkciu copy
            }
            else if (strcmp(argv[Lcounter], "swap") == 0) // funkcia SWAP - vykonavame presne ten isty postup ako pri funkcii cset akurat volame funkciu swap na upravu dat v tabulke
            {
                if (argc - Lcounter < 3) // funkcia ma dva parametre
                {
                    fprintf(stderr, "Zle zadany swap!!\n");
                    return 1;
                }
                addColFrom = atoi(argv[Lcounter + 1]);
                addColTo = atoi(argv[Lcounter + 2]);
                DataControll++;
                DataControllPerRow = DataControll / row;
                if (DataControllPerRow > 1)
                {
                    fprintf(stderr, "Prekroceny pocet prikazov na spracovanie dat!!\n");
                    return 1;
                }
                if (addColFrom <= 0 || addColTo <= 0)
                {
                    fprintf(stderr, "Zle zadany argument pre swap!!\n");
                    return 1;
                }
                if (addColFrom > coll || addColTo > coll)
                {
                    break;
                }

                swap(line, delimeter, addColFrom, addColTo); // volame a vykonavame funkciu swap
            }
            else if (strcmp(argv[Lcounter], "move") == 0) //funkcia MOVE -vykonavame presne ten isty postup ako pri funkcii cset akurat volame funkciu move na upravu dat v tabulke
            {
                if (argc - Lcounter < 3) // fnukcia ma dva parametre
                {
                    fprintf(stderr, "Zle zadany move!!\n");
                    return 1;
                }
                addColFrom = atoi(argv[Lcounter + 1]);
                addColTo = atoi(argv[Lcounter + 2]);
                DataControll++;
                DataControllPerRow = DataControll / row;
                if (DataControllPerRow > 1)
                {
                    fprintf(stderr, "Prekroceny pocet prikazov na spracovanie dat!!\n");
                    return 1;
                }
                if (addColFrom <= 0 || addColTo <= 0)
                {
                    fprintf(stderr, "Zle zadany argument pre move!!\n");
                    return 1;
                }
                if (addColFrom > coll || addColTo > coll)
                {
                    break;
                }
                if (addColFrom == addColTo)
                {
                    break;
                }

                move(line, delimeter, addColFrom, addColTo); // volame a vykonavame funkciu move
            }
        }
        printf("%s", line); // Vypisujem upraveny riadok
        row++;              // Inkrementujem pocitadlo riadkov

        for (Lcounter = 0; Lcounter < argc; Lcounter++) //funkcia ACOL - ak v ramci argumentov bol zadany acol volame ho az za vypisom riadku a vdaka tomu, ze na zaciatku vymazeme
                                                        // znak noveho riadku z kazdeho riadku sa nam delimeter(dalsi stlpec) vypise automaticky za poslednym znakom v danom riadku
                                                        // a tak vytvorime novy prazdny stlpec za poslednym stlpcom
        {
            if (strcmp(argv[Lcounter], "acol") == 0)
            {
                printf("%c", argv[2][0]); //vypisujeme prisluchajuci delimeter ako znak dalsieho noveho stlpca
            }
        }

        printf("\n"); // Manualne vypisujem znak noveho riadku, ktory som na zaciatku programu z riadku odstranil
    }

    for (Lcounter = 0; Lcounter < argc; Lcounter++) // fnukcia AROW - ak v ramci argumentov bol zadany arow volame ho az za nacitanim posledneho riadku zcyklu, kde postupne nacitavame riadky z tabulky
                                                    // takto dosiahneme to, ze sa nam vytvori novy riadok na konci tabulky iba raz a nebude vypisovany za kazdym nacitanym riadkom v cykle
    {
        if (strcmp(argv[Lcounter], "arow") == 0)
        {
            for (int i = 0; i < Pcol; i++) // pomocov pomocnej premennej pcol zistime kolko bolo stlpcov(delimetrov) v prvom riadku  a tomu prisluchajuci pocet
                                           // nasledne pomocov cyklu for tlacim do noveho prazdneho raidku na konci tabulky
            {
                printf("%c", argv[2][0]); // tlacime delimetre
            }
            printf("\n"); // este vytlacime pre tento riadok samostatne znak noveho riadku
        }
    }

    return 0; // ako posledne bezpecneukoncime program
}
