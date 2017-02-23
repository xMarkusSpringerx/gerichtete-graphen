#ifndef GraphAL_h
#define GraphAL_h

void Init(int n);
void Insert(int n, int src, int dest);
void Append(int src, int dest);
void Delete(int n, int src, int dest);
void DeleteNode(int n, int src, int dest);
void Destroy(int n);
void PrintResult(int n);

#endif /* GraphAL_h */
