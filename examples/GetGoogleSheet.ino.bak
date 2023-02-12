#include "WiFi.h"
#include <WiFiClientSecure.h>
#include "GetGoogleSheet.h"

String SCRIPT_ID = "AKfycbwQbosmrdKWoaXb8tTOQVF0SjhuoKTbMXabLLBSj7o3J9GnHIFQhnNqM6qJ9sYsGu43";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  WiFi.begin("arduino6", "123456789");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(400);
  }
  GetGoogleSheet Fn1;

  //Fn1.ARRAY_SIZE = 3;
  Fn1.begin(4,SCRIPT_ID);
  Fn1.Get(1, "voltage1", "20");
  Fn1.Get(2, "voltage2", "30");
  Fn1.Get(3, "voltage3", "40");
  Fn1.Get(4, "staus", "loss");
  Fn1.submit();
}

void loop() {
  // put your main code here, to run repeatedly:

}