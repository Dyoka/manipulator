#include <Servo.h>
#include <WiFi.h>
#include <UniversalTelegramBot.h>


const char* ssid = "12345678";
const char* password = "145645467654";


define BOT_TOKEN "hand_cntrl_bot"

WiFiClient client;
UniversalTelegramBot bot(BOT_TOKEN, client);

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }

  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
}

void loop() {
  int newMessageCount = bot.getUpdates(bot.last_message_received + 1);

  while (newMessageCount) {
    Serial.print("New message received: ");
    Serial.println(bot.messages[0].text);

    if (bot.messages[0].text == "/servo1_0") {
      servo1.write(0);
    } else if (bot.messages[0].text == "/servo1_90") {
      servo1.write(90);
    } else if (bot.messages[0].text == "/servo1_180") {
      servo1.write(180);
    }

    if (bot.messages[0].text == "/servo2_0") {
      servo2.write(0);
    } else if (bot.messages[0].text == "/servo2_90") {
      servo2.write(90);
    } else if (bot.messages[0].text == "/servo2_180") {
      servo2.write(180);
    }

    if (bot.messages[0].text == "/servo3_0") {
      servo3.write(0);
    } else if (bot.messages[0].text == "/servo3_90") {
      servo3.write(90);
    } else if (bot.messages[0].text == "/servo3_180") {
      servo3.write(180);
    }

    if (bot.messages[0].text == "/servo4_0") {
      servo4.write(0);
    } else if (bot.messages[0].text == "/servo4_90") {
      servo4.write(90);
    } else if (bot.messages[0].text == "/servo4_180") {
      servo4.write(180);
    }

    newMessageCount = bot.getUpdates(bot.last_message_received + 1);
  }
}