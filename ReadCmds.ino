
int maxInput = 200;
char byteIn[200];
char value[10];
int indexValue = 0;
char inByte;
int indexArray = 0;
String valueIn;

int readValue = 0;

void setup() {
  Serial.begin(9600);
  delay(5000);
  Serial.println("\n\nready");

}

void runCMD(String cmd,String value){
  if(cmd == "hi"){
      Serial.println("hello");
  }else if(cmd == "age"){
    Serial.print(value.toInt());
    Serial.println(" years old");    
  }else{
    Serial.println("unknown");
    Serial.print("cmd: ");
    Serial.println(cmd);
    Serial.print("value: ");
    Serial.println(value);
  }
}

void loop() {
  while (Serial.available() > 0) {
    // read the incoming byte:
    inByte = Serial.read();


    if (inByte == ';'||inByte=='\n') {


      byteIn[indexArray] = '\0';
      value[indexValue] = '\0';
      valueIn = value;
      indexArray = 0;
      indexValue = 0;
      readValue = 0;
      runCMD(byteIn,value);
    } else if (readValue == 1) {

      value[indexValue] = inByte;

      indexValue++;

      if (indexValue >= 10) {
        indexValue = 0;
      }

    } else {
      if (inByte == '=') {
        readValue = 1;

      } else {

        byteIn[indexArray] = inByte;
        indexArray++;
      }
    }

    if (inByte == '=') {
      readValue = 1;

    }


    if (indexArray >= maxInput) {
      indexArray = 0;
    }

  }
}




