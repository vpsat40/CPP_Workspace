/* 
 * Print bottom view of a binary tree
 * Given a binary tree, print the bottom view of it. Assume the left and right child of a node makes a 45–degree angle with the parent.
 * 
 * For example, the bottom view of the following tree is 7, 5, 8, 6:
 * 
 *      1
 *    /   \
 *   2     3
 *        /  \
 *       5    6
 *     /   \
 *    7     8
 * Bottom View of Binary Tree
 * 
 * We can easily solve this problem with the help of hashing. The idea is to create an empty map where each key represents the 
 * relative horizontal distance of the node from the root node, and the value in the map maintains a pair containing the node’s 
 * value and its level number. 
 * 
 * Then perform preorder traversal on the tree. Suppose the current node’s level is more than or equal to the maximum level seen 
 * so far for the same horizontal distance as the current node’s or current horizontal distance is seen for the first time. 
 * In that case, update the value and the level for the current horizontal distance in the map. For each node, recur for its 
 * left subtree by decreasing horizontal distance and increasing level by one, and recur for right subtree by increasing 
 * both level and horizontal distance by one.
 * 
 * The following figure shows the horizontal distance and level of each node in the above binary tree. 
 * The final values in the map will be:
 * 
 * (horizontal distance —> (node’s value, node’s level))
 * -1 —> (7, 4)
 *  0 —> (5, 3)
 *  1 —> (8, 4)
 *  2 —> (6, 3)
 * 
 *  Level 1     1
 *            /   \
 *  Level 2   2     3
 *                /   \
 *  Level 3      5     6
 *             /   \
 *  Level 4   7     8
 *            |  |  |   |
 *            |  |  |   |
 *           HD1 | HD3  |
 *              HD2     HD4
 */

#include <iostream>
#include <map>

using namespace std;

// Data structure to store a binary tree node

struct Node
{
    int key;
    Node *left, *right;

    Node(int key)
    {
        this->key = key;
        this->left = this->right = nullptr;
    }
};

void preOrderBottom(Node* node, int dist, int level, auto& bNode)
{
    // base case - if empty tree
    if(node == nullptr)
        return;

    // if the current level is more than or equal to maximul level seen so far
    // for the same horizontal distance or horizontal distance is seen for the first 
    // time, update the map

    if(level >= bNode[dist].second)
        //update value and level for the current distance
        bNode[dist] = {node->key, level};

    // recur for the left subtree by decreasing horizontal distance and 
    // increasing level by 1
    preOrderBottom(node->left, dist-1, level+1, bNode);

    // recur for the right subtree by increasing horizontal distance and 
    // level by 1
    preOrderBottom(node->right, dist+1, level+1, bNode);
}

void printBottom(Node* root)
{
    // create an empty map where
    // key = relative horizontal distance of the node from the root node,
    // value = pair containing the node's value and level

    map<int, pair<int, int>> bNodes;

    // Perform preorder traversal on the tree and fill the map accordingly
    preOrderBottom(root, 0, 0, bNodes);

    // Traverse the map and print the bottom view
    for(auto it:bNodes)
        cout << it.second.first << " ";
}

int main()
{
    Node *root= new Node(1);
    root->left= new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);

    printBottom(root);

    cout << endl;

    return 0;
}
