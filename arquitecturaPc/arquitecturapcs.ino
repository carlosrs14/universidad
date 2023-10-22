#include <Stepper.h>

int a=0, b = 1, c=2, d=3, e = 4, f =5, g =6;
int  r1 = 7, v1 = 8, am = 9, v2 = 11, r2 = 10;

void setup(){
  for(int i = 0; i<12; i++) pinMode(i, OUTPUT);
}
void todobajo(){
  for(int i = 0; i<7; i++)digitalWrite(i, HIGH);
}
void n0(){
  todobajo();
    for(int i =0; i<6; i++) digitalWrite(i, LOW);
}
void n1(){
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
}
void n2(){
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(g, LOW);
    digitalWrite(e, LOW);
    digitalWrite(d, LOW);
}
void n3(){
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(g, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
}
void n4(){
    digitalWrite(b, LOW);
    digitalWrite(g, LOW);
    digitalWrite(c, LOW);
    digitalWrite(f, LOW);
}
void n5(){
    digitalWrite(a, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
}
void n6(){
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
}
void n7(){
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
}
void n8(){
  for(int i = 0; i<7; i++){
    digitalWrite(i, LOW);
  }
}
void n9(){
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
}
void (*funciones[])() = {n0, n1, n2, n3, n4, n5, n6, n7, n8, n9};
void contar(int n){
  for(int i = n; i>=0; i--){
      todobajo();
      funciones[i]();
        delay(1000);
    }
}
void loop(){
  //rojo inico (los comentarios son para s1)
  digitalWrite(v2, HIGH);
  digitalWrite(r1, HIGH);
  contar(7);
  //amarillo 
  digitalWrite(r1, LOW);
  digitalWrite(am, HIGH);
  contar(2);
  //verde
  digitalWrite(am, LOW);
  digitalWrite(v2, LOW);
  digitalWrite(v1, HIGH);
  digitalWrite(r2, HIGH);
  contar(5);
  //verde y amarillo
  digitalWrite(r2, LOW);
  digitalWrite(am, HIGH);
  contar(2);  
  //apago amarillo y verde
  digitalWrite(am, LOW);
  digitalWrite(v1, LOW);
}
