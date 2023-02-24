# include <iostream> 
# include <vector>
# include <queue>
using namespace std;
struct bst {
    int dato;
    struct bst* left;
    struct bst* right;
}*r; 

class bst_tree {
    public: 
        bst* insert (bst *, int); 
        int height(bst*); 
        void visit(int); 
        void inorder (bst *);
        void preorder (bst *); 
        void postorder (bst *); 
        void lbyl (bst *); 
        bool ancestors(bst*,int);
        void whatlevelaml (int); 
        void searchvalue (bst *,int);
        bst_tree(){
            r = NULL;
        }
};


bst* bst_tree::insert(bst* r, int v){
    if(r == NULL){
        r = new bst; 
        r->dato = v;
        r->left = NULL; 
        r->right = NULL; 
        return r;
    }

    else if (v < r->dato){
        r->left = insert(r->left, v);
    }

    else if (v >= r->dato){
        r->right = insert(r->right, v); 
    } return r; 
}

int bst_tree::height(bst* t){
    int h = 0;
    if (t != NULL){
        int l_height = height(t->left);
        int r_height = height(t->right);
        int max_height = max(l_height, r_height); 
        h = max_height + 1; 
    }
    return h;
}

void bst_tree::preorder(bst* t){
    if(t == NULL)
        return;
    cout << t->dato << " ";
    preorder(t->left);
    preorder(t->right);
}

void bst_tree::inorder(bst* t){
    if(t == NULL)
        return; 
    inorder(t->left);
    cout << t->dato << " "; 
    inorder(t->right);
}

void bst_tree::postorder(bst* t){
    if(t == NULL)
        return;
    postorder(t->left);
    postorder(t->right);
    cout << t->dato << " "; 
}

void bst_tree::lbyl(bst* t){
    if(t == NULL)
        return;
    queue<bst*> q;
    q.push(t);
    while (!q.empty()){
        int nodes = q.size();
        while (nodes > 0){
            bst* temp = q.front();
            cout << temp->dato << " "; 
            q.pop();
            if(temp->left != NULL)
                q.push(temp->left);
            if(temp->right != NULL)
                q.push(temp->right);
            nodes--; 
        }
    }
}

void bst_tree::visit(int m){
    if (m == 1)
        return preorder(r);
    else if (m == 2)
        return inorder(r);
    else if (m == 3)
        return postorder(r);
    else if (m == 4)
        return lbyl(r);
    else{
        cout << "modo de recorrido no valido." << endl;
    }
}

bool bst_tree::ancestors(bst* t, int v){
    if(t == NULL)
        return false; 
    if(t->dato == v)
        return true;
    if(ancestors(t->left, v) || ancestors(t->right, v)){
        cout << t->dato << " ";
        return true;
    }    
    return false;
}

void bst_tree::searchvalue(bst* t, int v){
    if (t == NULL)
        cout << -1 << endl;

    else if (v == t->dato){
        int ac; 
        ac = height(t);
        if (ac == 3){
            cout << 0 << endl;
        }

        else if (ac == 2){
            cout << 1 << endl;
        }

        else if (ac == 1){
            cout << 2 << endl;
        }
    }
        

    else if (v >= t->dato){
        return searchvalue(t->right, v);
    }

    else if (v < t->dato){
        return searchvalue(t->left, v);
    }
}

void bst_tree::whatlevelaml(int v){
    return searchvalue(r, v);
}


