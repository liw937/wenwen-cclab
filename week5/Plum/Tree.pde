class Tree {
  float weight;

  Tree(float w) {
    weight=w;
  }

  void drawtree() {
    stroke(0);
    strokeWeight(weight);
    line(mouseX, mouseY, pmouseX, pmouseY);
  }
}

