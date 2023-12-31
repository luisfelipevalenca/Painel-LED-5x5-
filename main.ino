
// CONEXÕES
#define LINHA1 6
#define LINHA2 7
#define LINHA3 8
#define LINHA4 10
#define LINHA5 9

#define COLUNA1 5
#define COLUNA2 4
#define COLUNA3 3
#define COLUNA4 2
#define COLUNA5 A4

#define LBTN A0
#define RBTN A5

// PARÂMETROS
#define TEMPO_LINHA 1       // em milissegundos
#define TEMPO_QUADRO 16     // em milissegundos

// CONSTANTES
#define DIREITA 0
#define BAIXO   1
#define ESQUERDA  2
#define CIMA    3

const int linhas[] = {LINHA1, LINHA2, LINHA3, LINHA4, LINHA5};
const int colunas[] = {COLUNA1, COLUNA2, COLUNA3, COLUNA4, COLUNA5};

byte tela[5][5];  // Alterado para 5x5

// VARIÁVEIS
bool ultimoEstadoLBTN = LOW;
bool ultimoEstadoRBTN = LOW;

void limparTela() {
  for (int i = 0; i < 5; i++) {  
    for (int j = 0; j < 5; j++) {  
      tela[i][j] = 0;
    }
  }
}

void exibirTela(byte matriz[5][5]) {  
  for (byte c = 0; c < 5; c++) {  
    digitalWrite(colunas[c], HIGH);
    for (byte r = 0; r < 5; r++) {  
      digitalWrite(linhas[r], matriz[r][c] ? 0 : 255);
      delay(50);
    }
    for (byte r = 0; r < 5; r++) {  
      digitalWrite(linhas[r], HIGH);
      delay(50);
    }
    digitalWrite(colunas[c], LOW);
  }
}

void setup() {
  for (int i = 0; i < 5; i++) {  
    pinMode(linhas[i], OUTPUT);
    digitalWrite(linhas[i], LOW);

    pinMode(colunas[i], OUTPUT);
    digitalWrite(colunas[i], HIGH);
  }

  pinMode(LBTN, INPUT);
  pinMode(RBTN, INPUT);

  // Inicializar o estado inicial da tela
  limparTela();
}

void loop() {
  // Lógica para reagir aos botões
  if (digitalRead(LBTN) == HIGH && !ultimoEstadoLBTN) {
    // Piscar LEDs aleatoriamente
    for (int i = 0; i < 10; i++) {
      tela[random(5)][random(5)] = 1;  
    }
    exibirTela(tela);
    delay(5);  // Tempo de exibição 
    limparTela();
  }

  if (digitalRead(RBTN) == HIGH && !ultimoEstadoRBTN) {
    // Piscar LEDs aleatoriamente
    for (int i = 0; i < 10; i++) {
      tela[random(5)][random(5)] = 1; 
    }
    exibirTela(tela);
    delay(5);  // Tempo de exibição
    limparTela();
  }

  ultimoEstadoLBTN = digitalRead(LBTN);
  ultimoEstadoRBTN = digitalRead(RBTN);

  delay(TEMPO_QUADRO);
}
