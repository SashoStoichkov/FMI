#include <fstream>
#include <iostream>
using namespace std;

#include "File.h"

void File::copy(const File &other) {
  this->path = other.path;
  this->shapes = other.shapes;
}

void File::free() {
  this->path.clear();
  for (auto shape : this->shapes) {
    delete shape;
  }
  this->shapes.clear();
}

File::File(string path) : path(path) {}

File::File(const File &other) { copy(other); }

File::~File() { free(); }

File &File::operator=(const File &other) {
  if (this != &other) {
    free();
    copy(other);
  }
  return *this;
}

string File::getPath() const { return this->path; }

vector<Shape *> File::getShapes() const { return this->shapes; }

void File::addShape(Shape *shape) { this->shapes.push_back(shape); }

void File::removeShape(int index) {
  if (index <= 0 || index > this->shapes.size()) {
    cout << "Erase: There is no figure number " << index << "!" << endl;
    return;
  }

  cout << "Erase: Erased a " << this->shapes[index - 1]->getName() << "("
       << index << ")" << endl;

  delete this->shapes[index - 1];
  this->shapes.erase(this->shapes.begin() + index - 1);
}

void File::translateShape(int index, int dx, int dy) {
  if (index == -1) {
    for (auto shape : this->shapes) {
      shape->translate(dx, dy);
    }

    cout << "Translate: Translated all figures" << endl;
  } else {
    if (index < 0 || index >= this->shapes.size()) {
      cout << "Translate: There is no figure number " << index + 1 << "!"
           << endl;
      return;
    }

    this->shapes[index]->translate(dx, dy);

    cout << "Translate: Translated a " << this->shapes[index]->getName() << "("
         << index + 1 << ")" << endl;
  }
}

void File::withinShape(Shape *shape) const {
  if (shape->getName() != "circle" && shape->getName() != "rect") {
    cout << "Within: There is no shape named " << shape->getName()
         << "! Choose between circle and rectangle!" << endl;
    return;
  }

  int count = 0;

  for (auto currentShape : this->shapes) {
    if (currentShape->isWithin(shape)) {
      count++;

      cout << count << ". ";
      currentShape->print();
    }
  }

  if (count == 0) {
    cout << "Within: There are no figures within ";
    shape->print();
  }
}

void File::print() const {
  int count = 0;

  for (auto shape : this->shapes) {
    count++;
    cout << count << ". ";
    shape->print();
  }

  if (count == 0) {
    cout << "There are no figures!" << endl;
  }
}

void File::load() {
  ifstream file(path);

  if (!file.is_open()) {
    cout << "Load: File not found" << endl;
    return;
  }

  string line;
  // load svg file
  while (getline(file, line)) {
    if (line.find("<circle") != string::npos) {
      // parse <circle cx="5" cy="5" r="10" fill="blue" />
      string cx = line.substr(line.find("cx=") + 4,
                              line.find("\"", line.find("cx=") + 4) -
                                  line.find("cx=") - 4);

      string cy = line.substr(line.find("cy=") + 4,
                              line.find("\"", line.find("cy=") + 4) -
                                  line.find("cy=") - 4);

      string r = line.substr(line.find("r=") + 3,
                             line.find("\"", line.find("r=") + 3) -
                                 line.find("r=") - 3);

      string fill = line.substr(line.find("fill=") + 6,
                                line.find("\"", line.find("fill=") + 6) -
                                    line.find("fill=") - 6);

      Circle *circle = new Circle(stoi(cx), stoi(cy), stoi(r), fill);
      this->addShape(circle);

    } else if (line.find("<rect") != string::npos) {
      // parse <rect x="5" y="5" width="10" height="10" fill="blue" />
      string x = line.substr(line.find("x=") + 3,
                             line.find("\"", line.find("x=") + 3) -
                                 line.find("x=") - 3);

      string y = line.substr(line.find("y=") + 3,
                             line.find("\"", line.find("y=") + 3) -
                                 line.find("y=") - 3);

      string width = line.substr(line.find("width=") + 7,
                                 line.find("\"", line.find("width=") + 7) -
                                     line.find("width=") - 7);

      string height = line.substr(line.find("height=") + 8,
                                  line.find("\"", line.find("height=") + 8) -
                                      line.find("height=") - 8);

      string fill = line.substr(line.find("fill=") + 6,
                                line.find("\"", line.find("fill=") + 6) -
                                    line.find("fill=") - 6);

      Rectangle *rectangle =
          new Rectangle(stoi(x), stoi(y), stoi(width), stoi(height), fill);
      this->addShape(rectangle);

    } else if (line.find("<line") != string::npos) {
      // parse <line x1="5" y1="5" x2="10" y2="10" stroke="blue" />
      string x1 = line.substr(line.find("x1=") + 4,
                              line.find("\"", line.find("x1=") + 4) -
                                  line.find("x1=") - 4);

      string y1 = line.substr(line.find("y1=") + 4,
                              line.find("\"", line.find("y1=") + 4) -
                                  line.find("y1=") - 4);

      string x2 = line.substr(line.find("x2=") + 4,
                              line.find("\"", line.find("x2=") + 4) -
                                  line.find("x2=") - 4);

      string y2 = line.substr(line.find("y2=") + 4,
                              line.find("\"", line.find("y2=") + 4) -
                                  line.find("y2=") - 4);

      string stroke = line.substr(line.find("stroke=") + 8,
                                  line.find("\"", line.find("stroke=") + 8) -
                                      line.find("stroke=") - 8);

      Line *line = new Line(stoi(x1), stoi(y1), stoi(x2), stoi(y2), stroke);
      this->addShape(line);
    }
  }

  file.close();

  cout << "Load: Successfully loaded " << path << endl;
}

void File::save(string path) {
  if (path == "") {
    path = this->path;
  }

  ofstream file(path);

  if (!file.is_open()) {
    cout << "Save: File not found" << endl;
    return;
  }

  file << "<?xml version=\"1.0\" standalone=\"no\"?>" << endl;
  file << "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"" << endl;
  file << " \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">" << endl;
  file << "<svg>" << endl;

  for (auto shape : this->shapes) {
    file << " " << shape->toString() << endl;
  }

  file << "</svg>" << endl;

  file.close();

  cout << "Save: Successfully saved " << path << endl;
}