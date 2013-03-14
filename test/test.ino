#include <NESpad.h>

// put your own strobe/clock/data pin numbers here -- see the pinout in readme.txt
NESpad nintendo = NESpad(2,3,4);

byte state = 0;

/* A button gets marked as true as soon as it is pressed. That way
we know to not "press" it again */
boolean a = false; //A Button
boolean b = false; //B Button
boolean u = false; //Up Button
boolean d = false; //Down Button
boolean l = false; //Left Button
boolean r = false; //Right Button
boolean s = false; //Start Button
boolean e = false; //Select Button

/* We will pass on this array whenever a key is released. Once the
key is released we will turn that 0 into a 1. That way in our java program
we will know exactly which keys we just released. The keys will always go
in this order: a,b,u,d, l,r,s,e */
int keysReleased[] = {
0,0,0,0, 0,0,0,0};

/* We will set this to true only when a button has been released. This will
stop us from sending the keysReleased array every loop to our java robot */
boolean isReleased = false;

void setup() {
Serial.begin(9600);
}

void loop() {

delay(5);

state = nintendo.buttons();

// A
if (state & NES_A){
if(!a){
a = true; //Make sure the button is only pressed once
Serial.println('A'); //Print the button to be picked up by our robot
}
}
//Key might have been released so we check and if so change the
//value in our released array
else if (a == true){
a = false;
keysReleased[0] = 1;
isReleased = true;
}

// B
if (state & NES_B){
if(!b){
b = true; //Make sure the button is only pressed once
Serial.println('B'); //Print the button to be picked up by our robot
}
}
//Key might have been released so we check and if so change the
//value in our released array
else if (b == true){
b = false;
keysReleased[1] = 1;
isReleased = true;
}

// Up
if (state & NES_UP){
if(!u){
u = true; //Make sure the button is only pressed once
Serial.println('U'); //Print the button to be picked up by our robot
}
}
//Key might have been released so we check and if so change the
//value in our released array
else if (u == true){
u = false;
keysReleased[2] = 1;
isReleased = true;
}

// Down
if (state & NES_DOWN){
if(!d){
d = true; //Make sure the button is only pressed once
Serial.println('D'); //Print the button to be picked up by our robot
}
}
//Key might have been released so we check and if so change the
//value in our released array
else if (d == true){
d = false;
keysReleased[3] = 1;
isReleased = true;
}

// Left
if (state & NES_LEFT){
if(!l){
l = true; //Make sure the button is only pressed once
Serial.println('L'); //Print the button to be picked up by our robot
}
}
//Key might have been released so we check and if so change the
//value in our released array
else if (l == true){
l = false;
keysReleased[4] = 1;
isReleased = true;
}

//Right
if (state & NES_RIGHT){
if(!r){
r = true; //Make sure the button is only pressed once
Serial.println('R'); //Print the button to be picked up by our robot
}
}
//Key might have been released so we check and if so change the
//value in our released array
else if (r == true){
r = false;
keysReleased[5] = 1;
isReleased = true;
}

//Start
if (state & NES_START){
if(!s){
s = true; //Make sure the button is only pressed once
Serial.println('S'); //Print the button to be picked up by our robot
}
}
//Key might have been released so we check and if so change the
//value in our released array
else if (s == true){
s = false;
keysReleased[6] = 1;
isReleased = true;
}

//Select
if (state & NES_SELECT){
if(!e){
e = true; //Make sure the button is only pressed once
Serial.println('E'); //Print the button to be picked up by our robot
}
}
//Key might have been released so we check and if so change the
//value in our released array
else if (e == true){
e = false;
keysReleased[7] = 1;
isReleased = true;
}

/* If a key has been released then our java robot needs to know about it. So what we
are going to do is to iterate over our array if a key has been released and print out the
position in the array of that key. So for example if "Up" has been released we will
see that our array looks like this [0,0,1,0, 0,0,0,0]. So then we will print 2 to the java robot
so it knows that "Up" has been released. Likewise we would print 7 for the start button on release. */
if(isReleased){
isReleased = false; //Reset the boolean
for(int i=0; i < 8; i++){
if(keysReleased[i] == 1){
keysReleased[i] = 0; //Reset the button listener
Serial.println(i);
}
}
}
}
