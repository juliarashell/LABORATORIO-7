#define POT A0
class ControlPot
{
  public:
  ControlPot(int pin);
  void begin();
  void EncenderLed();
  void ApagarLed();
  private: // members for private use only
  int _pin;
  bool _status;  
};

ControlPot::ControlPot(int pin) // the constructor at work
{
  _pin = pin;  
}

void ControlPot::begin()
{
  Serial.begin(9600);
  pinMode(POT,INPUT); //Definimos el pin POT como entrada.
  pinMode(_pin,OUTPUT);
}

void ControlPot::EncenderLed()
{
  int valor = analogRead(POT);
  int mapeo = map(valor,512,1023,50,100);
  Serial.print("Valor POT: ");
  Serial.print(valor);
  Serial.print("| Valor en porcentaje: ");
  Serial.println(mapeo);

if(mapeo >=50 && mapeo <= 100)
  {
    digitalWrite(_pin,HIGH);
    _status = 1;
  }
}

void ControlPot::ApagarLed()
{
  int valor = analogRead(POT);
  int mapeo = map(valor,512,1023,50,100);
  Serial.print("Valor Potenciometro: ");
  Serial.print(valor);
  Serial.print("| Valor en porcentaje del Potenciometro: ");
  Serial.println(mapeo);

if(mapeo <50)
  {
    digitalWrite(_pin,LOW);
    _status = 0;
  }
}
