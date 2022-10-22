#define S0 6

#define S1 7

#define S2 8

#define S3 9

#define sensorOut 10

// Lưu trữ tần số được đọc bởi các photodiode

int redFrequency = 0;

int greenFrequency = 0;

int blueFrequency = 0;

void setup() {

     // Thiết lập các chân ngõ ra

     pinMode(S0, OUTPUT);

     pinMode(S1, OUTPUT);

     pinMode(S2, OUTPUT);

     pinMode(S3, OUTPUT);

     // Thiết lập sensorOut là ngõ vào

     pinMode(sensorOut, INPUT);

     // Thiết lập tỷ lệ tần số là 20%

     digitalWrite(S0,LOW);

     digitalWrite(S1,HIGH);

     // Thiết lập tốc độ cho giao tiếp nối tiếp

     Serial.begin(9600);

}

void loop() {

     // Thiết lập photodiode lọc màu đỏ

     digitalWrite(S2,LOW);

     digitalWrite(S3,LOW);

     // Đọc tần số ngõ ra

     redFrequency = pulseIn(sensorOut, LOW);

     // In giá trị đỏ (R)

     Serial.print("R = ");

     Serial.print(redFrequency);

     delay(100);

     // Thiết lập photodiode lọc màu xanh lá cây

     digitalWrite(S2,HIGH);

     digitalWrite(S3,HIGH);

     // Đọc tần số ngõ ra

     greenFrequency = pulseIn(sensorOut, LOW);

     // In giá trị màu xanh lá cây

     Serial.print(" G = ");

     Serial.print(greenFrequency);

     delay(100);

     // Thiết lập photodiode lọc màu xanh dương

     digitalWrite(S2,LOW);

     digitalWrite(S3,HIGH);

     // Đọc tần số ngõ ra

     blueFrequency = pulseIn(sensorOut, LOW);

     // In giá trị màu xanh dương

    Serial.print(" B = ");

     Serial.println(blueFrequency);

     delay(100);

}
