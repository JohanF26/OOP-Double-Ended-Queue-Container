
/*
 * Implement your functionality here without changing test.cpp
 */
#ifndef DEQUE_H
#define DEQUE_H

#define Deque_DEFINE(t)\
  struct Deque_##t##_Iterator;\
  struct Deque_##t{\
    /*Need to use dynamic array since we don't know the size*/\
    t* data;\
    int elems;\
    int maxElems;\
    /* = malloc(strlen("Deque_") + strlen(t) - 1);*/\
    char type_name[sizeof("Deque_")+sizeof(#t)-1] = "Deque_" #t;\
    /*indexes of first and last elements*/\
    int first;\
    int last;\
\
    /*Functions*/\
    size_t (*size)(Deque_##t *);\
    bool (*empty)(Deque_##t *);\
    bool (*less_by)(const t &elem1, const t &elem2);\
\
    /*Push-pop*/\
    void (*push_back)(Deque_##t *, t);\
    void (*push_front)(Deque_##t *, t);\
    t& (*pop_back)(Deque_##t *);\
    t& (*pop_front)(Deque_##t *);\
\
    /*We dont just need the object, we need a reference to it hence the &*/\
    t& (*at)(Deque_##t *, int);\
    t& (*front)(Deque_##t *);\
    t& (*back)(Deque_##t *);\
\
    /*Iterators of current deque*/\
    Deque_##t##_Iterator& (*begin)(Deque_##t *);\
    Deque_##t##_Iterator& (*end)(Deque_##t *);\
\
    /*clearing Functions*/\
    void (*clear)(Deque_##t *);\
    void (*dtor)(Deque_##t *);\
\
    /*sort*/\
    void (*sort)(Deque_##t *, Deque_##t##_Iterator it1, Deque_##t##_Iterator it2);\
  };\
\
  struct Deque_##t##_Iterator{\
    int iter;\
    Deque_##t *itdeq;\
    /*functions to change iter variable*/\
    void (*inc)(Deque_##t##_Iterator *);\
    void (*dec)(Deque_##t##_Iterator *);\
    t& (*deref)(Deque_##t##_Iterator *);\
  } it_one_##t, it_two_##t;\
\
  /*Deque_##t Functions*/\
  size_t Deque_##t##_size(Deque_##t *deq){\
    return (deq->elems);\
  }\
\
  bool Deque_##t##_empty(Deque_##t *deq){\
    return (deq->elems == 0);\
  }\
\
  /*Push-pop*/\
  void Deque_##t##_push_back(Deque_##t *deq, t elem){\
  	/*if(deq->elems != 0) deq->last++;*/\
    deq->elems++;\
    deq->last = deq->first + deq->elems;\
    /*printf("1\n");*/\
    if(deq->last == deq->maxElems){\
      /*printf("2\n");*/\
      deq->maxElems = deq->maxElems*10;\
      deq->data = (t*) realloc(deq->data, sizeof(t)*deq->maxElems);\
      /*printf("3\n");*/\
    }\
    /*printf("Used position %d\n", deq->last);*/\
    /*printf("4 size: %d\n", sizeof(deq->data));*/\
    deq->data[deq->last-1] = elem;\
    /*printf("5\n");*/\
  }\
\
  void Deque_##t##_push_front(Deque_##t *deq, t elem){\
    if(deq->elems != 0) deq->first--;\
    deq->elems++;\
    if(deq->first < 0){\
      deq->maxElems = deq->maxElems*10;\
      deq->data = (t*) realloc(deq->data, sizeof(t)*deq->maxElems);\
      deq->first = deq->maxElems/2;\
      deq->last = deq->first + deq->elems;\
      /*reallocating all the elements*/\
      for(int i = 0; i < deq->elems; i++){\
        deq->data[deq->first+1+i] = deq->data[i];\
      }\
    }\
    /*printf("Used position %d\n", deq->first);*/\
    deq->last = deq->first + deq->elems;\
    deq->data[deq->first] = elem;\
  }\
\
  t &Deque_##t##_pop_back(Deque_##t *deq){\
    deq->elems--;\
    deq->last = deq->first + deq->elems;\
    return deq->data[deq->last];\
  }\
\
  t &Deque_##t##_pop_front(Deque_##t *deq){\
    deq->first++;\
    deq->elems--;\
    deq->last = deq->first + deq->elems;\
    return deq->data[deq->first-1];\
  }\
\
  /*Accessing elements of deque*/\
  t& Deque_##t##_at(Deque_##t *deq, int i){\
    return deq->data[deq->first+i];\
  }\
\
  t& Deque_##t##_front(Deque_##t *deq){\
    return deq->data[deq->first];\
  }\
\
  t& Deque_##t##_back(Deque_##t *deq){\
    return deq->data[deq->last-1];\
  }\
\
  bool Deque_##t##_equal(Deque_##t deq1, Deque_##t deq2){\
  	bool retVal = true;\
    if(deq1.elems == deq2.elems){\
      for(int i = 0; i < deq1.elems; i++){\
        if(deq1.less_by(deq1.at(&deq1, i), deq2.at(&deq2, i)) || deq1.less_by(deq2.at(&deq2, i), deq1.at(&deq1, i))){\
          /*If any values are not equal set the retval to false*/\
          retVal = false;\
        }\
      }\
    } else{\
    	retVal = false;\
    }\
    return retVal;\
  }\
\
  /*Iterator Functions*/\
  void Deque_##t##_Iterator_inc(Deque_##t##_Iterator *it){\
    it->iter++;\
  }\
\
  void Deque_##t##_Iterator_dec(Deque_##t##_Iterator *it){\
    it->iter--;\
  }\
\
  t& Deque_##t##_Iterator_deref(Deque_##t##_Iterator *it){\
  	/*printf("%d\n", it->iter);*/\
    return (it->itdeq->data[it->iter]);\
  }\
\
  Deque_##t##_Iterator& Deque_##t##_begin(Deque_##t *deq){\
    it_one_##t.iter = deq->first;\
    it_one_##t.itdeq = deq;\
    it_one_##t.inc = Deque_##t##_Iterator_inc;\
    it_one_##t.dec = Deque_##t##_Iterator_dec;\
    it_one_##t.deref = Deque_##t##_Iterator_deref;\
    return it_one_##t;\
  }\
\
  Deque_##t##_Iterator& Deque_##t##_end(Deque_##t *deq){\
    it_two_##t.iter = deq->first + deq->elems;\
    it_two_##t.itdeq = deq;\
    it_two_##t.inc = &Deque_##t##_Iterator_inc;\
    it_two_##t.dec = &Deque_##t##_Iterator_dec;\
    it_two_##t.deref = &Deque_##t##_Iterator_deref;\
    /*printf("last: %d\n", deq->last);*/\
    return it_two_##t;\
  }\
  bool Deque_##t##_Iterator_equal(Deque_##t##_Iterator it1, Deque_##t##_Iterator it2){\
    if(it1.iter == it2.iter){\
      return true;\
    }\
    return false;\
  }\
