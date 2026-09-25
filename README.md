# Lora

A LoRa board project that I made in order to figure out how radios really work, rather than just reading about them. It was a great way for me to do some PCB design and play around with KiCad, while learning what to do when things don’t go according to plan (which happened quite a bit).

# How its works

This board is a custom designed wireless communication module for long range applications. It is based on the dual-core Raspberry Pi RP2040 microcontroller and SX1262 LoRa transceiver.


- Power & Connectivity. 5V power and data thru USB-C port. An AP2112K-3.3 LDO regulator efficiently steps this down to a stable 3.3V for the system.

- Processing & Memory - The RP2040 is the brain. The RP2040 requires external memory, so it’s coupled with a W25Q16JV SPI Flash chip to store your firmware.

- Long-Range RF The SX1262 provides sub-GHz LoRa wireless communication. The RF path is controlled by a PE4259 RF switch and a Johanson Balun to condition the signal for the antenna.

- Internal Routing: The RP2040 uses its SPI busses to talk to the Flash memory and the SX1262 LoRa chip.


```text
[ USB-C ] ──5V──► [ AP2112K-3.3 LDO ] ──3.3V──┐
                                              ▼
[ W25Q16 Flash ] ◄──SPI── [ RP2040 ] ──SPI──► [ SX1262 LoRa ]
                        (Main Brain)                │
                                                    ▼
                                            [ PE4259 Switch ]
                                                    │
                                                    ▼
                                                [ Antenna ]
                                                    📡

```



# Images:

## 3d

![PCB 3D Front](/image/pcb_3d_front.png)

![PCB 3D Back](/image/pcb_3d_back.png)


## Schematic

![Schematic](/image/schamtic.png)


## PCB 

![PCB Routing](/image/pcb_routing.png)




## Components

Total Physical Components: 53
Capacitors: 28
Resistors: 8
Inductors: 3
Crystals/Oscillators: 2
Push Buttons (Cherry MX): 2
Antenna / Pin Headers: 2 (1 Spring Antenna + 1 Pin Header)
Ferrite Beads: 1
RF Baluns: 1
USB-C Connectors: 1
Voltage Regulators (AP2112K): 1
RF Switches (PE4259): 1
Flash Memory (W25Q16JV): 1
SX1262 LoRa IC: 1
RP2040 Microcontroller: 1


# Bill of Materials (BOM)

The following table lists all components required to build this LoRa board. 

