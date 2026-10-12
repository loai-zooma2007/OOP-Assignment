#include"Filter.h"
#include<algorithm>
#include<cmath>

//filter(1):
void GrayScale(Image &image)
{
    for (int y = 0; y < image.height; y++)
    {
        for (int x = 0; x < image.width; x++)
        {
            unsigned int avg = (image(x, y, 0) + image(x, y, 1) + image(x, y, 2)) / 3;
            image(x, y, 0) = avg;
            image(x, y, 1) = avg;
            image(x, y, 2) = avg;
        }
    }
}

//filter(2):
void Black_White(Image &image)
{
    unsigned int _colorAvg=255/2;
    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            unsigned int avg = 0;
            for (int k = 0; k < 3; k++)
                avg += image(i, j, k);

            avg /= 3;
            for (int k = 0; k < 3; k++)
            {
                if (avg > _colorAvg)
                    image(i, j, k) = 255;
                else
                    image(i, j, k) = 0;
            }
        }
    }
}

//filter(3):
void Invert(Image &image)
{
    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            for (int k = 0; k < image.channels; k++)
            {
                image(i, j, k) = 255 - image(i, j, k);
            }
        }
    }
}

//filter(4):
void Fram(Image &image,int type,int Option,double thickness)
{
    unsigned int color0[3]{0},color1[3]{0},color2[3]{0};

    //simple fram
    if(type==1)
    {
        if(Option==1){color0[0]=255;color0[1]=0;color0[2]=0;}

        else if(Option==2){color0[0]=0;color0[1]=255;color0[2]=0;}

        else if(Option==3){color0[0]=0;color0[1]=0;color0[2]=255;}

        else if(Option==4){color0[0]=255;color0[1]=255;color0[2]=255;}

        else if(Option==5){color0[0]=0;color0[1]=0;color0[2]=0;}

        for (int i = 0; i < image.width; i++)
        {
            for (int j = 0; j < image.height; j++)
            {
                if (i > image.width - thickness || i < thickness ||
                    j > image.height - thickness || j < thickness)
                {image(i,j,0)=color0[0];image(i,j,1)=color0[1];
                 image(i,j,2)=color0[2];}

            }
        }
    }

    //decorated fram
    else if(type==2)
    {   if(Option==1){color0[0]=255;color0[1]=0;color0[2]=0;
                      color1[0]=255;color1[1]=255;color1[2]=255;
                      color2[0]=255;color2[1]=0;color2[2]=0;}

        else if(Option==2){color0[0]=255;color0[1]=0;color0[2]=0;
                           color1[0]=0;color1[1]=0;color1[2]=0;
                           color2[0]=255;color2[1]=0;color2[2]=0;}

        else if(Option==3){color0[0]=0;color0[1]=255;color0[2]=0;
                           color1[0]=255;color1[1]=255;color1[2]=255;
                           color2[0]=0;color2[1]=255;color2[2]=0;}

        else if(Option==4){color0[0]=0;color0[1]=255;color0[2]=0;
                           color1[0]=0;color1[1]=0;color1[2]=0;
                           color2[0]=0;color2[1]=255;color2[2]=0;}

        else if(Option==5){color0[0]=0;color0[1]=0;color0[2]=255;
                           color1[0]=255;color1[1]=255;color1[2]=255;
                           color2[0]=0;color2[1]=0;color2[2]=255;}

        else if(Option==6){color0[0]=0;color0[1]=0;color0[2]=255;
                           color1[0]=0;color1[1]=0;color1[2]=0;
                           color2[0]=0;color2[1]=0;color2[2]=255;}

        else if(Option==7){color0[0]=0;color0[1]=0;color0[2]=0;
                           color1[0]=255;color1[1]=255;color1[2]=255;
                           color2[0]=0;color2[1]=0;color2[2]=0;}

        else if(Option==8){color0[0]=255;color0[1]=255;color0[2]=255;
                           color1[0]=0;color1[1]=0;color1[2]=0;
                           color2[0]=255;color2[1]=255;color2[2]=255;}

        for (int i = 0; i < image.width; i++)
        {
            for (int j = 0; j < image.height; j++)
            {
                if (i > image.width - thickness || i < thickness ||
                    j > image.height - thickness || j < thickness)
                {image(i,j,0)=color0[0];image(i,j,1)=color0[1];
                    image(i,j,2)=color0[2];}

                if (i > image.width - (thickness/1.5) || i < (thickness/1.5) ||
                    j > image.height - (thickness/1.5) || j < (thickness/1.5))
                {image(i,j,0)=color1[0];image(i,j,1)=color1[1];
                    image(i,j,2)=color1[2];}

                if (i > image.width - (thickness/3) || i < (thickness/3) ||
                    j > image.height - (thickness/3) || j < (thickness/3))
                {image(i,j,0)=color2[0];image(i,j,1)=color2[1];
                    image(i,j,2)=color2[2];}

            }
        }
    }
}

