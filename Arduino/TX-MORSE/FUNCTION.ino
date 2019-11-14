void dot()
{
  // play a dot
  tone(buzzerPin, tonefreq);
  // LED
  digitalWrite(ledPin, HIGH);
  delay(dotlength);
  noTone(buzzerPin);
  // LED
  digitalWrite(ledPin, LOW);
  delay(inter);
}

void dash()
{
  // play a dash
  tone(buzzerPin, tonefreq);
  // LED
  digitalWrite(ledPin, HIGH);
  delay(dashlength);
  noTone(buzzerPin);
  // LED
  digitalWrite(ledPin, LOW);
  delay(inter);
}

void lA () {
  dot();  //letter A in morse code!
  dash();

}
void lB () {
  dash();  //same for B
  dot();
  dot();
  dot();

}
void lC () {
  dash();
  dot();
  dash();
  dot();

}
void lD () {
  dash();
  dot();
  dot();

}
void lE () {
  dot();

}
void lF () {
  dot();
  dot();
  dash();
  dot();

}
void lG () {
  dash();
  dash();
  dot();

}
void lH () {
  dot();
  dot();
  dot();
  dot();

}
void lI () {
  dot();
  dot();

}
void lJ () {
  dot();
  dash();
  dash();
  dash();

}
void lK () {
  dash();
  dot();
  dash();

}
void lL () {
  dot();
  dash();
  dot();
  dot();

}
void lM () {
  dash();
  dash();

}
void lN () {
  dash();
  dot();

}
void lO () {
  dash();
  dash();
  dash();

}
void lP () {
  dot();
  dash();
  dash();
  dot();

}
void lQ () {
  dash();
  dash();
  dot();
  dash();

}
void lR () {
  dot();
  dash();
  dot();

}
void lS () {
  dot();
  dot();
  dot();

}
void lT () {
  dash();
}
void lU () {
  dot();
  dot();
  dash();

}
void lV () {
  dot();
  dot();
  dot();
  dash();

}
void lW () {
  dot();
  dash();
  dash();

}
void lX () {
  dash();
  dot();
  dot();
  dash();

}
void lY () {
  dash();
  dot();
  dash();
  dash();

}
void lZ () {
  dash();
  dash();
  dot();
  dot();

}
void n1 () {
  dot();  //number 1 in morse code
  dash();
  dash();
  dash();
  dash();

}
void n2 () {
  dot();
  dot();
  dash();
  dash();
  dash();

}
void n3 () {
  dot();
  dot();
  dot();
  dash();
  dash();

}
void n4 () {
  dot();
  dot();
  dot();
  dot();
  dash();

}
void n5 () {
  dot();
  dot();
  dot();
  dot();
  dot();

}
void n6 () {
  dash();
  dot();
  dot();
  dot();
  dot();

}
void n7 () {
  dash();
  dash();
  dot();
  dot();
  dot();

}
void n8 () {
  dash();
  dash();
  dash();
  dot();
  dot();
}
void n9 () {
  dash();
  dash();
  dash();
  dash();
  dot();
}
void n0 () {
  dash();
  dash();
  dash();
  dash();
  dash();
}
