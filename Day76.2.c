// Helper DFS function
struct Node* dfs(struct Node* node, struct Node** map) {
    if (!node) return NULL;

    // If already cloned → return it
    if (map[node->val] != NULL)
        return map[node->val];

    // Create new node
    struct Node* clone = (struct Node*)malloc(sizeof(struct Node));
    clone->val = node->val;
    clone->numNeighbors = node->numNeighbors;
    clone->neighbors = (struct Node**)malloc(sizeof(struct Node*) * node->numNeighbors);

    // Store in map
    map[node->val] = clone;

    // Clone neighbors
    for (int i = 0; i < node->numNeighbors; i++) {
        clone->neighbors[i] = dfs(node->neighbors[i], map);
    }

    return clone;
}

struct Node *cloneGraph(struct Node *s) {
    if (!s) return NULL;

    // Map (assuming values 1–100)
    struct Node* map[101] = {NULL};

    return dfs(s, map);
}