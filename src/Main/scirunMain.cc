
/*
   For more information, please see: http://software.sci.utah.edu

   The MIT License

   Copyright (c) 2012 Scientific Computing and Imaging Institute,
   University of Utah.

   License for the specific language governing rights and limitations under
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

#include <Core/Application/Application.h>
#include <Interface/Application/GuiApplication.h>
#include <Core/ConsoleApplication/ConsoleApplication.h>


using namespace SCIRun::Core;
using namespace SCIRun::Gui;
using namespace SCIRun::Core::Console;


// If console needs to be shown.
#ifndef WINDOWS_NO_CONSOLE
int main(int argc, const char* argv[])
{
  Application::Instance().readCommandLine(argc, argv);
  
  //TODO: must read --headless flag here, or try pushing command queue building all the way up here

#ifndef BUILD_HEADLESS
  return GuiApplication::run(argc, argv);
#else
  return ConsoleApplication::run(argc, argv);
#endif
}

// If building on WIN32 and not showing console, use this entry point.
#else
#include <windows.h>
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
  const char *argv[] = {GetCommandLine()};
  int argc = 1;
  Application::Instance().readCommandLine(argc, argv);
  
  //TODO: must read --headless flag here, or try pushing command queue building all the way up here

#ifndef BUILD_HEADLESS
  return GuiApplication::run(argc, argv);
#else
  return ConsoleApplication::run(argc, argv);
#endif
}
#endif // End if for Windows main.