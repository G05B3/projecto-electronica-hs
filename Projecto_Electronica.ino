/*
 * PROJECTO DE ELECTRONICA
 * SPOTIFY LOW BUDGET
 * INCLUI UMA LISTA DE 5 MUSICAS PRE-DEFINIDAS, SELECIONAVEIS AO SE PRIMIR UM DOS DOIS BOTOES.
 * BOTAO DA ESQUERDA - AVANÇA UMA MUSICA
 * BOTAO DA DIREITA - RECUA UMA MUSICA
 */


#define BUZZER 2
#define BUTTONUP 3
#define BUTTONDOWN 4

//Segmentos
#define D1 0
#define D2 1
#define D4 2
#define D5 3
#define D7 4
#define D10 5
#define D11 6

const int SONG_LENGTH[5] = {44, 42, 55, 54, 18};

const int WEARENUMBERONE[44][3] = {{349, 750, 700}, {523, 250, 200}, {493, 125, 100}, {523, 125, 100}, {493, 125, 100}, {523, 125, 100}, {493, 250, 125}, {523, 250, 125}, {415, 500, 250}, {349, 750, 250},
                                {349, 250, 125}, {415, 250, 125}, {523, 250, 125}, {554, 500, 250}, {415, 500, 250}, {554, 500, 250}, {622, 500, 250},
                                {523, 250, 125}, {554, 250, 125}, {523, 250, 125}, {554, 250, 125}, {523, 1000, 375},
                                {349, 750, 700}, {523, 250, 200}, {493, 125, 100}, {523, 125, 100}, {493, 125, 100}, {523, 125, 100}, {493, 250, 125}, {523, 250, 125}, {415, 500, 250}, {349, 750, 250},
                                {349, 250, 125}, {415, 250, 125}, {523, 250, 125}, {554, 500, 250}, {415, 500, 250}, {622, 500, 250}, {554, 500, 250},
                                {523, 250, 125}, {554, 250, 125}, {523, 250, 125}, {554, 250, 125}, {523, 1000, 375}};

const int DRAGONBALLGT[42][3] = {{783, 500, 250}, {783, 500, 250}, {659, 250, 125}, {698, 250, 125}, {783, 250, 125}, {880, 250, 125}, {783, 500, 250}, {698, 500, 250}, {659, 500, 250}, {587, 500, 250},
                              {659, 500, 250}, {659, 500, 250}, {523, 250, 125}, {587, 250, 125}, {659, 250, 125}, {698, 250, 125}, {659, 500, 250}, {587, 500, 250}, {523, 500, 250}, {493, 1000, 250},
                              {440, 250, 125}, {440, 250, 125}, {523, 500, 250}, {880, 500, 250}, {783, 1000, 750}, {523, 500, 250}, {587, 250, 125}, {659, 250, 125},
                              {698, 500, 250}, {659, 500, 250}, {587, 500, 250}, {523, 500, 250}, {587, 1000, 750}, {523, 500, 250}, {493, 250, 250}, {523, 250, 250}, {523, 4000, 3750}, 
                              {349, 1250, 1250}, {391, 250, 225}, {349, 250, 225}, {329, 2500, 2250}};

const int RICKROLL[55][3] = {{415, 125, 62}, {466, 125, 62}, {553, 125, 62}, {466, 125, 62}, {698, 375, 250}, {698, 375, 250}, {623, 750, 700},
                            {415, 125, 62}, {466, 125, 62}, {523, 125, 62}, {415, 125, 62}, {623, 375, 250}, {623, 375, 250}, {554, 375, 300}, {523, 125, 62}, {466, 250, 125},
                            {415, 125, 62}, {466, 125, 62}, {553, 125, 62}, {466, 125, 62}, {553, 375, 250}, {623, 375, 250}, {523, 375, 250}, {415, 625, 375},
                            {415, 250, 125}, {623, 500, 250}, {554, 1000, 250},
                            {415, 125, 62}, {466, 125, 62}, {553, 125, 62}, {466, 125, 62}, {698, 375, 250}, {698, 375, 250}, {623, 750, 700},
                            {415, 125, 62}, {466, 125, 62}, {523, 125, 62}, {415, 125, 62}, {830, 500, 375}, {523, 250, 125}, {554, 375, 300}, {523, 125, 62}, {466, 250, 125},
                            {415, 125, 62}, {466, 125, 62}, {553, 125, 62}, {466, 125, 62}, {553, 375, 250}, {623, 375, 250}, {523, 375, 250}, {415, 625, 375},
                            {415, 250, 125}, {623, 500, 250}, {554, 2000, 250}};

const int ASTRONOMIA[54][3] = {{523, 250, 200}, {466, 250, 200}, {440, 250, 200}, {349, 250, 200}, {391, 500, 400}, {391, 250, 200}, {587, 250, 200}, {523, 500, 400}, {466, 500, 200}, 
                            {440, 500, 400}, {440, 250, 200}, {440, 250, 200}, {523, 500, 400}, {466, 250, 200}, {440, 250, 200}, {391, 500, 400}, {391, 250, 200}, {932, 250, 200}, {880, 250, 200}, 
                            {932, 250, 200}, {880, 250, 200}, {932, 250, 200}, {391, 500, 400}, {391, 250, 200}, {932, 250, 200}, {880, 250, 200}, {932, 250, 200}, {880, 250, 200}, {932, 250, 200},
                            {391, 500, 400}, {391, 250, 200}, {587, 250, 200}, {523, 500, 400}, {466, 500, 200}, 
                            {440, 500, 400}, {440, 250, 200}, {440, 250, 200}, {523, 500, 400}, {466, 250, 200}, {440, 250, 200}, {391, 500, 400}, {391, 250, 200}, {932, 250, 200}, {880, 250, 200}, 
                            {932, 250, 200}, {880, 250, 200}, {932, 250, 200}, {391, 500, 400}, {391, 250, 200}, {932, 250, 200}, {880, 250, 200}, {932, 250, 200}, {880, 250, 200}, {932, 250, 200}};

