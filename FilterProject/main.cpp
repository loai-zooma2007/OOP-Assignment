#include <iostream>
using namespace std;
#include "image_class.h"

Image image;
string fileName;

void setImg()
{
    cout << "------------------------------------\nEnter image file name: ";
    cin >> fileName;
}
void getNwImg()
{
    cout << "------------------------------------\nPls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";

    string newFileName;
    cin >> newFileName;

    cout << ((image.saveImage(newFileName)) ? "\nsuccess save" : "\nfailure save") << endl;
}

void BlckWht_filter(const string &NmImg)
{
    unsigned int _colorRange = 255 / 2;
    unsigned int _channels = 3;
    image.loadNewImage(NmImg);

    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            unsigned int avg = 0;
            for (int k = 0; k < _channels; k++)
                avg += image(i, j, k);

            avg /= _channels;
            for (int k = 0; k < _channels; k++)
            {
                if (avg > _colorRange)
                    image(i, j, k) = 255;
                else
                    image(i, j, k) = 0;
            }
        }
    }
    getNwImg();
}

void frame(const string &NmImg){
    int chooseNum;
    int chooseNum001;
    int chooseNum002;
    double thickness;
    Image Photo(NmImg);
    // Image Photo("luffy.jpg");
    cout << "Choose 1 or 2:-\n";
    cout << "1- simple frame: \n";
    cout << "2- Decorated frame: \n";
    cin >> chooseNum;
    if (chooseNum == 1)
    {
        cout << "Choose 1, 2, 3, 4 or 5:-\n";
        cout << "1- Red simple frame: \n";
        cout << "2- Green simple frame: \n";
        cout << "3- Blue simple frame: \n";
        cout << "4- White simple frame: \n";
        cout << "5- Black simple frame: \n";
        cin >> chooseNum001;
        cout << "Enter the Thickness: ";
        cin >> thickness;
    }
    if (chooseNum == 2)
    {
        cout << "Choose 1, 2, 3, 4, 5, 6, 7 or 8:-\n";
        cout << "1- Red & White Decorated frame: \n";
        cout << "2- Red & Black Decorated frame: \n";
        cout << "3- Green & White Decorated frame: \n";
        cout << "4- Green & Black Decorated frame: \n";
        cout << "5- Blue & White Decorated frame: \n";
        cout << "6- Blue & Black Decorated frame: \n";
        cout << "7- Black & White Decorated frame: \n";
        cout << "8- White & Black Decorated frame: \n";
        cin >> chooseNum002;
        cout << "Enter the Thickness: ";
        cin >> thickness;
    }
    
    for (int i = 0; i < Photo.width; i++)
    {
        for (int j = 0; j < Photo.height; j++)
        {
            if (chooseNum == 1)
            {
                if (chooseNum001 == 1)
                {
                    if (i > Photo.width-thickness || i < thickness || 
                        j > Photo.height-thickness || j < thickness)
                    {
                        Photo(i, j, 0) = 255;
                        Photo(i, j, 1) = 0;
                        Photo(i, j, 2) = 0;
                    }
                }
                if (chooseNum001 == 2)
                {
                    if (i > Photo.width-thickness || i < thickness || 
                        j > Photo.height-thickness || j < thickness)
                    {
                        Photo(i, j, 0) = 0;
                        Photo(i, j, 1) = 255;
                        Photo(i, j, 2) = 0;
                    }
                }
                if (chooseNum001 == 3)
                {
                    if (i > Photo.width-thickness || i < thickness || 
                        j > Photo.height-thickness || j < thickness)
                    {
                        Photo(i, j, 0) = 0;
                        Photo(i, j, 1) = 0;
                        Photo(i, j, 2) = 255;
                    }
                }
                if (chooseNum001 == 4)
                {
                    if (i > Photo.width-thickness || i < thickness || 
                        j > Photo.height-thickness || j < thickness)
                    {
                        Photo(i, j, 0) = 255;
                        Photo(i, j, 1) = 255;
                        Photo(i, j, 2) = 255;
                    }
                }
                if (chooseNum001 == 5)
                {
                    if (i > Photo.width-thickness || i < thickness || 
                        j > Photo.height-thickness || j < thickness)
                        {
                        Photo(i, j, 0) = 0;
                        Photo(i, j, 1) = 0;
                        Photo(i, j, 2) = 0;
                    }
                }
            }
            if (chooseNum == 2)
            {
                if (chooseNum002 == 1)
                {
                    if (i > Photo.width-thickness || i < thickness || 
                        j > Photo.height-thickness || j < thickness)
                    {
                        Photo(i, j, 0) = 255;
                        Photo(i, j, 1) = 0;
                        Photo(i, j, 2) = 0;
                    }
                    if (i > Photo.width-(thickness/1.5) || i < (thickness/1.5) || 
                    j > Photo.height-(thickness/1.5) || j < (thickness/1.5))
                    {
                        Photo(i, j, 0) = 255;
                        Photo(i, j, 1) = 255;
                        Photo(i, j, 2) = 255;
                    }
                    if (i > Photo.width-(thickness/3) || i < (thickness/3) || 
                        j > Photo.height-(thickness/3) || j < (thickness/3))
                    {
                        Photo(i, j, 0) = 255;
                        Photo(i, j, 1) = 0;
                        Photo(i, j, 2) = 0;
                    }
                
                }
                if (chooseNum002 == 2)
                {
                    if (i > Photo.width-thickness || i < thickness || 
                        j > Photo.height-thickness || j < thickness)
                    {
                        Photo(i, j, 0) = 255;
                        Photo(i, j, 1) = 0;
                        Photo(i, j, 2) = 0;
                    }
                    if (i > Photo.width-(thickness/1.5) || i < (thickness/1.5) || 
                        j > Photo.height-(thickness/1.5) || j < (thickness/1.5))
                    {
                        Photo(i, j, 0) = 0;
                        Photo(i, j, 1) = 0;
                        Photo(i, j, 2) = 0;
                    }
                    if (i > Photo.width-(thickness/3) || i < (thickness/3) || 
                        j > Photo.height-(thickness/3) || j < (thickness/3))
                    {
                        Photo(i, j, 0) = 255;
                        Photo(i, j, 1) = 0;
                        Photo(i, j, 2) = 0;
                    }
                
                }
                if (chooseNum002 == 3)
                {
                    if (i > Photo.width-thickness || i < thickness || 
                        j > Photo.height-thickness || j < thickness)
                    {
                        Photo(i, j, 0) = 0;
                        Photo(i, j, 1) = 255;
                        Photo(i, j, 2) = 0;
                    }
                    if (i > Photo.width-(thickness/1.5) || i < (thickness/1.5) || 
                        j > Photo.height-(thickness/1.5) || j < (thickness/1.5))
                    {
                        Photo(i, j, 0) = 255;
                        Photo(i, j, 1) = 255;
                        Photo(i, j, 2) = 255;
                    }
                    if (i > Photo.width-(thickness/3) || i < (thickness/3) || 
                        j > Photo.height-(thickness/3) || j < (thickness/3))
                    {
                        Photo(i, j, 0) = 0;
                        Photo(i, j, 1) = 255;
                        Photo(i, j, 2) = 0;
                    }
                
                }
                if (chooseNum002 == 4)
                {
                    if (i > Photo.width-thickness || i < thickness || 
                        j > Photo.height-thickness || j < thickness)
                    {
                        Photo(i, j, 0) = 0;
                        Photo(i, j, 1) = 255;
                        Photo(i, j, 2) = 0;
                    }
                    if (i > Photo.width-(thickness/1.5) || i < (thickness/1.5) || 
                        j > Photo.height-(thickness/1.5) || j < (thickness/1.5))
                    {
                        Photo(i, j, 0) = 0;
                        Photo(i, j, 1) = 0;
                        Photo(i, j, 2) = 0;
                    }
                    if (i > Photo.width-(thickness/3) || i < (thickness/3) || 
                        j > Photo.height-(thickness/3) || j < (thickness/3))
                    {
                        Photo(i, j, 0) = 0;
                        Photo(i, j, 1) = 255;
                        Photo(i, j, 2) = 0;
                    }
                
                }
                if (chooseNum002 == 5)
                {
                    if (i > Photo.width-thickness || i < thickness || 
                        j > Photo.height-thickness || j < thickness)
                    {
                        Photo(i, j, 0) = 0;
                        Photo(i, j, 1) = 0;
                        Photo(i, j, 2) = 255;
                    }
                    if (i > Photo.width-(thickness/1.5) || i < (thickness/1.5) || 
                        j > Photo.height-(thickness/1.5) || j < (thickness/1.5))
                    {
                        Photo(i, j, 0) = 255;
                        Photo(i, j, 1) = 255;
                        Photo(i, j, 2) = 255;
                    }
                    if (i > Photo.width-(thickness/3) || i < (thickness/3) || 
                        j > Photo.height-(thickness/3) || j < (thickness/3))
                    {
                        Photo(i, j, 0) = 0;
                        Photo(i, j, 1) = 0;
                        Photo(i, j, 2) = 255;
                    }
                
                }
                if (chooseNum002 == 6)
                {
                    if (i > Photo.width-thickness || i < thickness || 
                        j > Photo.height-thickness || j < thickness)
                    {
                        Photo(i, j, 0) = 0;
                        Photo(i, j, 1) = 0;
                        Photo(i, j, 2) = 255;
                    }
                    if (i > Photo.width-(thickness/1.5) || i < (thickness/1.5) || 
                        j > Photo.height-(thickness/1.5) || j < (thickness/1.5))
                    {
                        Photo(i, j, 0) = 0;
                        Photo(i, j, 1) = 0;
                        Photo(i, j, 2) = 0;
                    }
                    if (i > Photo.width-(thickness/3) || i < (thickness/3) || 
                        j > Photo.height-(thickness/3) || j < (thickness/3))
                    {
                        Photo(i, j, 0) = 0;
                        Photo(i, j, 1) = 0;
                        Photo(i, j, 2) = 255;
                    }
                }
                if (chooseNum002 == 7)
                {
                    if (i > Photo.width-thickness || i < thickness || 
                        j > Photo.height-thickness || j < thickness)
                    {
                        Photo(i, j, 0) = 0;
                        Photo(i, j, 1) = 0;
                        Photo(i, j, 2) = 0;
                    }
                    if (i > Photo.width-(thickness/1.5) || i < (thickness/1.5) || 
                        j > Photo.height-(thickness/1.5) || j < (thickness/1.5))
                    {
                        Photo(i, j, 0) = 255;
                        Photo(i, j, 1) = 255;
                        Photo(i, j, 2) = 255;
                    }
                    if (i > Photo.width-(thickness/3) || i < (thickness/3) || 
                        j > Photo.height-(thickness/3) || j < (thickness/3))
                    {
                        Photo(i, j, 0) = 0;
                        Photo(i, j, 1) = 0;
                        Photo(i, j, 2) = 0;
                    }
                }
                if (chooseNum002 == 8)
                {
                    if (i > Photo.width-thickness || i < thickness || 
                        j > Photo.height-thickness || j < thickness)
                    {
                        Photo(i, j, 0) = 255;
                        Photo(i, j, 1) = 255;
                        Photo(i, j, 2) = 255;
                    }
                    if (i > Photo.width-(thickness/1.5) || i < (thickness/1.5) || 
                        j > Photo.height-(thickness/1.5) || j < (thickness/1.5))
                    {
                        Photo(i, j, 0) = 0;
                        Photo(i, j, 1) = 0;
                        Photo(i, j, 2) = 0;
                    }
                    if (i > Photo.width-(thickness/3) || i < (thickness/3) || 
                        j > Photo.height-(thickness/3) || j < (thickness/3))
                    {
                        Photo(i, j, 0) = 255;
                        Photo(i, j, 1) = 255;
                        Photo(i, j, 2) = 255;
                    }
                }
            }
        }
    }
    image = Photo;
    getNwImg();
    // Photo.saveImage("Luffy001.jpg");
    // cout << "Image Save Successfully\n";
    // cout << "Good DMMAH";
}

