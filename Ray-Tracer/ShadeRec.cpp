#include "Constants.h"
#include "ShadeRec.h"

ShadeRec::ShadeRec(World& _m): impactAnObject(false), impactLocalPoint(), normal(), color(black), world(_m), t(0.0) {}
ShadeRec::ShadeRec(const ShadeRec& sr): impactAnObject(sr.impactAnObject), impactLocalPoint(sr.impactLocalPoint), normal(sr.normal), color(sr.color), world(sr.world), t(sr.t) {}

ShadeRec::~ShadeRec() {}