const int MINECRAFT[18][3] = {{466, 1000, 950}, {415, 500, 400}, {311, 1000, 990}, {369, 1500, 1400}, {466, 1000, 950}, {415, 500, 400}, {311, 1000, 990}, {277, 1500, 1250},
                            {466, 1000, 950}, {415, 500, 400}, {311, 1000, 990}, {369, 1500, 1400}, {466, 1000, 950}, {415, 500, 400}, {311, 500, 490}, {369, 500, 490}, {277, 1000, 990}, {233, 500, 490}};

//LookUpTable para o segment display
void LookUp(int digit, bool* segments){

   switch(digit)
   {
      case 0:
      segments[D1] = HIGH;
      segments[D2] = HIGH;
      segments[D4] = HIGH;
      segments[D7] = HIGH;
      segments[D10] = HIGH;
      segments[D11] = HIGH;             
      break;
      case 1:
      segments[D4] = HIGH;
      segments[D7] = HIGH;
      break;
      case 2:
      segments[D1] = HIGH;
      segments[D2] = HIGH;
      segments[D5] = HIGH;
      segments[D7] = HIGH;
      segments[D11] = HIGH;
      break;
      case 3:
      segments[D2] = HIGH;
      segments[D4] = HIGH;
      segments[D5] = HIGH;
      segments[D7] = HIGH;
      segments[D11] = HIGH;
      break;
      case 4:
      segments[D4] = HIGH;
      segments[D5] = HIGH;
      segments[D7] = HIGH;
      segments[D10] = HIGH;
      break;
      case 5:
      segments[D2] = HIGH;
      segments[D4] = HIGH;
      segments[D5] = HIGH;
      segments[D10] = HIGH;
      segments[D11] = HIGH;
      break;
      default:
      break;
   }
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(BUZZER, OUTPUT);
  pinMode(BUTTONUP, INPUT);
  pinMode(BUTTONDOWN, INPUT);

  //Pins do 7-Segment Display
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  static int contador = 0, leituraUP = 0, leituraDOWN = 0, i = 0, buttonflag = 1, song_index = 0;
  
  leituraUP = digitalRead(BUTTONUP);
  leituraDOWN = digitalRead(BUTTONDOWN);
  
  if (!leituraUP)
  {
    if (!buttonflag)
    {
      buttonflag = 1;
      if (contador < 5)
        contador++;
      else
        contador = 0;
      song_index = 0;
      Serial.println(contador);
    }
  }
  else if (!leituraDOWN)
  {
    if (!buttonflag)
    {
      buttonflag = 1;
      if (contador > 0)
        contador--;
      else
        contador = 5;
      song_index = 0;
      Serial.println(contador);
    }
  }
  else
    buttonflag = 0;

  //7 Segment Display
  bool segments[7] = {LOW, LOW, LOW, LOW, LOW, LOW, LOW};
  LookUp(contador, segments);
  digitalWrite(A0, segments[D1]);
  digitalWrite(A1, segments[D2]);
  digitalWrite(A2, segments[D4]);
  digitalWrite(A3, segments[D5]);
  digitalWrite(A4, segments[D7]);
  digitalWrite(A5, segments[D10]);
  digitalWrite(5, segments[D11]);
  
  //Tocar Musicas
  switch (contador)
  {
    case 1:
    if (song_index < SONG_LENGTH[0]){
      tone(BUZZER, WEARENUMBERONE[song_index][0], WEARENUMBERONE[song_index][2]*0.68);
      delay(WEARENUMBERONE[song_index][1]*0.68);
      song_index++;
    }
    else
    {
      song_index = 0;
      delay(2000);
    }
    break;
    case 2:
    if (song_index < SONG_LENGTH[1]){
      tone(BUZZER, DRAGONBALLGT[song_index][0], DRAGONBALLGT[song_index][2]*0.9);
      delay(DRAGONBALLGT[song_index][1]*0.9);
      song_index++;
    }
    else
    {
      song_index = 0;
      delay(2000);
    }
    break;
    case 3:
    if (song_index < SONG_LENGTH[2]){
      tone(BUZZER, RICKROLL[song_index][0], RICKROLL[song_index][2]);
      delay(RICKROLL[song_index][1]);
      song_index++;
    }
    else
    {
      song_index = 0;
      delay(2000);
    }
    break;
    case 4:
    if (song_index < SONG_LENGTH[3]){
      tone(BUZZER, ASTRONOMIA[song_index][0], ASTRONOMIA[song_index][2]);
      delay(ASTRONOMIA[song_index][1]);
      song_index++;
    }
    else
    {
      song_index = 0;
      delay(2000);
    }
    break;
  case 5:
    if (song_index < SONG_LENGTH[4]){
      tone(BUZZER, MINECRAFT[song_index][0], MINECRAFT[song_index][2]*1.1);
      delay(MINECRAFT[song_index][1]*1.1);
      song_index++;
    }
    else
    {
      song_index = 0;
    }
    break;
    default:
    break;
  }
}
