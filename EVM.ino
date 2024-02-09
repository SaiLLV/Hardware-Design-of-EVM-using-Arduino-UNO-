#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
int no_of_cand=0;
LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);
void setup()
{Serial.begin(9600);
 pinMode(13, OUTPUT);
 pinMode(10, OUTPUT);
 pinMode(9, OUTPUT);
 digitalWrite(10, HIGH);
 pinMode(A0, OUTPUT);
 digitalWrite(A0, HIGH);
  pinMode(A1, OUTPUT);
 digitalWrite(A1, HIGH);
  pinMode(A2, OUTPUT);
 digitalWrite(A2, HIGH);
 digitalWrite(13, HIGH);
 digitalWrite(9, HIGH);
 pinMode(8, OUTPUT);
 digitalWrite(8, HIGH);
 pinMode(7, OUTPUT);
 digitalWrite(7, HIGH);
 lcd_1.begin(16, 2); // Set up the number of columns and rows on the LCD.
 lcd_1.setCursor(0, 0);
  lcd_1.print("no of cand = ");
  lcd_1.print(no_of_cand);
while(Serial.available() == false);
no_of_cand= Serial.parseInt();}
void loop()
{
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting
  // begins with 0):
  lcd_1.clear();
  lcd_1.setCursor(0, 0);
  lcd_1.print("no of cand =");
  lcd_1.print(no_of_cand);
  no_of_cand=no_of_cand+1;
  delay(1000);
  int store[no_of_cand],pre=-1,cont=0;
  lcd_1.clear();
  for(int i=0;i<no_of_cand;i++){
  store[i]=0;}
  while(1){if(digitalRead(9)==LOW){pre=-1;}
    while(digitalRead(13)==LOW){cont = cont-1;
                                    if(cont<0){cont=no_of_cand-1;}
                                    sho(cont);
                                    while(digitalRead(13)==LOW){
                                      if(digitalRead(10)==LOW){
                                        pre=-81;
                                        break;}}}
      if(pre==-81){break;}
                               while(digitalRead(7)==LOW){
                               cont = cont-10;
                               if(cont<0){cont=no_of_cand-1;}
                                    sho(cont);
                                    while(digitalRead(7)==LOW);}
           while(digitalRead(10)==LOW){cont = cont+1;
                                    if(cont>no_of_cand-1){
                                    cont=0;}
                                    sho(cont);
                                    while(digitalRead(10)==LOW);}
  while(digitalRead(8)==LOW){cont = cont+10;
      if(cont>no_of_cand-1){cont=0;}
      sho(cont);
      while(digitalRead(8)==LOW);}
      while(digitalRead(A0)==LOW){if(digitalRead(A2)==LOW){store[cont]=store[cont]+1;
        lcd_1.clear();
  lcd_1.setCursor(0, 0);
  lcd_1.print("+1 vote for cand");
  lcd_1.print(cont);
      pre=cont;}
      while(digitalRead(A2)==LOW);}
      while(digitalRead(A1)==LOW){
        if(digitalRead(A2)==LOW){if(pre!=-1){store[cont]=store[cont]-1;
        pre=-1;
         lcd_1.clear();
  lcd_1.setCursor(0, 0);
  lcd_1.print("your vote has removed");}}}}
  for(int i=0;i<no_of_cand;i++){
    if(store[cont]<store[i]){
                   cont=i;}}
    for(int i=0;i<no_of_cand;i++){
    lcd_1.clear();
    lcd_1.setCursor(0, 0);
  lcd_1.print("votes for cand");
  lcd_1.print(i);
  lcd_1.print(":");
  lcd_1.print(store[i]);
  delay(1000);
  Serial.println("votes attined by cand"+String(i)+": "+String(store[i]));}
  Serial.println("cand with max votes");
  for(int i=0;i<no_of_cand;i++){
    if(store[i]==store[cont]){
    Serial.println(i);}}
  // print the number of seconds since reset:
  //lcd_1.print(seconds);
  delay(1000); // Wait for 1000 millisecond(s)
  //seconds += 1;
  no_of_cand=no_of_cand-1;
}
void sho(int a){
  lcd_1.clear();
  lcd_1.setCursor(0, 0);
  lcd_1.print("cand_no:");
  lcd_1.print(a);
  delay(1000);
  }