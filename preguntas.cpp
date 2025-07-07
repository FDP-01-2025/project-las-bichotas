#include <iostream>
#include <vector>
using namespace std;
struct pregunta
{
    string texto;
    vector<string> opciones;
    char respuesta;
};
vector<pregunta> preguntah = {
        {"Quien fue el primer pais en atacar en la segunda guerra mundial?", {"A) espana", "B) UK", "C) Alemania"}, 'C'},
        {"Que imperio construyo Machu Picchu?", {"A) Mayas", "B) Incas", "C) Aztecas"}, 'B'},
        {"Que muro cayo en 1989?", {"A) La Gran Muralla China", "B) El Muro de Berlin", "C) La Muralla de Adriano"}, 'B'},
        {"Quien es considerado el padre de la independencia de El Salvador?", {"A) Jose Matias Delgado", "B) Manuel Jose Arce", "C) Francisco Morazan"}, 'A'},
        {"Que fecha celebra El Salvador como Independencia?", {"A) 5 de mayo de 1821", "B) 15 de septiembre de 1821", "C) 20 de noviembre de 1821"}, 'B'},
        {"Que pueblos indigenas vivieron en territorio salvadoreno antes de la llegada de los espanoles?", {"A) Mayas y Pipiles", "B) Incas y Chibchas", "C) Nahuas y Quechuas"}, 'A'},
        {"Quien fue el primer presidente de El Salvador?", {"A) Francisco Morazan", "B) Manuel Jose Arce", "C) Gerardo Barrios"}, 'B'},
        {"Que guerra vivio El Salvador en la decada de 1980?", {"A) La guerra de los 100 anos", "B) La guerra civil salvadorena", "C) La guerra de Centroamerica"}, 'B'},
        {"Que acuerdo de paz puso fin a la guerra civil en El Salvador?", {"A) Tratado de Versalles", "B) Acuerdo de Camp David", "C) Acuerdos de Chapultepec"}, 'C'},
        {"Que heroe nacional salvadoreño lidero la lucha en el levantamiento de 1932?", {"A) Feliciano Ama", "B) Anastasio Aquino", "C) José Simeon Cañas"}, 'A'},
        {"Que evento comenzo en 1914?", {"A) La Revolución Francesa", "B) La Primera Guerra Mundial", "C) La Guerra Fria"}, 'B'},
        {"Que pacto en 1949 creo la OTAN?", {"A) Pacto de Varsovia", "B) Tratado del Atlantico Norte", "C) Tratado de Versalles"}, 'B'},
        {"Que caida en 1989 simboliza el final de la Guerra Fria?", {"A) La caída del Muro de Berlín", "B) La caida de Saigon", "C) La caida de Kabul"}, 'A'},
        {"Que pais lanzo el primer satelite al espacio en 1957?", {"A) Estados Unidos", "B) Alemania", "C) La URSS"}, 'C'},
        {"Que evento en 2001 sacudio al mundo?", {"A) La caida de la bolsa de Wall Street", "B) El 11 de septiembre en USA", "C) La primavera arabe"}, 'B'}};