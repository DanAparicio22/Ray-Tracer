#include "ShadeRec.h"

ShadeRec::ShadeRec(World &w) :impactAnObject(false), impactLocalPoint(), normal(), color(black), w(w) {}

ShadeRec::ShadeRec(const ShadeRec &sr) : impactAnObject(sr.impactAnObject), impactLocalPoint(sr.impactLocalPoint), color(sr.color), w(sr.w) {}

ShadeRec::~ShadeRec()
{
}
