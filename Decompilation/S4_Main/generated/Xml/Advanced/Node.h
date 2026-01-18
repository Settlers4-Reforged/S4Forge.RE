#ifndef ADVXMLPARSER_NODE_H
#define ADVXMLPARSER_NODE_H

#include "defines.h"

namespace AdvXMLParser {

class Node {
public:
    // address=[0x14f3f10]
    std::string const &  GetName(void)const;

    // address=[0x14f3f90]
    bool  IsNull(void)const;

    // address=[0x2f13420]
     Node(class AdvXMLParser::NodeContainer & a2, std::string const & a3);

    // address=[0x2f13460]
    virtual  ~Node(void);

    // address=[0x2f13480]
    void  Delete(void);

    // address=[0x2f134a0]
    virtual bool  IsKindOf(int a2)const;

    // address=[0x2f1e510]
    class AdvXMLParser::NodeContainer &  GetParent(void)const;

    // address=[0x3e2d2a8]
    static class AdvXMLParser::NodeContainer & null;

    // Type information members
private:
    struct NodeVtbl * lpVtbl;

};

} // namespace AdvXMLParser

#endif // ADVXMLPARSER_NODE_H
