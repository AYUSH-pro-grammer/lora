#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>

void displayInit();
void displayStatus(const char* line1, const char* line2 = nullptr);
void displayTx(unsigned long packetNumber);
void displayTxSuccess(unsigned long packetNumber, unsigned long duration);
void displayError(int errorCode);

#endif