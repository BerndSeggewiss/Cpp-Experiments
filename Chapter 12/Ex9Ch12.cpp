/*
* No. 9: Display an image on the screen, e.g., a photo of a bird. Label the image both with
* a title on the window and with a caption in the window.
*/

#include "..\..\..\OneDrive\Codesammlung\C++\Stroustr Prog - Principles and Practise Using C++\libs\Graph.h"  
#include "..\..\..\OneDrive\Codesammlung\C++\Stroustr Prog - Principles and Practise Using C++\libs\Simple_window.h"  

void add_image_with_caption(Simple_window& win, const string& filepath,
    Point img_pos, const string& caption_text,
    Point caption_pos)
{
    static Image img{ img_pos, filepath, Suffix::none };
    static Text caption{ caption_pos, caption_text };
    caption.set_font(Font::helvetica_bold);
    caption.set_font_size(20);
    win.attach(img);
    win.attach(caption);
}

int main()
{
    using namespace Graph_lib;
    Point top_left{ 500, 100 };
    Simple_window win{ top_left, 300, 300, "Photo of a cat" };
    add_image_with_caption(
        win,
        "C:\\Users\\Win11 Pro\\Downloads\\cat.jpg",
        Point{ 10, 10 },          // Bild links oben im Fenster
        "Small cat",
        Point{ 20, 40 }         // Caption oben links im Fenster
    );
    win.wait_for_button();
}