//OpenCASCADE tutorials by Laszlo Kudela
//December 2015

#include "Chapter1_Basics/inc/WriteCoordinatesToFile.hpp"
#include "OtherExamples/inc/StlPointsExtractor.hpp"

#include "StlAPI.hxx"
#include "TColgp_HArray1OfPnt.hxx"
#include <RWStl.hxx>
#include <Poly_Triangulation.hxx>
#include <iostream>

int main(int argc, char *argv[])
{
	
	if(argc < 2)
	{
		std::cout << "Usage: " << std::endl;
		std::cout << "extractStlPoints [InputSTLFile]" << std::endl;
		return 1;
	}

	char* inputFileName = argv[1];

	TopoDS_Shape stlShape;	
	std::cout << "Reading STL file " << inputFileName << " ..." << std::flush;

	StlAPI::Read(stlShape,inputFileName);
    Handle(Poly_Triangulation) triangulation = RWStl::ReadFile(inputFileName); 
	std::cout << "done.";
	std::cout << "Nb of nodes: " << triangulation->NbNodes();;

    TColgp_Array1OfPnt extractedStlPoints{triangulation->Nodes()};

	Handle(TColgp_HArray1OfPnt) extractedPoints = StlPointsExtractor::extractVerticesFromTopoDSShape(stlShape);

	WriteCoordinatesToFile::writeCoordinatesToFile("stlOutput.txt",extractedPoints->Array1());
	WriteCoordinatesToFile::writeCoordinatesToFile("stlOutputRWStl.txt", extractedStlPoints);
	
	return 0;
}
