#include <Arduino.h>
#include <Servo.h>
#include <ros.h>
#include <std_msgs/UInt8.h>

Servo servoA0;
ros::NodeHandle nh;

void setAngleCb( const std_msgs::UInt8& msg) {
    servoA0.write(msg.data);
    digitalWrite(13, HIGH-digitalRead(13));   // blink the led
}

ros::Subscriber<std_msgs::UInt8> setAngleSub("setAngle",&setAngleCb);

void setup() {
    pinMode(13,OUTPUT);
    servoA0.attach(A0);
    nh.initNode();
    nh.subscribe(setAngleSub);
}

void loop() {
    nh.spinOnce();
    delay(10);
}

    
