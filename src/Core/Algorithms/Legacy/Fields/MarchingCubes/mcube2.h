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

//
// ** SCIRun version of vtkMarchingCubesCases.hh -- added nbr info to cases **
//
// marching cubes case table for generating isosurfaces
//

#ifndef MCUBE2_H
#define MCUBE2_H

#include <Core/Algorithms/Fields/share.h>

namespace SCIRun {

typedef struct {
  int edges[16];
  int nbrs;
} TRIANGLE_CASES;

/* REFERENCED */
extern SCISHARE int edge_tab[12][2];

//
// Edges to intersect. Three at a time form a triangle. Comments at end of line
// indicate case number (0->255) and base case number (0->15).
//

extern SCISHARE TRIANGLE_CASES triCases[];

} // End namespace SCIRun

#endif // MCUBE2_H
