#define mic A0

unsigned long lastCross = 0;
unsigned long lastPrint = 0;

float freqSum = 0;
int freqCount = 0;

int minVal = 1023;
int maxVal = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Approx frequency detector started");
}

void loop() {
  int s = analogRead(MIC_PIN);

  if (s < minVal) minVal = s;
  if (s > maxVal) maxVal = s;
  int midpoint = (minVal + maxVal) / 2;

  static int lastS = midpoint;

  if (lastS < midpoint && s >= midpoint) {
    unsigned long now = micros();

    if (lastCross > 0) {
      float freq = 1000000.0 / (now - lastCross);
      if (freq > 50 && freq < 4000) {
        freqSum += freq;
        freqCount++;
      }
    }
    lastCross = now;
  }

  lastS = s;

  if (millis() - lastPrint >= 500) {
    lastPrint = millis();

    if (freqCount > 0) {
      float avgFreq = freqSum / freqCount;

      Serial.print("Approx frequency: ");
      Serial.print(avgFreq, 1);
      Serial.println(" Hz");
    } else {
      Serial.println("No stable signal");
    }

    freqSum = 0;
    freqCount = 0;
    minVal = 1023;
    maxVal = 0;
  }
}