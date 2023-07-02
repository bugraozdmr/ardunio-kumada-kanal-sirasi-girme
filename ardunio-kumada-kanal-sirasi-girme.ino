#include <IRremote.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3); // pcd8544 üretici

int RECV_PIN = 2;

IRrecv IR0(RECV_PIN);

decode_results results;

// buttons from controller
const long int tus_1 =16753245;
const long int tus_2 =16736925;
const long int tus_3 =16769565;
const long int tus_4 =16720605;
const long int tus_5 =16712445;
const long int tus_6 =16761405;
const long int tus_7 =16769055;
const long int tus_8 =16754775;
const long int tus_9 =16748655;
const long int tus_0 =16750695;

// let's begin...

long int tuslar[10]={tus_1,tus_2,tus_3,tus_4,tus_5,tus_6,tus_7,tus_8,tus_9,tus_0};

int p=0;    //kontrol deger

void setup()
{

  display.begin();
  display.clearDisplay(); // bu yapılmazsa başta çıkan yıldız sürekli çıkar
  // you can change the contrast around to adapt the display for the best viewing!
  display.setContrast(100);

  Serial.begin(9600);

  Serial.println("Enabling IRin");
  IR0.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
}
int  k, l, m;   //hesap degerleri

void loop()
{

  int u = 0; // bu işlem yapacak
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.println(" -kanal sira-");
  display.println("--------------"); // 14 karakter alabiliyor
  display.setTextSize(2);
  display.print("  ");
  display.print("---");
  display.display();

  if (IR0.decode(&results))
  {                                // tus kodu aliciya ulastiysa
    

    Serial.println(results.value);
    IR0.resume();                  // yeniden farkli tuslara basildiginda tekrar calis
    display.clearDisplay();        // once bir silelim
    display.setTextSize(1);
    display.setTextColor(BLACK);
    display.println(" -kanal sira-");
    display.println("--------------"); // 14 karakter alabiliyor
    display.setTextSize(2);
    display.print("  ");

    switch (results.value)
    {
    case tus_1:
      k = 1;
      break;
    case tus_2:
      k = 2;
      break;
    case tus_3:
      k = 3;
      break;
    case tus_4:
      k = 4;
      break;
    case tus_5:
      k = 5;
      break;
    case tus_6:
      k = 6;
      break;
    case tus_7:
      k = 7;
      break;
    case tus_8:
      k = 8;
      break;
    case tus_9:
      k = 9;
      break;
    case tus_0:
      k = 0;
      break;
    }
    Serial.print("k degeri :");
    Serial.println(k);
    u = k * 1;
    display.print(u);
    display.display();

    for (int i = 0; i < 7; i++)
    { // 700 ms beklerken basma olacak mı
      Serial.print("1.fonk :");
      Serial.println(i+1);
      if (IR0.decode(&results))
      {
        for(int j=0;j<10;j++){    //basili tutmak bozuk degerler donduruyor
          if((long int)results.value==tuslar[j]){
            p=1;
          }
        }
        if(p!=1) {
          Serial.print("hatali deger:");
          Serial.println(results.value);
          p=0;
          delay(500);
          continue;
        }
        Serial.print("1.fonk devam");
        Serial.println(results.value);
        u = 0;                    // u degiscek demek
        IR0.resume();             // yeniden farkli tuslara basildiginda tekrar calis
        display.clearDisplay();   // once bir silelim
        display.setTextSize(1);
        display.setTextColor(BLACK);
        display.println(" -kanal sira-");
        display.println("--------------"); // 14 karakter alabiliyor
        display.setTextSize(2);
        display.print("  ");

        switch (results.value)
        {
        case tus_1:
          l = 1;
          break;
        case tus_2:
          l = 2;
          break;
        case tus_3:
          l = 3;
          break;
        case tus_4:
          l = 4;
          break;
        case tus_5:
          l = 5;
          break;
        case tus_6:
          l = 6;
          break;
        case tus_7:
          l = 7;
          break;
        case tus_8:
          l = 8;
          break;
        case tus_9:
          l = 9;
          break;
        case tus_0:
          l = 0;
          break;
        }
        Serial.print("l degeri :");
        Serial.println(l);
        u = k * 10 + l * 1;
        display.print(u);
        display.display();
        break;
      }
      delay(250);
    }

    for (int i = 0; i < 7; i++)
    { // 700 ms beklerken basma olacak mi
      if (IR0.decode(&results))
      {
        Serial.print("2.fonk :");
        Serial.println(i+1);
        for(int j=0;j<10;j++){    //basili tutmak bozuk degerler donduruyor
          if((long int)results.value==tuslar[j]){
            p=1;
          }
        }
        if(p!=1) {
          Serial.print("hatali deger:");
          Serial.println(results.value);
          p=0;
          continue;
        }

        Serial.print("2.fonk devam");

        Serial.println(results.value);
        u = 0;                    // u degiscek demek
        IR0.resume();             // yeniden farkli tuslara basildiginda tekrar calis
        display.clearDisplay();   // once bir silelim
        display.setTextSize(1);
        display.setTextColor(BLACK);
        display.println(" -kanal sira-");
        display.println("--------------"); // 14 karakter alabiliyor
        display.setTextSize(2);
        display.print("  ");

        switch (results.value)
        {
        case tus_1:
          m = 1;
          break;
        case tus_2:
          m = 2;
          break;
        case tus_3:
          m = 3;
          break;
        case tus_4:
          m = 4;
          break;
        case tus_5:
          m = 5;
          break;
        case tus_6:
          m = 6;
          break;
        case tus_7:
          m = 7;
          break;
        case tus_8:
          m = 8;
          break;
        case tus_9:
          m = 9;
          break;
        case tus_0:
          m = 0;
          break;
        }
        Serial.print("m degeri :");
        Serial.println(m);
        u = k * 100 + l * 10 + m * 1;
        display.print(u);
        display.display();
        break;
      }
      delay(250);   //delay olmazsa bos gecmesi muhtemel
    }
    Serial.print("okunan deger :");
    Serial.println(u);
    Serial.println("3sn once");
    delay(3000); // 5 sn bekle
    Serial.println("3sn bitti");
  }
  display.display();
  display.clearDisplay();
}