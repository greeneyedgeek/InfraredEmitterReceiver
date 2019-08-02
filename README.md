# InfraredEmitterReceiver

<p>The intent of this project is to build a small infrared emitter and receiver. The emitter sends a signal to the receiver which then decodes it and outputs the corresponding RGB value.</p>

<h2>Hardware Required</h2>

<ul>
  <li>2 x Arduino Nano Board</li>
  <li>1 x IR Receiver</li>
  <li>1 x RGB LED</li>
  <li>1 x IR LED</li>
  <li>Jumper wires</li>
  <li>Breadboard</li>
  <li>Power source</li>
  <li>Resistors (to protect the circuit)</li>
</ul>

<h2>Circuit</h2>

<img src="" alt="Circuit">
  
RGB LED &nbsp;     | Arduino Nano Receiver
-------------------|------------
RGB LED RED        | 10 
REB LED GREEN      | 8
RGB LED BLUE       | 9
RGB LED GND        | GND
IR RECEIVER SIGNAL | PIN 2
IR RECEIVER VCC    | +5V
IR RECEIVER GND    | GND

RGB LED &nbsp;     | Arduino Nano Emitter
-------------------|------------
IR LED SIGNAL      | PIN 3
IR LED VCC         | +5V
IR LED GND         | GND


<h2>See Also</h2>
<ul>
    <li><a class="urllink" href="https://randomnerdtutorials.com/arduino-ir-remote-control/" rel="nofollow" target="_blank">Arduino – Control LEDs with IR Remote Control</a></li>
  <li><a class="urllink" href="https://arduino-projects-free.blogspot.com/2017/04/control-led-with-ir-remote-control-and.html" rel="nofollow" target="_blank">Control LED with IR Remote Control and Arduino </a></li>
  
  
</ul>
