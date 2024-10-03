#include <MsTimer2.h> // Thư viện timer 2
#include <Wire.h>
// Thu vien PWM servo
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVOMIN 125  // Số lượng độ dài xung 'tối thiểu' (trong số 4096)
#define SERVOMAX 1150  // Số lượng độ dài xung 'tối đa' (trong số 4096)
#define SERVO_FREQ 60 // Analog servos chạy tại 60hz
// Thu vien va khai bao cam bien khoang cach
#include <SharpIR.h>
#define ir1 A0
#define ir2 A1
#define ir3 A2
#define model 1080

/*#define runTimes(t) for (static uint32_t _lasttime;\
                         (uint32_t)((uint32_t)millis() - _lasttime) >= (t);\
                         _lasttime += (t))
*/

uint8_t servonum = 0;

SharpIR kc1(ir1, model);
SharpIR kc2(ir2, model);
SharpIR kc3(ir3, model);

// xác định cảm biến của bạn: 1080 cho GP2Y0A21Y
// 20150 cho GP2Y0A02Y
// Khai báo biến đo khoảng cách
uint16_t kctrai;
uint16_t kcgiua;
uint16_t kcphai;

uint16_t rpi; // nhan gia tri uart

int measure_dis(SharpIR distant)
{
    int32_t dis;
    dis = distant.distance(); // this returns the distance to the object you're measuring
    return dis;
}

int angleToPulse(int angle)
{
    int pulse = map(angle, 0, 360, SERVOMIN, SERVOMAX);
    return pulse;
}
// Khai bao cac chan dong co step
uint8_t tep = 3;
uint8_t dir = 2;
uint8_t ena = 4;

// Khai bao cac bien dieu khien step
uint16_t stp;
int8_t pos_step = 0; // vi tri cua step

void DistantSensor(void);
void Straight(float x);
void Left(float x);
void Right(float x);
void Stop(float x);
void Auto(int a, float y);
void Down(void);
void Down_2(void);
void Up(void);
void Up_2(void);
void Balance_1(void);
void Balance_2(void);

void setup()
{
    Serial.begin(9600);
    pwm.begin();
    pwm.setPWMFreq(SERVO_FREQ); // Analog servos chạy tại 60hz
    pinMode(ena, OUTPUT);       // Enable pin dung de khoi dong motor
    pinMode(tep, OUTPUT);       // Step chan xung
    pinMode(dir, OUTPUT);       // Dir xac dinh chieu quay
    digitalWrite(ena, LOW);     // Set Enable LOW - Khoi dong motor

    MsTimer2::set(1000, DistantSensor); // Timer ngat sau 1s
    MsTimer2::start();                  // Kich hoat timer
}

void loop()
{
    if (Serial.available() > 0)
    {
        rpi = Serial.read();
        rpi = rpi - 48; // Chuyen kieu char sang int => Từ bộ Mã ASCII
                        // Serial.print("Received: ");
        // Serial.println(rpi);
        if (rpi == 0)
        {
            Auto(25, 6);
        }
        else if (rpi == 1)
        {
            Auto(25, 6.75);
        }
        else if (rpi == 2)
        {
            Auto(25, 7.25);
        }
        else if (rpi == 3)
        {
            Left(6);
        }
        else if (rpi == 4)
        {
            Straight(6);
        }
        else if (rpi == 5)
        {
            Stop(6);
        }
        else if (rpi == 6)
        {
            Right(6);
        }
        else if (rpi == 7)
        {
            Left(6.75);
        }
        else if(rpi == 8)
        {
            Straight(6.75);
        }
        else if(rpi == 9)
        {
            Stop(6.75);
        }
        else if(rpi == 10)
        {
            Right(6.75);
        }
        else if(rpi == 11)
        {
            Left(7.25);
        }
        else if(rpi == 12)
        {
            Straight(7.25);
        }
        else if(rpi == 13)
        {
            Stop(7.25);
        }
        else if(rpi == 14)
        {
            Right(7.25);
        }
   
      else if(rpi == 17 && pos_step == 0){
            Down();
            pos_step = 1;
      }
      else if(rpi == 19 && pos_step == 0){
            Up();
            pos_step = -1;
      }
      else if(rpi == 21 && pos_step == 1){
            Balance_1();
            pos_step = 0;
      }
      else if(rpi == 22 && pos_step == -1){
            Balance_2();
            pos_step = 0;
      }
      else if(rpi == 18 && pos_step == -1){
            Down_2();
            pos_step = 1;
      }
      else if(rpi == 20 && pos_step == 1){
            Up_2();
            pos_step = -1;
      }
    }
}

void DistantSensor()
{
    kctrai = measure_dis(kc2);
    Serial.print("Khoang cach trai: ");
    Serial.print("47cm");
    kcgiua = measure_dis(kc3);
    Serial.print("\tKhoang cach giua: ");
    Serial.print("45cm");
    kcphai = measure_dis(kc1);
    Serial.print("\tKhoang cach phai: ");
    Serial.println("47cm");
}

