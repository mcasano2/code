//============================================================
//   file: scene.cpp
//   description: Scene class source file
//   date: 13 Feb 2011
//   MP2
//============================================================

#include <iostream>
#include "scene.h"

using namespace std;

// Scene constructor, creates an array of image pointers,
// an array for x coordinates, an array for y coordinates
// input max signifies size of array

Scene::Scene(int max)

{
   maxval=max;          
  
   imageArray = new Image*[maxval];  // dynamically allocate array of Image*
   xArray = new int[maxval];
   yArray = new int[maxval];

   for(int i=0; i<maxval; i++)     // runs through array
   {
      imageArray[i] = NULL;        // NULL signifies there is no image
   }

}

// Scene deconstructor, frees memory

Scene::~Scene()
{

   for (int i=0; i<maxval; i++)
   {

      delete imageArray[i]; // deletes memory allocated for Image
      imageArray[i] = NULL; 
   }

   delete[] imageArray;   // deletes arrays
   delete[] xArray;
   delete[] yArray;

}

// Copy Constructor for Scene, makes independent copy of 
// Scene located at memory address 'source'


Scene::Scene(Scene const & source)
{
   maxval=source.maxval;              // gets array size from source

   imageArray = new Image*[maxval];   // allocate memory for arrays
   xArray = new int[maxval];
   yArray = new int[maxval];

  
   for(int i=0; i<maxval; i++)        // initializes array
   {
      imageArray[i] = NULL;
   }

   for(int i=0; i<maxval; i++)
   {
      if (source.imageArray[i] != NULL)    // only allocates new memory if
      {                                    // index has no image (NULL)
         imageArray[i]=new Image;
         *(imageArray[i])=*(source.imageArray[i]); // copies image
         xArray[i]=source.xArray[i];               // copies x,y coord
         yArray[i]=source.yArray[i];
       
      }                         // end of if statement
   }                            // end of for loop

}

// Scene assignment operator makes independent copy
// of scene located at memory addr source

Scene const & Scene::operator=(Scene const & source) 
{

   if (this != &source)            // check for self assignment
   {

      for (int i=0; i<maxval; i++)    // frees memory associated with array
      {
         if (imageArray[i] != NULL)
         {
            delete imageArray[i]; 
            imageArray[i] = NULL;
         }

      }
   
      delete[] imageArray;   // deletes original arrays
      delete[] xArray;
      delete[] yArray;

      maxval=source.maxval;

      imageArray = new Image*[maxval];
      xArray = new int[maxval];
      yArray = new int[maxval];

      for(int i=0; i<maxval; i++)
      {
         if (source.imageArray[i] != NULL)    // only copies if nonempty
         {
            imageArray[i]=new Image;
            *(imageArray[i])=*(source.imageArray[i]);
            xArray[i]=source.xArray[i];
            yArray[i]=source.yArray[i];
         }  
      }     // ends for loop

   }        // ends if

   return *this;  // returns current Scene, goes straight here when if is false
}  

// This function adds a picture to the array
// FileName contains a string of the file name to load
// index is the index in the array to be accessed
// x and y are the x and y coordinates

void Scene::addpicture(const char* FileName, int index, int x, int y)
{

   if ( (index>=0) and (index<maxval) )   // error checking
   {
      if (imageArray[index] == NULL )
      {  
          imageArray[index]= new Image;  // allocates memory
      }
      else
      {
         delete imageArray[index];
         imageArray[index]= new Image; 
      }
   
      imageArray[index]->ReadFromFile(FileName);
      xArray[index]=x;
      yArray[index]=y;
   }
   else
   {
     cout << "index out of bounds" << endl;
   }

}

// This function changes the size of the array
// newmax indicates the newsize

