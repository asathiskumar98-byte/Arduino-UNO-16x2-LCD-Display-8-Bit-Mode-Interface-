# 🖥️ Arduino UNO 16x2 LCD Display (8-Bit Mode Interface)

This project demonstrates how to **interface a 16x2 LCD** with an **Arduino UNO** in **8-bit mode**, using **manual data pin control** (without LiquidCrystal library).  
It displays two lines of text:  
Hello
World

---

## 🧠 Overview

The **16x2 LCD** is a character display module capable of showing 16 characters per line, across 2 lines.  
In this project, the Arduino directly controls **8 data lines (D0–D7)** and **3 control lines (RS, RW, EN)** to send both commands and data manually — offering complete low-level understanding of how LCDs work internally.

---

## ⚙️ Hardware Requirements

- Arduino UNO  
- 16x2 LCD Module (HD44780 or compatible)  
- 10kΩ potentiometer (for contrast control)  
- Jumper wires  
- Breadboard  

---

## 🔌 Pin Configuration

| LCD Pin | Function | Arduino Pin |
|----------|-----------|--------------|
| RS | Register Select | 3 |
| RW | Read/Write | 4 |
| EN | Enable | 5 |
| D0 | Data Bit 0 | 6 |
| D1 | Data Bit 1 | 7 |
| D2 | Data Bit 2 | 8 |
| D3 | Data Bit 3 | 9 |
| D4 | Data Bit 4 | 10 |
| D5 | Data Bit 5 | 11 |
| D6 | Data Bit 6 | 12 |
| D7 | Data Bit 7 | 13 |
| VSS | GND | GND |
| VDD | +5V | 5V |
| VEE | Contrast Control | Middle pin of 10k pot |
| LED+ | Backlight + | 5V |
| LED− | Backlight − | GND |

---

## 🧾 Arduino Code

```cpp
const int RS = 3;
const int RW = 4;
const int EN = 5;
const int D0 = 6;
const int D1 = 7;
const int D2 = 8;
const int D3 = 9;
const int D4 = 10;
const int D5 = 11;
const int D6 = 12;
const int D7 = 13;

void printdata(unsigned char data) {
  if(data & 0x01 == 0x01) digitalWrite(D0,HIGH); else digitalWrite(D0,LOW);
  if(data & 0x02 == 0x02) digitalWrite(D1,HIGH); else digitalWrite(D1,LOW);
  if(data & 0x04 == 0x04) digitalWrite(D2,HIGH); else digitalWrite(D2,LOW);
  if(data & 0x08 == 0x08) digitalWrite(D3,HIGH); else digitalWrite(D3,LOW);
  if(data & 0x10 == 0x10) digitalWrite(D4,HIGH); else digitalWrite(D4,LOW);
  if(data & 0x20 == 0x20) digitalWrite(D5,HIGH); else digitalWrite(D5,LOW);
  if(data & 0x40 == 0x40) digitalWrite(D6,HIGH); else digitalWrite(D6,LOW);
  if(data & 0x80 == 0x80) digitalWrite(D7,HIGH); else digitalWrite(D7,LOW);
}

void lcd_data(unsigned char data) {
  printdata(data);
  digitalWrite(RS,HIGH);
  digitalWrite(RW,LOW);
  digitalWrite(EN,HIGH);
  delay(2);
  digitalWrite(EN,LOW);
}

void lcd_command(unsigned char command) {
  printdata(command);
  digitalWrite(RS,LOW);
  digitalWrite(RW,LOW);
  digitalWrite(EN,HIGH);
  delay(2);
  digitalWrite(EN,LOW);
}

void lcd_string(unsigned char str[], unsigned char num) {
  for (unsigned char i = 0; i < num; i++) {
    lcd_data(str[i]);
  }
}

void lcd_initialise() {
  lcd_command(0x38);  // 8-bit mode, 2 lines, 5x8 font
  lcd_command(0x0C);  // Display ON, Cursor OFF
  lcd_command(0x06);  // Increment cursor
  lcd_command(0x01);  // Clear display
}

void setup() {
  pinMode(RS,OUTPUT);
  pinMode(RW,OUTPUT);
  pinMode(EN,OUTPUT);
  pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D3,OUTPUT);
  pinMode(D4,OUTPUT);
  pinMode(D5,OUTPUT);
  pinMode(D6,OUTPUT);
  pinMode(D7,OUTPUT);
  lcd_initialise();
}

void loop() {
  lcd_command(0x80);           // Move cursor to first line
  lcd_string("Hello",4);
  lcd_command(0xC0);           // Move cursor to second line
  lcd_string("World",5);
}
```
🚀 Upload Steps
Open Arduino IDE

Copy and paste the code

Select Board → Arduino UNO

Select the correct COM Port

Click Upload

You’ll see the following output on your LCD:

nginx
Copy code
Hello
World
🧰 Tools Used
Arduino IDE (v2.0 or later)

GitHub Desktop (optional, for repo management)

📸 Output
Line 1: Hello
Line 2: World
🟩 Display updates instantly after power-up.
