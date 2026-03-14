#ifndef DEFINE_TRANSFORMER_H
#define DEFINE_TRANSFORMER_H

struct SConfigTypeString {
  int         id;
  const char *name;
};

#define TO_PAIR(id, name) SConfigTypeString{id, name}

#define TO_ENUM(id, name) name = id,

#endif // DEFINE_TRANSFORMER_H
