#ifndef DEFINE_TRANSFORMER_H
#define DEFINE_TRANSFORMER_H

struct DefinePair
{
  int id;
  const char *name;
};

#define TO_PAIR(id, name) DefinePair{id, name}



#endif // DEFINE_TRANSFORMER_H