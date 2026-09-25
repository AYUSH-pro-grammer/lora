#include "Display.h"

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define OLED_WIDTH   128
#define OLED_HEIGHT   32
#define OLED_ADDRESS 0x3C


#define OLED_SDA 4
#define OLED_SCL 5

Adafruit_SSD1306 display(
    OLED_WIDTH,
    OLED_HEIGHT,
    &Wire,
    -1
);


void displayInit() {


    Wire.setSDA(OLED_SDA);
    Wire.setSCL(OLED_SCL);

    Wire.begin();

    if (!display.begin(
            SSD1306_SWITCHCAPVCC,
            OLED_ADDRESS)) {

        return;
    }

    display.clearDisplay();

    display.setTextColor(SSD1306_WHITE);

    display.setTextSize(1);

    display.setCursor(0, 0);
    display.println("LORA NODE");

    display.setCursor(0, 12);
    display.println("Display OK");

    display.display();

    delay(1000);
}


void displayStatus(const char* line1, const char* line2) {

    display.clearDisplay();

    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(1);

    display.setCursor(0, 0);
    display.println("LORA NODE");

    display.setCursor(0, 12);
    display.println(line1);

    if (line2 != nullptr) {
        display.setCursor(0, 22);
        display.println(line2);
    }

    display.display();
}


void displayTx(unsigned long packetNumber) {

    display.clearDisplay();

    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(1);

    display.setCursor(0, 0);
    display.println("LORA NODE");

    display.setCursor(0, 12);
    display.println("TRANSMITTING...");

    display.setCursor(0, 22);
    display.print("PACKET #");
    display.println(packetNumber);

    display.display();
}


void displayTxSuccess(
    unsigned long packetNumber,
    unsigned long duration) {

    display.clearDisplay();

    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(1);

    display.setCursor(0, 0);
    display.println("LORA NODE");

    display.setCursor(0, 12);
    display.println("TX SUCCESS");

    display.setCursor(0, 22);
    display.print("#");
    display.print(packetNumber);

    display.print("  ");
    display.print(duration);
    display.println("ms");

    display.display();
}


void displayError(int errorCode) {

    display.clearDisplay();

    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(1);

    display.setCursor(0, 0);
    display.println("LORA NODE");

    display.setCursor(0, 12);
    display.println("TX ERROR");

    display.setCursor(0, 22);
    display.print("CODE: ");
    display.println(errorCode);

    display.display();
}