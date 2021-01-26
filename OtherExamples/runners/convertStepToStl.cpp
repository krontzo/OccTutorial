//OpenCASCADE tutorials by Laszlo Kudela
//2016 May

#include "STEPControl_Reader.hxx"
#include "StlAPI_Writer.hxx"
#include "TopoDS_Shape.hxx"
#include "Standard_ConstructionError.hxx"
#include "BRepMesh_IncrementalMesh.hxx"

#include "StlAPI.hxx"
int main(int argc, char *argv[])
{
  STEPControl_Reader reader;
  reader.ReadFile(argv[1]);
  reader.TransferRoots();
  TopoDS_Shape stepShape = reader.OneShape();
  BRepMesh_IncrementalMesh mesh(stepShape,0.01,Standard_False);
  mesh.Perform();
  try {
    StlAPI_Writer writer;
    //writer.SetASCIIMode(True)
    writer.Write(stepShape, argv[2]);
    StlAPI::Write(stepShape, "gel.stl", true);

    std::cout << "Error no?" << std::endl;
  } catch(Standard_ConstructionError& e) {
    std::cout << e.GetMessageString() << std::endl;
  }
  
  return 0;
}
