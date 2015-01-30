#include "SurfaceBitmapSource.h"

namespace zxing {
    
    SurfaceBitmapSource::SurfaceBitmapSource(ci::Surface& pixels) : image_(pixels), LuminanceSource(pixels.getWidth(), pixels.getHeight()) {
        width = pixels.getWidth();
        height = pixels.getHeight();
        pixel_cache = pixels.getData();
        
    }
    
    SurfaceBitmapSource::SurfaceBitmapSource(const unsigned char **pixels, int _width, int _height) {
        
        width = _width;
        height = _height;
        pixel_cache = *pixels;
    }
    
    SurfaceBitmapSource::SurfaceBitmapSource() {
        
    }
    
    int SurfaceBitmapSource::getWidth() const {
        return width;
    }
    
    int SurfaceBitmapSource::getHeight() const {
        return height;
    }
    
    ArrayRef<char> SurfaceBitmapSource::getRow(int y, ArrayRef<char> row) const {
        if (row == NULL) {
            row = ArrayRef<char>(width);
        }
        for (int x = 0; x < width; x++) {
            const unsigned char* p = &pixel_cache[3 * (y * width + x)];
            row[x] = (unsigned char)((
                                      306 * (int)(*p++) +
                                      601 * (int)(*p++) +
                                      117 * (int)(*p++) + 0x200) >> 10);
        }
        return row;
        
    }
    
    ArrayRef<char> SurfaceBitmapSource::getMatrix() const {
        int width = getWidth();
        int height =  getHeight();
        ArrayRef<char> matrix = ArrayRef<char>(width*height);
        //ArrayRef<char> m = matrix;
        const unsigned char* p = pixel_cache;
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                matrix[y*width + x] = (unsigned char)((
                                     306 * (int)(*p++) +
                                     601 * (int)(*p++) +
                                     117 * (int)(*p++) + 0x200) >> 10);
                //m++;
            }
        }
        return matrix;
    }

    
    bool SurfaceBitmapSource::isRotateSupported() const {
        return false;
    }
    
    Ref<LuminanceSource> SurfaceBitmapSource::rotateCounterClockwise() {
        return Ref<SurfaceBitmapSource> (NULL);
    }
    
}