#include "GetGoogleSheet.h"
#include <WiFiClientSecure.h>


void GetGoogleSheet::begin(int arr, String ID){
	GOOGLE_SCRIPT_ID = ID;
	ARRAY_SIZE = arr;
}

void GetGoogleSheet::Get(int index1, String value1, String value2){
	Title[index1 - 1] = value1;
  myArray[index1 - 1] = value2;
}


String GetGoogleSheet::geturl(){
	url = "/macros/s/" + GOOGLE_SCRIPT_ID;
  for (int i = 0; i < ARRAY_SIZE; i++) {
    if (i == 0)
      url = url + "/exec?" + Title[i] + "=" + myArray[i];
    else 
      url = url + "&" + Title[i] + "=" + myArray[i];
    
  }

  Serial.println(url);
  return url;
 
}

void GetGoogleSheet::submit(){
  WiFiClientSecure client; //--> Create a WiFiClientSecure object.
  client.setInsecure();

  if (!client.connect(host, httpsPort)) {
    Serial.println("connection failed");
    return;
  }
  String url = geturl();
  client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "User-Agent: esp32\r\n" + "Connection: close\r\n\r\n");
}
 
GetGoogleSheet::GetGoogleSheet() {
    
  }