# UV-Meter
Handheld, simple VEML6075 UV meter with battery and 3d printed case

# Overview
This is a small project for a handheld DIY UV meter based on the popular VEML6075 sensor. This type of sensor has the advantage of having actual UV-A and UV-B channels, which is necessary for a reliable calculation of the index.
The electronics are dead simple, suitable for anyone who knows how to solder.

![op1](https://user-images.githubusercontent.com/5310025/121422151-37d21600-c96f-11eb-93d1-0b672089b00e.jpg)

There is a 18650 li-ion battery in the case which can be charged via USB. The side part with the sensor is rotatable.

# Parts

![parts1](https://user-images.githubusercontent.com/5310025/121422311-67811e00-c96f-11eb-80f6-c8b3729c58fb.jpg)

The parts you can see in the picture: 
 - USB li-ion charger module and protection
 - Sensor breakout board (with 3.3V regulator)
 - 5V step-up converter
 - arduino pro nano clone (any will do)

Other parts I used:
 - 3D printed case
 - HMC16223 LCD, compatible to the popular HD44780 type
 - Some random button
 - RGB LED common cathode with resistors for 5V

The LCD was some part laying around, I suggest to replace the LCD by one of the cheap 0.92" I2C OLED displays.
This 5mm RGB type of LED is also a bit ugly, a WS2812B or similar should work much better and save some pins.

For pinout, refer to the source code and/or the pinout for the I2C pins.

# Case

![case](https://user-images.githubusercontent.com/5310025/121423046-250c1100-c970-11eb-9732-5c5b9ca6fc8c.jpg)

stls for the case are available in the repo, as well as the FreeCAD project files. Please be aware I am a FreeCAD novice.

![case2](https://user-images.githubusercontent.com/5310025/121423355-74524180-c970-11eb-9032-4f491a377969.jpg)

As you can see the parts are fixed together using an M4 screw with locking nut, so the sensor part is still rotatable.

![op2](https://user-images.githubusercontent.com/5310025/121423516-a499e000-c970-11eb-92de-4ac1b2b3fc78.jpg)

The charger port is hidden behind the sensor:

![charge](https://user-images.githubusercontent.com/5310025/121423527-a8c5fd80-c970-11eb-8755-2f4acd743d89.jpg)

# Suggestions

Feel free to use and modify everything to suit your needs.
Besides the two parts (Display and LED), I also suggest to cut away the edge of the sensor part so the case will lie straight when angeled.