void Scene::changemaxlayers(int newmax)
{

  if (newmax<maxval)                   // error handling
  { 
     for(int i=newmax; i<maxval; i++)
     {
        if (imageArray[i] != NULL)
        {
           cout << "invalid newmax" << endl;
           return;
        }        
     }
  }

   Image * *   imageArraytemp=new Image*[newmax];  // temp arrays to copy current one
   int*   xArraytemp = new int[newmax];
   int*   yArraytemp = new int[newmax];

   for(int i=0; i<maxval; i++)                 // copies current into temp arrays
   {
      if (imageArray[i]== NULL)
      {
          imageArraytemp[i]= NULL;
      }
      else
      {
          imageArraytemp[i]=imageArray[i];
          xArraytemp[i]=xArray[i];
          yArraytemp[i]=yArray[i];
      }

   }

// delete original imageArray
   for (int i=0; i<maxval; i++)
   {
      imageArray[i] = NULL;
   }

   delete[] imageArray;
   delete[] xArray;
   delete[] yArray;

// make new ImageArray
   maxval=newmax;
   imageArray=new Image*[newmax];
   xArray = new int[newmax];
   yArray = new int[newmax];

   for(int i=0; i<newmax; i++)
   {
      imageArray[i]=imageArraytemp[i];
      xArray[i]=xArraytemp[i];
      yArray[i]=yArraytemp[i];
   }

// delete imageArraytemp

     for (int i=0; i<newmax; i++)
   {
      imageArraytemp[i] = NULL;

   }

   delete[] imageArraytemp;   
   delete[] xArraytemp;
   delete[] yArraytemp;
   return;
  
}

// This function changes the index of a picture
// index is the current image and newindex is the target index
void Scene::changelayer(int index, int newindex)
{
   if ( (index >= 0) and ( newindex >= 0) and ( index<maxval) and (newindex<maxval) )
   {
      if (index==newindex)
      {
         return;    // leaves function if indexes are the same
      }
      
      imageArray[newindex] =  imageArray[index];
      xArray[newindex] =  xArray[index];
      yArray[newindex] =  yArray[index];
      imageArray[index]= NULL;
   }
   else
   {
      cout << "invalid index" << endl;   // error message for wrong index
   }

}

// This function assigns given x and y coordinates to
// a given index

void Scene::translate(int index, int xcoord, int ycoord)
{
   if ( (index>=0) and (index< maxval) and (imageArray[index] != NULL) )
   {
      xArray[index]=xcoord;
      yArray[index]=ycoord;
   }
   else
   {
      cout << "invalid index" << endl;
   }

}

// This function removes a picture from given index

void Scene::deletepicture(int index)
{
     if ( (index>=0) and (index< maxval) and (imageArray[index] != NULL) ) 
     {
       delete imageArray[index];
       imageArray[index]= NULL;     
     }
     else
     {
       cout << "invalid index" << endl;   // for out of bounds index
     }

}

// This function returns a pointer to an image at a given index

Image* Scene::getpicture(int index) const
{
   if ( (index>=0) and (index< maxval) )
   {
      return imageArray[index];
   }
   else
   {
      cout << "invalid index" << endl;
      return NULL;
   }

}

// Draws images from 0 to max-1 in order
// overwriting any previous images
// returns that Image

Image Scene::drawscene() const
{
   int finalwidth;  // final width of scene
   int finalheight; // final height of scene
   int calc;        // variable for calculations
   int imageheight; // variable for a single image height
   int imagewidth;  // variable for a single image width

   finalwidth=1;
   finalheight=1;

// determine max width and height

   for(int i=0; i<maxval; i++)
   {
      if (imageArray[i] != NULL)
      {
         calc = imageArray[i]->TellWidth() + xArray[i];
         if (finalwidth<calc)
         {
            finalwidth=calc;
         }
         calc = imageArray[i]->TellHeight() + yArray[i];
         if (finalheight<calc)
         {
            finalheight=calc;
         }
      }
   }

   Image drawn;   // Image for complete scene
   drawn.SetSize(finalwidth, finalheight);

   for(int z=0; z<maxval; z++)
   {
      if (imageArray[z] != NULL)   // skips if no image at index
      {
         imagewidth= imageArray[z]->TellWidth();
         imageheight= imageArray[z]->TellHeight();

         for (int j=0; j<imageheight; j++)
         {
            for (int i = 0; i<imagewidth; i++)
            {
           // gets RGB values
               int red = imageArray[z]->operator()(i, j)->Red; 
               int green = imageArray[z]->operator()(i, j)->Green;
               int blue = imageArray[z]->operator()(i, j)->Blue;
           // adds x,y coordinates to i,j coordinate
               drawn(i + xArray[z], j + yArray[z])->Red = red;
               drawn(i + xArray[z], j + yArray[z])->Green = green;
               drawn(i + xArray[z], j + yArray[z])->Blue = blue;
            }               // closes inner for loop
         }                  // closes outer for loop
      }                     // closes if statement

   }   // closes for loop for array index

return drawn;   // returns image

}
