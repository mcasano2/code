#include "EasyBMP.h"

// Sets up the output image
void setupOutput(BMP ** image, int w, int h);

// Returns my favorite color
RGBApixel * myFavoriteColor(int intensity);

int main()
{
    // Load in.bmp
    BMP * original = new BMP;


    original->ReadFromFile("in.bmp");
    int width  = original->TellWidth();
    int height = original->TellHeight();


    // Create out.bmp
    BMP * output;
    setupOutput(&output, width, height);    

    // Loud our favorite color to color the outline
    RGBApixel * myPixel = myFavoriteColor(192);

    // Go over the whole image, and if a pixel differs from that to its upper
    // left, color it my favorite color in the output
    for (int y = 1; y < height && y>0; y++)
    {
        for (int x = 1; x < width && x>0; x++)
        {
            // Calculate the pixel difference
            RGBApixel * prev = (*original)(x-1, y-1);
            RGBApixel * curr = (*original)(x  , y  );
            int diff = (curr->Red   - prev->Red  ) +
                       (curr->Green - prev->Green) +
                       (curr->Blue  - prev->Blue );

            // If the pixel is an edge pixel,
            // color the output pixel with my favorite color
            RGBApixel * currOutPixel = (*output)(x,y);
            if (diff > 100)
                *currOutPixel = *myPixel;
        }
    }
    
    // Save the output file
    output->WriteToFile("out.bmp");

    // Clean up memory
    delete output;
    delete original;
    delete myPixel;
}


// Sets up the output image
void setupOutput(BMP **  image, int w, int h)
{
    *image = new BMP;
    (*image)->SetSize(w, h);
}


// Returns my favorite color
RGBApixel * myFavoriteColor(int intensity)
{
    RGBApixel * color= new RGBApixel;
    (*color).Red   = 0;
    (*color).Green = intensity/2;
    (*color).Blue  = intensity;
    return color;
}

