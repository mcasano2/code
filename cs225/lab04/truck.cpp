/**
 * Copyright 2011 University of Illinois at Urbana-Champaign
 * CS 225 Lab 04 C++ Object Oriented Programming
 * Authors:
 *   Simon Krueger <skruege2@illinois.edu>
 *
 * Please see truck.h for documentation of the Truck class
 */

#include "truck.h"

#include "color.h"

namespace cs225 {

namespace {

const int TRAILER_WIDTH = 48;
const int TRAILER_HEIGHT = 16;
const RGBApixel TRAILER_COLOR = color::BLUE;

const int CABIN_WIDTH = 8;
const int CABIN_HEIGHT = 12;
const RGBApixel CABIN_COLOR = color::RED;

const int ENGINE_WIDTH = 6;
const int ENGINE_HEIGHT = 8;
const RGBApixel ENGINE_COLOR = color::RED;

const int WINDOW_WIDTH = 4;
const int WINDOW_HEIGHT = 4;
const RGBApixel WINDOW_COLOR = color::BLUE;

const int WHEEL_RADIUS = 3;
const RGBApixel WHEEL_COLOR = color::BLACK;

const int NUM_WHEELS = 5;

}  // namespace

Truck::Truck(const Vector2& center)
: center_(center),
  wheels(new Circle*[NUM_WHEELS]),
  trailer(new Rectangle(Vector2(center_.x()-TRAILER_WIDTH/2, center_.y()), TRAILER_COLOR, TRAILER_WIDTH, TRAILER_HEIGHT)),
  cabin(new Rectangle(Vector2(center_.x()+CABIN_WIDTH/2,
          (center_.y()+TRAILER_HEIGHT/2)-CABIN_HEIGHT/2), CABIN_COLOR, CABIN_WIDTH, CABIN_HEIGHT)),
  window(new Rectangle(Vector2(cabin->center().x(),
          cabin->center().y()-WINDOW_HEIGHT/2), WINDOW_COLOR, WINDOW_WIDTH,
        WINDOW_HEIGHT)),
  engine(new Rectangle(Vector2(cabin->center().x()+CABIN_WIDTH/2 +
          ENGINE_WIDTH/2,
          (cabin->center().y()+CABIN_HEIGHT/2) - ENGINE_HEIGHT/2), ENGINE_COLOR,
        ENGINE_WIDTH, ENGINE_HEIGHT)) {
  /* This should be cleaned up and not use the initialization list. =/ */
  const int left = (static_cast<int>(trailer->center().x()) - trailer->width() / 2) +
    WHEEL_RADIUS;
  const int right = (static_cast<int>(trailer->center().x()) + trailer->width() / 2) -
    WHEEL_RADIUS;
  const int y = (WHEEL_RADIUS*1/2 + static_cast<int>(trailer->center().y()) +
                 trailer->height() / 2);
  wheels[0] = new Circle(Vector2(left, y), WHEEL_COLOR, WHEEL_RADIUS);
  wheels[1] = new Circle(Vector2(left+WHEEL_RADIUS*2, y), WHEEL_COLOR, WHEEL_RADIUS);
  wheels[2] = new Circle(Vector2(right, y), WHEEL_COLOR, WHEEL_RADIUS);
  wheels[3] = new Circle(Vector2(right-WHEEL_RADIUS*2, y), WHEEL_COLOR, WHEEL_RADIUS);
  wheels[4] = new Circle(Vector2(engine->center().x()-WHEEL_RADIUS, y), WHEEL_COLOR, WHEEL_RADIUS);
}

Truck::Truck(const Truck& other)
: center_(other.center_),
  wheels(new Circle*[NUM_WHEELS]),
  trailer(new Rectangle(*(other.trailer))),
  cabin(new Rectangle(*(other.cabin))),
  window(new Rectangle(*(other.window))),
  engine(new Rectangle(*(other.engine))) {
  for (int i = 0; i < NUM_WHEELS; i++) {
    wheels[i] = new Circle(*(other.wheels[i]));
  }
}

Truck::~Truck() {
  clear();
}

Truck& Truck::operator=(const Truck& rhs) {
  if (this == &rhs) {
    return *this;
  }
  clear();
  copy(rhs);
  return *this;
}

Vector2 Truck::center() const {
  return this->center_;
}

void Truck::set_center(const Vector2& center) {
  const Vector2 delta(this->center_ - center);
  this->center_ = this->center_ + delta;
  for (int i = 0; i < NUM_WHEELS; i++) {
    wheels[i]->set_center(wheels[i]->center() + delta);
  }
  trailer->set_center(trailer->center() + delta);
  cabin->set_center(cabin->center() + delta);
  window->set_center(window->center() + delta);
  engine->set_center(engine->center() + delta);
}

void Truck::copy(const Truck& other) {
  center_ = other.center_;
  wheels = new Circle*[NUM_WHEELS];
  for (int i = 0; i < NUM_WHEELS; i++) {
    wheels[i] = new Circle(*(other.wheels[i]));
  }
  trailer = new Rectangle(*(other.trailer));
  cabin = new Rectangle(*(other.cabin));
  window = new Rectangle(*(other.window));
  engine = new Rectangle(*(other.engine));
}

void Truck::clear() {
  for (int i = 0; i < NUM_WHEELS; i++) {
    delete wheels[i];
    wheels[i] = NULL;
  }
  delete[] wheels;
  delete trailer;
  delete cabin;
  delete window;
  delete engine;
}

}  // namespace cs225
