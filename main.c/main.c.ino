//This code requires the folowing library: https://github.com/z3t0/Arduino-IRremote

#include <IRremote.h>
#include <IRremoteInt.h>



const int decodePin = 9; //entrada de "dados" do controle
const int ledPIN = 13;

IRrecv irrecv(decodePin);

decode_results results;
void setup() {
  Serial.begin(9600);
  pinMode(decodePin, INPUT);
  pinMode(ledPIN, OUTPUT);
  digitalWrite(ledPIN, LOW);
  Serial.println("Aplicacao Iniciada");
  irrecv.enableIRIn(); // inicia o receptor
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    
    irrecv.resume();
    } 
  
}
