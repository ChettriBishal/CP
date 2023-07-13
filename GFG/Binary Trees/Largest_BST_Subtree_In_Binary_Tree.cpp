    int largestBst(Node *root)
    {
    	return getlargest(root).size;
    }
    info getlargest(Node* root){
        if(root == NULL){
            return {0,true,INT_MAX,INT_MIN};
        }
        if(root->left == NULL && root->right == NULL){
            return {1, true, root->data, root->data};
        }
        info leftsub = getlargest(root->left);
        info rightsub = getlargest(root->right);
        info ok;
        if(leftsub.isbst && rightsub.isbst && leftsub.maxval < root->data && root->data < rightsub.minval){
            ok.size = 1 + leftsub.size + rightsub.size;
            ok.isbst = true;
            ok.minval = min(leftsub.minval,root->data); // also compare root->data incase there is no left subtree present 
            ok.maxval = max(rightsub.maxval,root->data); // in case right subtree isn't present 
            return ok;
        }
        ok.size = max(leftsub.size, rightsub.size);
        ok.isbst = false;
        return ok;
    }
};
