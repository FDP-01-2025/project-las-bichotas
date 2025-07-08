#include <iostream>
#include <vector>
using namespace std;

struct Question
{
    string text;
    vector<string> options;
    char answer;
};

// Se crearon las preguntas para luego ser llamadas como un vector dentro de nuestro codigo principal.
// El struct cuenta con el vector string que esta separado del string text para poder separar las preguntas.
// La variable char es usada para dar nuestra respuesta, la cual se compara en nuestro codigo de trivia para determinar si es correcta.

vector<Question> historyQuestions = {
    {"Quien fue el primer pais en atacar en la segunda guerra mundial?", {"A) espana", "B) UK", "C) Alemania"}, 'C'},
    {"Que imperio construyo Machu Picchu?", {"A) Mayas", "B) Incas", "C) Aztecas"}, 'B'},
    {"Que muro cayo en 1989?", {"A) La Gran Muralla China", "B) El Muro de Berlin", "C) La Muralla de Adriano"}, 'B'},
    {"Quien es considerado el padre de la independencia de El Salvador?", {"A) Jose Matias Delgado", "B) Manuel Jose Arce", "C) Francisco Morazan"}, 'A'},
    {"Que fecha celebra El Salvador como Independencia?", {"A) 5 de mayo de 1821", "B) 15 de septiembre de 1821", "C) 20 de noviembre de 1821"}, 'B'},
    {"Que pueblos indigenas vivieron en territorio salvadoreno antes de la llegada de los espanoles?", {"A) Mayas y Pipiles", "B) Incas y Chibchas", "C) Nahuas y Quechuas"}, 'A'},
    {"Quien fue el primer presidente de El Salvador?", {"A) Francisco Morazan", "B) Manuel Jose Arce", "C) Gerardo Barrios"}, 'B'},
    {"Que guerra vivio El Salvador en la decada de 1980?", {"A) La guerra de los 100 anos", "B) La guerra civil salvadorena", "C) La guerra de Centroamerica"}, 'B'},
    {"Que acuerdo de paz puso fin a la guerra civil en El Salvador?", {"A) Tratado de Versalles", "B) Acuerdo de Camp David", "C) Acuerdos de Chapultepec"}, 'C'},
    {"Que heroe nacional salvadoreno lidero la lucha en el levantamiento de 1932?", {"A) Feliciano Ama", "B) Anastasio Aquino", "C) Jose Simeon Canas"}, 'A'},
    {"Que evento comenzo en 1914?", {"A) La Revolucion Francesa", "B) La Primera Guerra Mundial", "C) La Guerra Fria"}, 'B'},
    {"Que pacto en 1949 creo la OTAN?", {"A) Pacto de Varsovia", "B) Tratado del Atlantico Norte", "C) Tratado de Versalles"}, 'B'},
    {"Que caida en 1989 simboliza el final de la Guerra Fria?", {"A) La caida del Muro de Berlin", "B) La caida de Saigon", "C) La caida de Kabul"}, 'A'},
    {"Que pais lanzo el primer satelite al espacio en 1957?", {"A) Estados Unidos", "B) Alemania", "C) La URSS"}, 'C'},
    {"Que evento en 2001 sacudio al mundo?", {"A) La caida de la bolsa de Wall Street", "B) El 11 de septiembre en USA", "C) La primavera arabe"}, 'B'}
};

vector<Question> musicQuestions = {
    {"Que cantante es conocido como the King of Pop?", {"A) Elvis Presley", "B) Michael Jackson", "C) Prince"}, 'B'},
    {"Que banda britanica estaba compuesta por John Lennon, Paul McCartney, George Harrison y Ringo Starr?", {"A) Queen", "B) The Beatles", "C) The Rolling Stones"}, 'B'},
    {"Quien canta WHITE FERRARI?", {"A) Kanye West", "B) Frank Ocean", "C) Bad Bunny"}, 'B'},
    {"Que genero musical nacio en el Bronx, Nueva York, en los anos 1970?", {"A) Jazz", "B) Rock and Roll", "C) Hip Hop"}, 'C'},
    {"Que ciudad de Estados Unidos es conocida como la cuna del Hip Hop?", {"A) Los Angeles", "B) Atlanta", "C) Nueva York (Bronx)"}, 'C'},
    {"Que artista latino tiene exitos como Vivir Mi Vida?", {"A) Marc Anthony", "B) Maluma", "C) Romeo Santos"}, 'A'},
    {"Que estilo musical popular nacio en Republica Dominicana?", {"A) Cumbia", "B) Merengue", "C) Tango"}, 'B'},
    {"Que artista latino es reconocido como pionero del trap en espanol?", {"A) Bad Bunny", "B) Anuel AA", "C) Arcangel"}, 'A'},
    {"Que banda de rock en espanol es de Argentina?", {"A) Soda Stereo", "B) Mana", "C) Cafe Tacvba"}, 'A'},
    {"Que cantante urbana canta Saoko?", {"A) Karol G", "B) Bad Bunny", "C) Rosalia"}, 'C'},
    {"Que grupo de Memphis es considerado pionero en el estilo Memphis Rap?", {"A) Three 6 Mafia", "B) Outkast", "C) Run-D.M.C"}, 'A'},
    {"Que artista canta Bichota?", {"A) Karol G", "B) Natti Natasha", "C) Anuel AA"}, 'A'},
    {"Que genero mezcla el jazz, musica afroamericana y latina?", {"A) Soul", "B) Latin Jazz", "C) Reggae"}, 'B'},
    {"Que cantante es conocido por sus comentarios polemicos en X?", {"A) Ye", "B) Kanye West", "C) Todas son correctas"}, 'C'},
    {"Que artista tiene el estilo de musica urbana en exitos como Felices los 4?", {"A) Maluma", "B) J Balvin", "C) Ozuna"}, 'A'}
};

