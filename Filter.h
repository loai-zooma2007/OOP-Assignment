#ifndef FILTER_H
#define FILTER_H
#include "Image_Class.h"

/*1*/void GrayScale(Image &image);
/*2*/void Black_White(Image &image);
/*3*/void Invert(Image &image);
/*4*/void Fram(Image &image,int type,int Option,double thickness);
/*5*/void Flip(Image &image,int type);
/*6*/void Rotate(Image &image,int angle);
/*7*/void Darken_Lighten(Image &image,float percent,int type);
/*8*/void Resize(Image &image,int NewX,int NewY);
/*9*/void Merge(Image &first,Image &second);
/*10*/void DetectEdges(Image &image);
/*11*/void Crop(Image &image,int NewWidth,int NewHeight,int x,int y);
/*12*/void Blur(Image &image,int radius);
/*13*/void Sunlight(Image &image,float intensity);
/*14*/void DenDenMushi(Image &image);
/*15*/void PurpleNight(Image &image);
/*16*/void Infrared(Image &image);
/*17*/void Skew(Image &image,float angleDgrs);
/*18*/void OilPaint(Image &image,int radius);

#endif // FILTER_H
