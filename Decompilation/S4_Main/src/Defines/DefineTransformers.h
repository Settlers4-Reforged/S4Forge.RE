#ifndef DEFINE_TRANSFORMER_H
#define DEFINE_TRANSFORMER_H

// struct SConfigTypeString {
//   int         id;
//   const char *name;
// };
struct SConfigTypeString {
    int         m_iId;
    char const *m_spName;
};

#define TO_PAIR(id, name) SConfigTypeString{id, #name},
/*
#define X TO_PAIR
SConfigTypeString s_s[] = {

};
#undef X
*/

#define TO_ENUM(id, name) name = id,

#endif // DEFINE_TRANSFORMER_H
