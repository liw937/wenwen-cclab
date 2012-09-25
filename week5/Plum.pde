float d1;
float n=6;
color c1=#B41648;
float angle =0;
float distance;
float increment=TWO_PI/n;
int x, y;
  float r=0;
  float s=1;


class Plum extends Layer {





  Plum(PApplet parent, int x, int y) {
    super(parent);
  }

  void setup() {

    smooth();
  }


  void draw() {

    //  scale(flowerS);
    //  rotate(flowerR);




//    if (keyPressed && (key==CODED)) {
//      if (keyCode==UP) {
//        s+=0.01;
//      };
//      if (keyCode==DOWN) {
//        s-=0.01;
//      }
//      if (keyCode==LEFT) {
//        r-=0.1;
//      }
//      if (keyCode==RIGHT) {
//        r+=0.1;
//      }
//    }
  }

  
  }
  
  
  void mouseClicked() {
    translate(mouseX, mouseY);

    d1=20;
    distance=1.5*d1;
    for (int i=0; i< n; i++) {

      fill(c1);
      noStroke();
      ellipse(cos(angle) * distance, sin(angle) * distance, 2*d1, 2*d1);
      angle+=increment;
      fill(242, 217, 90);
      noStroke();
      ellipse(0, 0, 2*d1, 2*d1);
    }
}


