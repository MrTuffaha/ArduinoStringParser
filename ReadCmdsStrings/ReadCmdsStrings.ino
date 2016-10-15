
String inputCMD = "";
String inputValue = "";
char inByte;

int readValue = 0;

void setup() {
  Serial.begin(9600);
  delay(1000);
  Serial.println("\nready\n");

}

void runCMD(String cmd,String value){
    Serial.print("cmd: ");
    Serial.println(cmd);
    Serial.print("value: ");
    Serial.println(value);
    Serial.println("result{");
  if(cmd == "hi"){
      Serial.println("hello");
  }else if(cmd == "age"){
    Serial.print(value.toInt());
    Serial.println(" years old");    
  }else{
    Serial.println("command unknown");
  }
  Serial.println("}\n");
}

void loop() {
  while (Serial.available() > 0) {
    // read the incoming byte:
    inByte = Serial.read();


    if (inByte == ';'||inByte=='\n') {
     runCMD(inputCMD,inputValue);
      readValue = 0;
     inputCMD = "";
     inputValue = "";
    } else if (readValue == 1) {

      inputValue += inByte;


    } else {
      if (inByte == '=') {
        readValue = 1;

      } else {

        inputCMD += inByte;
      }
    }
  }
}




