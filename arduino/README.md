<!--
 The MIT License (MIT)

 Copyright (c) 2018, Jeremy Cole

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
-->

Support for the SparkFun Fio v3 must be added to the Arduino IDE, by following the [installation instructions](https://github.com/sparkfun/Arduino_Boards#installation-instructions) to add the SparkFun Arduino Boards repository as an additional board manager URL. Once the SparkFun Arduino Boards are installed, "SparkFun Fio v3" should be available as a board choice (Tools → Board → Arduino AVR Boards → SparkFun Fio v3).

Additionally, the following Arduino libraries must also be installed:

* [TI\_TCA9548A](https://github.com/jeremycole/TI_TCA9548A) – Used for the TI TCA9548A I²C multiplexer.
* [AllSensors\_DLHR](https://github.com/jeremycole/AllSensors_DLHR) – Used for the AllSensors DLHR pressure sensors.
* [Temperature\_LM75\_Derived](https://github.com/jeremycole/Temperature_LM75_Derived) – Used for the TI TMP102 temperature sensor.

The above libraries may be installed using one of the following methods:

1. Using the Arduino IDE's library manager (Sketch → Include Library → Manage Libraries...) to download the most current version and allow automatic updates with new releases.
2. Downloading a specific release (or the "master" branch) from Github as a .ZIP file and installing it using the Arduino IDE's library manager (Sketch → Include Library → Add .ZIP Library...).
3. Manually installing either the .ZIP file as above or cloning the Git repository itself into the `libraries` subdirectory in the Arduino Sketchbook directory (Settings → Sketchbook location) – or doing so here and re-setting the sketchbook directory to this directory.
