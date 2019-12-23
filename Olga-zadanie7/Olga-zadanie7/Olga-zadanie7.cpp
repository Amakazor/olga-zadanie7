#include <iostream>
/*ZADANIE 7*/
/*Temat: funkcje*/

//przestrzeń globalna (global scope) opisana w przykładzie 7.1

//Funkcja do przykładu 7.1
int add(int a, int b)
{
	//przestrzeń lokalna (local scope) funkcji add()
	return a + b;
}

//Funkcja do przykładu 7.2
int add_three(int a, int b, int c);

//Funkcja do przykładu 7.3
void print_line(std::string s);

//Funkcja do przykładu 7.4
int quadratic_value(int parameter_a, int parameter_b, int parameter_c, int x);


int main()
{
	//przestrzeń lokalna (local scope) funkcji main
	bool example = true;
	if (!example)
	{
		//przestrzeń lokalna powyższego ifa
		int current_example = 4;

		/*PRZYKŁAD 7.1*/
		/*Pierwsza, prosta funkcja*/
		if (current_example == 1)
		{
			//przestrzeń lokalna kolejnego ifa

			//Funkcje należy deklarować w przestrzeni (scope) globalnej (global scope).
			//(Jest od tego wyjątek, bardzo ważny wyjątek, który omówimy daleko później)
			//To znaczy: nie we wnętrzu jakiejkolwiek innej funkcji.
			//O przestrzeni wspominałem Ci już wcześniej, mówiąc, że zmienna zadeklarowana w nawiasach klamrowych jest usuwana po klamrze. Klamry wyznaczają przestrzeń.
			//Słowo przestrzeń jest bardzo podobne do słowa blok, tylko do tego zawiera także przestrzeń globalną, która nie jest blokiem
			//Po drodze w tym pliku umieszczę kilka różnych oznaczeń przestrzeni.
			//Funkcję można użyć tylko po tym (w linijkach następujących), jak została zadeklarowana.
			//Dlatego funkcja add() została stworzona przed funkcją main()
			int x = 4;
			int y = 7;

			std::cin >> x;
			std::cin >> y;
			std::cout << add(x, y) << '\n';  //wykorzystanie własnej funkcji
		}
		/*KONIEC PRZYK£AD 7.1*/
		else if (current_example == 2)
		/*PRZYKŁAD 7.2*/
		/*deklaracja a definicja funkcji*/
		{
			//Spójrz na fukcję add_three()
			//Jej deklaracja znajduje się na początku pliku
			//A jej definicja na samym końcu pliku
			//Mimo to funkcja działa całkowicie poprawnie
			//To dlatego, że ważne jest, żeby deklaracja znajdowała się przed użyciem. Definicja może znajdować się wtedy gdziekolwiek indziej w tej samej przestrzeni
			//Innymi słowy: zanim użyjesz funkcji, musisz poinformować kompilator, że ona jest, czym jest i co potrzebuje.
			//To co robisz możesz opisać znacznie później
			//Rozdział deklaracji i definicji jest stosowany w celu porządkowania, np. żeby nie mieć za dużo rzeczy na początku pliku przed main()

			std::cout << add_three(5, 6, 7) << '\n';
		}
		/*KONIEC PRZYK£AD 7.1*/
		else if (current_example == 3)
		/*PRZYKŁAD 7.3*/
		/*funkcja typu void*/
		{
			//funkcja każdego typu poza void musi zwracać jakaś wartość przy pomocy operatora return
			//void to funkcja wykonująca czynność, nie zwraca wartości
			//tak jak funkcja print_line() zadeklarowana powyżej
			
			print_line("stringy_string");
			print_line("Linia druga.");
		}
		/*KONIEC PRZYK£AD 7.3*/
		else if (current_example == 4)
		/*PRZYKŁAD 7.4*/
		/*bardziej skomplikowana funkcja*/
		{
			//funkcja może mieć dowolną funkcjonalność jaka jest Ci tylko potrzebna
			//przykładem odrobinę bardziej skomplikowanej funkcji może być funkcja obliczająca wartość funkcji kwadratowej
			//czyli zadeklarowana powyżej quadratic_value()

			//możesz się pobawić wartościami tych zmiennych
			int _a = 5;
			int _b = 2;
			int _c = 5;

			int _x = 1;


			int _returned_quadratic_value = quadratic_value(_a, _b, _c, _x); //przypisanie wartości funkcji do zmiennej

			if (_returned_quadratic_value == INT32_MIN)
			{
				std::cout << "parametr a prawdopodobnie wyniosl 0" << '\n';
			}
			else
			{
				std::cout << "wartosc tej funkcji kwadratowej to: " << _returned_quadratic_value << '\n';
			}
		}
		/*KONIEC PRZYK£AD 7.4*/
	}
	else
	/*ZADANIE 7.1*/
	// I po raz kolejny rozwój tego samego programiku!
	// Ja zmodyfikowałem go już, żeby użył funkcji add() w dodawaniu
	// Zmodyfikuj go w taki sposób:
	// 1. Stwórz następujące funkcje typu int na działania matematyczne:
	// 1.1 substract() na odejmowanie dwóch liczb
	// 1.2 multiply() na mnożenie dwóch liczb
	// 1.3 divide() na dzielenie dwóch liczb (tylko dzielenie, sprawdzenie czy dzielnik nie jest zerem zostaw tak jak jest, zrobimy to później)
	// 2. Wykorzystaj je w odpowiednich miejscach
	// 3. Stwórz funkcję parse_int_min_max() typu int, ktora działa podobnie jak oznaczony poniżej fragment Twojego kodu, czyli:
	// 3.1 przyjmuje jako parametry dwa inty: minimalny i maksymalny
	// 3.2 (w pętli) pobiera od użykownika int z konsoli
	// 3.3 (w dalszym ciągu w pętli) sprawdza czy int z 3.2 jest pomiedzy wartościami parametrów
	// 3.4 zwraca ten int
	// 4. zastąp tą funkcją fragment kodu który będzie oznaczony (wspomniany w punkcie 3)
	//
	// PS: 
	// W poprzednim zadaniu to przegapiłem (bo nie wywala błędu), ale z powodu tego, że zmieniłaś gdzie wczytujesz liczba_jeden i liczba_dwa trochę zabugowała Ci się funkcjonalność pętli w dzieleniu. 
	// Nie robi się nieskończona pętla ponieważ używasz tam right_try, które wcześniej ma już przypisane true
	// Więc jako 5.:
	// 5. Przyjrzyj się, co nie tak się dzieje w sprawdzeniu błędów dzielenia i napraw to w dowolny sposób
	{
		int iterator = 0;

		while (true)
		{
			float liczba_jeden = 0;
			float liczba_dwa = 0;
			int u_input = 0;
			float suma = 0;
			bool right_try = false;
			bool false_try = true;

			std::cout << "1. Dodawanie" << "\n\n";
			std::cout << "2. Odejmowanie" << "\n\n";
			std::cout << "3. Dzielenie" << "\n\n";
			std::cout << "4. Mnozenie" << "\n\n";
			std::cout << "5. Zakoncz program" << "\n\n";

			//oznaczony fragment kodu do przerobienia na funkcję
			do
			{
				if (!false_try)
				{
					std::cout << "Przykro mi, wybrales bledny numer dzialania" << "\n\n";
				}

				std::cout << "Podaj prosze numer opcji" << "\n\n";
				std::cin >> u_input;
				std::cout << "\n\n";

				if (u_input == 1 || u_input == 2 || u_input == 3 || u_input == 4 || u_input == 5)
				{
					right_try = true;
				}

				else if (false_try)
				{
					false_try = false;
				}

			} while (right_try == false);
			//koniec oznaczonego fragmentu kodu

			if (u_input == 5)
			{
				break;
			}

			std::cout << "Podaj prosze pierwsza liczbe" << "\n\n";

			std::cin >> liczba_jeden;

			std::cout << "\n";


			std::cout << "Podaj prosze druga liczbe" << "\n\n";
			
			std::cin >> liczba_dwa;

			std::cout << "\n";

			switch (u_input)
			{
			case 1:
				std::cout << "Twoj wynik wynosi: " << add(liczba_jeden, liczba_dwa);
				break;

			case 2:
				suma = liczba_jeden - liczba_dwa;
				std::cout << "Twoj wynik wynosi: " << suma;
				break;

			case 3:

				right_try = false;

				do
				{
					if (false_try)
					{
						std::cout << "Przepraszam, ale nie mozna dzielic przez 0, sprobuj jeszcze raz \n\n";
						std::cin >> liczba_dwa;
						std::cout << "\n\n";
					}

					if (liczba_dwa != 0)
					{
						suma = liczba_jeden / liczba_dwa;
						std::cout << "Twoj wynik wynosi: " << suma << "\n\n";
						right_try = true;
					}
					else if (liczba_dwa == 0)
					{
						false_try = false;
					}
				} while (right_try == false);
				break;

			case 4:
				suma = liczba_jeden * liczba_dwa;
				std::cout << "Twoj wynik wynosi: " << suma;
				break;

			default:
				std::cout << "Niepoprawna opcja" << "\n";
				break;
			}

			std::cout << "\n\n";

			iterator++;
		}

		std::cout << "Twoja petla wykonala sie " << iterator << " razy. Mam nadzieje, ze dobrze sie bawiles, uzytkowniku." << "\n\n";
	}
	/*KONIEC ZADANIE 7.1*/
}

int add_three(int a, int b, int c)
{
	return a + b + c;
}

void print_line(std::string s)
{
	std::cout << s << '\n';
}

int quadratic_value(int parameter_a, int parameter_b, int parameter_c, int x)
{
	if (parameter_a != 0)
	{
		return ((parameter_a * parameter_a * x) + (parameter_b * x) + parameter_c);
	}
	else
	{
		//instrukcja return musi zostać dodana w każdej ścieżce funkcji. W przeciwnym przypadku wystąpi błąd
		//nie mamy jeszcze omówionych mechanizmów kontroli błędów w przypadku złych parametrów, więc w przypadku niepoprawnych danych zwrócimy minimalną wartość inta.
		//to jeszcze nie jest tak jak się powinno robić, ale to lepsze niż zwrócenie np. 0 który z większym prawdopodobieństwem może być poprawnym wynikiem niż minimalna wartość int
		return INT32_MIN;
	}
}