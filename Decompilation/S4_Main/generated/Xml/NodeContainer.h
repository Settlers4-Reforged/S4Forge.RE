#ifndef ADVXMLPARSER_NODECONTAINER_H
#define ADVXMLPARSER_NODECONTAINER_H

#include "defines.h"

namespace AdvXMLParser {

class NodeContainer {
public:
    // address=[0x14f3c60]
    struct AdvXMLParser::Node::ConstIteratorRef  Begin(void a2)const;

    // address=[0x14f3d40]
    struct AdvXMLParser::Node::ConstIteratorRef  End(void a2)const;

    // address=[0x2f13750]
     NodeContainer(class AdvXMLParser::NodeContainer & a2, std::string const & a3);

    // address=[0x2f13790]
    virtual  ~NodeContainer(void);

    // address=[0x2f13870]
    bool  IsEmpty(void)const;

    // address=[0x2f13890]
    void  AddText(std::string const & a2);

    // address=[0x2f13940]
    void  AddText(class AdvXMLParser::Bookmark & a2, int a3);

    // address=[0x2f139d0]
    void  DeleteChildren(void);

    // address=[0x2f13ac0]
    void  DeleteChild(class AdvXMLParser::Node const & a2);

protected:
    // address=[0x2f13b90]
    class AdvXMLParser::Node &  GetChild(int a2)const;

    // address=[0x2f13bd0]
    class AdvXMLParser::Node &  GetChild(int a2, int a3)const;

    // address=[0x2f13cd0]
    class AdvXMLParser::Node &  GetChild(char const * a2, int a3, int a4)const;

    // address=[0x2f13de0]
    void  Add(class AdvXMLParser::Node * a2);

    // address=[0x2f13e50]
    void  InsertBefore(class AdvXMLParser::Node const & a2, class AdvXMLParser::Node * a3);

    // address=[0x2f13f40]
    void  InsertAfter(class AdvXMLParser::Node const & a2, class AdvXMLParser::Node * a3);

    // address=[0x2f140d0]
    void  CloneChildren(class AdvXMLParser::NodeContainer & a2)const;

    // address=[0x2f141a0]
    void  DeleteChild(class std::_Vector_iterator<class std::_Vector_val<struct std::_Simple_types<class AdvXMLParser::Node *> > > a2);

    // address=[0x2f142f0]
    bool  FindChild(int a2, class std::_Vector_iterator<class std::_Vector_val<struct std::_Simple_types<class AdvXMLParser::Node *> > > & a3)const;

    // address=[0x2f143b0]
    bool  FindChild(char const * Str, class std::_Vector_iterator<class std::_Vector_val<struct std::_Simple_types<class AdvXMLParser::Node *> > > & a3)const;

    // address=[0x2f14470]
    bool  FindChild(char const * Str, int a3, class std::_Vector_iterator<class std::_Vector_val<struct std::_Simple_types<class AdvXMLParser::Node *> > > & a4)const;

    // address=[0x2f14550]
    bool  FindChild(class AdvXMLParser::Node const & a2, class std::_Vector_iterator<class std::_Vector_val<struct std::_Simple_types<class AdvXMLParser::Node *> > > & a3)const;

    // address=[0x2f145f0]
    bool  FindChild(int a2, class std::_Vector_const_iterator<class std::_Vector_val<struct std::_Simple_types<class AdvXMLParser::Node *> > > & a3)const;

    // address=[0x2f146b0]
    bool  FindChild(char const * Str, class std::_Vector_const_iterator<class std::_Vector_val<struct std::_Simple_types<class AdvXMLParser::Node *> > > & a3)const;

    // address=[0x2f14770]
    bool  FindChild(char const * Str, int a3, class std::_Vector_const_iterator<class std::_Vector_val<struct std::_Simple_types<class AdvXMLParser::Node *> > > & a4)const;

    // address=[0x2f14850]
    bool  FindChild(class AdvXMLParser::Node const & a2, class std::_Vector_const_iterator<class std::_Vector_val<struct std::_Simple_types<class AdvXMLParser::Node *> > > & a3)const;

    // address=[0x2f2ce60]
    virtual void  GenerateXML(class AdvXMLParser::GenerateContext & a2)const;

};

} // namespace AdvXMLParser

#endif // ADVXMLPARSER_NODECONTAINER_H
