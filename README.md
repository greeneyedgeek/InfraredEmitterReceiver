# InfraredEmitterReceiver

<p>The intent of this project is to build a small infrared emitter and receiver. The emitter sends a signal to the receiver which then decodes it and outputs the corresponding RGB value.</p>

<h2>Hardware Required</h2>

<ul>
  <li>2 x Arduino Nano Board</li>
  <li>1 x IR Receiver</li>
  <li>1 x RGB LED</li>
  <li>1 x IR LED</li>
  <li>4 x Resistor</li>
  <li>Jumper wires</li>
  <li>Breadboard</li>
  <li>Power source</li>

</ul>

<h2>Schematic</h2>

<img src="https://github.com/greeneyedgeek/InfraredEmitterReceiver/blob/master/schematic.png" alt="Schematic">

<h2>Breadboard</h2>

<img src="https://github.com/greeneyedgeek/InfraredEmitterReceiver/blob/master/breadboard.png" alt="Breadboard">
  
RGB LED &nbsp;     | Arduino Nano Receiver
-------------------|----------------------
RED                | 10 
BLUE               | 9
GREEN              | 8
GND                | GND

IR RECEIVER LED &nbsp; | Arduino Nano Receiver
-----------------------|----------------------
SIGNAL                 | PIN 2
VCC                    | +5V
GND                    | GND

IR LED &nbsp;      | Arduino Nano Emitter
-------------------|---------------------
SIGNAL             | PIN 3
VCC                | +5V
GND                | GND


<h2>See Also</h2>
<ul>
    <li><a class="urllink" href="https://randomnerdtutorials.com/arduino-ir-remote-control/" rel="nofollow" target="_blank">Arduino – Control LEDs with IR Remote Control</a></li>
  <li><a class="urllink" href="https://arduino-projects-free.blogspot.com/2017/04/control-led-with-ir-remote-control-and.html" rel="nofollow" target="_blank">Control LED with IR Remote Control and Arduino </a></li>
  
  
</ul>
