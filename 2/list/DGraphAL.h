#ifndef DGraphAL_h
#define DGraphAL_h

void Init(int n);
void Insert(int src, int dest);
void Delete(int src, int dest);
void Destroy();
void TopSort(void);
void PrintResult();
void Append(int src, int dest);
int hasPointer(int numb);
void DeleteDest(int src);

#endif