//filter(5):
void Flip(Image &image,int type)
{
    if(type==1)
    {
        for (int x = 0; x < image.width / 2; x++)
        {
            for (int y = 0; y < image.height; y++)
            {
                for (int c = 0; c < 3; c++)
                {
                    std::swap(image(x, y, c), image(image.width - 1 - x, y, c));
                }
            }
        }
    }
    else if(type==2)
    {
        for (int x = 0; x < image.width; x++)
        {
            for (int y = 0; y < image.height / 2; y++)
            {
                for (int c = 0; c < 3; c++)
                {
                    std::swap(image(x, y, c), image(x, image.height - 1 - y, c));
                }
            }
        }
    }
}

//filter(6):
Image _90rotated(const Image &image)
{
    Image rotatedImg(image.height, image.width);

    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            for (int k = 0; k < image.channels; k++)
            {
                rotatedImg(image.height - 1 - j, i, k) = image(i, j, k);
            }
        }
    }
    return rotatedImg;
}
void Rotate(Image &image,int angle)
{
    switch (angle)
    {
        case 90:
        {
            image = _90rotated(image);
            break;
        }
        case 180:
        {
            image = _90rotated(_90rotated(image));
            break;
        }
        case 270:
        {

            image = _90rotated(_90rotated(_90rotated(image)));
            break;
        }
    }
}

//filter(7):
void Darken_Lighten(Image &image,float percent,int type)
{
    percent = percent / 100.0f;

    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            for (int k = 0; k < image.channels; k++)
            {
                int cur = image(i, j, k);
                if (type == 1)
                {
                    cur = cur - cur * percent;
                }
                else
                {
                    cur = cur + (255 - cur) * percent;
                }
                if (cur > 255)
                    cur = 255;
                if (cur < 0)
                    cur = 0;
                image(i, j, k) = cur;
            }
        }
    }
}

//filter(8):
void Resize(Image &image,int NewX,int NewY)
{
    Image ReSize(NewX, NewY);
    double OldX = image.width;
    double OldY = image.height;
    double x = OldX / NewX;
    double y = OldY / NewY;

    for (int i = 0; i < NewX; i++)
    {
        for (int j = 0; j < NewY; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                ReSize(i, j, k) = image(int(i*x), int(j*y), k);
            }
        }
    }

    image = ReSize;
}

//filter(9):
void Merge(Image &first,Image &second)
{
    int width = std::min(first.width,second.width);
    int height = std::min(first.height,second.height);
    Image image(width,height);
    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                image(i,j,k)=(first(i,j,k)+second(i,j,k))/2;
            }
        }
    }
    first = image;
}

//filter(10):
void DetectEdges(Image &image)
{
    GrayScale(image);

    Image edgesImage(image.width, image.height);
    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                unsigned int avg = 0;
                int repeat = 0;

                for (int x = -1; x <= 1; x++)
                {
                    for (int y = -1; y <= 1; y++)
                    {
                        int newX = i + x;
                        int newY = j + y;
                        if (newX > 0 && newX < image.width
                            && newY > 0 && newY < image.height)
                        {
                            avg += image(newX, newY, k);
                            repeat++;
                        }
                    }
                }

                avg /= repeat;
                int ABS=image(i, j, k) - avg;

                int difference = std::abs(ABS);
                if (difference > 15)
                {
                    edgesImage(i, j, k) = 0;
                }
                else
                {
                    edgesImage(i, j, k) = 255;
                }
            }
        }
    }

    image = edgesImage;
}

//filter(11):
void Crop(Image &image,int NewWidth,int NewHeight,int x,int y)
{
    if( x<0 || y<0 || NewWidth<=0 || NewHeight<=0 || x+NewWidth > image.width || y+NewHeight > image.height )return;
    Image newimage(NewWidth,NewHeight);

    for (int i = 0; i < NewWidth; i++)
    {
        for (int j = 0; j < NewHeight; j++)
        {
            for (int k = 0; k < image.channels; k++)
            {
                newimage(i,j,k) = image(i+x,j+y,k);

            }
        }
    }

    image=newimage;
}

