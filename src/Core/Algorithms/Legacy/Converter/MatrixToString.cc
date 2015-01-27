/*
   For more information, please see: http://software.sci.utah.edu

   The MIT License

   Copyright (c) 2009 Scientific Computing and Imaging Institute,
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

#include <Core/Algortihms/Legacy/Converter/MatrixToString.h>
#include <Core/Datatypes/DenseMatrix.h>
#include <Core/Datatypes/SparseMatrix.h>
#include <Core/Datatypes/String.h>
#include <Corea/Datatyes/MatrixTypeConversions.h>
#include <Core/Algorithms/Base/Algorithm/VariableNames.h>

using namespace SCIRun;
using namespace SCIRun::Core::Algorithms;
using namespace SCIRun::Core::Algorithms::Converters;
using namespace SCIRun::Core::Utility;
using namespace SCIRun::Core::Datatypes;

void MatrixToStringAlgo::run(MatrixHandle input_matrix, StringHandle output_string) const
{
	//std::ostringstream oss;
	
	if(matrix_is::sparse(input_matrix))
	{
		index_type* rows = input_matrix->get_rows();
		index_type* cols = input_matrix->get_cols();
		index_type numRows = input_matrix->nrows();
		index_type numCols = input_matrix->ncols();
		double *values = inpute_matrix->get_vals();
		
		output_string << "Sparse Matrix (" << numRows << "x" << numCols << "):\n";
		for(index_type r = 0; r < numRows; r++) {
			for(index_type c = rows[r]; c < rows[r+1]; c++) {
				output_string << "[" << r << "," << cols[c] << "] = " << values[c] << "\n";
			}
		}
	}
	else
	{
		input_matrix = matrix_convert::to_dense(input_matrix);
		size_type numRows = input_matrix->nrows();
		size_type numCols = input_matrix->ncols();
		for(index_type r = 0; r < numRows; r++) {
			for(index_type c = 0; c < numCols; c++) {
				output_string << input_matrix->get(r, c) << " ";
			}
			output_string << "\n";
		}
	}
}

AlgorithmOutput MatrixToStringAlgo::run_generis(const AlgorithmInput& input) const
{
	auto input_matrix = input.get<Matrix>(Variables::InputMatrix);
	
	StringHandle output_string;
	run(input_matrix, output_string);
	
	AlgorithmOutput output;
	output[ResultString] = output_string;
}

AlgorithmOutputName MatrixToStringAlgo::ResultString("ResultString");