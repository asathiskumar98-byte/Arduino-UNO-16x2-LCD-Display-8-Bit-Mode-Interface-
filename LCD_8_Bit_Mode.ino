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

void printdata(unsigned char data)
{
  if(data&0x01 == 0x01) { digitalWrite(D0,HIGH); }
  else                    { digitalWrite(D0,LOW);  }

  if(data&0x02 == 0x02) { digitalWrite(D1,HIGH); }
  else                    { digitalWrite(D1,LOW);  }

  if(data&0x04 == 0x04) { digitalWrite(D2,HIGH); }
  else                    { digitalWrite(D2,LOW);  }

  if(data&0x08 == 0x08) { digitalWrite(D3,HIGH); }
  else                    { digitalWrite(D3,LOW);  }

  if(data&0x10 == 0x10) { digitalWrite(D4,HIGH); }
  else                    { digitalWrite(D4,LOW);  }

  if(data&0x20 == 0x20) { digitalWrite(D5,HIGH); }
  else                    { digitalWrite(D5,LOW);  }

  if(data&0x40 == 0x40) { digitalWrite(D6,HIGH); }
  else                    { digitalWrite(D6,LOW);  }

  if(data&0x80 == 0x80) { digitalWrite(D7,HIGH); }
  else                    { digitalWrite(D7,LOW);  }
}

void lcd_data(unsigned char data)
{
  printdata(data);
  digitalWrite(RS,HIGH);
  digitalWrite(RW,LOW);
  digitalWrite(EN,HIGH);
  delay(2);
  digitalWrite(EN,LOW);
}

void lcd_command(unsigned char command)
{
  printdata(command);
  digitalWrite(RS,LOW);
  digitalWrite(RW,LOW);
  digitalWrite(EN,HIGH);
  delay(2);
  digitalWrite(EN,LOW);
}

void lcd_string(unsigned char str[],unsigned char num)
{
  unsigned char i;
  for(i=0;i<num;i++)
  {
    lcd_data(str[i]);
  }
}

void lcd_initialise()
{
  lcd_command(0x38);
  lcd_command(0x0C);
  lcd_command(0x06);
  lcd_command(0x01);
}

void setup()
{
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

void loop()
{
  lcd_command(0x80);
  lcd_string("SATHIS",6);
  lcd_command(0xC0);
  lcd_string("KUMAR",5);
}