#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite spr = TFT_eSprite(&tft);

#define WIDTH 135
#define HEIGHT 240

/* Setting colors */
uint16_t red = 0xB926;
uint16_t pink = 0xD4D7;
uint16_t magenta = 0xD28D;

/* Setting initial shape size and offset of smallest center heart, to scale up */
int radius = 11; 
int triOffset = 20;
int circWOffset = 10;
int circHOffset = 5;

void setup() {
  tft.init();
  tft.setRotation(1);
  spr.createSprite(HEIGHT, WIDTH);
}

void loop(){
  tft.fillScreen(0);
  spr.fillSprite(TFT_BLACK);
  
  pinkCenter();
  delay(400);
  magentaCenter();
  delay(400);
  redCenter();
  delay(400); 
  pinkCenter();
  delay(400);
  magentaCenter();
  delay(400);
  redCenter();
  delay(400); 
}

/* Function to make one "frame" by layering small hearts over bigger ones */
void pinkCenter() {
  /* Number of hearts to fill a LilyGo T-Display */
  int biggest = 9;

  while(biggest>0){
    spr.fillTriangle((tft.width()/2) - (triOffset * biggest), tft.height()/2, (tft.width()/2) +(triOffset * biggest), tft.height()/2, tft.width()/2, (tft.height()/2) + (triOffset * biggest), magenta);
    spr.fillCircle((tft.width()/2) + (circWOffset * biggest), (tft.height()/2) - (circHOffset * biggest), radius * biggest, magenta);
    spr.fillCircle((tft.width()/2) - (circWOffset * biggest), (tft.height()/2) - (circHOffset * biggest), radius * biggest, magenta);
    biggest--;
    spr.fillTriangle((tft.width()/2) - (triOffset * biggest), tft.height()/2, (tft.width()/2) +(triOffset * biggest), tft.height()/2, tft.width()/2, (tft.height()/2) + (triOffset * biggest), red);
    spr.fillCircle((tft.width()/2) + (circWOffset * biggest), (tft.height()/2) - (circHOffset * biggest), radius * biggest, red);
    spr.fillCircle((tft.width()/2) - (circWOffset * biggest), (tft.height()/2) - (circHOffset * biggest), radius * biggest, red);
    biggest--;
    spr.fillTriangle((tft.width()/2) - (triOffset * biggest), tft.height()/2, (tft.width()/2) +(triOffset * biggest), tft.height()/2, tft.width()/2, (tft.height()/2) + (triOffset * biggest), pink);
    spr.fillCircle((tft.width()/2) + (circWOffset * biggest), (tft.height()/2) - (circHOffset * biggest), radius * biggest, pink);
    spr.fillCircle((tft.width()/2) - (circWOffset * biggest), (tft.height()/2) - (circHOffset * biggest), radius * biggest, pink);
    biggest--;
  }
  spr.pushSprite(0, 0);
}

void magentaCenter() {
  int biggest = 9;

  while(biggest>0){
    spr.fillTriangle((tft.width()/2) - (triOffset * biggest), tft.height()/2, (tft.width()/2) +(triOffset * biggest), tft.height()/2, tft.width()/2, (tft.height()/2) + (triOffset * biggest), red);
    spr.fillCircle((tft.width()/2) + (circWOffset * biggest), (tft.height()/2) - (circHOffset * biggest), radius * biggest, red);
    spr.fillCircle((tft.width()/2) - (circWOffset * biggest), (tft.height()/2) - (circHOffset * biggest), radius * biggest, red);
    biggest--;
    spr.fillTriangle((tft.width()/2) - (triOffset * biggest), tft.height()/2, (tft.width()/2) +(triOffset * biggest), tft.height()/2, tft.width()/2, (tft.height()/2) + (triOffset * biggest), pink);
    spr.fillCircle((tft.width()/2) + (circWOffset * biggest), (tft.height()/2) - (circHOffset * biggest), radius * biggest, pink);
    spr.fillCircle((tft.width()/2) - (circWOffset * biggest), (tft.height()/2) - (circHOffset * biggest), radius * biggest, pink);
    biggest--;
    spr.fillTriangle((tft.width()/2) - (triOffset * biggest), tft.height()/2, (tft.width()/2) +(triOffset * biggest), tft.height()/2, tft.width()/2, (tft.height()/2) + (triOffset * biggest), magenta);
    spr.fillCircle((tft.width()/2) + (circWOffset * biggest), (tft.height()/2) - (circHOffset * biggest), radius * biggest, magenta);
    spr.fillCircle((tft.width()/2) - (circWOffset * biggest), (tft.height()/2) - (circHOffset * biggest), radius * biggest, magenta);
    biggest--;
  }
  spr.pushSprite(0, 0);
}

void redCenter() {
  int biggest = 9;

  while(biggest>0){
    spr.fillTriangle((tft.width()/2) - (triOffset * biggest), tft.height()/2, (tft.width()/2) +(triOffset * biggest), tft.height()/2, tft.width()/2, (tft.height()/2) + (triOffset * biggest), pink);
    spr.fillCircle((tft.width()/2) + (circWOffset * biggest), (tft.height()/2) - (circHOffset * biggest), radius * biggest, pink);
    spr.fillCircle((tft.width()/2) - (circWOffset * biggest), (tft.height()/2) - (circHOffset * biggest), radius * biggest, pink);
    biggest--;
    spr.fillTriangle((tft.width()/2) - (triOffset * biggest), tft.height()/2, (tft.width()/2) +(triOffset * biggest), tft.height()/2, tft.width()/2, (tft.height()/2) + (triOffset* biggest), magenta);
    spr.fillCircle((tft.width()/2) + (circWOffset * biggest), (tft.height()/2) - (circHOffset * biggest), radius * biggest, magenta);
    spr.fillCircle((tft.width()/2) - (circWOffset * biggest), (tft.height()/2) - (circHOffset * biggest), radius * biggest, magenta);
    biggest--;
    spr.fillTriangle((tft.width()/2) - (triOffset * biggest), tft.height()/2, (tft.width()/2) +(triOffset * biggest), tft.height()/2, tft.width()/2, (tft.height()/2) + (triOffset * biggest), red);
    spr.fillCircle((tft.width()/2) + (circWOffset * biggest), (tft.height()/2) - (circHOffset * biggest), radius * biggest, red);
    spr.fillCircle((tft.width()/2) - (circWOffset * biggest), (tft.height()/2) - (circHOffset * biggest), radius * biggest, red);
    biggest--;
  }
  spr.pushSprite(0, 0);
}




