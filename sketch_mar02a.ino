#define BtnPin_R 3
#define BtnPin_B 12
#define BtnPin_Y 2
#define BtnPin_G 4

#define LedPin_R 10
#define LedPin_Y 11

#define CODE_LEN 4

char GoodCode[CODE_LEN]={'R','R','G','Y'};
char CurrLetter= ' ';
char Guess[CODE_LEN];
int currPos=0;


void setup() {
  Serial.begin(9600);
  pinMode(BtnPin_R,INPUT_PULLUP);
  pinMode(BtnPin_G,INPUT_PULLUP);
  pinMode(BtnPin_Y,INPUT_PULLUP);
}

bool yellowBtnIsPressed=false;
int lastGreenBtnVal;
void loop(){
  if(digitalRead(BtnPin_Y)==LOW){
    if(!yellowBtnIsPressed){
     CurrLetter='Y';
     Guess[currPos]=CurrLetter;
     currPos++;
     if(currPos>=CODE_LEN){
       currPos=0;
      }
    }
    yellowBtnIsPressed=true;
  }else{
    yellowBtnIsPressed=false;
  }
   if(digitalRead(BtnPin_R)==LOW){
     CurrLetter='R';
     Guess[currPos]=CurrLetter;
     currPos++;
     if(currPos>=CODE_LEN){
       currPos=0;
     }
     while(digitalRead(BtnPin_R)==LOW);
     delay(20);
  } 


   int GreenbtnVal=digitalRead(BtnPin_G);
   if((GreenbtnVal==LOW)&&(lastGreenBtnVal==HIGH)

CurrLetter='G';
     Guess[currPos]=CurrLetter;
     currPos++;
     if(currPos>=CODE_LEN){
       currPos=0;
     }  
  } 
  lastGreenBtnVal=GreenbtnVal;
  Serial.println(Guess);
  delay(50);
}