vector<Question> sportsQuestions = {
    {"Cuantos jugadores hay en el campo por equipo en un partido de futbol?", {"a) 9", "b) 10", "c) 11"}, 'C'},
    {"Cada cuantos anos se celebra la Copa Mundial de la FIFA?", {"a) Cada 2 anos", "b) Cada 4 anos", "c) Cada 5 anos"}, 'B'},
    {"Que pais ha ganado mas Copas del Mundo?", {"a) Alemania", "b) Italia", "c) Brasil"}, 'C'},
    {"Como se llama el torneo de clubes mas importante de Europa?", {"a) Europa League", "b) Champions League", "c) Conference League"}, 'B'},
    {"Cual de estos paises nunca ha ganado un Mundial?", {"a) Inglaterra", "b) Espana", "c) Paises Bajos"}, 'C'},
    {"Que significa 'hat-trick' en futbol?", {"a) Anotar tres goles en un partido", "b) Ganar tres titulos en un ano", "c) Defender tres penales"}, 'A'},
    {"Que pais fue sede del Mundial en 2022?", {"a) Rusia", "b) Qatar", "c) Japon"}, 'B'},
    {"Cual es la maxima autoridad en un partido de futbol?", {"a) El entrenador", "b) El capitan", "c) El arbitro"}, 'C'},
    {"Que superficie es la mas comun en el futbol profesional?", {"a) Arena", "b) Cesped", "c) Concreto"}, 'B'},
    {"Que pasa si un partido de eliminacion directa termina empatado tras los 90 minutos y el tiempo extra?", {"a) Se repite el partido", "b) Se define por penales", "c) Se da empate"}, 'B'},
    {"Cuantos anillos tiene el simbolo olimpico?", {"a) 4", "b) 5", "c) 6"}, 'B'},
    {"Que deporte se juega en un campo llamado 'diamond' en ingles?", {"a) Rugby", "b) Hockey", "c) Beisbol"}, 'C'},
    {"Cual es el principal torneo anual de tenis sobre cesped?", {"a) Roland Garros", "b) Wimbledon", "c) US Open"}, 'B'},
    {"Cuantos sets se necesitan ganar para triunfar en un partido de tenis masculino de Grand Slam?", {"a) 2", "b) 3", "c) 4"}, 'B'},
    {"Que deporte usa un disco llamado 'puck'?", {"a) Balonmano", "b) Hockey sobre hielo", "c) Waterpolo"}, 'B'}
};

vector<Question> geographyQuestions = {
    {"Cual es el rio mas largo del mundo?", {"a) Amazonas", "b) Nilo", "c) Yangtse"}, 'A'},
    {"Cual es la capital de Suecia?", {"a) Copenhague", "b) Estocolmo", "c) Oslo"}, 'B'},
    {"En que continente se encuentra Vietnam?", {"a) Asia", "b) Europa", "c) Africa"}, 'A'},
    {"Cual es el pais con mas islas en el mundo?", {"a) Indonesia", "b) Suecia", "c) Filipinas"}, 'B'},
    {"Cual es el desierto mas grande del mundo?", {"a) Sahara", "b) Antartico", "c) Gobi"}, 'B'},
    {"Cual es la montana mas alta del mundo?", {"a) K2", "b) Everest", "c) Aconcagua"}, 'B'},
    {"En que pais esta el Taj Mahal?", {"a) India", "b) Pakistan", "c) Nepal"}, 'A'},
    {"Cual es el pais mas poblado del mundo?", {"a) India", "b) China", "c) Estados Unidos"}, 'B'},
    {"Que pais tiene forma de bota?", {"a) Francia", "b) Italia", "c) Grecia"}, 'B'},
    {"Cual es la capital de Corea del Sur?", {"a) Busan", "b) Seul", "c) Tokio"}, 'B'},
    {"Cual es el lago mas grande de Africa?", {"a) Lago Victoria", "b) Lago Tanganica", "c) Lago Malawi"}, 'A'},
    {"En que continente esta Surinam?", {"a) Europa", "b) Africa", "c) America"}, 'C'},
    {"Cual es el pais mas pequeno del mundo?", {"a) Monaco", "b) San Marino", "c) Ciudad del Vaticano"}, 'C'},
    {"Que oceano bana la costa este de Estados Unidos?", {"a) Atlantico", "b) Pacifico", "c) Indico"}, 'A'},
    {"Cual es la capital de Nueva Zelanda?", {"a) Auckland", "b) Wellington", "c) Christchurch"}, 'B'}
};
