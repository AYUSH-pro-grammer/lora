# Lora

A LoRa board project that I made in order to figure out how radios really work, rather than just reading about them. It was a great way for me to do some PCB design and play around with KiCad, while learning what to do when things don’t go according to plan (which happened quite a bit).

# How its works

The board is a wireless communication module working on the principles of long-distance wireless communication and consists of an **ESP32-S3** along with **SX1262 LoRa transceiver**.

- **USB-C** supplies power and USB connectivity.
- **AMS1117-3.3** steps down 5V to 3.3V for electronics.
- **ESP32-S3** drives the firmware.
- **SX1262** takes care of LoRa wireless communication.
- The ESP32-S3 communicates with the SX1262 through **SPI**.


```text
USB-C → AMS1117-3.3 → 3.3V
                         │
                  ┌──────┴──────┐
                  │             │
              ESP32-S3 ← SPI → SX1262
                                │
                                📡

```


# Images:

## 3d

![PCB 3D Front](image/pcb_3d_front.png)
![PCB 3D Back](image/pcb_3d_back.png)


## Schematic

![Schematic](image/schamtic.png)


## PCB 

![PCB Routing](image/pcb_routing.png)


## Components

Total Physical Components: 51
Capacitors: 25
Resistors: 7
Inductors: 3
Crystals/Oscillators: 2
Push Buttons (Cherry MX): 2
Ferrite Beads: 1
RF Baluns: 1
USB-C Connectors: 1
Antenna/Pin Headers: 1
Voltage Regulators (AP2112K): 1
RF Switches (PE4259): 1
Flash Memory (W25Q16JV): 1
SX1262 LoRa IC: 1
RP2040 Microcontroller: 1


# Bill of Materials (BOM)

| Qty | Component | Selected Part | Supplier | Link |
|:---:|------------|---------------|----------|------|
| 1 | Antenna Pin | 2.54mm Vertical Pin Header | LCSC | https://www.lcsc.com/product-detail/C2337.html |
| 11 | 100nF Capacitor | 100nF 16V 0402 Ceramic | LCSC | https://www.lcsc.com/product-detail/C1525.html |
| 1 | 470nF Capacitor | 470nF 10V 0402 Ceramic | LCSC | https://www.lcsc.com/product-detail/C1527.html |
| 1 | 47pF Capacitor | 47pF 50V 0402 Ceramic | LCSC | https://www.lcsc.com/product-detail/C1554.html |
| 1 | 47nF Capacitor | 47nF 16V 0402 Ceramic | LCSC | https://www.lcsc.com/product-detail/C1530.html |
| 1 | 1nF Capacitor | 1nF 50V 0402 Ceramic | LCSC | https://www.lcsc.com/product-detail/C1523.html |
| 1 | 39pF Capacitor | 39pF 50V 0402 Ceramic | LCSC | https://www.lcsc.com/product-detail/C1553.html |
| 2 | 3.3pF Capacitor | 3.3pF 50V 0402 Ceramic | LCSC | https://www.lcsc.com/product-detail/C1548.html |
| 1 | Capacitor (Placeholder) | 100nF 16V 0402 Ceramic | LCSC | https://www.lcsc.com/product-detail/C1525.html |
| 2 | 1uF Capacitor | 1uF 10V 0402 Ceramic | LCSC | https://www.lcsc.com/product-detail/C1526.html |
| 2 | 15pF Capacitor | 15pF 50V 0402 Ceramic | LCSC | https://www.lcsc.com/product-detail/C1550.html |
| 2 | 10uF Capacitor | 10uF 6.3V 0402 Ceramic | LCSC | https://www.lcsc.com/product-detail/C1528.html |
| 1 | Ferrite Bead | 100 Ohm 0402 Ferrite Bead | LCSC | https://www.lcsc.com/product-detail/C1015.html |
| 1 | RF Balun | Johanson 0900FM15K0039 | LCSC | https://www.lcsc.com/product-detail/C186411.html |
| 1 | USB Type-C Connector | GCT USB4105 / 16-Pin Horizontal | LCSC | https://www.lcsc.com/product-detail/C2765186.html |
| 1 | 15uH Inductor | 15uH 0402 SMD Inductor | LCSC | https://www.lcsc.com/product-detail/C23985.html |
| 1 | 47nH Inductor | 47nH 0402 SMD Inductor | LCSC | https://www.lcsc.com/product-detail/C23987.html |
| 1 | 9.1nH Inductor | 9.1nH 0402 SMD Inductor | LCSC | https://www.lcsc.com/product-detail/C23988.html |
| 1 | 100 Ohm Resistor | 100Ω 1% 0402 Resistor | LCSC | https://www.lcsc.com/product-detail/C25076.html |
| 1 | 10k Ohm Resistor | 10kΩ 1% 0402 Resistor | LCSC | https://www.lcsc.com/product-detail/C25744.html |
| 1 | 27.4 Ohm Resistor | 27.4Ω 1% 0402 Resistor | LCSC | https://www.lcsc.com/product-detail/C25082.html |
| 1 | 24.4 Ohm Resistor | 24.3Ω 1% 0402 (Closest value) | LCSC | https://www.lcsc.com/product-detail/C25081.html |
| 2 | 5.1k Ohm Resistor | 5.1kΩ 1% 0402 Resistor | LCSC | https://www.lcsc.com/product-detail/C25905.html |
| 1 | 1k Ohm Resistor | 1kΩ 1% 0402 Resistor | LCSC | https://www.lcsc.com/product-detail/C25879.html |
| 2 | Tactile Switch | Cherry MX Clear Switch (5-pin) | StacksKB | https://stackskb.com/store/cherry-mx-clear-switch-5-pin-pack-of-10/ |
| 1 | Microcontroller | RP2040 (QFN-56) | LCSC | https://www.lcsc.com/product-detail/C2040.html |
| 1 | LoRa Transceiver | SX1262IMLTRT (QFN-24) | LCSC | https://www.lcsc.com/product-detail/C191341.html |
| 1 | RF Switch | PE4259-63 (SOT-363) | LCSC | https://www.lcsc.com/product-detail/C74415.html |
| 1 | 3.3V LDO Regulator | AP2112K-3.3TRG1 (SOT-23-5) | LCSC | https://www.lcsc.com/product-detail/C51118.html |
| 1 | SPI Flash Memory | W25Q16JVSSIQ (SOIC-8) | LCSC | https://www.lcsc.com/product-detail/C82317.html |
| 1 | 32MHz Crystal | 32MHz 3225 4-pin SMD | LCSC | https://www.lcsc.com/product-detail/C13738.html |
| 1 | 12MHz Crystal (for RP2040) | 12MHz 3225 4-pin SMD | LCSC | https://www.lcsc.com/product-detail/C13736.html |