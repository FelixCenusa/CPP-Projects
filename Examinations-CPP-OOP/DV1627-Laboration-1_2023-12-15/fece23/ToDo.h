#ifndef TO_DO_H
#define TO_DO_H
#include <string>
using namespace std;

// Nedan finns beskrivning av tre funktioner som du ska tillf�ra.

// I denna fil tillf�r du funktions-deklarationerna och i ToDo.cpp tillf�r du motsvarande
// funktions-definitioner.

// Varje separat fler-raders kommentar (dvs inom /*  */) motsvarar beskrivning av en separat funktion
// och det finns d�rmed tre s�dana avsnitt.

// Alla tre funktioner m�ste vara korrekt l�sta f�r att du ska bli godk�nd p� laboration 1.

// I filen TestCorrectness.cpp finns tester som anv�nds f�r att kontrollera.
// din l�sning, dvs de funktioner du implementerat.

// I catch_amalgamated.cpp finns "main"-funktionen inbakad, och denna anv�nds n�r testerna exekveras. 

// Om du vill skapa en egen main under tiden du implementerar funktionerna beh�ver du 
// utesluta catch_amalgamated.hpp, catch_amalgamated.cpp samt TestCorrectness.cpp fr�n l�nkning (build)



/*
Funktion som byter inneh�llet i tv� heltalsvariabler

Funktionen ska ta emot tv� heltal.

Funktionens namn ska vara exchange.

Parametrar ska anges s� att det �verensst�mmer med anropen som visas i exemplet nedan, d�r
numberOne och numberTwo representerar heltalsvariabler.

exchange(numberOne, numberTwo);

Efter anropet ska numberOne och numberTwo ha bytt v�rde, t.ex om 
nrOne inneh�ller 10 innan anropet och numberTwo inneh�ller 20 innan anropet s� inneh�ller 
numberOne 20 efter anropet och numberTwo 10 efter anropet.

*/

void exchange(int &numberOne, int &numberTwo);

int findBiggest(int arr[], int cap = 10);

bool readStringsFromFile(string fileName,string strs[], int cap = 5);


//int indexOfBiggest = findBiggest(arr, 10);

//int a = 10;
//int b = 20;
//void work(int &a, int b);


/*
Funktion f�r att l�sa fr�n textfil:

L�ser ett antal str�ngar fr�n en textfil. Dessa placeras i en array. Om inget antal anges ska 5 str�ngar l�sas fr�n fil.

Det finns en str�ng per rad p� filen och varje str�ng kan inneh�lla blanktecken (mellanslag, tabulering, ...).

Om det inte �r m�jligt att l�sa fr�n fil ska false returneras. Om l�sning genomf�rs ska true returneras.

Du kan f�ruts�tta att det finns tillr�ckligt med str�ngar p� filen.

Funktionens namn ska vara readStringsFromFile.

Parametrar ska anges s� att det �verensst�mmer med anropen som visas i exemplen nedan.
"example.txt" �r namnet p� textfilen och strs �r arrayen.

if (readStringsFromFile("example.txt", strs, 10)) {...}

Om det gick att l�sa fr�n filen example.txt ska true returneras och arrayen strs inneh�lla de 10 str�ngar som l�sts fr�n filen.
Om det inte gick att l�sa fr�n filen ska false returneras och arrayen strs vara of�r�ndrad avseende sitt inneh�ll.

readStringsFromFile("example.txt", strs);

Om det gick att l�sa fr�n filen example.txt ska true returneras och arrayen strs inneh�lla de 5 str�ngar som l�sts fr�n filen.
Om det inte gick att l�sa fr�n filen ska false returneras och arrayen strs vara of�r�ndrad avseende sitt inneh�ll.

*/


/*
Funktion f�r att s�ka det st�rsta heltalet i en array med heltal:

Funktionen ska returnera index f�r var det st�rsta heltalet i arrayen finns.

Om det finns flera heltal som har det st�rsta v�rdet ska index f�r det f�rsta av dessa returneras.

Funktionens namn ska vara findBiggest.

Du kan f�ruts�tta att det finna minst ett heltal i arrayen.

Parametrar ska anges s� att det �verensst�mmer med anropen som visas i exemplet nedan, d�r
arr representerar en array med heltal.

int indexOfBiggest = findBiggest(arr, 10);

Efter anropet ska indexOfBiggest inneh�lla index f�r var i arrayen arr det st�rsta av de 10 f�rsta heltalen finns.
*/


#endif



