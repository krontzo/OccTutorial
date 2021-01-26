#ifndef _STLPOINTEXTRACTOR_HPP_
#define _STLPOINTEXTRACTOR_HPP_
//OpenCASCADE tutorials by Laszlo Kudela
//December 2015

#include "TColgp_HArray1OfPnt.hxx"
#include "TopoDS_Shape.hxx"

class StlPointsExtractor
{
public:
	StlPointsExtractor ();
	virtual ~StlPointsExtractor ();

	static Handle(TColgp_HArray1OfPnt) extractVerticesFromTopoDSShape(const TopoDS_Shape& shape);
	static TopoDS_Shape extractManifoldBoundaries(const TopoDS_Shape& shape);

private:
	/* data */
};

#endif
