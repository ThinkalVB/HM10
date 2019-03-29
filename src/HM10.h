
#ifndef _HM10_H_
#define _HM10_H_

#include <SoftwareSerial.h>

class HM10 
{
  SoftwareSerial BTserial;

  bool bufferIsEmpty = true;
  bool dataRead = false;

public: 
  String data;

  HM10(uint8_t RX, uint8_t TX);
  void readData();
  void clearBuffer();
  bool bufferEmpty();

};

#endif /* _HM10_H_ */
