

#include <Arduino.h>
#include <SPI.h>
#include <RadioLib.h>
#define PIN_LORA_SCK    18
#define PIN_LORA_MOSI   19
#define PIN_LORA_MISO   20
#define PIN_LORA_NSS    21
#define PIN_LORA_BUSY   22 
#define PIN_LORA_NRST   23 
#define PIN_LORA_DIO1   16 

#define RF_FREQUENCY    915.0 
#define RF_BANDWIDTH    125.0   
#define RF_SPREADING    7       
#define RF_CODING_RATE  5 
#define RF_OUTPUT_POWER 14    
#define RF_PREAMBLE_LEN 8     


SX1262 radio = new Module(PIN_LORA_NSS, PIN_LORA_DIO1, PIN_LORA_NRST, PIN_LORA_BUSY);

uint32_t packetCounter = 0;

void setup() {
  Serial.begin(115200);
  while (!Serial && millis() < 3000); 

  Serial.println("\n==========================================");
  Serial.println("   RP2040 + SX1262 lora settingup Test    ");
  Serial.println("==========================================");


  SPI.setSCK(PIN_LORA_SCK);
  SPI.setTX(PIN_LORA_MOSI);
  SPI.setRX(PIN_LORA_MISO);
  SPI.begin();

  Serial.print("[SX1262] Initializing transceiver... ");


  int state = radio.begin(
    RF_FREQUENCY,
    RF_BANDWIDTH,
    RF_SPREADING,
    RF_CODING_RATE,
    RADIOLIB_SX126X_SYNC_WORD_PRIVATE,
    RF_OUTPUT_POWER,
    RF_PREAMBLE_LEN
  );

  if (state == RADIOLIB_ERR_NONE) {
    Serial.println("SUCCESS!");
  } else {
    Serial.print("FAILED, error code: ");
    Serial.println(state);
    Serial.println("Check SPI connections, 32MHz crystal, and 3.3V power rails.");
    while (true) {
      delay(1000);
    }
  }


  if (radio.setDio2AsRfSwitch(true) != RADIOLIB_ERR_NONE) {
    Serial.println("[SX1262] Warning: Failed to configure DIO2 as RF Switch control.");
  } else {
    Serial.println("[SX1262] RF Switch (DIO2) control enabled.");
  }

  Serial.println("[SX1262] Setup complete. Starting TX loop...\n");
}

void loop() {
  char payload[32];
  snprintf(payload, sizeof(payload), "PING #%lu", (unsigned long)packetCounter);

  Serial.print("[SX1262] Transmitting packet: \"");
  Serial.print(payload);
  Serial.print("\"... ");

  unsigned long startTime = millis();
  int state = radio.transmit(payload);
  unsigned long duration = millis() - startTime;

  if (state == RADIOLIB_ERR_NONE) {
    Serial.print("SENT! (");
    Serial.print(duration);
    Serial.print(" ms) | Data Rate: ");
    Serial.print(radio.getDataRate());
    Serial.println(" bps");
  } else if (state == RADIOLIB_ERR_PACKET_TOO_LONG) {
    Serial.println("FAILED: Packet too long.");
  } else if (state == RADIOLIB_ERR_TX_TIMEOUT) {
    Serial.println("FAILED: Transmission timed out.");
  } else {
    Serial.print("FAILED: Error code ");
    Serial.println(state);
  }

  packetCounter++;
  delay(3000); //  every 3 seconds
}
