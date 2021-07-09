#include <Crypto.h>
#include <string.h>
#include <SHA3.h>
#include "printf.h"

SHA3_256 sha3_256;
byte b_baru[32];
uint8_t buff[32];
String str_baru;
int h;

void setup() {
  Serial.begin(9600);
  printf_begin();

}

void loop() {
Serial.print("Masukan String : ");
  while(!Serial.available()>0);
  str_baru = Serial.readStringUntil('\n');
Serial.println(str_baru);

uint8_t inputHash[str_baru.length()];
str_baru.toCharArray(inputHash, str_baru.length()+1);
sha3_256.reset();
sha3_256.update(inputHash, str_baru.length());
sha3_256.finalize(b_baru, 32);
Serial.print("HASIL HASH SHA3 : ");

for(h=0;h<32;h++){
  printf("%02x", b_baru[h]);
  
  }
Serial.println("\nSelesai.\n");
}
