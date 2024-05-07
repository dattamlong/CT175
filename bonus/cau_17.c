#include <stdio.h>
#define MAX_N 50

typedef struct
{
    int A[100][100];
    int n;
} Graph;

typedef struct
{
    int size;
    int elements[MAX_N];
} List;

void make_null_list(List *pL)
{
    pL->size = 0;
}

void push_back(List *pL, int x)
{
    pL->elements[pL->size++] = x;
}

int element_at(List *pL, int i)
{
    if (pL->size > 0)
        return pL->elements[i - 1];
    return -1;
}

void copy_list(List *L1, List *L2)
{
    make_null_list(L1);
    L1->size = L2->size;

    for (int i = 0; i < L1->size; ++i)
        L1->elements[i] = L2->elements[i];
}

typedef struct
{
    int data[100];
    int front, rear;
} Queue;

void make_null_queue(Queue *pQ)
{
    pQ->front = 0;
    pQ->rear = -1;
}

void enqueue(Queue *pQ, int u)
{
    pQ->rear++;
    pQ->data[pQ->rear] = u;
}

int front(Queue *pQ)
{
    return pQ->data[pQ->front];
}

void dequeue(Queue *pQ)
{
    pQ->front++;
}

int empty_queue(Queue *pQ)
{
    return pQ->front > pQ->rear;
}

int NhapDuLieu(Graph *G)
{
    int c, d, m, x, y;
    scanf("%d%d", &G->n, &m);
    for (d = 1; d <= G->n; d++)
        for (c = 1; c <= G->n; c++)
            G->A[d][c] = 0;

    for (c = 0; c < m; c++)
    {
        scanf("%d%d", &x, &y);
        G->A[x][y] = 1;
    }
    return 1;
}

void SapXepToPo(Graph *G, List *pL)
{
    int n = G->n;
    int b[1000], d[1000];
    Queue q;
    make_null_queue(&q);
    make_null_list(pL);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (G->A[i][j])
            {
                b[j]++;
            }
        }

    for (int i = 1; i <= n; i++)
        if (!b[i])
        {
            d[i] = 1;
            enqueue(&q, i);
        }

    while (!empty_queue(&q))
    {
        int u = front(&q);
        dequeue(&q);

        push_back(pL, u);

        for (int v = 1; v <= n; v++)
        {
            if (G->A[u][v])
            {

                b[v]--;
                if (!b[v])
                {
                    enqueue(&q, v);
                    d[v] = d[u] + 1;
                }
            }
        }
    }
}

void InKetQua(Graph *G, List *pL)
{
    for (int i = 1; i <= pL->size; i++)
        printf("%d %d\n", element_at(pL, i), (i - 1) * 40 + 7);
}

int main()
{
    Graph G;
    List L;
    NhapDuLieu(&G);
    SapXepToPo(&G, &L);
    InKetQua(&G, &L);
    return 0;
}