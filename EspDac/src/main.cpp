
#include <Arduino.h>
#include <I2S.h>


const long sampleRate = 48000;
const int bitsPerSample = 16;
uint8_t *buffer;


int y = 0;
//int y1 = 0;
int y2 = 0;
int y3 = 0;
int y4 = 0;

int x[5] = {0};   
int x1[5] = {0};
int x2[5] = {0};
int x3[5] = {0};
int x4[5] = {0};

enum mode {
  H,
  M,
  L
};

int filter(mode _mode){
  double a[4];
  double b[5];

  if (_mode == H)
  {
    double Ha[4] = { 4.00007043, -6.0002113, 4.0002113, -1.00007043};
    *a = *Ha;
    double Hb[5] = { 0.03543882, -0.14175529,  0.21263294, -0.14175529,  0.03543882};
    *b = *Hb;

  }
  else if (_mode == M)
  {
    double Ma[4] = { 4.00007043, -6.0002113, 4.0002113, -1.00007043};
    *a = *Ma;
    double Mb[5] = { 0.03543882, -0.14175529,  0.21263294, -0.14175529,  0.03543882};
    *b = *Mb;
  }
    else if (_mode == L)
  {
    double La[4] = { 4.00007043, -6.0002113, 4.0002113, -1.00007043};
    *a = *La;
    double Lb[5] = { 0.03543882, -0.14175529,  0.21263294, -0.14175529,  0.03543882};
    *b = *Lb;
  }

  return 0;
}


void setup() {
  Serial.begin(115200);

    if (!I2S.begin(I2S_PHILIPS_MODE, 48000, 16)) {
    Serial.println("Failed to initialize I2S!");
    while (1); // do nothing
  }
  //I2S.setAllPins(5, 25, 35, 26); // you can change default pins; order of pins = (CLK, WS, IN, OUT)
  // if(!I2S.setDuplex()){
  //   Serial.println("ERROR - could not set duplex");
  //   while(true){
  //     vTaskDelay(10); // Cannot continue
  //   }
  // }
  // I2S.setAllPins(int sckPin, int fsPin, int sdPin, int outSdPin, int inSdPin);

  // //I2SClass::I2SClass() a;

  // if (!I2S.begin(I2S_PHILIPS_MODE, sampleRate, bitsPerSample)) {
  //   Serial.println("Failed to initialize I2S!");
  //   while(true){
  //     vTaskDelay(10); // Cannot continue
  //   }
  // }
  // buffer = (uint8_t*) malloc(I2S.getBufferSize() * (bitsPerSample / 8));
  // if(buffer == NULL){
  //   Serial.println("Failed to allocate buffer!");
  //   while(true){
  //     vTaskDelay(10); // Cannot continue
  //   }
  // }
  // Serial.println("Setup done");

}

void loop() {
  //I2S.write(I2S.read()); // primitive implementation sample-by-sample
  //Serial.println("asjgi");
  // Buffer based implementation
  //I2S.read(buffer, I2S.getBufferSize() * (bitsPerSample / 8));
  //I2S.write(buffer, I2S.getBufferSize() * (bitsPerSample / 8));
  int sample = I2S.read();
  Serial.println(sample);

  //optimistic_yield(1000); // yield if last yield occurred before <parameter> CPU clock cycles ago

}