void Rtt_filter(const string &NmImg)
{
    image.loadNewImage(NmImg);
    cout << "Select rotationAngle (90,180,270)::";
    int angle;
    cin >> angle;
    switch (angle)
    {
    case 90:
    {
        Image _90rotatedImg(image.height, image.width);

        for (int i = 0; i < image.width; i++)
        {
            for (int j = 0; j < image.height; j++)
            {
                for (int k = 0; k < image.channels; k++)
                {
                    _90rotatedImg(image.height - 1 - j, i, k) = image(i, j, k);
                }
            }
        }

        image = _90rotatedImg;
        break;
    }
    case 180:
    {
        Image _180rotatedImg(image.width, image.height);

        for (int i = 0; i < image.width; i++)
        {
            for (int j = 0; j < image.height; j++)
            {
                for (int k = 0; k < image.channels; k++)
                {
                    _180rotatedImg(image.width - 1 - i, image.height - 1 - j, k) = image(i, j, k);
                }
            }
        }

        image = _180rotatedImg;
        break;
    }
    case 270:
    {
        Image _270rotatedImg(image.height, image.width);
        for (int i = 0; i < image.width; i++)
        {
            for (int j = 0; j < image.height; j++)
            {
                for (int k = 0; k < image.channels; k++)
                {
                    _270rotatedImg(j, image.width - 1 - i, k) = image(i, j, k);
                }
            }
        }

        image = _270rotatedImg;
        break;
    }
    default:
        cout << "Wrong angle" << endl;
        break;
    }

    getNwImg();
}
void Menu()
{
    cout << "Menu:\n filter(1)::              filter(2):: Black&White_Image\n"
         << " filter(3)::              filter(4):: Frame_Image\n"
         << " filter(5)::              filter(6):: Rotate_Image\n"
         << " filter(7)::              filter(8):: \n";
    cout << "Pls enter filter's number: ";
    char fltrNum;
    cin >> fltrNum;
    switch (fltrNum)
    {
    case '2':
        setImg();
        BlckWht_filter(fileName);
        break;
    case '4':
        setImg();
        frame(fileName);
        break;
    case '6':
        setImg();
        Rtt_filter(fileName);
        break;
    default:
        cout << "Wrong filter number!" << endl;
        break;
    }
}

int main()
{
    cout << "  =Wellcome in ImageProcessing APP=\n======================================\n";
    Menu();
    return 0;
}