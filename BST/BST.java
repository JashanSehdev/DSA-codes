 /*
 * This code is an Implementation of Binary Search Tree.
 * taking an assumption that all inputs element are unique
 */
import java.util.Comparator;

public class BST <T extends Comparable<T>> {
    // attributes
    public Node root;

    BST () {
        this.root = null;
    }
    class Node {
        T data;
        Node left;
        Node right;

        Node (T data) {
            this.data = data;
            left = null;
            right = null;
        }
    }

    public void insert (T val) {
        this.root = insert(this.root, val);
    }

    // helper function for insert
    private Node insert (Node root, T val){
        if ( root == null) {
            root = new Node(val);
        }

        int cmp = root.data.compareTo(val);

        if (cmp > 0) {
            root.left = insert(root.left, val);
        }
        else if (cmp < 0) {
            root.right = insert(root.right, val);
        }
        else root.data = val;

        return root;
    }

    // getter for root
    public Node getRoot() {
        return root;
    }

    // for checking the placement of the tree
    public void show() {
        show (this.root);
        System.out.println();
    }
    private void show(Node root) {
        if (root == null) return;

        show(root.left);
        System.out.print(root.data + " ");
        show(root.right);
    }
    
    // this fuction can also use to find inorder succesor and use in delete function
    public Node min (Node root) { 
        if (root == null) return null;

        while (root.left != null) {
            root = root.left;
        }
        
        return root;
    }

    public Node max (Node Root) {
        if (root == null) return null;
        while( root.right != null) root = root.right;
        return root;
    }

    public Node floor(T val) {
        return floor (this.root, val);
    }

    private Node floor(Node root, T val) {
        if (root == null) return null;

        int cmp = root.data.compareTo(val);
        if (cmp == 0) {
            return root;
        }
        if ( cmp > 0) {
            return  floor(root.left, val);
        }
        Node t = floor (root.right, val);
        return (t != null) ? t : root;
    }

    public Node ceil(T val) {
        return ceil (root, val);
    }
    private Node ceil(Node root, T val) {
        if(root == null) return null;
        int cmp = root.data.compareTo(val);
        if (cmp == 0) return root;
        if (cmp < 0) return floor(root.right, val);
        Node t = ceil(root.left, val);
        return (t != null) ? t : root ;
    }

    public boolean search (T val) {
        return search (root, val);
    }
    private boolean search (Node root, T val) {
        if (root == null) return false;
        int cmp = root.data.compareTo(val);
        if (cmp == 0) return true;
        else if (cmp  > 0) return search(root.left, val);
        else return search (root.right, val);
    }

    public Node delete (T val) {
        return delete (root, val);
    }
    private Node delete (Node root, T val) {
        if (root == null) return null;

        int cmp = root.data.compareTo(val);

        if (cmp > 0) root.left = delete(root.left, val);
        else if (cmp < 0) root.right = delete( root.right, val);
        else {

            // for 0 child
            if (root.left == null && root.right == null) return root = null;
            
            // for 1 child
            if (root.left == null) return root.right;
            if (root.right == null) return root.left;
            else {
                Node IS = min(root.right);
                root.data = IS.data;
                root.right = delete(root.right, IS.data);
            }
        }
        return root;
        

    }


    public static void main (String [] args) {
        BST <Integer> btree = new BST();
        int[] input = {3,2,-1,5,9,4};

        for (int i : input) {
            btree.insert(i);
        }


        assert btree.floor(10).data == 9 : "floor 2 test case failed";
        assert btree.ceil(1).data == 2 : "ceil of 3 test case failed";
        btree.delete(3);
        assert btree.getRoot().data == 4: "Facing issue in delete function";
    }
}