//filter(12):
void Blur(Image &image,int radius)
{
    Image blurImage(image.width, image.height);
    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                int avg = 0;
                int repeat = 0;

                for (int x = -radius; x <= radius; x++)
                {
                    for (int y = -radius; y <= radius; y++)
                    {
                        int newX = i + x;
                        int newY = j + y;
                        if (newX >= 0 && newX < image.width && newY >= 0 && newY < image.height)
                        {
                            avg += image(newX, newY, k);
                            repeat++;
                        }
                    }
                }
                if(repeat>0)
                blurImage(i, j, k) = avg / repeat;
            }
        }
    }

    image = blurImage;
}

//filter(13):
void Sunlight(Image &image,float intensity)
{
    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                int _pixel = image(i,j,k);
                if(k==0)
                    _pixel += 30*intensity;
                else if(k==1)
                    _pixel += 20*intensity;
                else
                    _pixel += 10*intensity;
                if(_pixel>255)
                    _pixel=255;

                image(i,j,k)= _pixel;
            }
        }
    }
}

//filter(14):
void DenDenMushi(Image &image)
{
    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; 4 * j < image.height; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                image(i, 4 * j, k) *= 0.25;
            }
        }
    }
}

//filter(15):
void PurpleNight(Image &image)
{
    int x[3]={50,-40,60};
    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                int res=image(i,j,k)+x[k];
                if(res>255)
                    res=255;
                if(res<0)
                    res=0;
                image(i,j,k) = res;
            }
        }
    }
}

//filter(16):
void Infrared(Image &image)
{
    Image IR(image.width, image.height);

    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            IR(i, j, 0) = 255;
            IR(i, j, 1) = 255-image(i, j, 0);
            IR(i, j, 2) = 255-image(i, j, 0);
        }
    }

    image=IR;
}

//filter(17):
void Skew(Image &image,float angleDgrs)
{
    float angleRad = angleDgrs*M_PI/180.0f;
    float tanAngle =tan(angleRad);
    int shiftMax =(int)std::fabs(image.height*tanAngle);
    int newWidth = image.width+shiftMax;
    int newHeight = image.height;
    int baseShift = (tanAngle<0)?shiftMax:0;
    Image SkewImage(newWidth,newHeight);

    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            for (int k = 0; k < image.channels; k++)
            {
                SkewImage(i,j,k)=255;
            }
        }
    }

    for (int j = 0; j < image.height; j++)
    {
        for (int i = 0; i < image.width; i++)
        {
            int shift =(int)(j*tanAngle)+baseShift ;
            int NewI=i+shift;
            if(NewI>=0&&NewI<newWidth)
            {
                for (int k = 0; k < image.channels; k++)
                {
                    SkewImage(NewI,j,k)=image(i,j,k);
                }
            }
        }
    }

    image=SkewImage;
}

//filter(18):
void OilPaint(Image &image,int radius)
{
    if(radius<0)return;

    Image newImage(image.width,image.height);
    int numLevels = 20;

    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            int levelCount[256] = {0};
            int sumR[256] = {0}, sumG[256] = {0}, sumB[256] = {0};

            for (int dx = -radius; dx <= radius; dx++) {
                for (int dy = -radius; dy <= radius; dy++) {
                    int nx = i + dx;
                    int ny = j + dy;

                    if (nx >= 0 && nx < image.width && ny >= 0 && ny < image.height) {
                        int r = image(nx, ny, 0);
                        int g = image(nx, ny, 1);
                        int b = image(nx, ny, 2);

                        int intensity = (r + g + b) / 3;
                        int level = (intensity * numLevels) / 256;

                        if(level>=numLevels)level=numLevels-1;

                        levelCount[level]++;
                        sumR[level] += r;
                        sumG[level] += g;
                        sumB[level] += b;
                    }
                }
            }

            int maxLevel = 0, maxCount = 0;
            for (int l = 0; l < numLevels; l++) {
                if (levelCount[l] > maxCount) {
                    maxCount = levelCount[l];
                    maxLevel = l;
                }
            }
            if(maxCount>0)
            {
                newImage(i, j, 0) = sumR[maxLevel] / maxCount;
                newImage(i, j, 1) = sumG[maxLevel] / maxCount;
                newImage(i, j, 2) = sumB[maxLevel] / maxCount;
            }
        }
    }

    image = newImage;
}
