 PROJECT OVERVIEW:
-------------------
  The Enviro Clock is a compact embedded application designed to function as a digital environmental timekeeping device with alarm functionality.
  It uses an RTC module for accurate timing, a temperature sensor for real-time temperature measurement, and allows the user to set an alarm.
  When the current time matches the configured alarm time, the system triggers an buzzer and indicate alarm symbol on lcd.

 PURPOSE:
----------
  To display time, date, day, and room temperature continuously.
  To allow users to  edit hour,minute,second,date,month,year,day and to set,edit, and activate an alarm.
  To trigger a buzzer alarm when the set time is reached.


 MAIN FEATURES:
---------------
  Displays Time (HH:MM:SS).
  Shows Date (DD/MM/YYYY).
  Displays Day of Week (Mon–Sun).
  Shows Room Temperature (°C).
  Alarm setting & triggering using a buzzer.
  External Interrupt Button used to enter edit mode for:
    Time
    Date
    Day
    Alarm

 INSTALLATION STEPS:
--------------------
    >SET UP TOOLCHAIN:
      ->keil µVision.
    >HARDWARE CONNECT:
      ->LCD pins to LPC2148 gpio pins.
      ->KEYPAD 4X4 matrix pins to gpio pins.
      ->Temperature sensor ouput pin to ADC pins of lpc2148.
      ->BUZZER pin to gpio pin.
    >BUILD & FLASH:
      ->open in any IDE.
      ->compile software.
      ->flash using FLASH MAGIC.
    >START & TEST:
      ->power on the board.
      ->Clock, date, day, temperature, and alarm features should begin working.

 USAGE INSTRUCTIONS:
---------------------
```
  step1: power on the board.
        The LCD displays: HH:MM:SS  temp:
                          DD/MM/YYYY  Day
  step2: To adjust time or date or to set or edit alarm time use switch which invokes externel interrupt.
        Then the LCD dispaly:
                        1:clkinfoedit     ↑
                        2:alarminfoedit   ↓
        if upparow is selected
                        2:alarminfoedit   ↑
                        3:exit            ↓
  step3:  To edit clock info press 1 through keypad
          Then the LCD dispaly:
                        1:H 2:M 3:S 4:EXIT
                        5:D 6:M 7:Y 8:DY
          through this can select option and adjust the clock
  step4: To set or edit alarm time press 2 through keypad
            Then the LCD dispaly:
                        1:alarm edit 
                        2:alarm info
                        3:exit
          through this user can set or edit alarm time, and can witness the alarm mention time through alarm info.
          when alarm time is set, alarm symbol is displayed on LCD.
when RTC time matches the alarm time, the BUZZER turns on automatically and alarm symbol blink on LCD.
alarm can be stoped using switch and it can automatically turn off after 1 min of time.
```
 DEPENDENCIES:
---------------
```
  >LPC2148 Microcontroller
  >RTC Module (FBD64/DS1307/DS3231)
  >Temperature Sensor (LM35/DS18B20)
  >External Interrupt
  >16x2 LCD Display
  >4×4 Matrix Keypad
  >Buzzer for alarm
  >Embedded C standard libraries
```

 SAMPLE OUTPUT:
----------------
      LCD NORMAL DISPLAY
          11:22:03     T:39˚ C
          02/09/2006   TUE
    after alarm set LCD DISPLAY
          12:30:24    T:38˚ C
          02/09/2006  TUE 🕥


 REFERENCES:
-------------
```
  >NXP LPC214x User Manual
  >LM35 Temperature Sensor Datasheet
  >ARM7TDMI-S Technical Reference
```

 AUTHOR:
---------
    KARNE ARAVIND REDDY
    Embedded Firmware Developer
    
 
