#pragma once

/*
Authors: Shane Vance, Nico Espitia, Brennan Barni, Daniel Ortyn
Last Update: 2018/29/01
Purpose: CS 481 Project
*/

#include "stdafx.h"
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>

using namespace System::Windows::Forms;

namespace OpenGLForm 
{

	public ref class COpenGL: public System::Windows::Forms::NativeWindow
	{

	public:		

		COpenGL(System::Windows::Forms::Form ^ parentForm, GLsizei iWidth, GLsizei iHeight)
		{				

			CreateParams^ cp = gcnew CreateParams;

			//Set the position on the form
			cp->X = 0;
			cp->Y = 22; // accounts for the height of the status strip
			cp->Width = iWidth;
			cp->Height = iHeight;

			// specify the form as the parent.
			cp->Parent = parentForm->Handle;

			// create as a child of the specified parent and make OpenGL compliant (no clipping)
			cp->Style = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

			// create the actual window
			this->CreateHandle(cp);

			// set the world height and width for later
			this->worldWidth = iWidth;
			this->worldHeight = iHeight;

			// Create the data interface
			this->file = new DataInterface();

			m_hDC = GetDC((HWND)this->Handle.ToPointer());

			// check if everything went A-Okay when creating the Child Handle
			if(m_hDC)
			{
				this->MySetPixelFormat(m_hDC);
				this->Reshape(iWidth, iHeight);
				this->Init();
			}
		}

		// SET THE FILE PATH THAT WILL BE USED TO GRAPH THE DATA
		System::Void SetFilePath(std::string filepath)
		{	
			// read the file
			this->file->readFile(&filepath);
		}

		// BUTTON METHODS GO HERE //
		System::Void incrementSelectedSet(System::Void)
		{
			int selectedSetIndex = this->file->getSelectedSetIndex();
			selectedSetIndex++;
			if(selectedSetIndex >= this->file->getSetAmount()){
				selectedSetIndex = 0;
			}
			this->file->setSelectedSetIndex(selectedSetIndex);
		}

		System::Void decrementSelectedSet(System::Void)
		{
			int selectedSetIndex = this->file->getSelectedSetIndex();
			selectedSetIndex--;
			if(selectedSetIndex < 0){
				selectedSetIndex = this->file->getSetAmount()-1;
			}
			this->file->setSelectedSetIndex(selectedSetIndex);
		} 

		System::Void ascendingSort(System::Void)
		{
			int selectedSetIndex = this->file->getSelectedSetIndex();
			this->file->sortAscending(selectedSetIndex);
		}

		System::Void descendingSort(System::Void)
		{
			int selectedSetIndex = this->file->getSelectedSetIndex();
			this->file->sortDescending(selectedSetIndex);
		}

		System::Void originalSort(System::Void)
		{
			int selectedSetIndex = this->file->getSelectedSetIndex();
			this->file->sortOriginal();
		}

		System::Void mean(System::Void)
		{
			int selectedSetIndex = this->file->getSelectedSetIndex();
			double meanOfSet = this->file->getMean(selectedSetIndex);
			this->file->level(selectedSetIndex, meanOfSet);
		}

		System::Void median(System::Void)
		{
			int selectedSetIndex = this->file->getSelectedSetIndex();
			double medianOfSet = this->file->getMedian(selectedSetIndex);
			this->file->level(selectedSetIndex, medianOfSet);
		}

		System::Void originalData(System::Void)
		{
			this->file->zeroShifts();
		}

		System::Void hypercube(System::Void)
		{
			if(this->file->isPaintCluster())
			{
				this->file->togglePaintCluster();
			}else{
				int selectedSetIndex = this->file->getSelectedSetIndex();
				this->file->hypercube(selectedSetIndex, 0.2);
			}
		}

		/*
		System::Void save(System::Void)
		{
		std::string fileName = "testOutput.txt";
		file->readFile(&fileName);
		std::cout << "VisCanvas Custom Output" << std::endl;
		for(unsigned int i = 0; i < file->getSetAmount(); i++)
		{
		std::cout << file->getSetName(i);
		for(unsigned int j = 0; j < file->getDimensionAmount(); j++)
		{
		if(j == 0)
		{
		std::cout << file->getSetName(i) << ",";
		}
		else if(j == file->getDimensionAmount() - 1)
		{
		std::cout << file->getData(i,j) << std::endl;
		}
		else
		{
		std::cout << file->getDimensionData(i,j) << ",";
		}
		}
		}
		}
		*/

		int getDimensionSize(System::Void)
		{
			return this->file->getDimensionAmount();
		}

		// Get the dimension name for settings window
		const char* getDimensionName(int dimensionIndex)
		{
			std::string str = *this->file->getDimensionName(dimensionIndex);
			return str.c_str();
		}

		// Sets the background color
		System::Void Background(int r, int g, int b)
		{
			GLfloat red =   ((GLfloat)r) / 255.0f;
			GLfloat green = ((GLfloat)g) / 255.0f;
			GLfloat blue =  ((GLfloat)b) / 255.0f;
			glClearColor(red, green, blue, 0.0f);
		}

		// SET THE RGB VALUES FOR THE COLOR PALETTE
		System::Void SetRGB(GLdouble red, GLdouble green, GLdouble blue) 
		{
			this->R = red;
			this->G = green;
			this->B = blue;
		}


		// THIS ALLOWS FOR THE CHILD WINDOW TO BE RESIZED ACCORDINGLY 
		System::Void Resize(int x, int y, int width, int height, UINT uFlags)		
		{
			this->worldHeight = height;
			this->worldWidth = width;
			SetWindowPos((HWND)this->Handle.ToPointer(), NULL, x, y, width, height, uFlags);
			Reshape((GLsizei)width, (GLsizei)height);
		}

		System::Void Render(System::Void)
		{
			this->Display();
		}


		System::Void SwapOpenGLBuffers(System::Void)
		{
			SwapBuffers(m_hDC);
		}

	private:

		double worldWidth;  // Set the world width
		double worldHeight; // Set the world height
      double mouseX; // Holds mouse X coord
		double mouseY; // Holds mouse Y coord

		double worldMouseX; // Holds mouse X coord when mapped to world
		double worldMouseY; // Holds mouse Y coord when mapped to world
      
      boolDrawingDragged = false; // Is made true via mouselistener when dragging the mouse

		GLdouble R; // Red
		GLdouble G; // Green
		GLdouble B; // Blue
		
		/* Create the DataInterface for reading the file */
		DataInterface* file;

		HDC m_hDC;
		HGLRC m_hglrc;

	protected:
		~COpenGL(System::Void)
		{
			this->DestroyHandle();
		}

		/* DO NOT REMOVE OR MODIFY THIS */
		GLint MySetPixelFormat(HDC hdc)
		{
			PIXELFORMATDESCRIPTOR pfd = { 
				sizeof(PIXELFORMATDESCRIPTOR),  //  size of this pfd  
				1,                     // version number  
				PFD_DRAW_TO_WINDOW |   // support window  
				PFD_SUPPORT_OPENGL |   // support OpenGL  
				PFD_DOUBLEBUFFER,      // double buffered  
				PFD_TYPE_RGBA,         // RGBA type  
				24,                    // 24-bit color depth  
				0, 0, 0, 0, 0, 0,      // color bits ignored  
				0,                     // no alpha buffer  
				0,                     // shift bit ignored  
				0,                     // no accumulation buffer  
				0, 0, 0, 0,            // accum bits ignored  
				32,                    // 32-bit z-buffer      
				0,                     // no stencil buffer  
				0,                     // no auxiliary buffer  
				PFD_MAIN_PLANE,        // main layer  
				0,                     // reserved  
				0, 0, 0                // layer masks ignored  
			}; 


			GLint  iPixelFormat; 

			// get the device context's best, available pixel format match 
			if((iPixelFormat = ChoosePixelFormat(hdc, &pfd)) == 0)
			{
				MessageBox::Show("ChoosePixelFormat Failed");
				return 0;
			}

			// make that match the device context's current pixel format 
			if(SetPixelFormat(hdc, iPixelFormat, &pfd) == FALSE)
			{
				MessageBox::Show("SetPixelFormat Failed");
				return 0;
			}

			if((m_hglrc = wglCreateContext(m_hDC)) == NULL)
			{
				MessageBox::Show("wglCreateContext Failed");
				return 0;
			}

			if((wglMakeCurrent(m_hDC, m_hglrc)) == NULL)
			{
				MessageBox::Show("wglMakeCurrent Failed");
				return 0;
			}

			return 1;
		}


		// THIS IS WHERE ANY BUTTON CLICKS GO // the parent window will need to handle the other key presses
		virtual void WndProc( Message %msg ) override
		{
			switch (msg.Msg)
			{

			case WM_LBUTTONDOWN:
				{			
					//	MessageBox::Show("THIS IS A TEST: LEFT BUTTON");
				}
				break;
			}

			NativeWindow::WndProc( msg );
		}


		double getWorldMouseX(){
			double xWorld = GetCursorPos->(double)x;
			// divide by panel width to get the porportion of the window
			xWorld /= worldWidth;
			// multiply by the world width to parse the porportion of the window into the world
			xWorld *= worldWidth;

			return xWorld;
		} // Converts raw mouse X coordinates to world coordinates

		double getWorldMouseY(){
			double yWorld = GetCursorPos->(double)y;
			// divide by panel height to get the proportion of the window
			yWorld /= worldHeight;
			// multiply by the world height to parse the proportion of the window into the world
			yWorld *= worldHeight;

			return yWorld;
		} // Converts raw mouse Y coordinates to world coordinates
      
      // this method takes the passed mouse click coordinates and finds the dimension clicked on
		int findClickedDimension(){
			double xAxisIncrement = worldWidth/(this->file->getDimensionAmount()+2);
			double xMouseWorldPosition = getWorldMouseX();
			double yMouseWorldPosition = getWorldMouseY();


			for (int i = 0; i < file->getDimensionAmount(); i++)
			{
				double shiftAmount = this->file->getDimensionShift(i);
				double dimensionX = (xAxisIncrement) * i;
				double dimensionYMax = (worldHeight * 0.5) + worldHeight * 0.75+shiftAmount;
				double dimensionYMin = (worldHeight * 0.5) + worldHeight * 0.1+shiftAmount;

				if ((xMouseWorldPosition - dimensionX) < (worldWidth/(file->getDimensionAmount() +2)/2.0) && (xMouseWorldPosition - dimensionX) > -.1
					&& dimensionYMin <= yMouseWorldPosition && dimensionYMax >= yMouseWorldPosition) {
						return i;
				}
			}
			return -1;
		}
      
      void drawDraggedDimension(double x, double y, int dimensionIndex)
		{
			double shiftAmount = this->file->getDimensionShift(dimensionIndex);
			glColor4d(0.0, 0.0, 0.0, 0.5);
			glBegin(GL_LINE_STRIP);
				glVertex2d(x, shiftAmount * (worldHeight * 0.5) + worldHeight * 0.75);
				glVertex2d(x * i, shiftAmount * (worldHeight * 0.5) + worldHeight * 0.1);
			glEnd();

			glLineWidth(3.0);
			glPointSize(5.0);

			double xAxisIncrement = worldWidth/(this->file->getDimensionAmount()+2);
			for (int j = 0; j < file->getSetAmount(); j++)
			{
				std::vector<doubl>* colorOfCurrent = this->file->getSetColor(j);
				double colorAlpha = (*colorOfCurrent)[3];
				colorAlpha *= 0.5;
				glColor4d((*colorOfCurrent)[0],(*colorOfCurrent)[1],(*colorOfCurrent)[2],colorAlpha);
				glBegin(GL_POINTS); // draws points

				double currentData = this->file->getData(j, dimensionIndex);
				glVertex2d(x, currentData * (worldHeight * 0.5) + (0.175 * worldHeight));
				
				glEnd(); // ends drawing line
		}
      
      void insertDimension(double x, double y, double newX, double newY){

			double xAxisIncrement = worldWidth / (this->file->getDimensionAmount()+2);

			// on mouse depress
			int clickedDimensionIndex = findClickedDimension();

			// on mouse release 
			double newXMouseWorldPosition = getWorldMouseX(GetCursorPos->(double)x);	
			double newYMouseWorldPosition = getWorldMouseY(GetCursorPos->(double)y);

			// for each dimension, if new X position is between dimension i and its predecessor, insert current dimension between them
			for (int i = 0; i < file->getDimensionAmount(); i++)
			{
				double shiftAmount = this->file->getDimensionShift(i);
				double dimensionX = (xAxisIncrement) * i;
				double dimensionXMinusOne = (xAxisIncrement) * (i-1);

				// if dimension is "dropped" between dimension i and its predecessor, insert dimension between them
				if (newXMouseWorldPosition < dimensionX && newXMouseWorldPosition > dimensionXMinusOne)
				{
					file->moveData(clickedDimensionIndex, i-1);
				}
			}
			// then, redraw the visualization with altered data
			glClear();
			display();

			// draw the moved line
			glLineWidth(2.0);
			glClear(GL_COLOR_BUFFER_BIT);
			glColor3f(0.0f, 0.0f, 0.0f);
			glBegin(GL_LINE_STRIP);
			glVertex2d(((xAxisIncrement) * ClickedDimensionIndex)+shiftXBy, (shiftAmount * (worldHeight * 0.5) + worldHeight * 0.75)+shiftYBy);
			glVertex2d(((xAxisIncrement) * ClickedDimensionIndex)+shiftXBy, (shiftAmount * (worldHeight * 0.5) + worldHeight * 0.1)+shiftYBy);
			glEnd();

			// finally, call drawData() method to draw the line between all data points
			drawData();
			glFlush();
	    }
		
		void clickAndDrag(){
			worldMouseX = getWorldMouseX();
			worldMouseY = getWorldMouseY();
			int clickedDimension = findClickedDimension();
			
			// ensures that the clicked dimension is valid
			if (clickedDimension != -1){
				
				// while the mouse left button is depressed
				drawDragged = true;
				while ((GetKeyState(VK_LBUTTON) & 0x80) != 0)
					{
						drawDraggedDimension(worldMouseX, worldMouseY, clickedDimension);
					}
				// upon the release of the left mouse button
				drawDragged = false;
				droppedDimension = findClickedDimension();
				
				if (droppedClickedDimension != -1){ 
					file->insertDimension(clickedDimension,droppedDimension);
				}
			}
		}
		
		/*	
			MOUSE LISTENER METHOD
			For every single listener method (common methods):
				- set worldMouse coordinates (x any y) 
				- at end of function, call display()
			On depress:
				- when initially getting click, set drawDragged to true
			On release:
				- set drawDragged to false
				- call insertDimension method to move dimension
			On drag: (when mouse is depressed and the mouse cursor is moving)
				- Call the common methods
		*/

		void drawParallelLines()
		{
			glLineWidth(2.0);
			glClear(GL_COLOR_BUFFER_BIT);
			double xAxisIncrement = worldWidth/(this->file->getDimensionAmount()+2);
			glColor3f(0.0f, 0.0f, 0.0f);

			for (int i = 0; i < this->file->getDimensionAmount(); i++)
			{
				double shiftAmount = this->file->getDimensionShift(i);
				glBegin(GL_LINE_STRIP);
				// was (xAxisIncrement) * i
				glVertex2d((-this->worldWidth / 2.0) + ((xAxisIncrement) * (i + 1)), (shiftAmount * (this->worldHeight * 0.5) + this->worldHeight * 0.75));
				glVertex2d((-this->worldWidth / 2.0) + ((xAxisIncrement) * (i + 1)), (shiftAmount * (this->worldHeight * 0.5) + this->worldHeight * 0.1));
				glEnd();
			}
		} // draws parallel lines for dimensions (pulled out of Display function and made into its own function)

		GLvoid Display(GLvoid)
		{
			drawParallelLines();
			drawData();
			glFlush();
		}

		// Graphs the data to the world
		GLvoid drawData(GLvoid) 
		{
			glLineWidth(3.0);
			double xAxisIncrement = this->worldWidth / (this->file->getDimensionAmount()+1);
			if(this->file->isPaintCluster()) {
				std::vector<double>* colorOfCurrent = this->file->getClusterColor();
				glColor4d((*colorOfCurrent)[0], (*colorOfCurrent)[1], (*colorOfCurrent)[2], (*colorOfCurrent)[3]);
				// draw minimum of cluster
				glBegin(GL_LINE_STRIP); // begins drawing lines
				for (int i = 0; i < this->file->getDimensionAmount(); i++)
				{
					double currentData = this->file->getClusterMinimum(i);
					glVertex2d((-this->worldWidth / 2.0) + ((xAxisIncrement) * (i + 1)), (currentData * (this->worldHeight * 0.5)) + (0.175 * this->worldHeight));
				}
				glEnd(); // ends drawing line

				// draw cluster mean
				glBegin(GL_LINE_STRIP); // begins drawing lines
				for (int i = 0; i < this->file->getDimensionAmount(); i++)
				{
					double currentData = this->file->getClusterMean(i);
					glVertex2d((-this->worldWidth / 2.0) + ((xAxisIncrement) * (i + 1)), (currentData * (this->worldHeight * 0.5)) + (0.175 * this->worldHeight));
				}
				glEnd(); // ends drawing line

				// draw cluster maximum
				glBegin(GL_LINE_STRIP); // begins drawing lines
				for (int i = 0; i < this->file->getDimensionAmount(); i++)
				{
					double currentData = this->file->getClusterMaximum(i);
					glVertex2d((-this->worldWidth / 2.0) + ((xAxisIncrement) * (i + 1)), (currentData * (this->worldHeight * 0.5)) + (0.175 * this->worldHeight));
				}
				glEnd(); // ends drawing line

			}else{

				for (int j = 0; j < this->file->getSetAmount(); j++)
				{
					std::vector<double>* colorOfCurrent = this->file->getSetColor(j);
					glColor4d((*colorOfCurrent)[0], (*colorOfCurrent)[1], (*colorOfCurrent)[2], (*colorOfCurrent)[3]);
					glBegin(GL_LINE_STRIP); // begins drawing lines
					for (int i = 0; i < this->file->getDimensionAmount(); i++)
					{
						double currentData = this->file->getData(j, i);
						glVertex2d((-this->worldWidth / 2.0) + ((xAxisIncrement) * (i + 1)), (currentData * (this->worldHeight * 0.5)) + (0.175 * this->worldHeight));
					}
					glEnd(); // ends drawing line
				}
			}
		}


		// INITIALIZE THE GL SETTINGS
		GLvoid Init(GLvoid)										
		{
			this->Background(194, 206, 218);	        // background is blue-ish gray
		}

		// RESIZE AND INITIALIZE THE GL WINDOW
		GLvoid Reshape(GLsizei width, GLsizei height)		    
		{
			// compute aspect ratio of the new window
			if (height == 0) 
			{
				height = 1; // To prevent divide by 0
			}

			// set the viewport to cover the new window
			glViewport(0, 0, width, height);
			
			// set the orthosphere and keep center of the screen
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluOrtho2D((GLdouble)-width / 2.0, (GLdouble)width / 2.0, (GLdouble)-height / 4.0, (GLdouble)height + 100);

		}
	};
}