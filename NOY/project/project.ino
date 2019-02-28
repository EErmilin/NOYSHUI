#include <iarduino_DHT.h>

int DHTPIN = 2; // Пин датчика

int h_max = 0;
int h_min = 0;
int t_max = 0;
int t_min = 0;
iarduino_DHT sensor(DHTPIN);

//int knopka = 9; // Пин кнопки

void setup() {

//pinMode(9,INPUT);

Serial.begin(9600);

delay(2000);

}

void loop() 
{
  switch(1) // Здесь должно лежать получаемое число с C++ вместо 1
  {
    case 1:
    {
      temp();
      delay(200);
      break;
    }
    case 2:
    {
      hum();
      delay(200);
      break;
    }
  }
}
void temp()
{
  switch(sensor.read())
  {
    case DHT_OK:
    {
      t_max = float(1.05 * sensor.tem);
      t_min = float(0.95 * sensor.tem);
    }
  }
}
void hum()
{
  switch(sensor.read())
  {
    case DHT_OK:
    {
      h_max = float(1.05 * sensor.hum);
      h_min = float(0.95 * sensor.hum);
    }
  }
}
