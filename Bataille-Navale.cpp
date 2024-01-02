//DM Programme bataille navale c++ Maxime Dupont-Jourdan CIEL 1
//save in github :https://github.com/max21910/Bataille-Navale
#include <iostream>
using namespace std;

char NavireA[8][8]; //placement navire A
char NavireB[8][8]; //placement navire B
char JoueurA[8][8]; //coup jouer A
char JoueurB[8][8]; //coup jouer B
char point = 46; //"." point ASCII
char ship = 88; // "X" ASCII
char miss_Shoot = 74; //"J" ASCII
char Shoot = 84; //"T" ASCII
char firstrow;
int firstligne;
int coupA = 0;
int coupB = 0;
int numberBoat = 4; //4 bateaux max 1 X = 1 bateaux

void printNavireA() {
    cout << "Bataille navale\n";
    cout << "  A  B  C  D  E  F  G  H\n";
    for (int Number = 0; Number < 8; Number++) {
        cout << Number + 1 << " "; 
        for (int ligne = 0; ligne < 8; ligne++)
        {
            cout << NavireA[Number][ligne] << "  ";
        }
         cout << "\n"; //return line.
    }
}

void printNavireB() {
    cout << "Bataille navale\n";
    cout << "  A  B  C  D  E  F  G  H\n";
    for (int Number = 0; Number < 8; Number++)
    {
        cout << Number + 1 << " "; 
        for (int ligne = 0; ligne < 8; ligne++)
        {
            cout << NavireB[Number][ligne] << "  ";
        }
        cout << "\n"; //return line.
    }
}

void printshootA() {
    cout << "\n"; // Ligne vide
    cout << "joueur A:\n";
    cout << "Bataille navale\n";
    cout << "  A  B  C  D  E  F  G  H\n";
    for (int Number = 0; Number < 8; Number++) {
        cout << Number + 1 << " "; 
        for (int ligne = 0; ligne < 8; ligne++)
        {
            cout << JoueurA[Number][ligne] << "  ";
        }
         cout << "\n"; //return line.
    }
}

void printshootB() {
    cout << "\n"; // Ligne vide
    cout << "joueur B:\n";
    cout << "Bataille navale\n";
    cout << "  A  B  C  D  E  F  G  H\n";
    for (int Number = 0; Number < 8; Number++) {
        cout << Number + 1 << " "; 
        for (int ligne = 0; ligne < 8; ligne++)
        {
            cout << JoueurB[Number][ligne] << "  ";
        }
         cout << "\n"; //return line.
    }
}

void input_playerA() {
    cout << "Positions du joueur A\n";
    for (int i = 1; i <= numberBoat; i++) {
        bool validInput = false;
        while (!validInput)
        {
            cout << "Saisir la " << i << "e position de colonne:\n";
            cin >> firstrow;
            if (firstrow >= 'A' && firstrow <= 'H') //verif non depassement de tableaux
            {
                firstrow = firstrow - 'A';
                cout << "Saisir la " << i << "e position de ligne:\n";
                cin >> firstligne;
                if (firstligne >= 1 && firstligne <= 8) //verif non depassement de tableaux
                {
                    firstligne = firstligne - 1;
                    if (NavireA[firstligne][firstrow] == ship) //si deja bateaux alors position deja saisie 
                    {
                        cout << "Erreur: Position deja saisie\n";
                    }
                    else 
                    {
                    NavireA[firstligne][firstrow] = ship; //remplacement des points par les croix symbole bateaux
                    validInput = true;
                    }
                }
                else
                {
                    cout << "Erreur: Veuillez saisir une ligne valide entre 1 et 8.\n";
                }
            } 
            else 
            {
                 cout << "Erreur: Veuillez saisir une case entre A et H.\n";
            }
            if (!validInput)
            { 
                cout << "Veuillez réessayer: \n";
            }
        }
    }
}

void input_playerB() {
    cout << "Positions du joueur B\n";
    for (int i = 1; i <= numberBoat; i++) {
        bool validInput = false;
        while (!validInput)
        {
            cout << "Saisir la " << i << "e position de colonne:\n";
            cin >> firstrow;
            if (firstrow >= 'A' && firstrow <= 'H') //verif non depassement de tableaux
            {
                firstrow = firstrow - 'A';
                cout << "Saisir la " << i << "e position de ligne:\n";
                cin >> firstligne;
                if (firstligne >= 1 && firstligne <= 8) //verif non depassement de tableaux
                {
                    firstligne = firstligne - 1;
                    if (NavireB[firstligne][firstrow] == ship) //si deja bateaux alors position deja saisie 
                    {
                        cout << "Erreur: Position deja saisie\n";
                    }
                    else 
                    {
                    NavireB[firstligne][firstrow] = ship; //remplacement des points par les croix symbole bateaux
                    validInput = true;
                    }
                }
                else
                {
                    cout << "Erreur: Veuillez saisir une ligne valide entre 1 et 8.\n";
                }
            } 
            else 
            {
                 cout << "Erreur: Veuillez saisir une case entre A et H.\n";
            }
            if (!validInput)
            { 
                cout << "Veuillez réessayer: \n";
            }
        }
    }
}

