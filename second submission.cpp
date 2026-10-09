#include <iostream>
#include "Image_Class.h"
void Crop(Image& image) {
    int x,y,W,H;
    std::cout << "Pls enter the starting point X and Y in order: " << std::endl;
    std::cin >> x >> y ;
    std::cout << "Pls enter the width and height in order: " << std::endl;
    std::cin >> W >> H;
    Image newimage(W,H);
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++) {
            for (int k = 0; k < image.channels; k++) {
                newimage(i,j,k) = image(i+x,j+y,k);

            }
        }
    }
    //------------------delete or cut this part when will you build the menu-------------------
    std::cout << "Pls enter name : " << std::endl;
    std::string filename;
    std::cin >> filename;
    newimage.saveImage(filename);
}
void purple(Image& image) {
    int x[3]={50,-40,60};
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < image.channels; k++) {
                int res=image(i,j,k)+x[k];
                if(res>255)
                    res=255;
                if(res<0)
                    res=0;
                image(i,j,k) = res;
            }
        }
    }
    //-------------delete or cut this part when will you build the menu--------------
    std::cout << "Pls enter name : " << std::endl;
    std::string filename;
    std::cin >> filename;
    image.saveImage(filename);
}
int main() {
    std::string filename;
    std::cout << "Pls enter colored image name to crop:  " << std::endl;
    std::cin >> filename;
    Image image(filename);
    purple(image);
    return 0;
}