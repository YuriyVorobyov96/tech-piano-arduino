
#define BUZZER_PIN    13 // buzzer pin
#define FIRST_KEY_PIN 5  // first pin with key
#define KEY_COUNT     5  // keys count
#define LED_GREEN     2
#define LED_BLUE      3
#define LED_RED       4
#define POT_PIN       A0

int keyCode;

void setup()
{
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_RED,OUTPUT);
  pinMode(LED_GREEN,OUTPUT);
  pinMode(LED_BLUE,OUTPUT);
  pinMode(POT_PIN,INPUT);
  Serial.begin(9600);
}

void loop()
{
  while (Serial.available() == 0)
  {
    digitalWrite(LED_RED,LOW);
    digitalWrite(LED_BLUE,LOW);
    digitalWrite(LED_GREEN,LOW);

  for (int i = 0; i < KEY_COUNT; ++i) {
    int keyPin = i + FIRST_KEY_PIN;

    boolean keyUp = digitalRead(keyPin);
    int rotation = analogRead(POT_PIN);

    int beg_freq = rotation*3;
    
    if (!keyUp) {
      String str = "" + i;
      Serial.println(str);
      int frequency = beg_freq + i * 500;
      tone(BUZZER_PIN, frequency, 20);
      if ((i == 0) or (i == 1))
        {
          digitalWrite(LED_GREEN,HIGH);
        } else if((i == 2) or (i == 3))
        {
           digitalWrite(LED_RED,HIGH);
        } else if(i == 4)
        {
          digitalWrite(LED_BLUE,HIGH);
        }
    }
    /*digitalWrite(LED_RED,LOW);
    digitalWrite(LED_BLUE,LOW);
    digitalWrite(LED_GREEN,LOW);*/
    }
  };
  keyCode = Serial.read(); 
  
  int rotation = analogRead(POT_PIN);
  int beg_freq = rotation*3;
  int frequency = beg_freq + keyCode * 500;

    tone(BUZZER_PIN, frequency, 40);

  if ((keyCode == 0) or (keyCode == 1))
        {
          digitalWrite(LED_GREEN,HIGH);
        } else if((keyCode == 2) or (keyCode == 3))
        {
           digitalWrite(LED_RED,HIGH);
        } else if(keyCode == 4)
        {
          digitalWrite(LED_BLUE,HIGH);
        }
  
}

