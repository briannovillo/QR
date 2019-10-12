#include <qrcode.h>
#include <UTFT.h>

#define LEFT_PADDING 40
#define QR_VERSION 3
#define PIXEL_SCALE 8

UTFT myGLCD(ILI9341_16, 38, 39, 40, 41);

void setup() {
    myGLCD.InitLCD();
    myGLCD.fillScr(VGA_BLACK);
    myGLCD.setColor(VGA_WHITE);
 
    // Create the QR code
    QRCode qrcode;
    uint8_t qrcodeData[qrcode_getBufferSize(QR_VERSION)];
    qrcode_initText(&qrcode, qrcodeData, QR_VERSION, 0, "MIRAME MAMI, SIN MANOS!");

    int QRSize = qrcode.size;
    int QRScaledSize = QRSize * PIXEL_SCALE;
    
    for (uint8_t y = 0; y < QRScaledSize; y = y+PIXEL_SCALE) {
      for (uint8_t x = 0; x < QRScaledSize; x = x+PIXEL_SCALE) {
          if (qrcode_getModule(&qrcode, x/PIXEL_SCALE, y/PIXEL_SCALE)) {
              for (uint8_t p = 0; p < PIXEL_SCALE; p++) {
                myGLCD.drawRect(x+LEFT_PADDING, y, x+p+LEFT_PADDING, y+p);
              }
          }
      }
    }
}

void loop() {

}
