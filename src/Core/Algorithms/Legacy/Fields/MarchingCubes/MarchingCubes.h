/*
   For more information, please see: http://software.sci.utah.edu

   The MIT License

   Copyright (c) 2015 Scientific Computing and Imaging Institute,
   University of Utah.

   
   Permission is hereby granted, free of charge, to any person obtaining a
   copy of this software and associated documentation files (the "Software"),
   to deal in the Software without restriction, including without limitation
   the rights to use, copy, modify, merge, publish, distribute, sublicense,
   and/or sell copies of the Software, and to permit persons to whom the
   Software is furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included
   in all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
   OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
   THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
   DEALINGS IN THE SOFTWARE.
*/

#ifndef CORE_ALGORITHMS_VISUALIZATION_MARCHINGCUBES_H
#define CORE_ALGORITHMS_VISUALIZATION_MARCHINGCUBES_H 1

#include <Core/Datatypes/Field.h>
#include <Core/Datatypes/Matrix.h>

#include <Core/Thread/Thread.h>
#include <Core/Geom/GeomGroup.h>

#include <string>
#include <vector>

#include <Core/Algorithms/Util/AlgoBase.h>
#include <Core/Algorithms/Fields/share.h>

namespace SCIRunAlgo {

using namespace SCIRun;

class SCISHARE MarchingCubesAlgo : public AlgoBase {

  public:

    MarchingCubesAlgo()
    {
      add_bool("transparency",false);
      add_bool("build_geometry", false);
      add_bool("build_field", false);
      add_bool("build_node_interpolant", false);
      add_bool("build_elem_interpolant", false);
      
      add_int("num_threads",-1);
      
      add_color("color",Color(0.5,0.5,0.5));
      add_colormap("colormap",0);
    };
    
    bool run(FieldHandle input, std::vector<double>& isovalues, 
             GeomHandle& geometry,
             FieldHandle& field,
             MatrixHandle& node_interpolant,
             MatrixHandle& elem_interpolant );

    bool run(FieldHandle input, std::vector<double>& isovalues, 
             GeomHandle& geometry );

    bool run(FieldHandle input, std::vector<double>& isovalues, 
             FieldHandle& field );

    bool run(FieldHandle input, std::vector<double>& isovalues, 
             FieldHandle& field, MatrixHandle& interpolant );

};
  
} // End namespace AlgoSCIRun

#endif
