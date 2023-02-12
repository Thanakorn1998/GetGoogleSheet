#include <WiFiClientSecure.h>
#include <Arduino.h>

class GetGoogleSheet
{
  public:
    int Sum = 0;
	int ARRAY_SIZE;
	
	String url;
	String GOOGLE_SCRIPT_ID;
	String myArray[50];
	String Title[50];
    GetGoogleSheet();
   
	String geturl();
	void begin(int arr, String ID);
	void Get(int index1, String value1, String value2);
	void submit();
	
	private:
	int i;
	const char* host = "script.google.com";
	const int httpsPort = 443;
};
