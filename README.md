# arduino
Arduino Experiences

<h1>Steps to install arduino ide in ubuntu 16</h1>

1. Install the Arduino IDE (https://www.arduino.cc/en/Main/Software) and choosed linux 64 file. 

2. Uncompressed to a folder and execute install

        $ ./install.sh
    
3. Run

        $ ./arduino

4. Go to Tab Tools and choose your board and Port

e.g. Arduino Duemilanove. Port was /dev/ttyUSB0

5. Verify permissions (group)

The file /dev/ttyUSB0 is from group 'dialout', so you have to add it to your user with

        $ sudo adduser $(whoami) dialout

6. Restart ubuntu (Yes, it was needed for me) and run again

        $ ./arduino


<h2>The examples</h2>
<p>This examples were primarly impired in the code from (https://www.arduino.cc)</p>

1. blink_led_with_potentiometer - A potentiometer increasing the blink ratio from a led.

2. toneMelody - Part of the bubble bobble main song.
