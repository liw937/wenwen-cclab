import com.nootropic.processing.layers.*;

Tree t1;
Tree t2;

AppletLayers layers;


void setup() {
  size(800, 500);
  background(255);

  t1= new Tree(10);
  t2= new Tree(5);
  layers= new AppletLayers(this);
}


void paint(java.awt.Graphics g) {
  if (layers != null) {
    layers.paint(this);
  } 
  else {
    super.paint(g);
  }
}

void draw() {

 
  
  if (keyPressed) {
    if (key == 't'|| key=='T') {
      t1.drawtree();
    }
  }


  if (keyPressed) {
    if (key == 'r'|| key=='R') {
      t2.drawtree();
    }
  }
  
layers.addLayer(new Plum(this,mouseX,mouseY));


}



 



