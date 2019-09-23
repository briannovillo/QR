/**
 *  QRCode
 *
 *  A quick example of generating a QR code.
 *
 *  This prints the QR code to the serial monitor as solid blocks. Each module
 *  is two characters wide, since the monospace font used in the serial monitor
 *  is approximately twice as tall as wide.
 *
 */

#include <qrcode.h>
#include <UTFT.h>

// Declare which fonts we will be using
extern uint8_t BigFont[];

UTFT myGLCD(ILI9341_16, 38, 39, 40, 41);

void setup() {
    myGLCD.InitLCD();
    myGLCD.setFont(BigFont);
    myGLCD.fillScr(VGA_BLACK);
    myGLCD.setColor(VGA_WHITE);
  
    // Create the QR code
    QRCode qrcode;
    uint8_t qrcodeData[qrcode_getBufferSize(3)];
    qrcode_initText(&qrcode, qrcodeData, 3, 0, "ESTO ES UNA PRUEBA Y FUNCIONA WIIII");
  
    for (uint8_t y = 0; y < qrcode.size; y++) {
      for (uint8_t x = 0; x < qrcode.size; x++) {
          if (qrcode_getModule(&qrcode, x, y)) {
              myGLCD.drawPixel(x, y);
          }
      }
    }
}

void loop() {

}
