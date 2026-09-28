#include <iostream>
#include "Image_Class.h"
void Invert(Image& image){
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < image.channels; k++) {
                image(i,j,k)=255-image(i,j,k);
            }
        }
    }
    //-------------delete or cut this part when will you build the menu--------------
    std::cout << "Pls enter name : " << std::endl;
    std::string filename;
    std::cin >> filename;
    image.saveImage(filename);
}
void Darkenandlighten(Image& image){
    std::cout << "1-Darker\n2-lighter"<<std::endl;
    int x;
    std::cin >> x;
    float percent;
    std::cout << "enter the percent:" << std::endl;
    std::cin >> percent;
    percent = percent / 100.0f;
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < image.channels; k++) {
                int cur=image(i,j,k);
                if (x==1) {
                    cur=cur-cur*percent;
                }
                else {
                    cur=cur+(255-cur)*percent;
                }
                if (cur>255) cur=255;
                if (cur<0) cur=0;
                image(i,j,k) = cur;
            }
        }
    }
    //------------------delete or cut this part when will you build the menu-------------------
    std::cout << "Pls enter name : " << std::endl;
    std::string filename;
    std::cin >> filename;
    image.saveImage(filename);
}
int main() {
    std::string filename;
    std::cout << "Pls enter colored image name to turn to gray scale: ";
    std::cin >> filename;
    Image image(filename);
    Darkenandlighten(image);
    return 0;
}