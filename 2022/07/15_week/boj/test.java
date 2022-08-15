class Node{
    Node left;
    Node right;
    int val;

    Node(int data){
        val = data;
        left = null;
        right = null;
    }

    Node findMin(Node root, int val){
        if(root == null){
            return null;
        }
        else if(root.val == val){
            return root;
        }
        else{
            return findMin(left, val);
        }
    }

    Node insert(Node root, int val){
        if(root == null){
            root = new Node(val);
            return root;
        }
        if(root.val > val){
            return insert(root.left, val);
        }
        else if(root.val < val){
            return insert(root.right, val);
        }
        return root;
    }

    Node findVal(Node root, int val){
        if(root == null){
            return root;
        }
        if(root.val > val){
            return findVal(root.left, val);
        }
        else if(root.val < val){
            return findVal(root.right, val);
        }
        return root;
    }

    Node popVal(Node root, int val){
        if(root == null){
            return null;
        }
        if(root.val > val){
            return popVal(root.left, val);
        }
        else if(root.val < val){
            return popVal(root.right, val);
        }
        else{
            Node target = findVal(root, val);
            Node node = null;
            if(target.left == null && target.right != null){
                target.val = target.right.val;
                target.right = null;
            }else if(target.left != null && target.right == null){
                target.val = target.left.val;
                target.left = null;
            }
            else{
                node = findMin(root, val);
                target.val = node.val;
                node = null;
            }
            return node;
        }
    }
}
