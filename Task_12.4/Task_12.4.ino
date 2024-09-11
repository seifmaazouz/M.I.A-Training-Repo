// Motor control pins
const int motorPinPWM = 5; // PWM pin for motor speed control
const int motorPinIN1 = 8; // Direction control pin 1
const int motorPinIN2 = 9; // Direction control pin 2

// Potentiometer pin
const int potPin = A0;

// Exponential smoothing factor
const float alpha = 0.2; // 0 < alpha < 1
// As you incease the aplha nearer to 1, the motor reaches its desired speed faster and less smoothly

class PID {
  private:
    float kp;
    float ki;
    float kd;
    float prevError = 0.0;
    float integral = 0.0;
    float output = 0.0;
  	unsigned long lastTime;
  
  public:
    PID(float kp, float ki, float kd):kp(kp), ki(ki), kd(kd) {
      	lastTime = millis(); // Initialize lastTime
    }

    void compute(float setpoint, float currentSpeed) {
        unsigned long currentTime = millis();
        float elapsedTime = (currentTime - lastTime) / 1000.0; // Convert to seconds

        float error = setpoint - currentSpeed;
        integral += error * elapsedTime;
        float derivative = (error - prevError) / elapsedTime;
        output = kp * error + ki * integral + kd * derivative;

        prevError = error;
        lastTime = currentTime;
    }

    float getOutput() {
        return constrain(output, 0, 255); // Constrain output to PWM range
    }
};
// Create PID controller object
PID pid(1.0, 0.1, 0.1); // Initialize PID with default values (kp, ki, kd)

// Exponential smoothing variables
float smoothedSpeed = 0.0;

void setup() {
    // Set motor control pins as output
    pinMode(motorPinPWM, OUTPUT);
    pinMode(motorPinIN1, OUTPUT);
    pinMode(motorPinIN2, OUTPUT);

    // Set motor direction (can be adjusted as needed)
    digitalWrite(motorPinIN1, HIGH);
    digitalWrite(motorPinIN2, LOW);

    // Start serial comms
    Serial.begin(9600);
}

void loop() {
    // Read the potentiometer value
    int potValue = analogRead(potPin);

    // Map potentiometer value to setpoint range
    float setpoint = map(potValue, 0, 1023, 0, 255);

    // Exponential smoothing for soft start
    smoothedSpeed = smoothedSpeed + alpha * (setpoint - smoothedSpeed);

    // Compute PID output
    pid.compute(setpoint, smoothedSpeed);

    // Apply PID output to motor
    analogWrite(motorPinPWM, pid.getOutput());

    // Print data for monitoring
    Serial.print("Potentiometer Value: ");
    Serial.print(potValue);
    Serial.print(" | Setpoint: ");
    Serial.print(setpoint);
    Serial.print(" | Smoothed Speed: ");
    Serial.print(smoothedSpeed);
    Serial.print(" | PID Output: ");
    Serial.println(pid.getOutput());

    // Small delay for stability
    delay(100);
}
