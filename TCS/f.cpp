#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define MAX 256
typedef struct Node 
{
    char name[50];
    int level;
    struct Node* children[MAX];
    int num_children;
} Node;
Node* create_node(const char* name) 
{
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->name, name);
    node->num_children = 0;
    return node;
}
void add_child(Node* parent, Node* child) 
{
    parent->children[parent->num_children++] = child;
}
Node* find_node(Node* nodes[], int* node_count, char* name) 
{
    for (int i = 0; i < *node_count; i++)
    {
        if (strcmp(nodes[i]->name, name) == 0)
            return nodes[i];
    }
    nodes[*node_count] = create_node(name);
    return nodes[(*node_count)++];
}
void bfs_assign_levels(Node* root) 
{
    Node* queue[MAX];
    int front = 0, rear = 0;
    root->level = 0;
    queue[rear++] = root;
    while (front < rear) {
        Node* current = queue[front++];
        for (int i = 0; i < current->num_children; i++) 
        {
            Node* child = current->children[i];
            child->level = current->level + 1;
            queue[rear++] = child;
        }
    }
}
int main() 
{
    int N, A, B, C, m, n;
    char line[1024], *token;
    Node* nodes[MAX];
    int node_count = 0;
    Node* root = NULL;
    scanf("%d\n", &N);
    for (int i = 0; i < N; i++) 
    {
        fgets(line, sizeof(line), stdin);
        char* colon = strchr(line, ':');
        if (colon)
        {
            *colon = '\0';
            Node* parent = find_node(nodes, &node_count, strtok(line, " \n"));
            if (i == 0) root = parent;
            token = strtok(colon + 1, " \n");
            while (token) 
            {
                Node* child = find_node(nodes, &node_count, token);
                add_child(parent, child);
                token = strtok(NULL, " \n");
            }
        } 
        else 
        {
            if (i == 0) root = find_node(nodes, &node_count, strtok(line, " \n"));
        }
    }
    bfs_assign_levels(root);
    char melody1[MAX][50], melody2[MAX][50];
    fgets(line, sizeof(line), stdin);
    m = 0;
    token = strtok(line, "-\n");
    while (token)
    {
        strcpy(melody1[m++], token);
        token = strtok(NULL, "-\n");
    }
    fgets(line, sizeof(line), stdin);
    n = 0;
    token = strtok(line, "-\n");
    while (token) 
    {
        strcpy(melody2[n++], token);
        token = strtok(NULL, "-\n");
    }
    scanf("%d %d %d", &A, &B, &C);
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= m; i++)
        dp[i][0] = dp[i - 1][0] - C;
    for (int j = 1; j <= n; j++)
        dp[0][j] = dp[0][j - 1] - C;
    for (int i = 1; i <= m; i++) 
    {
        for (int j = 1; j <= n; j++) 
        {
            dp[i][j] = dp[i - 1][j] - C;
            dp[i][j] = (dp[i][j - 1] - C > dp[i][j]) ? dp[i][j - 1] - C : dp[i][j];
            int tune1_level = find_node(nodes, &node_count, melody1[i - 1])->level;
            int tune2_level = find_node(nodes, &node_count, melody2[j - 1])->level;
            if (strcmp(melody1[i - 1], melody2[j - 1]) == 0 || tune1_level == tune2_level)
            {
                dp[i][j] = (dp[i - 1][j - 1] + A > dp[i][j]) ? dp[i - 1][j - 1] + A : dp[i][j];
            } 
            else 
            {
                dp[i][j] = (dp[i - 1][j - 1] - B > dp[i][j]) ? dp[i - 1][j - 1] - B : dp[i][j];
            }
        }
    }
    printf("%d\n", dp[m][n]);
    return 0;
}