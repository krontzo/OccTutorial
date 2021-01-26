#ifndef _GEOMETRYWRITER_HPP_
#define _GEOMETRYWRITER_HPP_
//OpenCASCADE tutorial by Laszlo Kudela
//January 2016

#include <string>
#include "Geom_Curve.hxx"
#include "Geom_Surface.hxx"

class GeometryWriter
{
public:
	GeometryWriter ();
	virtual ~GeometryWriter ();

	static void writeGeomEntityToStepFile(Handle(Geom_Curve) curve, std::string fileName);
	static void writeGeomEntityToStepFile(Handle(Geom_Surface) curve, std::string fileName);

private:
};
#endif
