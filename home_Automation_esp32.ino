#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "webpageCode.h";

WiFiClient client;
ESP8266WebServer server(80);

const char* ssid = "Ho Saketo join Karlo...";
const char* password = "9428440375SB$9879883073";

#define Li1 14
#define Li2 12
#define Fan1 13
#define Fan2 15
#define biltIn LED_BUILTIN

void webpage()
{
  server.send(200, "text/html", webpageCode);
}

void setup() {

  Serial.begin(9600);
  WiFi.softAP(ssid, password);  // nodemcu start as a hotspots
  Serial.println();
  Serial.println("NodeMCU is Started!");
  Serial.println(WiFi.softAPIP());

  server.on("/", webpage);
  server.on("/update", getChange);
  server.begin();

  pinMode(biltIn, OUTPUT);
  pinMode(Li1, OUTPUT);
  pinMode(Li2, OUTPUT);
  pinMode(Fan1, OUTPUT);
  pinMode(Fan2, OUTPUT);
}

void loop() {

  server.handleClient();
}

void getChange() {
  if (server.args() > 0) // Argument Where recived
  {
    for ( int i = 0; i < server.args(); i++)
    {
      Serial.println(server.argName(i));
      String Argument_name = server.argName(i);
      String Client_Response = "";
      int switch_button = 0;

      if (server.argName(i) == "Light_1")      // light 1 on/off
      {
        Serial.println(server.arg(i));
        Client_Response = server.arg(i);
        switch_button = 1;
      } else if (server.argName(i) == "Light_2") // light 2 on/off
      {
        Serial.println(server.arg(i));
        Client_Response = server.arg(i);
        switch_button = 2;
      } else if (server.argName(i) == "Fan_1")  // fan 1 on/off
      {
        Serial.println(server.arg(i));
        Client_Response = server.arg(i);
        switch_button = 3;
      } else if (server.argName(i) == "Fan_2")  // fan 2 on/off
      {
        Serial.println(server.arg(i));
        Client_Response = server.arg(i);
        switch_button = 4;
      }

      if (Client_Response == "on")
      {
        switch (switch_button)
        {
          case 1:
            digitalWrite(Li1, HIGH);
            Serial.println(Argument_name);
            Serial.println(Client_Response);
            break;
          case 2:
            digitalWrite(Li2, HIGH);
            Serial.println(Argument_name);
            Serial.println(Client_Response);
            break;
          case 3:
            digitalWrite(Fan1, HIGH);
            Serial.println(Argument_name);
            Serial.println(Client_Response);
            break;
          case 4:
            digitalWrite(Fan2, HIGH);
            Serial.println(Argument_name);
            Serial.println(Client_Response);
            break;
        }
      } else if (Client_Response = "off")
      {
        switch (switch_button)
        {
          case 1:
            digitalWrite(Li1, LOW);
            Serial.println(Argument_name);
            Serial.println(Client_Response);
            break;
          case 2:
            digitalWrite(Li2, LOW);
            Serial.println(Argument_name);
            Serial.println(Client_Response);
            break;
          case 3:
            digitalWrite(Fan1, LOW);
            Serial.println(Argument_name);
            Serial.println(Client_Response);
            break;
          case 4:
            digitalWrite(Fan2, LOW);
            Serial.println(Argument_name);
            Serial.println(Client_Response);
            break;
        }
      }

    }


  }
}
