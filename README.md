## Audio Frequency Detection using Microphone and NodeMCU

This project implements a basic audio frequency detection system using a condenser microphone, an LM358 op-amp for signal amplification and biasing, and a NodeMCU (ESP8266) used as a wired microcontroller.

The detected frequency is calculated from the time-domain signal and displayed in real time on the Arduino IDE Serial Monitor.

### Why this project?
This is a foundation project for building a sound-based encoder and decoder system. The long-term goal is to transfer data using audio signals.

I experimented with Frequency Shift Keying (FSK) multiple times but did not achieve stable results yet. This repository focuses on improving frequency detection accuracy before revisiting FSK or exploring alternative modulation techniques.

### What this project covers
- Microphone signal amplification using LM358
- Analog signal conditioning for ADC input
- Frequency estimation from audio signals
- Practical challenges like noise and timing errors

### Future work
- Improve noise filtering and stability
- Implement reliable FSK or alternative modulation
- Build a complete audio-based data transmission system
