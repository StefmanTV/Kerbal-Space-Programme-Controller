//stageing
const int STAGE_BUTTON = 2;
int LastSTAGE = HIGH;

//map
const int MAP_BUTTON = 4;
int LastMAP = HIGH;
bool MAPstate = false;

//SAS
const int SAS_SWITCH = 5;
int LastSAS = HIGH;

//RCS
const int RCS_SWITCH = 6;
int LastRCS = LOW;

//forward
const int TimeForward_BUTTON = 10;
int LastTimeForward = HIGH;

//backward
const int TimeBack_BUTTON = 9;
int LastTimeBack = HIGH;

//RCS JOY
#define RVRX_PIN A0
#define RVRY_PIN A1
int xValueR = 0;
int yValueR = 0;

//NORM JOY
#define NRVX_PIN A2
#define NRVY_PIN A3
int xValueN = 0;
int yValueN = 0;

//THROTTLE
#define THROTTLE A4
int LastTHROTTLE = 0;



void setup()
{
  Serial.begin(9600);
  pinMode(STAGE_BUTTON, INPUT_PULLUP);
  pinMode(MAP_BUTTON, INPUT_PULLUP);
  pinMode(SAS_SWITCH, INPUT_PULLUP);
  pinMode(RCS_SWITCH, INPUT_PULLUP);
  pinMode(TimeForward_BUTTON, INPUT_PULLUP);
  pinMode(TimeBack_BUTTON, INPUT_PULLUP);
}

void loop()
{
  //stageing
  int CurrentSTAGE = digitalRead(STAGE_BUTTON);
  
  if (LastSTAGE == HIGH && CurrentSTAGE == LOW)
  {
    Serial.println("STAGE");
  }
  LastSTAGE = CurrentSTAGE;

  //map
  int CurrentMAP = digitalRead(MAP_BUTTON);

  if (LastMAP == HIGH && CurrentMAP == LOW)
  {
    MAPstate = !MAPstate;
  
    if (MAPstate == true)
    {
      Serial.println("MAP ON");
    }
    else
    {
      Serial.println("MAP OFF");
    }
  }
  LastMAP = CurrentMAP;

  //SAS
  int CurrentSAS = digitalRead(SAS_SWITCH);

  if (CurrentSAS != LastSAS)
  {
    if (CurrentSAS == LOW)
    {
      Serial.println("SAS ON");
    }
    else
    {
      Serial.println("SAS OFF");
    }
  }
  LastSAS = CurrentSAS;

  //RCS
  int CurrentRCS = digitalRead(RCS_SWITCH);

  if (CurrentRCS == LOW)
  {
    Serial.println("RCS ON");
    xValueR = analogRead(RVRX_PIN);
    yValueR = analogRead(RVRY_PIN);

    Serial.println(xValueR);
    Serial.println(yValueR);
  }
  if (LastRCS == LOW && CurrentRCS == HIGH)
  {
    Serial.println("RCS OFF");
  }
  LastRCS = CurrentRCS;

  //Time Forward
  int CurrentTimeForward = digitalRead(TimeForward_BUTTON);

  if (LastTimeForward == HIGH && CurrentTimeForward == LOW)
  {
    Serial.println("Next Multiplier");
  }
  LastTimeForward = CurrentTimeForward;

  
  //Time Backwards
  int CurrentTimeBack = digitalRead(TimeBack_BUTTON);

  if (LastTimeBack == HIGH && CurrentTimeBack == LOW)
  {
    Serial.println("Prev Multiplier");
  }
  LastTimeBack = CurrentTimeBack;

  //NORM JOYSICK
  xValueN = analogRead(NRVX_PIN);
  yValueN = analogRead(NRVY_PIN);

  //throttle
  int CurrentTHROTTLE = analogRead(THROTTLE);
  int perc_throttle = map(CurrentTHROTTLE, 0, 1023, 0, 100);
  if (LastTHROTTLE != CurrentTHROTTLE)
  {
    Serial.println(perc_throttle);
    delay(200);
  }
  LastTHROTTLE = CurrentTHROTTLE;

}