**Note on Pricing:** The `Order Cost` column reflects the actual checkout price based on the **Minimum Order Quantity (MOQ)** required by suppliers (like LCSC's cut-tape minimums). Because of these MOQs, you will have leftover passive components (resistors, capacitors, etc.) that can be used for future builds.

| Qty | Component | Selected Part | Supplier | Link | MOQ | Unit Price (USD) | Order Cost (USD) |
|:---:|:---|:---|:---|:---|:---:|:---:|:---:|
| 1 | LoRa Spring Antenna | BW915SNX17-5W2 | LCSC | [Link](https://www.lcsc.com/product-detail/C496556.html) | 5 | $0.165 | $0.83 |
| 1 | Antenna Pin Header | 2.54-1*40P Pin Header | LCSC | [Link](https://www.lcsc.com/product-detail/C2337.html) | 5 | $0.159 | $0.80 |
| 12 | 100nF Capacitor | 100nF 16V 0402 X7R | LCSC | [Link](https://www.lcsc.com/product-detail/C1525.html) | 100 | $0.005 | $0.46 |
| 1 | 150pF Capacitor | 150pF 50V 0402 X7R | LCSC | [Link](https://www.lcsc.com/product-detail/C1527.html) | 100 | $0.004 | $0.43 |
| 1 | 20pF Capacitor | 20pF 50V 0402 C0G | LCSC | [Link](https://www.lcsc.com/product-detail/C1554.html) | 100 | $0.007 | $0.69 |
| 1 | 220pF Capacitor | 220pF 50V 0402 X7R | LCSC | [Link](https://www.lcsc.com/product-detail/C1530.html) | 100 | $0.003 | $0.25 |
| 1 | 1.8pF Capacitor | 1.8pF 50V 0402 C0G | LCSC | [Link](https://www.lcsc.com/product-detail/C1553.html) | 100 | $0.005 | $0.50 |
| 2 | 15pF Capacitor | 15pF 50V 0402 C0G | LCSC | [Link](https://www.lcsc.com/product-detail/C1548.html) | 100 | $0.004 | $0.36 |
| 2 | 12pF Capacitor | 12pF 50V 0402 C0G | LCSC | [Link](https://www.lcsc.com/product-detail/C1547.html) | 100 | $0.006 | $0.60 |
| 2 | 1pF Capacitor | 1pF 50V 0402 C0G | LCSC | [Link](https://www.lcsc.com/product-detail/C1550.html) | 100 | $0.003 | $0.27 |
| 3 | 160pF Capacitor | 160pF 50V 0402 X7R | LCSC | [Link](https://www.lcsc.com/product-detail/C1528.html) | 100 | $0.005 | $0.51 |
| 2 | 1uF Capacitor | 1uF 16V 0402 X5R | LCSC | [Link](https://www.lcsc.com/product-detail/C167339.html) | 50 | $0.015 | $0.73 |
| 1 | 1nF Capacitor | 1nF 50V 0402 X7R | LCSC | [Link](https://www.lcsc.com/product-detail/C1523.html) | 100 | $0.005 | $0.51 |
| 1 | Ferrite Bead | 100Ω@100MHz 0402 | LCSC | [Link](https://www.lcsc.com/product-detail/C280601.html) | 20 | $0.006 | $0.12 |
| 1 | RF Balun | 0900FM15D0039E | LCSC | [Link](https://www.lcsc.com/product-detail/C1513363.html) | 1 | $1.214 | $1.21 |
| 1 | USB Type-C Connector | TYPE-C 16PIN SMD | LCSC | [Link](https://www.lcsc.com/product-detail/C2765186.html) | 20 | $0.071 | $1.43 |
| 1 | 15nH Inductor | 15nH ±3% 0402 | LCSC | [Link](https://www.lcsc.com/product-detail/C329619.html) | 10 | $0.041 | $0.41 |
| 1 | 47nH Inductor | 47nH ±2% 0402 | LCSC | [Link](https://www.lcsc.com/product-detail/C22334.html) | 10 | $0.064 | $0.64 |
| 1 | 9.1nH Inductor | 9.1nH ±2% 0402 | LCSC | [Link](https://www.lcsc.com/product-detail/C7516935.html) | 1 | $0.095 | $0.09 |
| 1 | 100 Ohm Resistor | 100Ω ±1% 0402 | LCSC | [Link](https://www.lcsc.com/product-detail/C25076.html) | 100 | $0.004 | $0.37 |
| 2 | 10k Ohm Resistor | 10kΩ ±1% 0402 | LCSC | [Link](https://www.lcsc.com/product-detail/C25744.html) | 100 | $0.003 | $0.31 |
| 1 | 150 Ohm Resistor | 150Ω ±1% 0402 | LCSC | [Link](https://www.lcsc.com/product-detail/C25082.html) | 100 | $0.002 | $0.19 |
| 1 | 140 Ohm Resistor | 140Ω ±1% 0402 | LCSC | [Link](https://www.lcsc.com/product-detail/C25081.html) | 100 | $0.002 | $0.20 |
| 2 | 5.1k Ohm Resistor | 5.1kΩ ±1% 0402 | LCSC | [Link](https://www.lcsc.com/product-detail/C25905.html) | 100 | $0.002 | $0.23 |
| 1 | 2.2k Ohm Resistor | 2.2kΩ ±1% 0402 | LCSC | [Link](https://www.lcsc.com/product-detail/C25879.html) | 100 | $0.004 | $0.35 |
| 1 | Microcontroller | RP2040 (QFN-56) | LCSC | [Link](https://www.lcsc.com/product-detail/C2040.html) | 1 | $0.997 | $1.00 |
| 1 | LoRa Transceiver | SX1262IMLTRT (QFN-24) | LCSC | [Link](https://www.lcsc.com/product-detail/C191341.html) | 1 | $3.222 | $3.22 |
| 1 | RF Switch / LDO | LM337BTG | LCSC | [Link](https://www.lcsc.com/product-detail/C74415.html) | 1 | $0.673 | $0.67 |
| 1 | 3.3V LDO Regulator | AP2112K-3.3TRG1 | LCSC | [Link](https://www.lcsc.com/product-detail/C51118.html) | 5 | $0.173 | $0.86 |
| 1 | SPI Flash Memory | W25Q16JVSSIQ (SOIC-8) | LCSC | [Link](https://www.lcsc.com/product-detail/C82317.html) | 1 | $1.023 | $1.02 |
| 1 | 32MHz Crystal | X322532MMB4SI | LCSC | [Link](https://www.lcsc.com/product-detail/C113671.html) | 5 | $0.108 | $0.54 |
| 1 | 12MHz Crystal | X322512MSB4SI | LCSC | [Link](https://www.lcsc.com/product-detail/C9002.html) | 5 | $0.096 | $0.48 |
| 2 | Tactile Switch | Cherry MX Clear (Pack of 10) | StacksKB | [Link](https://stackskb.com/store/cherry-mx-clear-switch-5-pin-pack-of-10/) | 10 | $0.480 | $4.80 |

| 1 | Oled Display | 0.96 Inch OLED Display Module | RoboCraze | [Link](https://robocraze.com/products/0-96in-oled-display-module-4pin) | 1 | $1.74 | $1.74 
| **-** | **Total Procurement Cost (1st Batch Order)** | | | | | | **~$26.82** |