void checkwinner() {
    int hitA = 0;
    int hitB = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (JoueurB[i][j] == Shoot)
            { 
                hitA++;  //comptage nombre de bateaux toucher
            }
            if (JoueurA[i][j] == Shoot)
            {  
                hitB++;  //comptage nombre de bateaux toucher
            }
        }
    }
    if (hitA == 4) {   //il y a 4 bateaux max par joueur car 1 bateaux = 1X donc si il y a 4 touche il ne reste plus de bateaux
        cout << "Le joueur A a gagné! en " << hitA << " coups gagnants et " << coupA +1 << " coups au total \n"; //ajout de 1 pour prende en compte le dernier coup jouer
        exit(0); //stop the program 
    } else if (hitB == 4) {
        cout << "Le joueur B a gagné! en " << hitB << " coups gagnants et " << coupB +1<< " coups au total \n"; //ajout de 1 pour prende en compte le dernier coup jouer
        exit(0); //stop the program 
    }
}

void Place_Fire()
 {
    while (true)
    {
        cout << "Au tour du Joueur A:\n";
        for (int a = 1; a <= 2; a++)
        {
            bool validInput = false;
            while (!validInput)
            {
                cout << "Saisir la case de A-H:";
                cin >> firstrow;
                if (firstrow >= 'A' && firstrow <= 'H') 
                {
                    firstrow = firstrow - 'A'; // Convert letter to ASCII then to number
                    cout << "Saisir la ligne :\n";
                    cin >> firstligne;
                    firstligne = firstligne - 1;
                    if (firstligne >= 0 && firstligne <= 8)
                    {
                        JoueurA[firstligne][firstrow] = ship;
                        coupA++; // 1 coup de plus joué par le joueur A
                        if (JoueurA[firstligne][firstrow] == NavireB[firstligne][firstrow]) 
                        {
                            JoueurA[firstligne][firstrow] = Shoot;
                        } 
                        else 
                        {
                            JoueurA[firstligne][firstrow] = miss_Shoot;
                        }
                        validInput = true;
                        } 
                        else 
                        {
                            cout << "Erreur: Veuillez saisir une ligne valide entre 1 et 8.\n";
                        }   
                    } 
                    else
                    {
                        cout << "Erreur: Veuillez saisir une case entre A et H.\n";
                    }
                    printshootA();
                    checkwinner();
                }
            }
        cout << "Au tour du Joueur B:\n";
        for (int a = 1; a <= 2; a++)
        {
            bool validInput = false;
            while (!validInput) 
            {
                cout << "Saisir la case de A-H:";
                cin >> firstrow;
                if (firstrow >= 'A' && firstrow <= 'H') 
                {
                    firstrow = firstrow - 'A'; // Convert letter to ASCII then to number
                    cout << "Saisir la ligne :\n";
                    cin >> firstligne;
                    firstligne = firstligne - 1;
                    if (firstligne >= 0 && firstligne <= 8)
                    {
                        JoueurB[firstligne][firstrow] = ship;
                        coupB++; // 1 coup de plus joué par le joueur B
                        if (JoueurB[firstligne][firstrow] == NavireA[firstligne][firstrow])
                        {
                            JoueurB[firstligne][firstrow] = Shoot;
                        } 
                        else 
                        {
                            JoueurB[firstligne][firstrow] = miss_Shoot;
                        }
                        validInput = true;
                    } 
                    else
                    {
                        cout << "Erreur: Veuillez saisir une ligne valide entre 1 et 8.\n";
                    }
                } 
                else
                {
                    cout << "Erreur: Veuillez saisir une case entre A et H.\n";
                }
                printshootB();
                checkwinner();
            }
        }
    }
}

void createGameTable() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            NavireA[i][j] = point;
            NavireB[i][j] = point;
            JoueurA[i][j] = point;
            JoueurB[i][j] = point;
        }
    }
}

int main() {
    char input;
    cout <<"Bataille navale C++ by Max21910\n";
	cout <<"Demarer le jeux avec la touche P\n";
	cin >> input;
	if (input == 'P')
	{
    	createGameTable();
    	printNavireA();
    	input_playerA();
    	input_playerB();
    /*  verification placement de bateaux
    cout << "\n";
    cout << "joueur A:\n";
    printNavireA();
    cout << "\n";
    cout << "joueur B:\n";
    printNavireB();
     */
    	Place_Fire();
    }
    else 
    {
    	return 0;
    }
}