\
  /*clearing Functions*/\
  void Deque_##t##_clear(Deque_##t *deq){\
    deq->first = deq->last = deq->maxElems/2;\
    deq->elems = 0;\
  }\
\
  void Deque_##t##_dtor(Deque_##t *deq){\
    free(deq->data);\
  }\
\
  int t##_comparison(const void * void_elem1, const void * void_elem2, void *void_deq){\
      Deque_##t* deq = (Deque_##t*) void_deq;\
      t* elem1 = (t*) (void_elem1);\
      t* elem2 = (t*) (void_elem2);\
      if(deq->less_by(*elem1, *elem2)){\
          return 0;\
      }\
      return 1;\
  }\
  /*sort*/\
  void Deque_##t##_sort(Deque_##t *deq, Deque_##t##_Iterator it1, Deque_##t##_Iterator it2){\
    void * void_deq = (void *) deq;\
    qsort_r(deq->data+it1.iter, it2.iter - it1.iter, sizeof(t), t##_comparison, void_deq);\
  }\
 \
   void Deque_##t##_ctor(Deque_##t *deq, bool (*comp_func)(const t &elem1, const t &elem2)){\
    /*variables*/\
    deq->data = (t*) malloc(sizeof(t)*100);\
    deq->elems = 0;\
    deq->maxElems = 100;\
    /*starting in the middle reduces amount of reallocs*/\
    deq->first = deq->maxElems/2;\
    deq->last = deq->maxElems/2;\
\
    /*functions*/\
    deq->size = &Deque_##t##_size;\
    deq->empty = &Deque_##t##_empty;\
    deq->less_by = comp_func;\
\
    /*Push-pop*/\
    deq->push_back = &Deque_##t##_push_back;\
    deq->push_front = &Deque_##t##_push_front;\
    deq->pop_back = &Deque_##t##_pop_back;\
    deq->pop_front = &Deque_##t##_pop_front;\
\
    /*references to deque elements*/\
    deq->at = &Deque_##t##_at;\
    deq->front = &Deque_##t##_front;\
    deq->back = &Deque_##t##_back;\
\
    /*iterators*/\
    deq->begin = &Deque_##t##_begin;\
    deq->end = &Deque_##t##_end;\
\
    /*clearing Functions*/\
    deq->clear = &Deque_##t##_clear;\
    deq->dtor = &Deque_##t##_dtor;\
\
    /*sort*/\
    deq->sort = &Deque_##t##_sort;\
  }\

#endif
