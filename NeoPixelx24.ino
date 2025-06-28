//By SanguineX01

#include <Adafruit_NeoPixel.h>
#include <Bounce2.h>

// Only for Adafruit QT Py 2040
// Only for Adafruit NeoPixel Ring 24 RGB

#define NEOPIXEL_PIN        29 // Set to Pin A0
#define NEOPIXEL_NUMPIXELS  24
#define BUTTON_PIN          21 // Used as power and brightness button
#define BRIGHTNESS_STEPS    4

Adafruit_NeoPixel pixels(NEOPIXEL_NUMPIXELS, NEOPIXEL_PIN, NEO_RGB + NEO_KHZ800);
Bounce b = Bounce();

// Starts in powered off state
int brightness = 0;

void setBrightness() {
    int brightnessVal = (int)(((float)brightness/BRIGHTNESS_STEPS)*255);

    pixels.clear();
    pixels.fill(pixels.Color(brightnessVal, brightnessVal, brightnessVal, brightnessVal), 0, NEOPIXEL_NUMPIXELS);
    pixels.show();
}
// Sets up LEDs and button
void setup() {
    
    pixels.begin();

    
    b.attach(BUTTON_PIN, INPUT);
    b.interval(25);

    
    setBrightness();
}

void loop() {
    b.update();

    if(b.fell()) {
        if(brightness == 0) {
            brightness = BRIGHTNESS_STEPS;
        } else {
            brightness--;
        }

        setBrightness();
    }
}