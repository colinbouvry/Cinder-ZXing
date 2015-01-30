// Cinder ZXing Block
//
// Copyright (c) 2012, Dawid Górny dawidgorny.com
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
//
// This code is intended to be used with the Cinder C++ library, http://libcinder.org

#pragma once

#include <zxing/LuminanceSource.h>
#include "cinder/Surface.h"

namespace zxing {
    
    class SurfaceBitmapSource : public LuminanceSource {
    private:
        ci::Surface image_;
        int width;
        int height;
        const unsigned char* pixel_cache;
        
    public:
        SurfaceBitmapSource(ci::Surface& image);
        SurfaceBitmapSource(const unsigned char **pixels, int _width, int _height);
        
		SurfaceBitmapSource();
        
        int getWidth() const;
        int getHeight() const;
        ArrayRef<char> getRow(int y, ArrayRef<char> row) const;
        ArrayRef<char> getMatrix() const ;

        bool isRotateSupported() const;
        Ref<LuminanceSource> rotateCounterClockwise();
    };
    
}
