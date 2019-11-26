#include <SPI.h>
#include "RF24.h"

RF24 radio(9, 10);
const byte addresses [][6] = {"00001", "00002"};
String inputString = "";         // biến giữ giá trị data gửi từ máy tính
boolean stringComplete = false;  // biến flag sẽ bằng true nếu đã nhận hết data từ máy tính
String commandString = "";
char recieveData;
char transmitData;
String message = "";
boolean isConnected = false;
const int buzzerPin = 6;
const int ledPin = 3;

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  radio.begin();                            //Bắt đầu quá giao tiếp
  radio.openWritingPipe(addresses[1]);      //Cài đặt địa chỉ sẽ gửi data
  radio.openReadingPipe(1, addresses[0]);   //Cài đặt địa chỉ sẽ nhận data
  radio.setPALevel(RF24_PA_MIN);            //Công suất dựa trên khoảng cách truyền
  radio.startListening();                   //Bắt đầu lắng nghe 
}

void loop() {
  delay(5);
  if (radio.available()) {
    radio.read(&recieveData, sizeof(recieveData)); // đọc tín dữ liệu từ client
    if (recieveData != '\0') {
      morseTranslate(recieveData); // chuyển data nhận được thành mã Morse
      message += recieveData; // cộng data nhận được thành 1 chuỗi
    }
    else {
      Serial.println(message); // gửi chuỗi nhận được qua cổng COM của máy tính
      message = "";
      radio.stopListening(); // dừng việc lắng nghe
    }
  }
  //Winform
  if (stringComplete) // Nếu data từ máy tính đã đọc xong
  {
    radio.stopListening(); // Dừng lắng nghe để chuyển sang chế độ truyền
    stringComplete = false;
    getCommand(); 
    if (commandString.equals("TEXT")) 
    {
      String text = getText();
      sendText(text);
    }
    inputString = "";
  }
  radio.startListening();
}

//Lấy lệnh trong data mà máy tính gửi lên (#TEXT,#START,#STOP)
void getCommand()
{
  if (inputString.length() > 0)
  {
    commandString = inputString.substring(1, 5);
  }
}

//Lấy text từ data mà máy tính gửi lên
String getText()
{
  String value = inputString.substring(5, inputString.length() - 2);
  return value;
}

// Hàm đọc data từ máy tính
void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputString += inChar;
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}

// Hàm gửi data cho client khác bằng RF
void sendText(String text)
{
  for (int i = 0; i <= text.length(); i++) {
    transmitData = text[i];
    radio.write(&transmitData, sizeof(transmitData));
    transmitData = "";
    delay(1000);
  }
}
