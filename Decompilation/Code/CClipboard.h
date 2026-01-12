#ifndef CCLIPBOARD_H
#define CCLIPBOARD_H

class CClipboard : public IClipboard {
public:
    // address=[0x147f5e0]
    virtual void  CopyTextToClipboard(char const *);

    // address=[0x147f690]
    virtual void  CopyTextToClipboard(std::string const &);

    // address=[0x147f6c0]
    virtual void  GetTextFromClipboard(std::string &,int);

    // address=[0x147f7f0]
     CClipboard(void);

};


#endif // CCLIPBOARD_H
