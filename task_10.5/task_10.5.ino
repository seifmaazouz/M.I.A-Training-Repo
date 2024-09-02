#include <Wire.h>

// MPU6050 I2C address (Default address for MPU6050)
const int MPU_ADDR = 0x68;  // MPU6050 I2C address is 0x68 when AD0 pin is LOW

// MPU6050 Register Addresses
const int PWR_MGMT_1 = 0x6B; // Power Management 1 register (used to wake up the MPU6050)
const int GYRO_XOUT_H = 0x43; // Gyroscope X-axis high byte register
const int GYRO_XOUT_L = 0x44; // Gyroscope X-axis low byte register
const int GYRO_YOUT_H = 0x45; // Gyroscope Y-axis high byte register
const int GYRO_YOUT_L = 0x46; // Gyroscope Y-axis low byte register
const int GYRO_ZOUT_H = 0x47; // Gyroscope Z-axis high byte register
const int GYRO_ZOUT_L = 0x48; // Gyroscope Z-axis low byte register

void setup() {
  // Initialize serial communication at 115200 baud
  Serial.begin(115200);

  // Initialize I2C communication
  Wire.begin();

  // Wake up MPU6050 (it starts in sleep mode)
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(PWR_MGMT_1);
  Wire.write(0); // Write 0 to the Power Management 1 register to wake up the MPU6050
  Wire.endTransmission(true);
}

void loop() {
  // Read gyro values
  int16_t gyroX = readGyro(GYRO_XOUT_H, GYRO_XOUT_L);
  int16_t gyroY = readGyro(GYRO_YOUT_H, GYRO_YOUT_L);
  int16_t gyroZ = readGyro(GYRO_ZOUT_H, GYRO_ZOUT_L);

  // Compute yaw from gyro readings (this is a simplified example; in a real application, you'll need to integrate these values over time)
  float yaw = atan2(gyroY, gyroX) * 180.0 / PI;

  // Print the yaw value
  Serial.print("Yaw: ");
  Serial.println(yaw);

  // Delay for a while
  delay(100);
}

int16_t readGyro(int highByteRegister, int lowByteRegister) {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(highByteRegister);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 2);

  int16_t value = (Wire.read() << 8) | Wire.read();
  return value;
}