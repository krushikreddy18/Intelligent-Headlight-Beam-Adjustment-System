# 🚗 Intelligent Headlight Beam Adjustment System

This project simulates an **automatic headlight beam adjustment system** using an **Arduino UNO**, **LDR sensors**, and **NeoPixel LED matrices**.  

The system detects oncoming vehicles using **Light Dependent Resistors (LDRs)** and automatically switches the headlights between **high beam** and **low beam** to improve road safety and reduce glare.  

---

## 🔧 Hardware Used
- Arduino UNO (or compatible board)  
- 3 × LDR sensors  
- 2 × 8×8 NeoPixel LED matrices  
- Resistors for LDR calibration  
- Convex lens (to enhance LDR detection accuracy)  
- Jumper wires and breadboard  

---

## ⚡ Working Principle
- **High Beam (default):** Both LED matrices are ON at full brightness.  
- **Low Beam (when vehicle detected):** LED matrices are dimmed / partially turned OFF to reduce glare.  
- **Vehicle Detection:** If **any LDR sensor** detects incoming headlights (value below threshold), the system switches to **low beam mode**.  

---

## 🖥️ Circuit Connections
- LDR 1 → A0  
- LDR 2 → A1  
- LDR 3 → A2  
- NeoPixel Matrix 1 → Pin 6  
- NeoPixel Matrix 2 → Pin 7  

---

## 📜 Code Explanation
- Uses the [Adafruit NeoPixel library](https://github.com/adafruit/Adafruit_NeoPixel).  
- Threshold (`LDR_THRESHOLD`) is set to **350** (can be calibrated).  
- `high_beam()` function turns on all LEDs on both matrices.  
- `low_beam()` function turns off half of the LEDs (simulating dimmed headlights).  

---

## ▶️ How to Run
1. Install the **Adafruit NeoPixel** library in Arduino IDE.  
2. Connect hardware as per the wiring diagram above.  
3. Upload `beam_adjustment.ino` to your Arduino UNO.  
4. Open **Serial Monitor** to observe LDR readings and beam switching.  

---

## 📌 Future Improvements
- Expand to real car headlights with relay + LED headlamp setup.  
