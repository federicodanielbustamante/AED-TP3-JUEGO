/*
	TP 3 - Realizar un juego de preguntas y respuestas.
	Federico Daniel Bustamante
	17/05/2015
*/

#include <iostream>
#include <cstdlib>

int main() {
	bool nextQuestion(true);
	int category;
	int record = 0;
	int userResponse;
	// Categorias (0: Deportes, 1: Historia, 2: Geografia)
	// Preguntas Falsas
	const std::string sportsFalse[]    = {"¿Manuel Ginobili juega al Futbol?", "¿En el Basquet juegan 11 jugarores por equipo?", "¿La camiseta del club Huracan es Azul y Roja?"};
	const std::string historyFalse[]   = {"¿Belgrano cruzo los andes?", "¿Cristobal Colon llego a America en 1424?", "¿El 25 de Mayo se festeja el dia de la Independencia Argentina?"};
	const std::string geographyFalse[] = {"¿La ciudad de Roma queda en Francia?", "¿La capital de Argentina es La Plata?", "¿Las cataratas del Iguazu quedan en la provincia de Corrientes?"};

	const std::string sportsTrue[]    = {"¿Lionel Messi juega en el Barcelona?", "¿Los pumas juegan al Rugby?", "¿El mundial de futbol 2014 fue en Brasil?"};
	const std::string historyTrue[]   = {"¿El 9 de Julio es el dia de la Independencia Argentina?", "¿Cristobal Colon llego a America en 1492?", "¿En 2010 se festejo el Bicentenario de la Revolucion de Mayo?"};
	const std::string geographyTrue[] = {"¿La ciudad de Milan queda en Italia?", "¿La capital de la Provincia de Buenos Aires es La Plata?", "¿El Perito Moreno queda en Santa Cruz?"};

	while (nextQuestion) {
		std::cout << "Seleccione la categoria: \n";
		std::cout << "0: Deportes  \n";
		std::cout << "1: Historia  \n";
		std::cout << "2: Geografia \n";
		std::cin >> category;

		// Seteamos que tipo de respuesta queremos usar
		int questionResponse = std::rand() % 2;
		int questionIndex = std::rand() % 3;

		if (questionResponse == 1) {
			switch(category) {
				case 0 : std::cout << sportsTrue[questionIndex];
				break;
				case 1 : std::cout << historyTrue[questionIndex];
				break;
				case 2 : std::cout << geographyTrue[questionIndex];
				break;
			}
		} else {
			switch(category) {
				case 0 : std::cout << sportsFalse[questionIndex];
				break;
				case 1 : std::cout << historyFalse[questionIndex];
				break;
				case 2 : std::cout << geographyFalse[questionIndex];
				break;
			}
		}

		std::cout << "\n0: Falso, 1: Verdadero: ";

		std::cin >> userResponse;

		if (userResponse == questionResponse) {
			std::cout << "\nPerfecto, vamos por otra pregunta \n";
			record = record + 1;
		} else {
			nextQuestion = false;
		}
	}

	std::cout << "Tu record es:" << record;
}
