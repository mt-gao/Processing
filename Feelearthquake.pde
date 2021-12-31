import processing.sound.*;
import processing.serial.*;

SoundFile sample;
Waveform waveform;
Serial port;

int samples = 100;
int b;
int value = 0;
PFont font;

float circle = 200;
float rot;
float color1;
float freq = 0.000005; 
int cont = 0;
float r;

void setup()
{
  size(displayWidth, displayHeight);

  sample = new SoundFile(this, "eqsound.mp3");
  //sample.loop();

  waveform = new Waveform(this, samples);
  waveform.input(sample);
  
  font = createFont("Bogart-Extralight-Italic-trial.ttf", 128);
  
  port = new Serial(this, "COM3", 9600);
}

void draw()
{  
  background(255,242,236);
  translate(width/2, height/2);
  rotate(radians(rot));
  waveform.analyze();
  
  if (keyPressed){
    if (key == 'a' || key == 'A'){
      sample.loop();
    }
    if (key == 's' || key == 'S'){
        for(int i = 0; i < samples; i++)
        {
          b = abs(int(waveform.data[i]*60));
        }
        value = b;
    }
    if (key == 'd' || key == 'D'){
      b = 0;
      value = 0;
    }
  }
  
  if (value == 0){
  }
  else{
      beginShape();
      ellipseMode(RADIUS);
        for (int i=0; i<500; i ++) {
          circle= 200 + 50*sin(millis()*freq*i);
          color1=map(circle,150,250,255,60);
          r=map(circle,150,250,5,2);
          fill(color1,0,74);
          noStroke();
          ellipse((circle+b)*cos(i)*1.5, (circle+b)*sin(i)*1.5,r*1.5,r*1.5);    
          rot=rot+0.00005;
        }      
      endShape();   
  }

  println(b);
  port.write(b);
}
