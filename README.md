# Binary Tree Operations

This project implements a binary tree in C++ with various operations to insert nodes and traverse the tree. The program includes functions to create nodes, insert nodes, and perform different tree traversals such as pre-order, in-order, and post-order. It also features a function to visually display the tree structure.

## Repository Name
binary-tree-operations

## Features

- **Insert Node**: Adds a new node to the binary tree.
- **Pre-order Traversal**: Traverses the tree in pre-order (root, left, right).
- **In-order Traversal**: Traverses the tree in in-order (left, root, right).
- **Post-order Traversal**: Traverses the tree in post-order (left, right, root).
- **Display Tree**: Visually displays the structure of the binary tree.
- **Menu Interface**: Provides a user-friendly interface to perform the above operations.

## Usage

Compile the program using a C++ compiler and run the executable. You will be prompted to enter the number of nodes and their values, after which you can perform various tree operations.

### Example Commands

1. **Insert Node**: Prompts the user to enter the value for each new node.
2. **Pre-order Traversal**: Displays the nodes in pre-order traversal.
3. **In-order Traversal**: Displays the nodes in in-order traversal.
4. **Post-order Traversal**: Displays the nodes in post-order traversal.
5. **Display Tree**: Visually displays the tree structure.

## Code Snippets

### Create Node

This function creates a new node with a given value and initializes its left and right children to NULL.

```cpp
NDO crearNodo(int x) {
    NDO nuevoNodo = new(struct nodo); // Create space for the new node
    nuevoNodo->dato = x; // Assign the value to the new node
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;
    return nuevoNodo; // Return the new node
}
```

### Insert Node

This function inserts a new node into the binary tree. If the tree is empty, it creates a new node as the root. Otherwise, it inserts the node in the correct position based on its value.

```cpp
void insertar(NDO& arbol, int x) {
    if (arbol == NULL) { // Check if the tree is empty
        arbol = crearNodo(x); // Create a new node
    } else if (x < arbol->dato) { // If the value is less than the root
        insertar(arbol->izq, x); // Insert in the left subtree
    } else if (x > arbol->dato) { // If the value is greater than the root
        insertar(arbol->der, x); // Insert in the right subtree
    }
}
```

### Pre-order Traversal

This function performs a pre-order traversal of the binary tree, printing the value of each node as it visits them.

```cpp
void preOrden(NDO arbol) {
    if (arbol != NULL) { // If the node is not NULL
        cout << arbol->dato << "  "; // Print the current node
        preOrden(arbol->izq); // Recursively traverse the left subtree
        preOrden(arbol->der); // Recursively traverse the right subtree
    }
}
```

### Menu Interface

This part of the code provides a simple interface to interact with the binary tree. It prompts the user to enter the number of nodes and their values, and then displays the tree and performs various traversals.

```cpp
int main() {
    NDO arbol = NULL; // Create the binary tree

    int n; // Number of nodes in the tree
    int x; // Value to insert in each node

    cout << "\n\t - - - - - GRAFUNGO BINARIO - - - - - \n\n";
    cout << " NUMERO DE NODOS: ";
    cin >> n;
    cout << endl;

    // Insert nodes into the tree
    cout << "\t NODO " << "| VAL " << endl;
    for (int i = 0; i < n; i++) {
        cout << "\t  #" << i + 1 << "  | "; // Indicator of the current node
        cin >> x; // Input value
        insertar(arbol, x);
    }

    // Display the tree
    cout << "\n ARBOL GENERADO \n\n";
    verArbol(arbol, 0);

    // Pre-order traversal
    cout << "\n\n PreOrden: ";
    preOrden(arbol);
    cout << endl << endl;

    // In-order traversal
    cout << "\n\n enOrden: ";
    enOrden(arbol);
    cout << endl << endl;

    // Post-order traversal
    cout << "\n\n postOrden: ";
    postOrden(arbol);
    cout << endl << endl;

    system("pause");
    return 0;
}
```
## How to Run

1. Clone the repository:
    ```bash
    git clone https://github.com/KPlanisphere/binary-tree-operations.git
    ```
2. Navigate to the project directory:
    ```bash
    cd binary-tree-operations
    ```
3. Compile the code:
    ```bash
    g++ ABinario_V2.cpp -o binary_tree
    ```
4. Run the executable:
    ```bash
    ./binary_tree
    ```

