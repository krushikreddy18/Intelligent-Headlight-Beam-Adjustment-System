#include <Adafruit_NeoPixel.h>
const int LDR_1= A0;
const int LDR_2 = A1;
const int LDR_3 = A2;


#define PIN1 6        // Connected to DI pin on the matrix
#define PIN2 7
#define NUMPIXELS 64 // 8x8 matrix = 64 LEDs

Adafruit_NeoPixel matrix1(NUMPIXELS, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel matrix2(NUMPIXELS, PIN2, NEO_GRB + NEO_KHZ800);


// Simple LED bulb pins


// Define brightness levels
#define LOW_BEAM_BRIGHTNESS 100   // PWM value (0-255)
#define HIGH_BEAM_BRIGHTNESS 255  // PWM value (0-255)

// Adjusted LDR threshold based on observed behavior
#define LDR_THRESHOLD 350  // Adjusted for inverted LDR behavior
 // If vehicle detected within this distance, force low beam

void setup() {
    Serial.begin(9600);
    matrix1.begin();
     matrix2.begin();
  matrix1.setBrightness(50); // Optional: limit brightness for power safety
  matrix2.setBrightness(50);

  matrix1.clear();
  matrix2.clear();
   
    //Serial.println("High Beam: Both ON Initially");
}

// Function to measure distance using ultrasonic sensor

void high_beam()
{
      for(int i = 0; i < NUMPIXELS; i++) 
  {
    matrix1.setPixelColor(i, matrix1.Color(255, 255, 255));
    matrix1.show();
    //delay(50);
  }
    for(int i = 0; i < NUMPIXELS; i++) 
  {
    matrix2.setPixelColor(i, matrix1.Color(255, 255, 255));
    matrix2.show();
    //delay(50);
  }

}
void low_beam()
{
      for(int i = 0; i < NUMPIXELS/2; i++) 
  {
    
    
    matrix1.setPixelColor(i, matrix1.Color(0, 0, 0));
    matrix1.show();
    matrix2.setPixelColor(i, matrix1.Color(0, 0, 0));
    matrix2.show();
    
    
    //delay(50);
  }
    
}
void loop() {
    // Read LDR values
    int light1 = analogRead(LDR_1);
    int light2 = analogRead(LDR_2);
    int light3 = analogRead(LDR_3);
    Serial.print("ldr 1Light Level: ");
    Serial.print(light1);
    Serial.print("| ldr2 Light Level: ");
    Serial.println(light2);
    Serial.print(" | ldr3 Light Level: ");
    Serial.println(light3);

   
    if ((light1 < LDR_THRESHOLD) || (light2 < LDR_THRESHOLD) ||(light3 < LDR_THRESHOLD) ) 
    {
        low_beam();
        Serial.println("HIGH Beam: BOTH ON");
    } else {
        high_beam();
        Serial.println("LOW Beam: Left ON, Right OFF");
    }

    delay(100);
}
