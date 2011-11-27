#pragma warning(push)
#pragma warning(disable:4819)
#include <boost/gil/gil_all.hpp>
#include <boost/gil/extension/io/png_dynamic_io.hpp>
#include <boost/gil/extension/io/jpeg_dynamic_io.hpp>
#pragma warning(pop)
using namespace boost::gil;
int main()
{
    rgb8_image_t img(512, 512);
    rgb8_pixel_t red(255, 0, 0);
    fill_pixels(view(img), red);
    jpeg_write_view("redsquare.png", const_view(img));
    return 0;
}
