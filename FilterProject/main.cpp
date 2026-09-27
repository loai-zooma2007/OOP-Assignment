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
         << " filter(3)::              filter(4):: \n"
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