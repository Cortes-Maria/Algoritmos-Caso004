float t = 0;
float increment = 0.05;
int circles = 2;
int cantCircles = 5;
int sizeCircle = 50;
int cantEllipses = 10;
color[] colors = new color[100];

void setup(){
  size(1200,800);
  for (int i = 0; i < 100; i++){
    colors[i] = color(random(0,255), random(0,255), random(0,255));
  };
}

void drawCircle(int sizeCircle, int xc, int yc, color cl){
  for(int i=0; i<cantEllipses; i++){
    float r = ((TWO_PI)/cantEllipses)*i;
    fill(cl);
    ellipse(xc+(sin(r)*sizeCircle), yc+(cos(r)*sizeCircle),7,7);
  }
}

void drawCircles(int n, int sizeCircle,int xc, int yc, color cl){
  for(int i=1; i<n+1; i++){
    drawCircle(sizeCircle*i, xc, yc, cl);
  }
}

void draw(){
  background(0);
  for(int i=0; i<circles; i++){
    float r = ((TWO_PI)/circles)*i + t;
    drawCircles(cantCircles,sizeCircle,int((width/2)+(sin(r)*sizeCircle/2)), int((height/2)+(cos(r)*sizeCircle/2)), colors[i]);
  }
  
  
  //pushMatrix();

  //popMatrix();
  if(t > TWO_PI/circles || t<0){
    increment = -increment;
  }
  t += increment;
}
