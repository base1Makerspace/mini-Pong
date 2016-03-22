 #include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int paddle = A0;
const int paddle2 = A1;
const int resetButton = 7;
const int piezoPin = 6;
int yvalue;
int y;
int y2value;
int y2;
int x = 2;
int zeil;
int switchState = 0;
int speed = 150;
int val = 1;

int running = true;

void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);
  pinMode(resetButton, INPUT);
}

void loop () {
  switchState = digitalRead(resetButton);
  if (switchState == HIGH) {
	  running = true;
          speed = 150;
  }
  
  if (gameover) {
    running = false;
    lcd.setCursor(0,0);
		lcd.print("Game Over");
                 tone(piezoPin, 262, 375);
                 delay(700);
                 tone(piezoPin, 196, 375);
                 delay(700);
                 tone(piezoPin, 165, 740);
                 delay(300);
                 tone(piezoPin, 220, 490);
                 delay(300);
                 tone(piezoPin, 247, 490);
                 delay(300);
                 tone(piezoPin, 220, 490);
                 delay(300);
                 tone(piezoPin, 208, 490);
                 delay(300);
                 tone(piezoPin, 233, 490);
                 delay(300);
                 tone(piezoPin, 208, 490);
                 delay(300);
                 tone(piezoPin, 196, 1300);
                 delay(1000);
                 gameover = false;
       }
  
  if (running) {       
	  yvalue = analogRead(paddle);
	  y2value = analogRead(paddle2);
	  Serial.print("speed = ");
          Serial.println(speed);
	  if (yvalue < 511) {
	   y =  0;
	  } else {
		y = 1;
	  }
	  
	  if (y2value < 511) {
		y2 = 0;
	  } else {
		y2 = 1;
	  }
	  lcd.clear();
	//lcd.setCursor(x,y);
	  lcd.setCursor(0,y);
	  lcd.print("|");
	  lcd.setCursor(15,y2);
	  lcd.print("|");
	  
	  
	  if (x >= 14 || x <= 1) {
		val = -val;
		zeil = random(2);
                tone(piezoPin, 180, 20);
               if (speed > 20) {
                 speed -= 2;
               }
                 
	  }
	  x = x + val;
			
	  lcd.setCursor(x, zeil);
	  lcd.print(".");
	  
	  if (y2 != zeil && x == 14) {
		lcd.setCursor(x , zeil);
		//lcd.clear();
		lcd.print(" ."); // naughty hack
		gameover = true;
	  }
	  
	
	  if (y != zeil && x == 1) {
		running = false;
		lcd.setCursor(0, zeil);
		lcd.print(". ");

	   }
		
	   delay(speed);
	   }
}
