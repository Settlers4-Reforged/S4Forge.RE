#ifndef CGRABBER_H
#define CGRABBER_H

class CGrabber {
public:
    // address=[0x14944f0]
    static void __cdecl DoGrab(std::wstring);

    // address=[0x14947b0]
    static void * __cdecl GetScreenBits(void *,void *,int *,int *,int,bool);

};


#endif // CGRABBER_H