void Stop(float x)
{
    pwm.setPWM(0, 0, angleToPulse(100));
    pwm.setPWM(2, 0, angleToPulse(100));
    delay(x);
}

void Straight(float x)
{

    for (float angle = 75.5; angle <= 122.5; angle++)
    {
        delay(x);
        pwm.setPWM(0, 0, angleToPulse(angle));
        pwm.setPWM(2, 0, angleToPulse(angle));
    }
    for (float angle = 122.5; angle >= 75.5; angle--)
    {
        delay(x);
        pwm.setPWM(0, 0, angleToPulse(angle));
        pwm.setPWM(2, 0, angleToPulse(angle));
    }
}

void Left(float x)
{
    for (int angle = 55; angle <= 100; angle++)
    {
        delay(x);
        pwm.setPWM(0, 0, angleToPulse(angle));
        pwm.setPWM(2, 0, angleToPulse(angle));
    }
    for (int angle = 100; angle >= 55; angle--)
    {
        delay(x);
        pwm.setPWM(0, 0, angleToPulse(angle));
        pwm.setPWM(2, 0, angleToPulse(angle));
    }
}
void Right(float x)
{
    for (int angle = 100; angle <= 145; angle++)
    {
        delay(x);
        pwm.setPWM(0, 0, angleToPulse(angle));
        pwm.setPWM(2, 0, angleToPulse(angle));
    }
    for (int angle = 145; angle >= 100; angle--)
    {
        delay(x);
        pwm.setPWM(0, 0, angleToPulse(angle));
        pwm.setPWM(2, 0, angleToPulse(angle));
    }
}

void Auto(int a, float y)
{
    if (kctrai >= a)
    {
        if (kcgiua >= a && kcphai >= a)
        {
            Straight(y);
        }
        else if (kcgiua < a && kcphai >= a)
        {
            Right(y);
        }
        else if (kcgiua >= a && kcphai < y)
        {
            Straight(y);
        }
        else
        {
            Left(y);
        }
    }
    else
    {
        if (kcgiua >= a && kcphai >= a)
        {
            Straight(y);
        }
        else if (kcgiua < a && kcphai >= a)
        {
            Right(y);
        }
        else if (kcgiua >= a && kcphai < a)
        {
            Straight(y);
        }
        else
        {
            Right(y);
        }
    }
}

void Down(void)
{
    digitalWrite(dir, HIGH);         // Chân dir dùng để xác định chiều quay (hoặc thay đổi dây của motor)
    for (stp = 1; stp <= 600; stp++) // Quay 1 vòng
    {
        digitalWrite(tep, HIGH); // Cạnh lên
        delay(1);                // Thời gian xuất xung = tốc độ quay
        digitalWrite(tep, LOW);  // Cạnh xuống
        delay(1);
    }
}
void Down_2(void)
{
    digitalWrite(dir, HIGH);          // Chân dir dùng để xác định chiều quay (hoặc thay đổi dây của motor)
    for (stp = 1; stp <= 1200; stp++) // Quay 2 vòng
    {
        digitalWrite(tep, HIGH); // Cạnh lên
        delay(1);                // Thời gian xuất xung = tốc độ quay
        digitalWrite(tep, LOW);  // Cạnh xuống
        delay(1);
    }
}
void Up(void)
{
    digitalWrite(dir, LOW);
    for (stp = 1; stp <= 600; stp++) // Quay 1 vòng
    {
        digitalWrite(tep, HIGH); // Cạnh lên
        delay(1);                // Thời gian xuất xung = tốc độ quay
        digitalWrite(tep, LOW);  // Cạnh xuống
        delay(1);
    }
}

void Up_2(void)
{
    digitalWrite(dir, LOW);
    for (stp = 1; stp <= 1200; stp++) // Quay 2 vòng
    {
        digitalWrite(tep, HIGH); // Cạnh lên
        delay(1);                // Thời gian xuất xung = tốc độ quay
        digitalWrite(tep, LOW);  // Cạnh xuống
        delay(1);
    }
}

void Balance_1(void)
{
    digitalWrite(dir, LOW);
    for (stp = 1; stp <= 600; stp++) // Quay 1 vòng
    {
        digitalWrite(tep, HIGH); // Cạnh lên
        delay(1);                // Thời gian xuất xung = tốc độ quay
        digitalWrite(tep, LOW);  // Cạnh xuống
        delay(1);
    }
}

void Balance_2()
{
    digitalWrite(dir, HIGH);         // Chân dir dùng để xác định chiều quay (hoặc thay đổi dây của motor)
    for (stp = 1; stp <= 600; stp++) // Quay 1 vòng
    {
        digitalWrite(tep, HIGH); // Cạnh lên
        delay(1);                // Thời gian xuất xung = tốc độ quay
        digitalWrite(tep, LOW);  // Cạnh xuống
        delay(1);
    }
}
