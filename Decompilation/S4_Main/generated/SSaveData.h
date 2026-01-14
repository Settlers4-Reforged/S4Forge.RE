#ifndef _SSAVEDATA_H
#define _SSAVEDATA_H

namespace  {

class SSaveData {
public:
    // address=[0x16a7170]
    bool  TSparseMap<unsigned char>IsBufferEnd(void)const;

    // address=[0x16a7850]
    void  TSparseMap<unsigned char>SetAsBufferEnd(void);

};

} // namespace 

#endif // _SSAVEDATA_H
